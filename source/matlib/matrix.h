#ifndef _GRAPHICS_MATRIX_H_
#define _GRAPHICS_MATRIX_H_

#include "primitives.h"

int init_projection_matrix(float near, float far, float fov, float aspect_ratio);

Mat4x4* get_projection_matrix();


#endif

