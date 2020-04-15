#include "matmath.h"
#include "primitives.h"
#include <math.h>
#include <stdio.h>

/**Multiply a vector by a 4x4 matix and store the result in the out parameter
*/
void mul_vec_mat(Vec3f* in, Vec3f* out, Mat4x4* mat)
{
    if(in && out && mat)
    {
        float x, y, z, w;

        x = in->x * mat->mat[0][0] + in->y * mat->mat[1][0] + in->z * mat->mat[2][0] + mat->mat[3][0];
        y = in->x * mat->mat[0][1] + in->y * mat->mat[1][1] + in->z * mat->mat[2][1] + mat->mat[3][1];
        z = in->x * mat->mat[0][2] + in->y * mat->mat[1][2] + in->z * mat->mat[2][2] + mat->mat[3][2];
        w = in->x * mat->mat[0][3] + in->y * mat->mat[1][3] + in->z * mat->mat[2][3] + mat->mat[3][3];
        
        if(w != 0.0f)
        {
            x /= w;
            y /= w;
            z /= w;
        }
        out->x = x;
        out->y = y;
        out->z = z;

    }
}

/**Calculate the cross product of two vectors and store the result in out*/
void vec_cross_product(Vec3f* a, Vec3f* b, Vec3f* out)
{
    if(out && a && b)
    {
        out->x = (a->y * b->z) - (a->z * b->y);
        out->y = (a->z * b->x) - (a->x * b->z); 
        out->z = (a->x * b->y) - (a->y * b->x);
    }
}

/**Calculate the dot product of two vectors, if either of the vectors
   are null, then 0.0 is returned.*/
float vec_dot_product(Vec3f* a, Vec3f* b)
{
    if(a && b)
    {
        return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
    }
    else
    {
        return 0.0f;
    }
}

/**Normalize a vectori and store the result in out. 
   A vector that is already normalized (length 1)
   will remain normalized.*/
void vec_normalize(Vec3f* in, Vec3f* out)
{
    if(in && out)
    {
        float len, x, y, z;
        x = in->x;        
        y = in->y;
        z = in->z;
        
        len = sqrtf(in->x*in->x + in->y * in->y + in->z * in->z);
        x /= len; y /= len; z /= len;
        
        out->x = x;
        out->y = y;
        out->z = z;
    }
}
