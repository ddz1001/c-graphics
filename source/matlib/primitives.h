#ifndef _GRAPHICS_VECTOR_H
#define _GRAPHICS_VECTOR_H

//3d float vector
typedef struct {
    float x;
    float y;
    float z;
} Vector3f;

//3-dimension triangle
typedef struct {
    Vector3f points[3];
} Triangle;

//Mesh
typedef struct {
    Triangle* triangles;
} Mesh;


#endif
