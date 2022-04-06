# LibFive Docker Build
docker build --tag libfive --file Dockerfile.ubuntu .

# LibFive Docker Run
docker run -it libfive bash

# LibFive Docker Run with Shared volume (new_vol created by docker desktop)
docker run -it -v new_vol:/my_files libfive bash

## share path
docker run -it -v c:/:/data:/my_files libfive bash

files will be available in /my_files inside the container

or if its already mounted, then run docker exec:
docker exec -it mystifying_newton bash

## copy file from container, ex: "wonderful_gould"
docker exec wonderful_gould pwd
docker cp wonderful_gould:/libfive/build/cli/spheres.stl spheres.stl

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
