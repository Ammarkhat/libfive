# LibFive Docker Build
docker build --tag libfive --file Dockerfile.ubuntu .

# LibFive Docker Run
docker run -it libfive bash

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

#emscripten
emcmake cmake ..
or
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DUSE_BOOST_HEADERS=1 .. 