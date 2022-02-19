#include <iostream>

#include "libfive.h"

#include "libfive/eval/evaluator.hpp"
#include "libfive/tree/opcode.hpp"
#include "libfive/tree/tree.hpp"
#include "libfive/tree/data.hpp"
#include "libfive/eval/eval_deriv_array.hpp"
#include "libfive/eval/eval_interval.hpp"
#include "libfive/render/brep/region.hpp"
#include "libfive/render/brep/contours.hpp"
#include "libfive/render/brep/mesh.hpp"
#include "libfive/render/brep/settings.hpp"
#include "libfive/render/discrete/voxels.hpp"
#include "libfive/render/discrete/heightmap.hpp"

int main(int argc, char** argv){
    int r1 = 1;
    int r2 = 1;
    int x1 = 1;
    int x2 = 1;
    if(argc > 1){
        r1 = atoi(argv[1]);
    }
    if(argc > 2){
        r2 = atoi(argv[2]);
    }
    if(argc > 3){
        x1 = atoi(argv[3]);
    }
    if(argc > 4){
        x2 = atoi(argv[4]);
    }

    // Unlike the C bindings, the C++ interface manages memory automatically
    // through flyweight handles and RAII.  These objects will be freed
    // when they go out of scope
    auto x = libfive::Tree::X();
    auto y = libfive::Tree::Y();
    auto z = libfive::Tree::Z();

    // Arithemetic is overloaded for the libfive::Tree type
    auto out = min( sqrt(((x-x1) * (x-x1)) + (y * y) + (z * z)) - r1,
                    sqrt(((x+x2) * (x+x2)) + (y * y) + (z * z)) - r2) - 0.75;

    // Pick the target region to render
    auto bounds = libfive::Region<3>({-4, -4, -4}, {4, 4, 4});

    // Mesh::render returns a unique_ptr, so it cleans up automatically
    libfive::BRepSettings settings;
    libfive::Mesh::render(out, bounds, settings)->saveSTL("spheres.stl");

    return 0;
}