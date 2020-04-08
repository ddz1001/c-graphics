#include "matrix.h"
#include "primitives.h"
#include <math.h>
#include <stdlib.h>

static Mat4x4* _stored_matrix;

static int _init = 0;
static float _NEAR;
static float _FAR;
static float _FOV;
static float _ASPECT;
static float _FOV_RAD;

/** Initialize the projection matrix. If the matrix is already initialized, then 
    nothing happens and 0 is returned. Otherwise, 1 is returned.
*/
int init_projection_matrix(float near, float far, float fov, float aspect_ratio)
{
    if(_init) {
        return 0;
    }

    _NEAR = near;
    _FAR = far;
    _FOV = fov;
    _ASPECT = aspect_ratio;
    _FOV_RAD = 1.0f / tanf(_FOV * 0.5f  / 180.0f * M_PI);
    
    _init = 1;
    return 1;
}
/** Get the projection matrix. If not initialized, then a null pointer is returned;
*/
Mat4x4* get_projection_matrix() 
{
    if(!_init)
    {
        return NULL;
    }
    else if(!_stored_matrix)
    {
        Mat4x4* newmat = create_matrix();
        newmat->mat[0][0] = _ASPECT * _FOV_RAD;
        newmat->mat[1][1] = _FOV_RAD;
        newmat->mat[2][2] = _FAR / (_FAR - _NEAR);
        newmat->mat[3][2] = (-_FAR * _NEAR) / (_FAR - _NEAR);
        newmat->mat[2][3] = 1.0f;
        newmat->mat[3][3] = 0.0f;
        
        _stored_matrix = newmat;
        return newmat;
    }
    else {
        return _stored_matrix;
    }
}

