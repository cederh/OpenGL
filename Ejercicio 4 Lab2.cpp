#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h> 

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
GLfloat scale = 1.0f;

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

// Propiedades del material

    GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f};
    GLfloat mat_diffuse[] = { 0.780392f, 0.568627f, 0.113725f};
    GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f};
    GLfloat shine[] = {27.8974f};


// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClearColor(1,1,1,0.5);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
// Rotacion de 25 grados en torno al eje x
    glRotated(16.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-20.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
   //setMaterial
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);

    glTranslated(0.0f, 0.0f, 0.0f);
    glRotated(0.0f, 1.0f, 0.0f, 0.0f);
    glRotated(180.0f, 0.0f, 1.0f, 0.0f);
    glRotated(180.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidCube(0.3);
    glPopMatrix();


    glPushMatrix();
 

    glTranslated(0.5f, -0.1f, 0.0f);
    glRotated(-100.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCone(0.20, 0.40,50,50);
    glPopMatrix();


    glPushMatrix();
  
    glTranslated(-0.5f, 0.0f, 0.0f);
    glRotated(200.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();
    glPushMatrix();

    //plano_cartesiano();
    
  glFlush();
}

void init (void)
{

// Ubicamos la fuente de luz en el punto
    GLfloat light_position[] = { -100.0, 100.0, 50.0, 0.0 };
// Activamos la fuente de luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //Activamos las luces en 0
	glDepthFunc(GL_LESS); //comparación de profundidad
	glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}
void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();

}

int main (int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Figuras");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;

}

//Hecho por Carlos Edenilson Romero Hernandez RH13026
