#include <iostream>

#include "libfive.h"

int main(int argc, char** argv){
    // Unlike the C bindings, the C++ interface manages memory automatically
    // through flyweight handles and RAII.  These objects will be freed
    // when they go out of scope
    auto x = Kernel::Tree::X();
    auto y = Kernel::Tree::Y();
    auto z = Kernel::Tree::Z();

    // Arithemetic is overloaded for the Kernel::Tree type
    auto out = (x * x) + (y * y) + (z * z) - 1;

    // Pick the target region to render
    auto bounds = Region<3>({-2, -2, -2}, {2, 2, 2});

    // Mesh::render returns a unique_ptr, so it cleans up automatically
    Mesh::render(out, bounds)->saveSTL("sphere.stl");

    return 0;
}