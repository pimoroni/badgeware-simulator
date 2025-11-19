#!/bin/bash

BADGEWARE_SIMULATOR=$(dirname "${BASH_SOURCE[0]}")
PYTHON_SCRIPT="$1"
TIME_SECONDS="$2"
OUTPUT_FILE="$3"

printf "Running in $BADGEWARE_SIMULATOR\n"
printf "Python script: $PYTHON_SCRIPT\n"

cp "$PYTHON_SCRIPT" "$BADGEWARE_SIMULATOR/root/record_app.py"
cd "$BADGEWARE_SIMULATOR"

./build/micropython record_app $TIME_SECONDS

if ["$TIME_SECONDS" -eq "0"]; then
    cp "$BADGEWARE_SIMULATOR/screenshots/record_app-000001.png" "$OUTPUT_FILE"
else
    ffmpeg -pattern_type glob -r 60 -i 'screenshots/record_app-*.png' -c:v libx264 -preset ultrafast -crf 18 -vf scale=640:480:flags=neighbor -fps_mode passthrough "$OUTPUT_FILE"
fi

rm -r "$BADGEWARE_SIMULATOR/screenshots/record_app-*.png"
