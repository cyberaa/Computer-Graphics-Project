/*
    lightmaterial.c
    Nate Robins, 1997

    Adapted by: Joel Arrais; Pedro Martins; Jorge Henriques
    
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "glm.h"


typedef struct _cell {
    int id;
    int x, y;
    float min, max;
    float value;
    float step;
    char* info;
    char* format;
} cell;


cell light_pos[4] = {
    { 1, 210, 30, -5.0, 5.0, -2.0, 0.01,
        "Specifies X coordinate of light vector.", "%.2f" },
    { 2, 270, 30, -5.0, 5.0, 2.0, 0.01,
    "Specifies Y coordinate of light vector.", "%.2f" },
    { 3, 330, 30, -5.0, 5.0, 2.0, 0.01,
    "Specifies Z coordinate of light vector.", "%.2f" },
    { 4, 390, 30, 0.0, 1.0, 1.0, 1.0,
    "Specifies directional (0) or positional (1) light.", "%.2f" },
};

cell light_Ka[4] = {
    { 5, 200, 60, 0.0, 1.0, 0.0, 0.01,
        "Specifies ambient red intensity of the light.", "%.2f" },
    { 6, 260, 60, 0.0, 1.0, 0.0, 0.01,
    "Specifies ambient green intensity of the light.", "%.2f" },
    { 7, 320, 60, 0.0, 1.0, 0.0, 0.01,
    "Specifies ambient blue intensity of the light.", "%.2f" },
    { 8, 380, 60, 0.0, 1.0, 1.0, 0.01,
    "Specifies ambient alpha intensity of the light.", "%.2f" },
};

cell light_Kd[4] = {
    {  9, 200, 90, 0.0, 1.0, 1.0, 0.01,
        "Specifies diffuse red intensity of the light.", "%.2f" },
    { 10, 260, 90, 0.0, 1.0, 1.0, 0.01,
    "Specifies diffuse green intensity of the light.", "%.2f" },
    { 11, 320, 90, 0.0, 1.0, 1.0, 0.01,
    "Specifies diffuse blue intensity of the light.", "%.2f" },
    { 12, 380, 90, 0.0, 1.0, 1.0, 0.01,
    "Specifies diffuse alpha intensity of the light.", "%.2f" },
};

cell light_Ks[4] = {
    { 13, 200, 120, 0.0, 1.0, 1.0, 0.01,
        "Specifies specular red intensity of the light.", "%.2f" },
    { 14, 260, 120, 0.0, 1.0, 1.0, 0.01,
    "Specifies specular green intensity of the light.", "%.2f" },
    { 15, 320, 120, 0.0, 1.0, 1.0, 0.01,
    "Specifies specular blue intensity of the light.", "%.2f" },
    { 16, 380, 120, 0.0, 1.0, 1.0, 0.01,
    "Specifies specular alpha intensity of the light.", "%.2f" },
};

cell spot_direction[3] = {
    { 17, 250, 260, -1.0, 1.0, 1.0, 0.01,
        "Specifies X coordinate of spotlight direction vector.", "%.2f" },
    { 18, 310, 260, -1.0, 1.0, -1.0, 0.01,
    "Specifies Y coordinate of spotlight direction vector.", "%.2f" },
    { 19, 370, 260, -1.0, 1.0, -1.0, 0.01,
    "Specifies Z coordinate of spotlight direction vector.", "%.2f" },
};

cell spot_exponent = { 20, 210, 290, 0.0, 128.0, 30.0, 1.0,
"Specifies intensity distribution of spotlight.", "%.0f" };
cell spot_cutoff = { 21, 410, 290, 0.0, 91.0, 91.0, 1.0,
"Specifies maximum spread angle of spotlight (180 = off).", "%.0f" };

cell Kc = { 22, 120, 410, 0.0, 5.0, 1.0, 0.01,
"Specifies constant attenuation factor.", "%.2f" };
cell Kl = { 23, 215, 410, 0.0, 5.0, 0.0, 0.01,
"Specifies linear attenuation factor.", "%.2f" };
cell Kq = { 24, 315, 410, 0.0, 5.0, 0.0, 0.01,
"Specifies quadratic attenuation factor.", "%.2f" };

cell material_Ka[4] = {
    { 25, 220, 260, 0.0, 1.0, 0.2, 0.01,
        "Specifies ambient red reflectance of the material.", "%.2f" },
    { 26, 280, 260, 0.0, 1.0, 0.2, 0.01,
    "Specifies ambient green reflectance of the material.", "%.2f" },
    { 27, 340, 260, 0.0, 1.0, 0.2, 0.01,
    "Specifies ambient blue reflectance of the material.", "%.2f" },
    { 28, 400, 260, 0.0, 1.0, 1.0, 0.01,
    "Specifies ambient alpha reflectance of the material.", "%.2f" },
};

cell material_Kd[4] = {
    { 29, 220, 290, 0.0, 1.0, 0.8, 0.01,
        "Specifies diffuse red reflectance of the material.", "%.2f" },
    { 30, 280, 290, 0.0, 1.0, 0.8, 0.01,
    "Specifies diffuse green reflectance of the material.", "%.2f" },
    { 31, 340, 290, 0.0, 1.0, 0.8, 0.01,
    "Specifies diffuse blue reflectance of the material.", "%.2f" },
    { 32, 400, 290, 0.0, 1.0, 1.0, 0.01,
    "Specifies diffuse alpha reflectance of the material.", "%.2f" },
};

cell material_Ks[4] = {
    { 33, 220, 320, 0.0, 1.0, 1.0, 0.01,
        "Specifies specular red reflectance of the material.", "%.2f" },
    { 34, 280, 320, 0.0, 1.0, 1.0, 0.01,
    "Specifies specular green reflectance of the material.", "%.2f" },
    { 35, 340, 320, 0.0, 1.0, 1.0, 0.01,
    "Specifies specular blue reflectance of the material.", "%.2f" },
    { 36, 400, 320, 0.0, 1.0, 1.0, 0.01,
    "Specifies specular alpha reflectance of the material.", "%.2f" },
};

cell material_Ke[4] = {
    { 37, 220, 350, 0.0, 1.0, 0.0, 0.01,
        "Specifies red emitted light intensity of the material.", "%.2f" },
    { 38, 280, 350, 0.0, 1.0, 0.0, 0.01,
    "Specifies green emitted light intensity of the material.", "%.2f" },
    { 39, 340, 350, 0.0, 1.0, 0.0, 0.01,
    "Specifies blue emitted light intensity of the material.", "%.2f" },
    { 40, 400, 350, 0.0, 1.0, 1.0, 0.01,
    "Specifies alpha emitted light intensity of the material.", "%.2f" },
};

cell material_Se = { 41, 200, 380, 0.0, 128.0, 50.0, 1.0,
"Specifies the specular exponent of the material.", "%.0f" };

cell lmodel_Ka[4] = {
    { 42, 220, 260, 0.0, 1.0, 0.2, 0.01,
        "Specifies ambient red intensity of the entire scene.", "%.2f" },
    { 43, 280, 260, 0.0, 1.0, 0.2, 0.01,
    "Specifies ambient green intensity of the entire scene.", "%.2f" },
    { 44, 340, 260, 0.0, 1.0, 0.2, 0.01,
    "Specifies ambient blue intensity of the entire scene.", "%.2f" },
    { 45, 400, 260, 0.0, 1.0, 1.0, 0.01,
    "Specifies ambient alpha intensity of the entire scene.", "%.2f" },
};

cell local_viewer = { 46, 460, 340, 0.0, 1.0, 0.0, 1.0,
"Specifies infinite (0.0) or local (1.0) light model.", "%.1f" };

cell two_side = { 47, 415, 390, 0.0, 1.0, 0.0, 1.0,
"Specifies one (0.0) or two (1.0) sided lighting.", "%.1f" };


GLfloat eye[3] = { 0.0, 0.0, 2.0 };
GLfloat at[3]  = { 0.0, 0.0, 0.0 };
GLfloat up[3]  = { 0.0, 1.0, 0.0 };

GLboolean world_draw = GL_TRUE;
GLMmodel* pmodel = NULL;
GLint selection = 0;
GLfloat spin_x = 0.0;
GLfloat spin_y = 0.0;

void redisplay_all(void);
GLdouble projection[16], modelview[16];
GLuint window, screen;

void
cell_vector(float* dst, cell* cell, int num)
{
    while (--num >= 0)
        dst[num] = cell[num].value;
}

void
drawmodel(void)
{
    if (!pmodel) {
        pmodel = glmReadOBJ("/data/ferrari_599gtb.obj");
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    
    glmDraw(pmodel, GLM_SMOOTH);
}

void
screen_reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width/height, 0.5, 8.0);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1],up[2]);
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void
screen_display(void)
{
    GLfloat pos[4], lKa[4], lKd[4], lKs[4];
    GLfloat dir[3], mKa[4], mKd[4], mKs[4], mKe[4];
    GLfloat lmKa[4];
    
    cell_vector(pos, light_pos, 4);
    cell_vector(lKa, light_Ka, 4);
    cell_vector(lKd, light_Kd, 4);
    cell_vector(lKs, light_Ks, 4);
    cell_vector(dir, spot_direction, 3);
    cell_vector(mKa, material_Ka, 4);
    cell_vector(mKd, material_Kd, 4);
    cell_vector(mKs, material_Ks, 4);
    cell_vector(mKe, material_Ke, 4);
    cell_vector(lmKa, lmodel_Ka, 4);
    
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, local_viewer.value);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, two_side.value);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmKa);
    
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lKa);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lKd);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lKs);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
    glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, (int)spot_exponent.value);
    if (spot_cutoff.value > 90)
        glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, 180);
    else
        glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, (int)spot_cutoff.value);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, Kc.value);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, Kl.value);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, Kq.value);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mKa);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mKd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mKs);
    glMaterialfv(GL_FRONT, GL_EMISSION, mKe);
    glMaterialf(GL_FRONT, GL_SHININESS, material_Se.value);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin_y, 1.0, 0.0, 0.0);
    glRotatef(spin_x, 0.0, 1.0, 0.0);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    if (pmodel)
        drawmodel();
    else 
        glutSolidTorus(0.25, 0.75, 28, 28);
    glPopMatrix();
    
#if 0    
#define TESS 20
    glNormal3f(0.0, 1.0, 0.0);
    for (i = 0; i < TESS; i++) {
        glBegin(GL_TRIANGLE_STRIP);
        for (j = 0; j <= TESS; j++) {
            glVertex3f(-1+(float)i/TESS*2, -1.0, -1+(float)j/TESS*2);
            glVertex3f(-1+(float)(i+1)/TESS*2, -1.0, -1+(float)j/TESS*2);
        }
        glEnd();
    }
#endif
    
    glutSwapBuffers();
}


int old_x, old_y;

void
screen_motion(int x, int y)
{
    spin_x = x - old_x;
    spin_y = y - old_y;
    
    redisplay_all();
}

void
redisplay_all(void)
{
	glutSetWindow(screen);
    glutPostRedisplay();
}

int
main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1024,1024);
    glutInitWindowPosition(0, 0);
    glutInit(&argc, argv);
    
    window = glutCreateWindow("Ferrari");
    
    glutReshapeFunc(screen_reshape);
    glutDisplayFunc(screen_display);
    glutMotionFunc(screen_motion);

    drawmodel();
    redisplay_all();
	    
    glutMainLoop();
    return 0;
}
