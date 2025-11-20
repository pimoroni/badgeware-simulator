#!/bin/bash

BADGEWARE_SIMULATOR=$(dirname "${BASH_SOURCE[0]}")
PYTHON_SCRIPT="$1"
TIME_SECONDS="$2"
OUTPUT_FILE="$3"

printf "Headless: Running script $PYTHON_SCRIPT for $TIME_SECONDS sec.\n"
printf "Running in $BADGEWARE_SIMULATOR, output $OUTPUT_FILE\n"

cp "$PYTHON_SCRIPT" "$BADGEWARE_SIMULATOR/root/record_app.py"
cd "$BADGEWARE_SIMULATOR"

./build/micropython record_app $TIME_SECONDS false

if [[ "$TIME_SECONDS" -eq "0" ]]; then
    printf "Copying $BADGEWARE_SIMULATOR/screenshots/record_app-000001.png to $OUTPUT_FILE\n"
    cp "$BADGEWARE_SIMULATOR/screenshots/record_app-000001.png" "$OUTPUT_FILE"
else
    printf "Generating video from $BADGEWARE_SIMULATOR/screenshots/record_app-*.png and saving to $OUTPUT_FILE\n"
    #ffmpeg -y -pattern_type glob -r 60 -i 'screenshots/record_app-*.png' -c:v libx264 -preset ultrafast -crf 18 -vf format=yuv420p,scale=640:480:flags=neighbor -movflags +faststart -an -fps_mode passthrough "$OUTPUT_FILE"
    ffmpeg -y -pattern_type glob -r 60 -i 'screenshots/record_app-*.png' -c:v libvpx -vf scale=640:480:flags=neighbor -movflags +faststart -an -fps_mode passthrough -auto-alt-ref 0 "$OUTPUT_FILE"
fi

rm -r $BADGEWARE_SIMULATOR/screenshots/record_app-*.png
