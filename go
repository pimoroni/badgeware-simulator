reset

if [ "${1-}" = "root" ]; then
	make -j && ./build/micropython root=root-badgeware watch=root-badgeware/system
else
	make -j && ./build/micropython code=./test/main.py
fi
