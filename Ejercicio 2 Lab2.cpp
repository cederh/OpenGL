#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h> 

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
GLfloat scale = 1.0f;


void tablero (void){


	glPointSize(420);
    glBegin(GL_POINTS);
    glColor3f( 0.0, 0.0, 0.0 );
    glVertex3f(-0.1f, -0.106f, 0.0f);
    glEnd();
  
    glPointSize(420);
    glBegin(GL_POINTS);
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(-0.1f, -0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    glPushMatrix();

  

for(float k=-0.4; k< 0.4; k+=0.2){
     for(float l=-0.4; l< 0.4; l+=0.2){
    glPointSize(60);
    glBegin(GL_POINTS);
    glColor3f( 0.0, 0.0, 0.0 );
    glVertex3f(k, l, 0.0f);
    glEnd();
  

       }
    }

for(float k=-0.3; k< 0.2; k+=0.2){
     for(float l=-0.3; l< 0.2; l+=0.2){

     glPointSize(60);
    glBegin(GL_POINTS);
    glColor3f( 0.0, 0.0, 0.0 );
    glVertex3f(k, l, 0.0f);
    glEnd();

       }
    }

    
}

void tablero_cube(){


for(float k=-0.4; k< 0.4; k+=0.2){
     for(float l=-0.4; l< 0.4; l+=0.2){
    glColor3f( 0.0, 0.0, 0.0 );
    glTranslatef(k,l, 0.0f);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
  

       }
    }

for(float k=-0.3; k< 0.2; k+=0.2){
     for(float l=-0.3; l< 0.2; l+=0.2){;
    glColor3f( 0.0, 0.0, 0.0 );
    glTranslatef(k,l, 0.0f);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();

       }
    }

glEnd();

}


void plano_cartesiano (void)
{

  glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glVertex2f(-8.0f, 0.0f);
  glVertex2f(8.0f, 0.0f);

  glEnd();
  glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glVertex2f(0.0f, -15.0f);
  glVertex2f(0.0f, 25.0f);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glVertex3f(0.0f, 0.0f, 20.0f);
  glVertex3f(0.0f, 0.0f, 20.0f);
  glEnd();

}

void display (void)
{

    glClearColor(0.1,0.5,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

    glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(0.0f, 0.0f, 0.0f, 1.0f );
    glTranslatef(0.2f, 0.2f, 1.0f);
    glScalef(2.0f, 2.0f, 2.0f);

   
  tablero();
  //plano_cartesiano();
  glEnd();
  glFlush();
  glutSwapBuffers();
}


void init (void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.5, 1.5, -1.5, 1.5, -0.0, 40.0);
}

int main (int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Tablero de Ajedrez");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;

}

//Hecho por Carlos Edenilson Romero Hernandez RH13026
