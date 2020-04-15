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

