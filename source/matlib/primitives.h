#ifndef _GRAPHICS_PRIMITIVES_H_
#define _GRAPHICS_PRIMITIVES_H_

typedef struct {
    float x;
    float y;
    float z; 
}  Vec3f;

typedef struct {
    Vec3f* point[3];
} Triangle;

typedef struct {
    Triangle** tris;
    int _true_size;
    int size; 
} Mesh;

typedef struct {
    float mat[4][4];
} Mat4x4;


Vec3f* create_vec3f(float x, float y, float x);

Triangle* create_triangle(Vec3f* a, Vec3f* b, Vec3f* c);

Mesh* create_mesh();

void add_mesh_triangle(Triangle* tri, Mesh* mesh);

Mat4x4* create_matrix();

/** Primitive shapes */

Mesh* create_cube(float size);


#endif
