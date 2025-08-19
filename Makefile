CMAKE_BUILD_DIR = "build"

all: submodules cmake_build_dir cmake_configure cmake_build

submodules:
	git submodule update --init
	cd lib/micropython; git submodule update --init lib/micropython-lib

cmake_build_dir:
	mkdir -p "${CMAKE_BUILD_DIR}"

cmake_configure:
	cmake -S micropython -B "${CMAKE_BUILD_DIR}"

cmake_build:
	cmake --build "${CMAKE_BUILD_DIR}" -j

run:
	"./${CMAKE_BUILD_DIR}/micropython" code=test/main.py
