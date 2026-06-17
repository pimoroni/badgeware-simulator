# Badgeware Simulator

Simulator for the development of the Picovector graphics API and accompanying badgeware apps.

## Controls

| Key    | Action |
|--------|--------|
| H      | Home   |
| Left   | A      |
| Space  | B      |
| Right  | C      |
| Up     | Up     |
| Down   | Down   |
| Escape | Hot Reload |
| P      | Screenshot |
| R      | Continuous Recording |

## Screenshots

The screenshot hotkey - `p` - takes a single screenshot and saves it to `screenshots/screenshot-<timestamp>.png`

### Convert to video

Run `screenshot-to-video.py` with a filename (either ending with .png or .gif), or:

```
ffmpeg -pattern_type glob -r 60 -i 'screenshots/screenshot-*.png' -c:v libx264 -preset ultrafast -crf 18 -vf scale=640:480:flags=neighbor -fps_mode passthrough video.mp4
```

## Continuous Recording

Continuous recording toggles automatic screenshots every single frame.

Frames are saved as `screenshots/cont-<session>-<frame>.png`.

:warning: Note: `session` resets every application close, so move/process your continuous recordings before reloading.

### Convert to video

```
ffmpeg -pattern_type glob -r 60 -i 'screenshots/cont-01-*.png' -c:v libx264 -preset ultrafast -crf 18 -vf scale=640:480:flags=neighbor -fps_mode passthrough video.mp4
```

## Building

### Linux

Deps: `libxi-dev libxcursor-dev`

Running on a Pi: `LIBGL_ALWAYS_SOFTWARE=1`
