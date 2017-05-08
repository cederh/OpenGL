#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h> 

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
GLfloat scale = 1.0f;


void base (void){



    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f(0.50,  0.50,  0.50 );
    glVertex3f( 0.5, -0.5, 0.5 );
    glVertex3f( 0.5,  0.5, 0.5 );
    glVertex3f(-0.5,  0.5, 0.5 );
    glVertex3f(-0.5, -0.5, 0.5 );
    glEnd();


    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(0.25,  0.25,  0.25 );
    glVertex3f(-0.5, -0.5,  0.5 );
    glVertex3f(-0.5,  0.5,  0.5 );
    glVertex3f(-0.5,  0.5, -0.5 );
    glVertex3f(-0.5, -0.5, -0.5 );
    glEnd();


    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(0.65,  0.65,  0.65 );
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glVertex3f(-0.5, -0.5,  0.5 );
    glVertex3f(-0.5, -0.5, -0.5 );
    glEnd();

    //Mesa
    glBegin(GL_POLYGON);
     glColor3f( 0.60,  0.40, 0.12 );
    glVertex3f( 0.3, -0.2, -0.3 );
    glVertex3f( 0.3, -0.2,  0.3 );
    glVertex3f(-0.3, -0.2,  0.3 );
    glVertex3f(-0.3, -0.2, -0.3 );
    glEnd();

    glTranslatef(0.1f, -0.18f, 0.0f);
    glColor3f(0.0, 0.0, 0.0);
    glutWireTeapot(0.07);

    
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
  glVertex3f(0.0f, 0.0f, -20.0f);
  glVertex3f(0.0f, 0.0f, 20.0f);
  glEnd();

}

void display (void)
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
 // Rotacion de -5 grados en torno al eje x
    glRotated(-20.0, 1.0, 0.0, 0.0);
  // Rotacion de 20 grados en torno al eje y
    glRotated(45.0, 0.0, 1.0, 0.0);
   //setMaterial

    base();
    //plano_cartesiano();
   
    glPopMatrix();
    glPushMatrix();

    //Pata Izquierda
    glColor3f( 0.60,  0.40, 0.12 );
    glTranslated(-0.65f, -0.4f, 0.03f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    glTranslated(-0.65f, -0.35f, 0.03f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();


    glTranslated(-0.65f, -0.3f, 0.03f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    glTranslated(-0.65f, -0.25f, 0.03f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    
    glTranslated(-0.65f, -0.2f, 0.03f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    
    //Pata Derecha

    glTranslated(0.26f, 0.0f, 0.16f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    glTranslated(0.26f, -0.05f, 0.16f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    glTranslated(0.26f, -0.1f, 0.16f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    glTranslated(0.26f, -0.15f, 0.16f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    glTranslated(0.26f, -0.2f, 0.16f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    //Pata Delantera

    glTranslated(0.1f, -0.08f, -0.2f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    glTranslated(0.1f, -0.13f, -0.2f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    
    glTranslated(0.1f, -0.18f, -0.2f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();

    glTranslated(0.1f, -0.23f, -0.2f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
    
    glTranslated(0.1f, -0.28f, -0.2f);
    glutSolidCube(0.05);
    glPopMatrix();
    glPushMatrix();
     
  glEnd();
  glFlush();
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
  glutCreateWindow("Comedor");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;

}

//Hecho por Carlos Edenilson Romero Hernandez RH13026
