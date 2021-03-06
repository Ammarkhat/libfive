/*
 *  C API for the libfive standard library
 *
 *  DO NOT EDIT BY HAND!
 *  This file is automatically generated from libfive/stdlib/libfive_stdlib.h
 *
 *  It was last generated on 2022-02-09 19:39:14 by user bramp
 */
#pragma once
#include "libfive/tree/tree.hpp"

// Header (hand-written in gen_c.py)
struct TreeVec2 {
    libfive::Tree x, y;
};
struct TreeVec3 {
    libfive::Tree x, y, z;
};
typedef libfive::Tree TreeFloat;

// Autogenerated content begins here

////////////////////////////////////////////////////////////////////////////////
// csg
libfive::Tree _union(libfive::Tree, libfive::Tree);
libfive::Tree intersection(libfive::Tree, libfive::Tree);
libfive::Tree inverse(libfive::Tree);
libfive::Tree difference(libfive::Tree, libfive::Tree);
libfive::Tree offset(libfive::Tree, TreeFloat);
libfive::Tree clearance(libfive::Tree, libfive::Tree, TreeFloat);
libfive::Tree shell(libfive::Tree, TreeFloat);
libfive::Tree blend_expt(libfive::Tree, libfive::Tree, TreeFloat);
libfive::Tree blend_expt_unit(libfive::Tree, libfive::Tree, TreeFloat);
libfive::Tree blend_rough(libfive::Tree, libfive::Tree, TreeFloat);
libfive::Tree blend_difference(libfive::Tree, libfive::Tree, TreeFloat, TreeFloat);
libfive::Tree morph(libfive::Tree, libfive::Tree, TreeFloat);
libfive::Tree loft(libfive::Tree, libfive::Tree, TreeFloat, TreeFloat);
libfive::Tree loft_between(libfive::Tree, libfive::Tree, TreeVec3, TreeVec3);

////////////////////////////////////////////////////////////////////////////////
// shapes
libfive::Tree circle(TreeFloat, TreeVec2);
libfive::Tree ring(TreeFloat, TreeFloat, TreeVec2);
libfive::Tree polygon(TreeFloat, int, TreeVec2);
libfive::Tree rectangle(TreeVec2, TreeVec2);
libfive::Tree rounded_rectangle(TreeVec2, TreeVec2, TreeFloat);
libfive::Tree rectangle_exact(TreeVec2, TreeVec2);
libfive::Tree rectangle_centered_exact(TreeVec2, TreeVec2);
libfive::Tree triangle(TreeVec2, TreeVec2, TreeVec2);
libfive::Tree box_mitered(TreeVec3, TreeVec3);
libfive::Tree box_mitered_centered(TreeVec3, TreeVec3);
libfive::Tree box_exact_centered(TreeVec3, TreeVec3);
libfive::Tree box_exact(TreeVec3, TreeVec3);
libfive::Tree rounded_box(TreeVec3, TreeVec3, TreeFloat);
libfive::Tree sphere(TreeFloat, TreeVec3);
libfive::Tree half_space(TreeVec3, TreeVec3);
libfive::Tree cylinder_z(TreeFloat, TreeFloat, TreeVec3);
libfive::Tree cone_ang_z(TreeFloat, TreeFloat, TreeVec3);
libfive::Tree cone_z(TreeFloat, TreeFloat, TreeVec3);
libfive::Tree pyramid_z(TreeVec2, TreeVec2, TreeFloat, TreeFloat);
libfive::Tree torus_z(TreeFloat, TreeFloat, TreeVec3);
libfive::Tree gyroid(TreeVec3, TreeFloat);
libfive::Tree emptiness_();
libfive::Tree array_x(libfive::Tree, int, TreeFloat);
libfive::Tree array_xy(libfive::Tree, int, int, TreeVec2);
libfive::Tree array_xyz(libfive::Tree, int, int, int, TreeVec3);
libfive::Tree array_polar_z(libfive::Tree, int, TreeVec2);
libfive::Tree extrude_z(libfive::Tree, TreeFloat, TreeFloat);

////////////////////////////////////////////////////////////////////////////////
// transforms
libfive::Tree move(libfive::Tree, TreeVec3);
libfive::Tree reflect_x(libfive::Tree, TreeFloat);
libfive::Tree reflect_y(libfive::Tree, TreeFloat);
libfive::Tree reflect_z(libfive::Tree, TreeFloat);
libfive::Tree reflect_xy(libfive::Tree);
libfive::Tree reflect_yz(libfive::Tree);
libfive::Tree reflect_xz(libfive::Tree);
libfive::Tree symmetric_x(libfive::Tree);
libfive::Tree symmetric_y(libfive::Tree);
libfive::Tree symmetric_z(libfive::Tree);
libfive::Tree scale_x(libfive::Tree, TreeFloat, TreeFloat);
libfive::Tree scale_y(libfive::Tree, TreeFloat, TreeFloat);
libfive::Tree scale_z(libfive::Tree, TreeFloat, TreeFloat);
libfive::Tree scale_xyz(libfive::Tree, TreeVec3, TreeVec3);
libfive::Tree rotate_x(libfive::Tree, TreeFloat, TreeVec3);
libfive::Tree rotate_y(libfive::Tree, TreeFloat, TreeVec3);
libfive::Tree rotate_z(libfive::Tree, TreeFloat, TreeVec3);
libfive::Tree taper_x_y(libfive::Tree, TreeVec2, TreeFloat, TreeFloat, TreeFloat);
libfive::Tree taper_xy_z(libfive::Tree, TreeVec3, TreeFloat, TreeFloat, TreeFloat);
libfive::Tree shear_x_y(libfive::Tree, TreeVec2, TreeFloat, TreeFloat, TreeFloat);
libfive::Tree repel(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree repel_x(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree repel_y(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree repel_z(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree repel_xy(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree repel_yz(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree repel_xz(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree attract(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree attract_x(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree attract_y(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree attract_z(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree attract_xy(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree attract_yz(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree attract_xz(libfive::Tree, TreeVec3, TreeFloat, TreeFloat);
libfive::Tree revolve_y(libfive::Tree, TreeFloat);
libfive::Tree twirl_x(libfive::Tree, TreeFloat, TreeFloat, TreeVec3);
libfive::Tree twirl_axis_x(libfive::Tree, TreeFloat, TreeFloat, TreeVec3);
libfive::Tree twirl_y(libfive::Tree, TreeFloat, TreeFloat, TreeVec3);
libfive::Tree twirl_axis_y(libfive::Tree, TreeFloat, TreeFloat, TreeVec3);
libfive::Tree twirl_z(libfive::Tree, TreeFloat, TreeFloat, TreeVec3);
libfive::Tree twirl_axis_z(libfive::Tree, TreeFloat, TreeFloat, TreeVec3);

////////////////////////////////////////////////////////////////////////////////
// text
libfive::Tree text(const char*, TreeVec2);
