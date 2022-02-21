# LibFive Docker Build
docker build --tag emscripten_libfive --file Dockerfile.emscripten.debian .

# LibFive Docker Run
docker run -it emscripten_libfive bash

# LibFive Docker Run with Shared volume (new_vol created by docker desktop)
docker run -it -v new_vol:/my_files emscripten_libfive bash

## share path
docker run -it -v c:/:/data:/my_files emscripten_libfive bash

files will be available in /my_files inside the container

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

## using emscripten
emcmake cmake ..
or
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DUSE_BOOST_HEADERS=1 .. 
emmake make
