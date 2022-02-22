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

#include <msgpack.hpp>

struct MeshStr {
  public:
    MSGPACK_DEFINE_MAP(faces, vertices);
    std::vector<int> faces;
    std::vector<float> vertices;
};

extern "C" char* get_mesh(unsigned long* size) 
{
    double r1 = 1;
    double r2 = 1;
    double x1 = 1;
    double x2 = 1;
    double d = 0.75;
    // Unlike the C bindings, the C++ interface manages memory automatically
    // through flyweight handles and RAII.  These objects will be freed
    // when they go out of scope
    auto x = libfive::Tree::X();
    auto y = libfive::Tree::Y();
    auto z = libfive::Tree::Z();

    // Arithemetic is overloaded for the libfive::Tree type
    auto a = ((x-x1) * (x-x1)) + (y * y) + (z * z) - r1;
    auto b = ((x+x2) * (x+x2)) + (y * y) + (z * z) - r2;
    auto out = min(a,b) - d;
    // auto out = abs(min(max(abs(z + x1),max(abs(x + x1), abs(y + x1)))-r1, max(abs(z-x2),max(abs(x - x2), abs(y - x2)))-r2)) - d;

    // Pick the target region to render
    auto bounds = libfive::Region<3>({-4, -4, -4}, {4, 4, 4});

    // Mesh::render returns a unique_ptr, so it cleans up automatically
    libfive::BRepSettings settings;
    auto mesh = libfive::Mesh::render(out, bounds, settings);
    MeshStr m;
    uint32_t num = std::accumulate(meshes.begin(), meshes.end(), (uint32_t)0,
            [](uint32_t i, const Mesh* m){ return i + m->branes.size(); });
    m.vertices.push_back(num);
    
    // for (const auto& v : mesh->verts)
    // {
    //     m.vertices.push_back(v.x());
    //     m.vertices.push_back(v.y());
    //     m.vertices.push_back(v.z());
    // }
    // for (const auto& t : mesh->branes)
    // {
    //     for (unsigned i=0; i < 3; ++i)
    //     {
    //         m.faces.push_back(t[i]);
    //     }
    // }
      
    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, m);

    *size = sbuf.size();
    return sbuf.data();
}
