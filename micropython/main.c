/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
 * Copyright (c) 2014-2017 Paul Sokolovsky
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "badgeware.h"
#include "modsimulator.h"

#ifndef NO_QSTR
#define SOKOL_ARGS_IMPL
#define SOKOL_TIME_IMPL
#define SOKOL_GL_IMPL

#include "sokol_app.h"
#include "sokol_args.h"
#include "sokol_gfx.h"
//#include "sokol_gl.h"
#include "sokol_log.h"
#include "sokol_glue.h"
#include "sokol_time.h"
#include "cimgui.h"
#include "sokol_imgui.h"
#endif

bool debug_view = false;
ImVec2 window_size;
ImVec2 window_aspect;

static struct {
    sg_pass_action pass_action;
    struct {
        ImVec2 buffer_size;
        ImVec2 render_size;
        sg_image screen;
        sg_view view;
    } badgeware;
    struct {
        ImVec2 buffer_size;
        ImVec2 render_size;
        sg_image screen;
        sg_view view;
    } debug;
    struct {
        sg_sampler nearest_clamp;
        sg_sampler linear_clamp;
    } smp;
} state;

void* smemtrack_alloc(size_t size, void* user_data) {
    return malloc(size);
}

void smemtrack_free(void* ptr, void* user_data) {
    free(ptr);
}

static void recalculate_render_sizes(void) {
    state.badgeware.render_size.y = window_size.y;
    state.badgeware.render_size.x = (state.badgeware.render_size.y / state.badgeware.buffer_size.y) * state.badgeware.buffer_size.x;

    state.debug.render_size.y = window_size.y;
    state.debug.render_size.x = (state.debug.render_size.y / state.debug.buffer_size.y) * state.debug.buffer_size.x;
    state.debug.render_size.x += 1;
}

static void sokol_init(void) {
    stm_setup(); // sokol_time.h

    sg_setup(&(sg_desc){
        .environment = sglue_environment(),
        .logger.func = slog_func,
        .allocator = (sg_allocator) {
            .alloc_fn = smemtrack_alloc,
            .free_fn = smemtrack_free
        }
    });

    simgui_setup(&(simgui_desc_t){ .allocator = (simgui_allocator_t) {
        .alloc_fn = smemtrack_alloc,
        .free_fn = smemtrack_free
    }});

    state.smp.nearest_clamp = sg_make_sampler(&(sg_sampler_desc){
        .min_filter = SG_FILTER_NEAREST,
        .mag_filter = SG_FILTER_NEAREST,
        .wrap_u = SG_WRAP_CLAMP_TO_EDGE,
        .wrap_v = SG_WRAP_CLAMP_TO_EDGE,
    });

    state.smp.linear_clamp = sg_make_sampler(&(sg_sampler_desc){
        .min_filter = SG_FILTER_LINEAR,
        .mag_filter = SG_FILTER_LINEAR,
        .wrap_u = SG_WRAP_CLAMP_TO_EDGE,
        .wrap_v = SG_WRAP_CLAMP_TO_EDGE,
    });

    // initial clear color
    state.pass_action = (sg_pass_action) {
        .colors[0] = { .load_action = SG_LOADACTION_CLEAR, .clear_value = { 0.0f, 0.5f, 1.0f, 1.0 } }
    };

    state.badgeware.buffer_size.x = 160;
    state.badgeware.buffer_size.y = 120;

    state.debug.buffer_size.x = DEBUG_BUFFER_WIDTH;
    state.debug.buffer_size.y = DEBUG_BUFFER_HEIGHT;

    recalculate_render_sizes();

    // Main Badgeware display output
    state.badgeware.screen = sg_alloc_image();
    sg_init_image(state.badgeware.screen, &(sg_image_desc){
        .width = state.badgeware.buffer_size.x,
        .height = state.badgeware.buffer_size.y,
        .pixel_format = SG_PIXELFORMAT_RGBA8,
        .usage.dynamic_update = true
    });
    state.badgeware.view = sg_make_view(&(sg_view_desc){ .texture.image = state.badgeware.screen });

    // Supplementary debug output
    state.debug.screen = sg_alloc_image();
    sg_init_image(state.debug.screen, &(sg_image_desc){
        .width = state.debug.buffer_size.x,
        .height = state.debug.buffer_size.y,
        .pixel_format = SG_PIXELFORMAT_RGBA8,
        .usage.dynamic_update = true
    });
    state.debug.view = sg_make_view(&(sg_view_desc){ .texture.image = state.debug.screen });

    if(badgeware_init() != 0) {
        exit(EXIT_FAILURE);
    }
}

// from https://github.com/floooh/sokol-samples/blob/master/sapp/imgui-images-sapp.c#L52
// helper function to construct ImTextureRef from ImTextureID
// FIXME: remove when Dear Bindings offers such helper
static ImTextureRef imtexref(ImTextureID tex_id) {
    return (ImTextureRef){ ._TexID = tex_id };
}

/*
static void _igWindowMaintainAspect(ImGuiSizeCallbackData* data)
{
    ImVec2 *aspect = (ImVec2 *)data->UserData;
    data->DesiredSize.x = (data->DesiredSize.y / aspect->y) * aspect->x;
}*/

//ImVec2 aspect = {4, 3};

static void sokol_frame(void) {
    simgui_new_frame(&(simgui_frame_desc_t){
        .width = sapp_width(),
        .height = sapp_height(),
        .delta_time = sapp_frame_duration(),
        .dpi_scale = sapp_dpi_scale(),
    });

    // Re-setup Sokol Time if Badgeware is going to hot-reload
    // gives us a clean slate for ticks
    if(badgeware_will_hot_reload()) {
        stm_setup();
    }
    badgeware_update(stm_ms(stm_now()));

    const ImVec2 uv0 = { 0, 0 };
    const ImVec2 uv1 = { 1, 1 };

    // Update and display the main Badgeware view
    sg_update_image(state.badgeware.screen, &(sg_image_data){
        .mip_levels[0] = {
            .ptr = framebuffer,
            .size = state.badgeware.buffer_size.x * state.badgeware.buffer_size.y * sizeof(uint32_t),
        }
    });
    igSetNextWindowPos((ImVec2){0, 0}, ImGuiCond_Always);
    igSetNextWindowSize(state.badgeware.render_size, ImGuiCond_Always);
    igPushStyleVarImVec2(ImGuiStyleVar_WindowPadding, (ImVec2){0.0f, 0.0f});
    igPushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    if (igBegin("Badgeware Output", 0, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize)) {
        ImTextureID texid0 = simgui_imtextureid_with_sampler(state.badgeware.view, state.smp.nearest_clamp);
        igImageEx(imtexref(texid0), state.badgeware.render_size, uv0, uv1);
    }
    igEnd();
    igPopStyleVar(); // ImGuiStyleVar_WindowPadding
    igPopStyleVar(); // ImGuiStyleVar_WindowBorderSize

    if(debug_view) {
        // Update and display the dedicated debug pane
        sg_update_image(state.debug.screen, &(sg_image_data){
            .mip_levels[0] = {
                .ptr = debug_buffer,
                .size = state.debug.buffer_size.x * state.debug.buffer_size.y * sizeof(uint32_t),
            }
        });
        igSetNextWindowPos((ImVec2){state.badgeware.render_size.x, 0}, ImGuiCond_Always);
        igSetNextWindowSize(state.debug.render_size, ImGuiCond_Always);
        igPushStyleVarImVec2(ImGuiStyleVar_WindowPadding, (ImVec2){0.0f, 0.0f});
        igPushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        if (igBegin("Debug Output", 0, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize)) {
            ImTextureID texid0 = simgui_imtextureid_with_sampler(state.debug.view, state.smp.nearest_clamp);
            igImageEx(imtexref(texid0), state.debug.render_size, uv0, uv1);
        }
        igEnd();
        igPopStyleVar(); // ImGuiStyleVar_WindowPadding
        igPopStyleVar(); // ImGuiStyleVar_WindowBorderSize
    }

    sg_begin_pass(&(sg_pass){ .action = state.pass_action, .swapchain = sglue_swapchain() });
    simgui_render();
    sg_end_pass();
    sg_commit();
}

static void sokol_cleanup(void) {
    badgeware_deinit();
    simgui_shutdown();
    sg_shutdown();
}

static void sokol_event(const sapp_event* ev) {
    if(ev->type == SAPP_EVENTTYPE_RESIZED) {
        window_size = (ImVec2){ev->window_width, ev->window_height};
        recalculate_render_sizes();
    }
    if(ev->type == SAPP_EVENTTYPE_KEY_DOWN || ev->type == SAPP_EVENTTYPE_KEY_UP) {
        bool keydown = ev->type == SAPP_EVENTTYPE_KEY_DOWN;
        uint8_t mask = 0;
        switch (ev->key_code) {
            case SAPP_KEYCODE_H: // Home
                mask = 0b100000;
                break;
            case SAPP_KEYCODE_LEFT: // A
                mask = 0b010000;
                break;
            case SAPP_KEYCODE_SPACE: // B
                mask = 0b001000;
                break;
            case SAPP_KEYCODE_RIGHT: // C
                mask = 0b000100;
                break;
            case SAPP_KEYCODE_UP: // Up
                mask = 0b000010;
                break;
            case SAPP_KEYCODE_DOWN: // Down
                mask = 0b000001;
                break;
            case SAPP_KEYCODE_ESCAPE: // Home
                modsim_set_hot_reload();
                badgeware_trigger_hot_reload();
                break;
            default:
                simgui_handle_event(ev);
                return;
        }
        badgeware_input(mask, keydown);
    }
    simgui_handle_event(ev);
}


sapp_desc sokol_main(int argc, char* argv[]) {
    badgeware_preinit();

    sargs_setup(&(sargs_desc){
        .argc = argc,
        .argv = argv
    });

    window_size.x = 160 * 6;
    window_size.y = 120 * 6;
    window_aspect.x = 4;
    window_aspect.y = 3;

    if (sargs_boolean("debug")) {
        debug_view = true;

        window_size.x = (160 + 100) * 6;
        window_aspect.x = 13;
        window_aspect.y = 6;
    }

    return (sapp_desc){
        .init_cb = sokol_init,
        .frame_cb = sokol_frame,
        .cleanup_cb = sokol_cleanup,
        .event_cb = sokol_event,
        .window_title = "Badgeware Desktop",
        .width = window_size.x,
        .height = window_size.y,
        .aspect_x = window_aspect.x,
        .aspect_y = window_aspect.y,
        .icon.sokol_default = true,
        .logger.func = slog_func,
    };
}