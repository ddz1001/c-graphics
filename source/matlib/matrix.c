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

/** Get the identity matrix*/
Mat4x4* get_identity_matrix()
{
    Mat4x4* identity = create_matrix();
    identity->mat[0][0] = 1;
    identity->mat[1][1] = 1;
    identity->mat[2][2] = 1;
    identity->mat[3][3] = 1;

    return identity;
}

/** Get a translation matrix*/
Mat4x4* get_translation_matrix(float tx, float ty, float tz)
{
    Mat4x4* tr = create_matrix();
    
    tr->mat[0][0] = 1; tr->mat[0][3] = tx;
    tr->mat[1][1] = 1; tr->mat[1][3] = tx;
    tr->mat[2][2] = 1; tr->mat[2][3] = tx; 
    tr->mat[3][3] = 1;

    return tr;
}

/** Get a rotation matrix. For param axis:
    x : X-rotation matrix
    y : Y-rotation matrix
    z : Z-rotation matrix
    
    All other inputs are undefined and will return NULL
*/
Mat4x4* get_rotation_matrix(char axis, float theta)
{
    Mat4x4* rot = create_matrix();
    
    switch(axis)
    {
        case 'x':
            rot->mat[0][0] = 1;
            
            rot->mat[1][1] = cosf(theta);
            rot->mat[1][2] = -sinf(theta);
            
            rot->mat[2][1] = sinf(theta);
            rot->mat[2][2] = cosf(theta);
            break;
        case 'y':
            rot->mat[0][0] = cosf(theta);
            rot->mat[0][2] = sinf(theta);

            rot->mat[1][1] = 1;

            rot->mat[2][0] = -sinf(theta);
            rot->mat[2][2] = cosf(theta);
            break;
        case 'z':
            rot->mat[0][0] = cosf(theta);
            rot->mat[0][1] = -sinf(theta);
            
            rot->mat[1][0] = sinf(theta);
            rot->mat[1][1] = cosf(theta);

            rot->mat[2][2] = 1;
            break;

        default:
            return NULL;
    }

    rot->mat[3][3] = 1;

    return rot;
}

/**Get scaling matrix */
Mat4x4* get_scaling_matrix(float sx, float sy, float sz)
{
    Mat4x4* sc = create_matrix();
    
    sc->mat[0][0] = sx;
    sc->mat[1][1] = sy;
    sc->mat[2][2] = sz;
    sc->mat[3][3] = 1;

    return sc;
}

