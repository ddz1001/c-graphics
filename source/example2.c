/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
#include "gfxlib/gfx.h"
#include "matlib/matrix.h"
#include "matlib/primitives.h"
#include "matlib/matmath.h"

void draw_scr();

Mat4x4* proj;
Mat4x4* normal_translate;
Mat4x4* normal_scale;
Mat4x4* z_translate;
Vec3f* camera;

Mesh* cube;

float theta = 0.0f;

int main()
{
	int ysize = 800;
	int xsize = 800;
    
    float aspect_ratio = ((float) xsize) / ((float) ysize);


    init_projection_matrix(10.0f, 1000.0f, 85.0f, aspect_ratio);
    proj = get_projection_matrix();
    normal_translate = get_translation_matrix(1.0f, 1.0f, 0.0f);
    normal_scale = get_scaling_matrix(0.5f * (float)xsize, 0.5f * (float)ysize, 1.0f);
    z_translate = get_translation_matrix(0.0f, 0.0f, 10.0f);

    camera = create_vec3f(0, 0, 0);

    cube = create_cube(1.0f);
	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(0,200,100);

    draw_scr();

	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
        if(c=='r')
        {
            theta += 0.05f;
            gfx_clear();
            draw_scr();
        }
	}

	return 0;
}

void draw_scr()
{
    Vec3f *at, *bt, *ct;
    Mat4x4* x_rot;
    Mat4x4* y_rot; 
    Mat4x4* z_rot;
    
    Mat4x4* ident;

    x_rot = get_rotation_matrix('x', theta);
    y_rot = get_rotation_matrix('y', theta);
    z_rot = get_rotation_matrix('z', theta);
    
    for(int i = 0; i < cube->size; i++)
    {
        at = create_vec3f(0, 0, 0);
        bt = create_vec3f(0, 0, 0);
        ct = create_vec3f(0, 0, 0);
 
        ident = get_identity_matrix();
        
        copy_vec3f(cube->tris[i]->point[0], at);
        copy_vec3f(cube->tris[i]->point[1], bt);
        copy_vec3f(cube->tris[i]->point[2], ct);        

        mul_vec_mat(at, at, x_rot); 
        mul_vec_mat(bt, bt, x_rot); 
        mul_vec_mat(ct, ct, x_rot); 
        
        mul_vec_mat(at, at, y_rot);
        mul_vec_mat(bt, bt, y_rot); 
        mul_vec_mat(ct, ct, y_rot); 
        
        /* 
        mul_vec_mat(at, at, z_rot); 
        mul_vec_mat(bt, bt, z_rot); 
        mul_vec_mat(ct, ct, z_rot);
        */
        
        mul_vec_mat(at, at, z_translate);
        mul_vec_mat(bt, bt, z_translate);
        mul_vec_mat(ct, ct, z_translate);
        
        //Get the surface normal for the current face
        Vec3f *surface_normal, *line_a, *line_b, *normal_cam;
        
        surface_normal = create_vec3f(0, 0, 0); //empty
        normal_cam = create_vec3f(at->x - camera->x,
                                  at->y - camera->y,
                                  at->z - camera->z);

        line_a = create_vec3f(bt->x - at->x,
                              bt->y - at->y,
                              bt->z - at->z);
        
        line_b = create_vec3f(ct->x - at->x,
                              ct->y - at->y,
                              ct->z - at->z);
        
        vec_cross_product(line_a, line_b, surface_normal);
        vec_normalize(surface_normal, surface_normal);
        
        float dot = vec_dot_product(surface_normal, normal_cam);

        //if(surface_normal->z < 0.0f)
        if(dot < 0.0f)
        {        
             mul_vec_mat(at, at, proj);
             mul_vec_mat(bt, bt, proj);
             mul_vec_mat(ct, ct, proj);
         
             mul_vec_mat(at, at, normal_translate);
             mul_vec_mat(bt, bt, normal_translate);
             mul_vec_mat(ct, ct, normal_translate);
                
             mul_vec_mat(at, at, normal_scale);
             mul_vec_mat(bt, bt, normal_scale);
             mul_vec_mat(ct, ct, normal_scale);

             gfx_line(at->x, at->y, bt->x, bt->y);
             gfx_line(bt->x, bt->y, ct->x, ct->y);
             gfx_line(ct->x, ct->y, at->x, at->y);
        }

        free_vec3f(line_a);
        free_vec3f(line_b);
        free_vec3f(surface_normal);
        free_vec3f(normal_cam);
         
        free_vec3f(at);
        free_vec3f(bt);
        free_vec3f(ct);
        
    }
    
    free_mat4x4(ident);  
 
    free_mat4x4(x_rot);
    free_mat4x4(y_rot);
    free_mat4x4(z_rot);        
    

}

