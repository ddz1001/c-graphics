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

Mesh* cube;

float theta = 0.0f;

int main()
{
	int ysize = 800;
	int xsize = 800;
    
    float aspect_ratio = ((float) xsize) / ((float) ysize);


    init_projection_matrix(10.0f, 1000.0f, 90.0f, aspect_ratio);
    proj = get_projection_matrix();
    normal_translate = get_translation_matrix(1.0f, 1.0f, 0.0f);
    normal_scale = get_scaling_matrix(0.5f * (float)xsize, 0.5f * (float)ysize, 1.0f);
    z_translate = get_translation_matrix(0.0f, 0.0f, 1.0f);

    cube = create_cube(1.0f);
	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(0,200,100);

	// Draw a triangle on the screen.
	//gfx_line(100,100,200,100);
	//gfx_line(200,100,150,150);
	//gfx_line(150,150,100,100);

    draw_scr();

	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
        if(c=='r')
        {
            theta += 5.0f;
            gfx_clear();
            draw_scr();
        }
	}

	return 0;
}

void draw_scr()
{
    Vec3f *at, *bt, *ct;
    //Mat4x4* x_rot;
    //Mat4x4* y_rot; 
    //Mat4x4* z_rot;
    
    Mat4x4* ident;

    //x_rot = get_rotation_matrix('x', theta);
    //y_rot = get_rotation_matrix('y', theta);
    //z_rot = get_rotation_matrix('z', theta);
    
    for(int i = 0; i < cube->size; i++)
    {
        at = create_vec3f(0, 0, 0);
        bt = create_vec3f(0, 0, 0);
        ct = create_vec3f(0, 0, 0);
       
        ident = get_identity_matrix();

        mul_vec_mat(cube->tris[i]->point[0], at, z_translate); 
        mul_vec_mat(cube->tris[i]->point[1], bt, z_translate); 
        mul_vec_mat(cube->tris[i]->point[2], ct, z_translate); 
        /**
        mul_vec_mat(at, at, y_rot);
        mul_vec_mat(bt, bt, y_rot); 
        mul_vec_mat(ct, ct, y_rot); 

        mul_vec_mat(at, at, z_rot); 
        mul_vec_mat(bt, bt, z_rot); 
        mul_vec_mat(ct, ct, z_rot);
       
        mul_vec_mat(at, at, z_translate);
        mul_vec_mat(bt, bt, z_translate);
        mul_vec_mat(ct, ct, z_translate);
        */
        mul_vec_mat(at, at, proj);
        mul_vec_mat(bt, bt, proj);
        mul_vec_mat(ct, ct, proj);
 
        mul_vec_mat(at, at, normal_translate);
        mul_vec_mat(bt, bt, normal_translate);
        mul_vec_mat(ct, ct, normal_translate);
        
        mul_vec_mat(at, at, normal_scale);
        mul_vec_mat(bt, bt, normal_scale);
        mul_vec_mat(ct, ct, normal_scale);
        
        mul_vec_mat(at, at, ident);
        mul_vec_mat(bt, bt, ident);
        mul_vec_mat(ct, ct, ident);
        
        /**
        at->x += 1.0f; at->y += 1.0f;
        bt->x += 1.0f; bt->y += 1.0f;
        ct->x += 1.0f; ct->y += 1.0f;
        **/

        /**
        at->x *= 0.5f * (float)xsize;
        at->y *= 0.5f * (float)ysize;
        bt->x *= 0.5f * (float)xsize;
        bt->y *= 0.5f * (float)ysize;
        ct->x *= 0.5f * (float)xsize;
        ct->y *= 0.5f * (float)ysize;
        **/

        gfx_line(at->x, at->y, bt->x, bt->y);
        gfx_line(bt->x, bt->y, ct->x, ct->y);
        gfx_line(ct->x, ct->y, at->x, at->y);
        
 
        free_vec3f(at);
        free_vec3f(bt);
        free_vec3f(ct);
    }
    
    free_mat4x4(ident);  
 
    //free_mat4x4(x_rot);
    //free_mat4x4(y_rot);
    //free_mat4x4(z_rot);        
    

}

