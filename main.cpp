#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
void init(void)
{
    //GLfloat light_position[] = { -1.0, 1.0, 1.0, 0.0 };
// Activamos la fuente de luz
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0); //Activamos las luces en 0
    //glDepthFunc(GL_LESS); //comparación de profundidad
    //glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
    //glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
 //  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}
//funcion que controla los matariales 
/*void color(float q, float w, float e, float r, float t, float y, float u, float i, float o, float p)
{
    
GLfloat mat_ambient[] = { q, w, e, p };
GLfloat mat_diffuse[] = { r, t, y, p };
GLfloat mat_specular[] = { u, i, o, p };
GLfloat shine[] = {27.8974f};

glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shine);

}
*/
void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}
void display(void)
{
   glClearColor(1,1,1,0.5); //Fondo de color blanco
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

// Rotacion del eje x
    glRotated(10.0, 1.0, 0.0, 0.0);
// Rotacion del eje y
    glRotated(-15.0, 0.0, 1.0, 0.0);

// Dibujamos una la base Azul
    glPushMatrix();
    glTranslatef(-160.0,-180.0,30.0);
    glColor3f(0.0,0.0,1.0);
    glutSolidCube (70.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-200.0,-180.0,30.0);
    glColor3f(0.0,0.0,1.0);
    glutSolidCube (70.0);
    glPopMatrix();

//DIbujamos el cubo Rojo
    glPushMatrix();
    glTranslatef(20.0,-220.0,30.0);
    glColor3f(1.0,0.0,0.0);
    glutSolidCube (50.0);
    glPopMatrix();
    
//Dibujamos el cubo negro (Iman de la grua)
    glPushMatrix();
    glTranslatef(230.0,-90.0,50.0);
    glColor3f(0.25,0.25,0.25);
    glutSolidCube (30.0);
    glPopMatrix();

//Dibujamos el cubo amarillo
    glPushMatrix();
    glTranslatef(300.0,60.0,90.0);
    glColor3f(1.0,1.0,0.0);
    glutSolidCube (35.0);
    glPopMatrix();

//DIbujamos el cubo verdes
    glPushMatrix();
    glTranslatef(30.0,30.0,30.0);
    glColor3f(0.0,1.0,0.0);
    glutSolidCube (45.0);
    glPopMatrix();
   
//Dibujando el Pilar

    glPushMatrix();
    glTranslatef(-175.0,-110.0,30.0);
    glColor3f(0.98,0.625,0.12);
    glutSolidCube (70.0);
    glTranslatef(-175.0,-90.0,30.0);
    glutSolidCube (70.0);
    glPopMatrix();
   
   glFlush();
}

int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels   
    glutInitWindowSize (900, 800);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (10, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Fifuras");
// Inicializamos el sistema
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
