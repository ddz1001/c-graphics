#ifndef _MAT_MATH_H_
#define _MAT_MATH_H_

#include "primitives.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

void mul_vec_mat(Vec3f* in, Vec3f* out, Mat4x4* mat);

void vec_cross_product(Vec3f* a, Vec3f* b, Vec3f* out);

float vec_dot_product(Vec3f* a, Vec3f* b);

void vec_normalize(Vec3f* in, Vec3f* out);
#endif
