#include "primitives.h"
#include <stdlib.h>
#define MESH_DEF_SIZE 12


Vec3f* create_vec3f(float x, float y, float x)
{
    Vec3f* vec = (Vec3f*) malloc(sizeof(Vec3f));
    
    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}

Triangle* create_triangle(Vec3f* a, Vec3f* b, Vec3f* c)
{
    if(a && b && c)
    {
        Triangle* tri = (Triangle*) malloc(sizeof(Triangle));
        tri->point[0] = a;
        tri->point[1] = b;
        tri->point[2] = c; 

        return tri;
    }
    else 
    {
        return 0;
    }
}

Mesh* create_mesh()
{
    Mesh* mesh = (Mesh*) malloc(sizeof(Mesh));
    mesh->size = 0;
    
    mesh->_true_size = MESH_DEF_SIZE;
    mesh->tris = (Triangle**) malloc(sizeof(Triangle*) * mesh->_true_size);
    
    return mesh;
}


void add_mesh_triangle(Triangle* tri, Mesh* mesh)
{
    if(tri && mesh)
    {
        if(mesh->tris)
        {
            if(mesh->size >= mesh->_true_size)
            {
                mesh->_true_size += MESH_DEF_SIZE;
                mesh->tris = (Triangle**) realloc(mesh->tris, sizeof(Triangle*) * mesh->_true_size);
            }
            mesh->tris[mesh->size - 1] = tri;
            mesh->size++;
        }
    }
}

Mat4x4* create_matrix()
{
    Mat4x4* mat = (Mat4x4*) malloc(sizeof(Mat4x4));
    return mat;
}



Mesh* create_cube(float size)
{
    Vec3f* a1, b1, c1;
    Vec3f* a2, b2, c2;
    Vec3f* a3, b3, c3;
    Vec3f* a4, b4, c4;
    Vec3f* a5, b5, c5;
    Vec3f* a6, b6, c6;
    Vec3f* a7, b7, c7;
    Vec3f* a8, b8, c8;
    Vec3f* a9, b9, c9;
    Vec3f* a10, b10, c10;
    Vec3f* a11, b11, c11;
    Vec3f* a12, b12, c12;
    
    float i = size;
    
    //Create the vectors
    a1 = create_vec3f(-i, -i,  i);
    b1 = create_vec3f( i, -i,  i);
    c1 = create_vec3f( i,  i,  i);
    
    a2 = create_vec3f(-i, -i,  i);
    b2 = create_vec3f( i,  i,  i);
    c2 = create_vec3f(-i,  i,  i);

    a3 = create_vec3f( i, -i,  i);
    b3 = create_vec3f( i, -i, -i);
    c3 = create_vec3f( i,  i, -i);

    a4 = create_vec3f( i, -i,  i);
    b4 = create_vec3f( i,  i, -i);
    c4 = create_vec3f( i,  i,  i);

    a5 = create_vec3f( i, -i, -i);
    b5 = create_vec3f(-i, -i, -i);
    c5 = create_vec3f(-i,  i, -i);

    a6 = create_vec3f( i, -i, -i);
    b6 = create_vec3f(-i,  i, -i);
    c6 = create_vec3f( i,  i, -i);

    a7 = create_vec3f(-i, -i, -i);
    b7 = create_vec3f(-i, -i,  i);
    c7 = create_vec3f(-i,  i,  i);

    a8 = create_vec3f(-i, -i, -i);
    b8 = create_vec3f(-i,  i,  i);
    c8 = create_vec3f(-i,  i, -i);

    a9 = create_vec3f(-i,  i,  i);
    b9 = create_vec3f( i,  i,  i);
    c9 = create_vec3f( i,  i, -i);

    a10 = create_vec3f(-i,  i,  i);
    b10 = create_vec3f( i,  i, -i);
    c10 = create_vec3f(-i,  i, -i);

    a11 = create_vec3f( i, -i,  i);
    b11 = create_vec3f(-i, -i, -i);
    c11 = create_vec3f( i, -i, -i);

    a12 = create_vec3f( i, -i,  i);
    b12 = create_vec3f(-i, -i,  i);
    c12 = create_vec3f(-i, -i, -i);

    //Create the triangles    
    Triangle* t1, t2, t3, t4, t5, t6, t7, t8, t9 ,t10, t11, t12;
    t1 = create_triangle(a1, b1, c1);
    t2 = create_triangle(a2, b2, c2);
    t3 = create_triangle(a3, b3, c3);
    t4 = create_triangle(a4, b4, c4);
    t5 = create_triangle(a5, b5, c5);
    t6 = create_triangle(a6, b6, c6);
    t7 = create_triangle(a7, b7, c7);
    t8 = create_triangle(a8, b8, c8);
    t9 = create_triangle(a9, b9, c9);
    t10 = create_triangle(a10, b10, c10);
    t11 = create_triangle(a11, b11, c11);
    t12 = create_triangle(a12, b12, c12);
    
    //Create the mesh
    Mesh* cube = create_mesh();
    add_mesh_triangle(t1, cube);  
    add_mesh_triangle(t2, cube); 
    add_mesh_triangle(t3, cube); 
    add_mesh_triangle(t4, cube); 
    add_mesh_triangle(t5, cube); 
    add_mesh_triangle(t6, cube); 
    add_mesh_triangle(t7, cube); 
    add_mesh_triangle(t8, cube); 
    add_mesh_triangle(t9, cube); 
    add_mesh_triangle(t10, cube); 
    add_mesh_triangle(t11, cube); 
    add_mesh_triangle(t12, cube); 
    
    return cube; 
}

