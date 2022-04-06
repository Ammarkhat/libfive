/*
libfive: a CAD kernel for modeling with implicit functions
Copyright (C) 2017  Matt Keeter

This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#pragma once

#ifdef __cplusplus
#include <cstdint>
#include "libfive/tree/tree.hpp"
#include "libfive/eval/evaluator.hpp"
extern "C" {
#else
#include <stdint.h>
#include <stdbool.h>
#endif

/*
 *  libfive_interval is a range used in interval arithmetic
 *  It usually represents either a spatial region (along a single axis)
 *  or a range that is guaranteed to contain a value.
 */
typedef struct libfive_interval  { float lower; float upper; } libfive_interval;

/*
 *  libfive_region2:  A 2D region
 */
typedef struct libfive_region2   { libfive_interval X, Y; } libfive_region2;

/*
 *  libfive_region3:  A 3D region
 */
typedef struct libfive_region3   { libfive_interval X, Y, Z; } libfive_region3;

/*
 *  libfive_vec2:  A 2D point or vector
 */
typedef struct libfive_vec2      { float x, y; } libfive_vec2;

/*
 *  libfive_vec3:  A 3D point or vector
 */
typedef struct libfive_vec3      { float x, y, z; } libfive_vec3;

/*
 *  libfive_vec4:  A 4D point or vector
 */
typedef struct libfive_vec4      { float x, y, z, w; } libfive_vec4;

/*
 *  libfive_tri:    A triangle, with corners stored as indices
 *  into a separate vertex array
 */
typedef struct libfive_tri       { uint32_t a, b, c; } libfive_tri;

/*
 *  libfive_mesh is an indexed 3D mesh.
 *  There are vert_count vertices, and tri_count triangles.
 */
typedef struct libfive_mesh {
    libfive_vec3* verts;
    libfive_tri* tris;
    uint32_t tri_count;
    uint32_t vert_count;
} libfive_mesh;

/*
 *  libfive_mesh_coords is an indexed 3D mesh, similar to
 *  libfive_mesh, with sets of vertex indices separated by -1 instead
 *  of using triangle structs. There are vert_count vertices, and
 *  coord_index_count coordinate indices (including the -1s), for
 *  coord_index_count / 4 total triangles.
 */
typedef struct libfive_mesh_coords {
    libfive_vec3* verts;
    uint32_t vert_count;
    int32_t* coord_indices;
    uint32_t coord_index_count;
} libfive_mesh_coords;

////////////////////////////////////////////////////////////////////////////////
/*
 *  Frees an libfive_mesh data structure
 */
void libfive_mesh_delete(libfive_mesh* m);

/*
 *  Frees an libfive_mesh_coords data structure
 */
void libfive_mesh_coords_delete(libfive_mesh_coords* m);

/*
 *  Takes a string description of an op-code ('min', 'max', etc) and
 *  returns the libfive::Opcode value, or -1 if no such value exists.
 */
int libfive_opcode_enum(const char* op);

/*
 *  Returns the number of arguments for the given opcode
 *  (either 0, 1, 2, or -1 if the opcode is invalid)
 */
int libfive_opcode_args(int op);

////////////////////////////////////////////////////////////////////////////////

/*  libfive_vars is a general-purpose struct for mapping a set of
 *  free variables to their values.  The variables are opaque
 *  pointers, i.e. values returned with libfive_tree_id. */
typedef struct libfive_vars {
    void* const* vars;
    float* values;
    uint32_t size;
} libfive_vars;
void libfive_vars_delete(libfive_vars* j);

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
typedef const libfive::Tree::Data* libfive_tree;
typedef libfive::Evaluator *libfive_evaluator;
#else
typedef struct libfive_tree_ libfive_tree_;
typedef struct libfive_tree_* libfive_tree;

typedef struct libfive_evaluator_ libfive_evaluator_;
typedef struct libfive_evaluator_ *libfive_evaluator;
#endif

#ifdef __cplusplus
}
#endif
