#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>

double Txval=0,Tyval=0,Tzval=0,ex=6, ey=6, ez=5,cx=-10,cy= 0,cz =0;
double tx = -5, ty= -2, tz= -2, rotAngle=0.0, rotAngle1=0.0;
double windowHeight=1200, windowWidth=700;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;
bool flagScale = true, rotFlag = true,l1=true,l2=true,l3=true,l1a=true,l1d=true,l1s=true,l2a=true,l2d=true,l2s=true,l3a=true,l3d=true,l3s=true;


static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, 3.0}, //1
    {3.0, 0.0, 3.0}, //2
    {3.0, 0.0, 0.0}, //3
    {0.0, 3.0, 0.0}, //4
    {0.0, 3.0, 3.0}, //5
    {3.0, 3.0, 3.0}, //6
    {3.0, 3.0, 0.0}  //7
};

static GLubyte quadIndices1[6][4] =
{
    {0, 1, 2, 3}, //bottom
    {4, 5, 6, 7}, //top
    {5, 1, 2, 6}, //front
    {0, 4, 7, 3}, // back is clockwise
    {2, 3, 7, 6}, //right
    {1, 5, 4, 0}  //left is clockwise
};
static void getNormal3p(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void drawCube(float x, float y,float z,float p, float q, float r)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { x, y, z, 1.0 };
    GLfloat mat_specular[] = { 0.5, 0, 0, 1.0 };
    GLfloat mat_diffuse[] = { p, q, r, 1.0 };
    GLfloat mat_shininess[] = {100};
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[quadIndices1[i][0]][0], v_cube[quadIndices1[i][0]][1], v_cube[quadIndices1[i][0]][2],
                    v_cube[quadIndices1[i][1]][0], v_cube[quadIndices1[i][1]][1], v_cube[quadIndices1[i][1]][2],
                    v_cube[quadIndices1[i][2]][0], v_cube[quadIndices1[i][2]][1], v_cube[quadIndices1[i][2]][2]);


        glVertex3fv(&v_cube[quadIndices1[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices1[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices1[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices1[i][3]][0]);
    }
    glEnd();
}
void light()
{
    glPushMatrix();
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 10.0, 0.0, 10.0, 1.0 };
    if(l1 == true)
    {
        glEnable( GL_LIGHT0);
        if(l1a == true)
        {
            glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
        }
        else
        {
            glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);
        }

        if(l1d ==true)
        {
            glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        }
        else
        {
            glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);
        }
        if(l1s == true)
        {
            glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
        }
        else
        {
            glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);
        }
    }
    else
    {
        glDisable(GL_LIGHT0);
    }


    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
    glPopMatrix();
}
void light1()
{
    glPushMatrix();
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 0.0, 10.0, 10.0, 1.0 };
    if(l2 == true)
    {
        glEnable( GL_LIGHT1);
        if(l2a == true)
        {
            glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
        }
        else
        {
            glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
        }

        if(l2d ==true)
        {
            glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
        }
        else
        {
            glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);
        }
        if(l2s == true)
        {
            glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
        }
        else
        {
            glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);
        }
    }
    else
    {
        glDisable(GL_LIGHT1);
    }
    glLightfv( GL_LIGHT1, GL_POSITION, light_position);
    glPopMatrix();
}
void light2(float x, float y, float z)
{
    glPushMatrix();
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = {x,y,z, 1.0 };

    if(l3 == true)
    {
        glEnable( GL_LIGHT2);
        if(l3a == true)
        {
            glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient);
        }
        else
        {
            glLightfv( GL_LIGHT2, GL_AMBIENT, no_light);
        }

        if(l3d ==true)
        {
            glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse);
        }
        else
        {
            glLightfv( GL_LIGHT2, GL_DIFFUSE, no_light);
        }
        if(l3s == true)
        {
            glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular);
        }
        else
        {
            glLightfv( GL_LIGHT2, GL_SPECULAR, no_light);
        }
    }
    else
    {
        glDisable(GL_LIGHT2);
    }
    glLightfv( GL_LIGHT2, GL_POSITION, light_position);

    GLfloat spot_direction[] = { 0.0, 0.0, -1.0 };
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT2, GL_SPOT_CUTOFF, 30.0);
    glPopMatrix();
}

void walls()
{
    glPushMatrix();
    //glColor3f( 0.698,0.745, 0.733);
    glTranslated(tx,ty+2,Tzval+4);
    glScalef(10.1,0.005,2);
    drawCube(0.349,0.372,0.367,0.698,0.745, 0.733);
    glPopMatrix();
    glPushMatrix();
    //glColor3f( 0.698,0.745, 0.733);
    glTranslated(tx,ty+11.7,Tzval+4);
    glScalef(10.1,0.005,2);
    drawCube(0.349,0.372,0.367,0.698,0.745, 0.733);
    glPopMatrix();
    glPushMatrix();
    //glColor3f( 	0.745, 0.698, 0.733);
    glTranslated(tx,ty+2,Tzval+4);
    glScalef(10.1,3.25,2);
    glRotatef(90,0.0,0.0,1.0);
    drawCube(0.372, 0.349,0.367,0.745, 0.698, 0.733);
    glPopMatrix();
    glPushMatrix();
    //glColor3f( 	1.0, 1.0, 1.0);
    glTranslated(tx,ty+2,Tzval+4);
    glScalef(10.1,3.25,1);
    glRotatef(-90,1.0,0.0,0.0);
    drawCube(0.5, 0.5, 0.5,1.0, 1.0, 1.0);
    glPopMatrix();
    glPushMatrix();
    //glColor3f( 0.906, 0.902, 0.714);
    glTranslated(tx,ty+2,Tzval+13);
    glScalef(10.1,3.25,1);
    glRotatef(-90,1.0,0.0,0.0);
    drawCube(0.453,0.451,0.357,0.906, 0.902, 0.714);
    glPopMatrix();
    glPushMatrix();
    //glColor3f( 0.529, 0.808, 0.922);
    glTranslated(tx+7.0,ty+5.75,Tzval+4.0001);
    glScalef(1.8,1.5,0.5);
    glRotatef(-90,1.0,0.0,0.0);
    drawCube(0.265,0.404,0.461,0.529, 0.808, 0.922);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	1, 0.753, 0.796);
    glTranslated(tx,ty+2.001,Tzval+4);
    glScalef(2.1,0.007,2);
    drawCube(0.5,0.298,0.257,1, 0.753, 0.796);
    glPopMatrix();
    glPushMatrix();
    //glColor3f( 	0.659, 0.596, 0.514);
    glTranslated(tx+0.001,ty+2.001,Tzval+4);
    glScalef(0.006,1.5,2.0);
    glRotatef(90,0.0,0.0,1.0);
    drawCube(0.329,0.298,0.257,0.659, 0.596, 0.514);
    glPopMatrix();

}
void bed()
{

    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0.408, 0.102, 0.102);
    glTranslated(tx+0.005,ty+9.25,Tzval+5);
    glRotatef(-90,1.0,0.0,0.0);
    glScalef(2.1,2,0.01);
    drawCube(0.204, 0.051, 0.051,0.408, 0.102, 0.102);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0.0, 0.0, 1.0);
    glTranslated(tx+4.005,ty+7.5,Tzval+5.005);
    glRotatef(-90,1.0,0.0,0.0);
    glScalef(0.8,0.005,0.5);
    drawCube(0,0,0.5,0.0,0.0, 1.0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0.0, 0.0, 1.0);
    glTranslated(tx+0.505,ty+7.2,Tzval+5.005);
    glRotatef(-90,1.0,0.0,0.0);
    glScalef(0.5,0.05,0.2);
    drawCube(0.0, 0.0, 0.5,0.0, 0.0, 1.0);
    glDisable(GL_LIGHTING);

    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0.0, 0.0, 1.0);
    glTranslated(tx+0.505,ty+8.2,Tzval+5.005);
    glRotatef(-90,1.0,0.0,0.0);
    glScalef(0.5,0.05,0.2);
    drawCube(0.0, 0.0, 0.5,0.0, 0.0, 1.0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1.0, 0.0, 0.0);
    glTranslated(tx+0.005,ty+7,Tzval+5);
    glRotatef(-90,1.0,0.0,0.0);
    glScalef(2.1,2,0.75);
    drawCube(0.5, 0.0, 0.0,1.0, 0.0, 0.0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.408, 0.102, 0.102);
    glTranslated(tx+0.005,ty+7,Tzval+5);
    glScalef(0.1,0.75,0.5);
    drawCube(0.204, 0.051, 0.051,0.408, 0.102, 0.102);
    glDisable(GL_LIGHTING);
    glPopMatrix();

}
void weardrope1()
{
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.408, 0.102, 0.102);
    glTranslated(tx+0.005,ty+10.25,Tzval+4);
    glRotatef(-7,0.0,0.0,1.0);
    glScalef(1.1,0.5,0.75);
    drawCube(.204, 0.051, 0.051,0.408, 0.102, 0.102);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+0.005,ty+10.25,Tzval+6.25);
    glRotatef(-7,0.0,0.0,1.0);
    glScalef(1.1,0.5,0.005);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+3.205,ty+10.05,Tzval+4);
    glRotatef(-7,0.0,0.0,1.0);
    glScalef(0.05,0.35,0.3);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+3.205,ty+10.05,Tzval+5);
    glRotatef(-7,0.0,0.0,1.0);
    glScalef(0.05,0.35,0.3);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+3.205+1,ty+10.45,Tzval+5.5);
    glRotatef(-7,0.0,0.0,1.0);
    glScalef(0.005,0.05,0.02);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+3.205+1,ty+10.45,Tzval+4.7);
    glRotatef(-7,0.0,0.0,1.0);
    glScalef(0.005,0.05,0.02);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}
void weardrope2()
{
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    //glColor3f(0.408, 0.102, 0.102);
    glTranslated(tx+0.005,ty+3,Tzval+4);
    glScalef(0.5,0.5,0.75);
    drawCube(.204, 0.051, 0.051,0.408, 0.102, 0.102);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+0.005,ty+3,Tzval+6.25);
    glScalef(0.5,0.5,0.05);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+0.005+1.5,ty+3.0005,Tzval+6.25-0.75);
    glScalef(0.005,0.5,0.03);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+0.005+1.5,ty+3.0005+0.74,Tzval+6.25-0.375);
    glScalef(0.005,0.07,0.03);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+0.005+1.5,ty+3.0005,Tzval+6.25-0.75-0.75);
    glScalef(0.005,0.5,0.03);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+0.005+1.5,ty+3.0005+0.74,Tzval+6.25-0.75-0.375);
    glScalef(0.005,0.07,0.03);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+0.005+1.5,ty+3.0005,Tzval+6.25-0.75-0.75-0.74);
    glScalef(0.005,0.5,0.05);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+0.005+1.5,ty+3.0005+0.74,Tzval+6.25-0.75-0.75-0.375);
    glScalef(0.005,0.07,0.03);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+0.005+1.5,ty+3.07,Tzval+4);
    glScalef(0.05,0.005,0.75);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+0.005+1.5,ty+3.07+1.4,Tzval+4);
    glScalef(0.05,0.005,0.75);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}
void weardrope_mirror()
{
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.408, 0.102, 0.102);
    glTranslated(tx+6,ty+2.2,Tzval+4);
    glScalef(1.1,0.25,0.5);
    drawCube(.204, 0.051, 0.051,0.408, 0.102, 0.102);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+6.001,ty+2.95,Tzval+4);
    glScalef(0.01,0.005,0.5);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+7.101,ty+2.95,Tzval+4);
    glScalef(0.01,0.005,0.5);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+8.201,ty+2.95,Tzval+4);
    glScalef(0.01,0.005,0.5);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+9.301,ty+2.95,Tzval+4);
    glScalef(0.01,0.005,0.5);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+9.301-0.35,ty+2.95,Tzval+4.75);
    glScalef(0.015,0.005,0.09);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+8.201-0.35,ty+2.95,Tzval+4.75);
    glScalef(0.015,0.005,0.09);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+7.101-0.35,ty+2.95,Tzval+4.75);
    glScalef(0.015,0.005,0.09);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    ///mirror
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+7,ty+2.2,Tzval+5.5);
    glScalef(0.5,0.005,1.0);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+6.05,ty+2.25,Tzval+5.5);
    glScalef(1.1,0.25,0.02);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+7.05,ty+2.25,Tzval+8.5);
    glScalef(0.5,0.005,0.02);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+7.05,ty+2.25,Tzval+5.5);
    glScalef(0.05,0.005,1.0);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.698, 0.365, 0.298);
    glTranslated(tx+8.4,ty+2.25,Tzval+5.5);
    glScalef(0.05,0.005,1.0);
    drawCube(0.349,0.183,0.149,0.698, 0.365, 0.298);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}
void window1()
{
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+2,ty+2,Tzval+6);
    glScalef(0.5,0.05,1);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0, 0, 0);
    glTranslated(tx+2,ty+2.005,Tzval+6.75);
    glScalef(0.5,0.05,0.02);
    drawCube(0, 0, 0,0, 0, 0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0, 0, 0);
    glTranslated(tx+2.005,ty+2.005,Tzval+7.5);
    glScalef(0.5,0.05,0.02);
    drawCube(0, 0, 0,0, 0, 0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0, 0, 0);
    glTranslated(tx+2.00,ty+2.005,Tzval+8.25);
    glScalef(0.5,0.05,0.02);
    drawCube(0, 0, 0,0, 0, 0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0, 0, 0);
    glTranslated(tx+2.75,ty+2.005,Tzval+6);
    glScalef(0.05,0.05,1);
    drawCube(0, 0, 0,0, 0, 0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}
void window2()
{
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(1, 1, 1);
    glTranslated(tx+2,ty+10,Tzval+6.55);
    glScalef(0.05,0.5,0.8);
    drawCube(0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0, 0, 0);
    glTranslated(tx+2.06,ty+2+8,Tzval+7.05);
    glScalef(0.05,0.5,0.02);
    drawCube(0, 0, 0,0, 0, 0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0, 0, 0);
    glTranslated(tx+2.06,ty+2+8,Tzval+7.55);
    glScalef(0.05,0.5,0.02);
    drawCube(0, 0, 0,0, 0, 0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0, 0, 0);
    glTranslated(tx+2.06,ty+2+8,Tzval+8.05);
    glScalef(0.05,0.5,0.02);
    drawCube(0, 0, 0,0, 0, 0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0, 0, 0);
    glTranslated(tx+2.06,ty+2+8.75,Tzval+6.55);
    glScalef(0.05,0.01,0.8);
    drawCube(0, 0, 0,0, 0, 0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}
void photoframe()
{
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0.529, 0.808, 0.922);
    glTranslated(tx+0.002,ty+3.5,Tzval+7);
    glScalef(0.05,0.5,0.5);
    drawCube(0.265,0.404,0.461,0.529, 0.808, 0.922);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0.8, 0.0, 0.0);
    glTranslated(tx+0.007,ty+3.5,Tzval+7);
    glScalef(0.05,0.5,0.05);
    drawCube(0.4,0,0,0.8, 0.0, 0.0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0.8, 0.0, 0.0);
    glTranslated(tx+0.007,ty+3.5,Tzval+7);
    glScalef(0.05,0.02,0.5);
    drawCube(0.4,0,0,0.8, 0.0, 0.0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0.8, 0.0, 0.0);
    glTranslated(tx+0.007,ty+3.5,Tzval+8.5);
    glScalef(0.05,0.5,0.05);
    drawCube(0.4,0,0,0.8, 0.0, 0.0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0.8, 0.0, 0.0);
    glTranslated(tx+0.007,ty+4.95,Tzval+7);
    glScalef(0.05,0.02,0.55);
    drawCube(0.4,0,0,0.8, 0.0, 0.0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}
void clock()
{
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	1, 1, 1);
    glTranslated(tx+0.001,ty+7.5,Tzval+7.5);
    glScalef(0.05,0.2,0.3);
    drawCube(	0.5, 0.5, 0.5,1, 1, 1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0, 0,0 );
    glTranslated(tx+0.006,ty+7.5,Tzval+7.5);
    glScalef(0.05,0.02,0.3);
    drawCube(0, 0,0,0, 0,0 );
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0, 0,0 );
    glTranslated(tx+0.006,ty+8.06,Tzval+7.5);
    glScalef(0.05,0.02,0.3);
    drawCube(0, 0,0,0, 0,0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0, 0, 0);
    glTranslated(tx+0.006,ty+7.5,Tzval+7.49);
    glScalef(0.05,0.2,0.02);
    drawCube(0, 0,0,0, 0,0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0, 0, 0);
    glTranslated(tx+0.006,ty+7.5,Tzval+8.34);
    glScalef(0.05,0.2,0.02);
    drawCube(0, 0,0,0, 0,0);
    glDisable(GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0, 0,0 );
    glTranslated(tx+0.061,ty+7.5+0.28,Tzval+7.49+0.425);
    glRotatef(rotAngle1,-1,0,0);
    glScalef(0.05,0.005,0.08);
    drawCube(0, 0,0,0, 0,0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0, 0,0 );
    glTranslated(tx+0.121,ty+7.6,Tzval+7.65);
    glRotatef(-45,1.0,0.0,1.0);
    glScalef(0.005,0.005,0.12);
    drawCube(0, 0,0,0, 0,0);
    glDisable(GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
    //glColor3f( 	0, 0,0 );
    glEnable(GL_LIGHTING);
    light();
    light1();
    glTranslated(tx+0.121,ty+7.90,Tzval+7.84);
    glRotatef(95,1.0,0.0,1.0);
    glScalef(0.005,0.005,0.07);
    drawCube(0, 0,0,0, 0,0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}
void fan()
{
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.502, 0.257, 0.24);
    glTranslated(tx+6.05,ty+5.25+3,Tzval+5.5+3.5);
    glRotatef(rotAngle,0,0,-1);
    glScalef(0.4,0.05,0.02);
    drawCube(0.251,0.129,0.12,0.502, 0.257, 0.24);
    glDisable(GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.502, 0.257, 0.24);
    glTranslated(tx+6.05,ty+5.25+3,Tzval+5.5+3.5);////+0.15
    glRotatef(rotAngle,0,0,-1);
    glScalef(0.05,0.4,0.02);
    drawCube(0.251,0.129,0.12,0.502, 0.257, 0.24);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.502, 0.257, 0.24);
    glTranslated(tx+6.05,ty+5.25+3,Tzval+5.5+3.5);//+0.15
    glRotatef(180,0,0,-1);
    glRotatef(rotAngle,0,0,-1);
    glScalef(0.4,0.05,0.02);
    drawCube(0.251,0.129,0.12,0.502, 0.257, 0.24);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.502, 0.257, 0.24);
    glTranslated(tx+6.05,ty+5.25+3,Tzval+5.5+3.5);////-0.05
    glRotatef(180,0,0,-1);
    glRotatef(rotAngle,0,0,-1);
    glScalef(0.05,0.4,0.02);
    drawCube(0.251,0.129,0.12,0.502, 0.257, 0.24);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f(0.408, 0.102, 0.102);
    glTranslated(tx+6.05+0.05,ty+5.25+3+0.05,Tzval+5.5+3.5);
    glRotatef(180,0,0,-1);
    glScalef(0.05,0.05,0.2);
    drawCube(.204, 0.051, 0.051,0.408, 0.102, 0.102);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}
void lamp()
{
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	1, 0, 0.375);
    glTranslated(tx+3.205,ty+10.05+0.35,Tzval+5+2);
    glRotatef(-7,0.0,0.0,1.0);
    glScalef(0.05,0.18,0.25);
    drawCube(0.5,0,0.188,1, 0, 0.375);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_LIGHTING);
    light();
    light1();
    //glColor3f( 	0, 0, 0.375);
    glTranslated(tx+3.205,ty+10.05+0.35+0.18,Tzval+5+2-.75);
    glRotatef(-7,0.0,0.0,1.0);
    glScalef(0.05,0.05,0.25);
    drawCube(0,0,0.188,0, 0, 0.375);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(60,1,0.1,100);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(ex,ey,ez, cx,cy,cz, 0,0,1);

    glViewport(0, 0, windowHeight, windowWidth);

    glTranslated(tx,ty,tz);
    glEnable(GL_LIGHTING);
    light();
    light1();
    light2(tx+3.205,ty+8.05+0.35,Tzval+5+6);
    glPushMatrix();
    glTranslated(tx+7.0+3,ty+5.75+2,Tzval+4.0001+0.55);
    glutSolidSphere(0.5, 20, 16);
    glPopMatrix();
    glPushMatrix();
    walls();
    glPopMatrix();
    ///bed
    glPushMatrix();
    bed();
    glPopMatrix();

    ///box1
    glPushMatrix();
    weardrope1();
    glPopMatrix();

    ///box2
    glPushMatrix();
    weardrope2();
    glPopMatrix();

    ///box3
    glPushMatrix();
    weardrope_mirror();
    glPopMatrix();
    ///window1
    glPushMatrix();
    window1();
    glPopMatrix();
    ///window2
    glPushMatrix();
    window2();
    glPopMatrix();

    ///photo frame
    glPushMatrix();
    photoframe();
    glPopMatrix();

    ///clock
    glPushMatrix();
    clock();
    glPopMatrix();

    ///fan
    glPushMatrix();
    fan();
    glPopMatrix();
    ///lamp
    glPushMatrix();
    lamp();
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glFlush();
    glutSwapBuffers();
}
void myRotate()
{
    if (rotFlag == true)
    {
        rotAngle+= 0.3;

        if(rotAngle > 360 )
            rotAngle -= 360;
    }
    rotAngle1+= 0.2;
    if(rotAngle1 > 360 )
        rotAngle -= 360;
    glutPostRedisplay();
}
void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case '6': //up arrow to move upwards along Y axis
        ey+=0.10;
        break;
    case '4':
        ey-=0.10;
        break;
    case '+':
        ex-=0.10;//zoom in
        break;
    case '-':
        ex+=0.10;////zoom out
        break;
    case '8':
        ez+=0.1;
        break;
    case '5':
        ez-=0.1;
    case 'a':
        cx+=1.0;////zoom out
        break;
    case 'b':
        cy+=1.0;
        break;
    case 'c':
        cz+=1.0;
        break;
    case 'e':
        rotFlag = false;
        break;
    case 'r':
        rotFlag = true;
        break;
    case '1':
        l1= !l1;//light1 on/off
        break;
    case '2':
        l2 = !l2;//light2 on/off
        break;
    case '3':
        l3 = !l3;//spot light on/off
        break;
    case 'x':
        l1a= !l1a;//light1 ambient on/off
        break;
    case 'y':
        l1d = !l1d;//light1 diffuse on/off
        break;
    case 'z':
        l1s= !l1s;//light1 specular on/off
        break;
    case 'k':
        l2a= !l2a;//light2 ambient on/off
        break;
    case 'l':
        l2d = !l2d;//light2 diffuse on/off
        break;
    case 'm':
        l2s= !l2s;//light2 specular on/off
        break;
    case 'f':
        l3a= !l3a;//spot light ambient on/off
        break;
    case 'g':
        l3d = !l3d;//spot light diffuse on/off
        break;
    case 'h':
        l3s= !l3s;//spot light specular on/off
        break;
    case 27:    // Escape key
        exit(1);
    }
    glutPostRedisplay();
}



int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    printf("Keyboard options:\n");
    printf(" +   :Zoom in\n");
    printf(" -    :Zoom out\n");
    printf(" 4    :Go Left\n");
    printf(" 6    :Go Right\n");
    printf(" 2    :Go Down\n");
    printf(" 8    :Go UP\n");
    printf(" e    :Rotation off for fan\n");
    printf(" r    :Rotation on for fan\n");
    printf(" a    :Camera movement for Left direction\n");
    printf(" b    :Camera movement for Right direction\n");
    printf(" c    :Camera movement for Up direction\n");
    printf(" 1    :Light 1 on/off\n");
    printf(" x    :Light 1 Ambient property on/off\n");
    printf(" y    :Light 1 Diffuse property on/off\n");
    printf(" z    :Light 1 Specular property on/off\n");
    printf(" 2    :Light 2 on/off\n");
    printf(" k    :Light 2 Ambient property on/off\n");
    printf(" l    :Light 2 Diffuse property on/off\n");
    printf(" m    :Light 2 Specular property on/off\n");
    printf(" 3    :Spot Light on/off\n");
    printf(" f    :Spot Light Ambient property on/off\n");
    printf(" g    :Spot Light Diffuse property on/off\n");
    printf(" h    :Spot Light Specular property on/off\n");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("ROOM Design");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(myRotate);
    glutMainLoop();

    return 0;
}

