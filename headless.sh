!/bin/bash

PYTHON_SCRIPT=$1
TIME_SECONDS=$2

printf "Python script: $PYTHON_SCRIPT\n"

BADGEWARE_SIMULATOR="/home/jon/badgeware-simulator"

cp "$PYTHON_SCRIPT" "$BADGEWARE_SIMULATOR/root/record_app.py"
cd "$BADGEWARE_SIMULATOR"

./build/micropython record_app $TIME_SECONDS
