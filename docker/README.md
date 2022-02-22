# LibFive Docker Build
docker build --tag emscripten_libfive --file Dockerfile.emscripten.debian .

# LibFive Docker Run
docker run -it emscripten_libfive bash

# LibFive Docker Run with Shared volume (new_vol created by docker desktop)
docker run -it -v new_vol:/my_files emscripten_libfive bash

## share path
docker run -it -v c:/:/data:/my_files emscripten_libfive bash

files will be available in /my_files inside the container

or if its already mounted, then run docker exec:
docker exec -it mystifying_newton bash

## copy file from container, ex: "keen_banach"
docker exec keen_banach pwd
docker cp keen_banach:/libfive/build/cli/sphere.stl sphere.stl

# LibFive build libfive
git clone https://github.com/Ammarkhat/libfive.git
cd libfive
mkdir build
cd build
cmake ..
make -j4

## update local repo
git fetch --all
git reset --hard origin/dev-ammar
cd build
make -j4

## clone submodule msg-c
git clone https://github.com/msgpack/msgpack-c

## using emscripten
emcmake cmake ..
emmake make -j8
emcc libfive/src/libfive.a -o libfive.html

emcc libfive/src/libfive.a -o libfive.html -Os \
      -s WASM=1 \
      -s FETCH=1 \
      -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap", "setValue", "getValue"]' \
      -s ALLOW_MEMORY_GROWTH=1 \
      -s EXPORTED_FUNCTIONS="['_malloc', '_get_mesh', '_free']"

## some examples of emcc
emcc hello.c -o hello.js -s WASM=1 -s EXPORTED_FUNCTIONS='["_fib"]' -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]'

emcc lib/libzstd.bc -o zstd.js -O2 -s WASM=1 -s EXPORTED_FUNCTIONS="['_ZSTD_compress', '_ZSTD_compressBound', '_ZSTD_isError']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap']" -s ALLOW_MEMORY_GROWTH=1 -s ABORTING_MALLOC=0

emcc \
      -Os \
      -s WASM=1 \
      -s FETCH=1 \
      -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap", "setValue", "getValue"]' \
      -s USE_PTHREADS=1 \
      -s PTHREAD_POOL_SIZE=4 \
      -s ALLOW_MEMORY_GROWTH=1 \
      -s EXPORTED_FUNCTIONS="['_show_friends', '_malloc', '_get_address', '_free', '_add_numbers', '_get_cars', '_calculate_sums']" \
      src/modules/friends/show-friends.cpp \
      src/modules/friends/friend.cpp \
      src/modules/friends/friends.cpp \
      src/modules/get-address.cpp \
      src/modules/add-numbers.cpp \
      src/modules/spreadsheet.cpp \
      src/modules/get-cars.cpp \
      -I/Users/torgeirhelgevold/development/msgpack-c/include \
      -o src/app/wasm/wasm-module.js

