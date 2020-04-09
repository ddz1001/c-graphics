#ifndef _GRAPHICS_MATRIX_H_
#define _GRAPHICS_MATRIX_H_

#include "primitives.h"

int init_projection_matrix(float near, float far, float fov, float aspect_ratio);

Mat4x4* get_projection_matrix();

Mat4x4* get_identity_matrix();

Mat4x4* get_translation_matrix(float tx, float ty, float tz);

Mat4x4* get_rotation_matrix(char axis, float theta);

Mat4x4* get_scaling_matrix(float sx, float sy, float sz);
#endif

