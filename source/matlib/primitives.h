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

/**Constructors*/
Vec3f*      create_vec3f(float x, float y, float z);
Triangle*   create_triangle(Vec3f* a, Vec3f* b, Vec3f* c);
Mesh*       create_mesh();
void        add_mesh_triangle(Triangle* tri, Mesh* mesh);
Mat4x4*     create_matrix();

/**Memory deallocation*/

void free_vec3f(Vec3f* ptr);
void free_triangle(Triangle* ptr);
void free_mesh(Mesh* ptr);
void free_mat4x4(Mat4x4* ptr);

/**Copy*/

void copy_vec3f(Vec3f* ptr, Vec3f* out);
void copy_triangle(Triangle* ptr, Triangle* out);
void copy_mesh(Mesh* ptr, Mesh* out);
void copy_mat4x4(Mat4x4* ptr, Mat4x4* out);

/** Primitive shapes */

Mesh* create_cube(float size);

/** Print contents */
void print_vec3f(Vec3f* ptr);
void print_mat4x4(Mat4x4* ptr);
void print_triangle(Triangle* ptr);
 

#endif
