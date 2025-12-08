import simulator
import gc
from picovector import debug, brushes, shapes, PixelFont
import time


DEBUG_FONT = PixelFont.load("/system/assets/fonts/ignore.ppf")
DEBUG_BG = brushes.color(0, 0, 0)
DEBUG_FG = brushes.color(255, 255, 255)

AVERAGE_OVER = 10

NOMINAL_FREE_MEM = 230656

BAR_WIDTH = 4
MAX_AVERAGES = int(debug.width / (BAR_WIDTH + 1))

t_start = 0
t_total = 0
frames = 0
frame_averages = []
mem_averages = []


def draw_graph(title, graph, x, y, bar_width=8, bar_height=100, max_value=None):
    debug.text(title, x, y)
    debug.brush = brushes.color(255, 0, 0)
    shapes.line(0, y, debug.width, y, 2).draw(debug)
    debug.brush = brushes.color(255, 255, 255)
    _tw, th = debug.measure_text(title)
    y += th + 5
    if graph:
        max_avg = max_value if max_value else max(graph)
        for avg in graph:
            avg = int(avg / max_avg * bar_height)
            shapes.rectangle(x, y + bar_height - avg, bar_width, avg).draw(debug)
            x += bar_width + 1
    shapes.line(0, y + bar_height, debug.width, y + bar_height, 2).draw(debug)
    return th + 5 + bar_height


def update():
    debug.brush = DEBUG_BG
    debug.clear()

    debug.font = DEBUG_FONT
    debug.brush = DEBUG_FG
    debug.text("Hello Debug!", 1, 0)

    y = 30
    y += draw_graph("Frame time (ms)", frame_averages, 1, y, bar_width=BAR_WIDTH)
    draw_graph("Mem free (%)", mem_averages, 1, y, max_value=1.0, bar_width=BAR_WIDTH)


def __enter__():
    global t_start

    t_start = time.ticks_ms()



def __exit__(_type, _value, _traceback):
    global frames, t_total
    frames += 1
    t_total += time.ticks_diff(time.ticks_ms(), t_start)
    if frames == AVERAGE_OVER:
        frame_averages.append(t_total / AVERAGE_OVER)
        mem_averages.append(gc.mem_free() / NOMINAL_FREE_MEM)
        while len(frame_averages) > MAX_AVERAGES:
            frame_averages.pop(0)
            mem_averages.pop(0)
        t_total = 0
        frames = 0
    update()