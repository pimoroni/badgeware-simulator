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
| H      | Screenshot |
| Escape | Hot Reload |

## Screenshots to Video

Run `screenshot-to-video.py` with a filename (either ending with .png or .gif), or:

```
ffmpeg -pattern_type glob -r 60 -i 'screenshots/screenshot-*.png' -c:v libx264 -preset ultrafast -crf 18 -vf scale=640:480:flags=neighbor -fps_mode passthrough video.mp4
```

## Building

### Linux

Deps: `libxi-dev libxcursor-dev`

Running on a Pi: `LIBGL_ALWAYS_SOFTWARE=1`
