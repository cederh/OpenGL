#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

//Definimos variables
double rotate_x=0;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;

void display(){

    glClearColor(1,1,1,0.5); //Color de fondo
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
// Rotacion Eje X
    glRotated(-5, 1.0, 0.0, 0.0);
// Rotacion Eje Y
    glRotated(20.0, 0.0, 1.0, 0.0);
  
    glPushMatrix();

// Dibujamos la base de la grua (Color Azul)
  
    glRotatef(0.0,0.1,0.1,0.0); 
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(0.0f, -0.7f, 0.0f);
    glutSolidCube(0.25);
    glPopMatrix();
    glPushMatrix();

//Dibujando iman de la grua
    glColor3f(0.0, 0.0, 0.0);
    glRotatef (rotate_x, 0.0 , 0.1 , 0.0 );
    glTranslatef (X, Y, Z);
    glTranslated(0.7f, -0.5f, 0.0f);
    glutSolidCube(0.07);
    glPopMatrix();
    glPushMatrix();

//Cubo  Color amarillo
    glTranslated(0.9f, -0.4f, 0.0f);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();

//Cubo color rojo
    glColor3f(1.0, 0.0, 0.0);
    glTranslated(0.3f, -0.7f, 0.0f);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();

//Cubo  Color Verde
    glColor3f(0.0, 1.0, 0.0);
    glTranslated(0.2f, -0.3f, 0.6f);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();

//Dibujamos el pilar de la grua (Color Rojo)
    for (GLfloat p=-0.7; p<=0.2; p+=0.01){
        glColor3f(1.0, 0.0, 0.0);
        glTranslated(0.0f, p, 0.0f);
        glutSolidCube(0.13);
        glPopMatrix();
        glPushMatrix();
    }

// Dibujamos el brazo de la grua (Color Azul)
  for (GLfloat h=0.0; h<=0.7; h+=0.01){
        glColor3f(0.0, 0.0, 1.0);
        glRotatef (rotate_x, 0.0 , 0.1 , 0.0 );
        glTranslated(h, 0.3 , 0.0f);
        glutSolidCube(0.08);
        glPopMatrix();
        glPushMatrix();
    }
// Dibujamos el brazo 2 de la grua (Color Azul)
    for (GLfloat h2=-0.1; h2<=0.3; h2+=0.01){
        glColor3f(0.0, 0.0, 1.0);
        glRotatef (rotate_x, 0.0 , 0.1 , 0.0 );
        glTranslated(0.7f, h2, 0.0f);
        glutSolidCube(0.08);
        glPopMatrix();
        glPushMatrix();
    }
// Dibujamos el cable de la grua
    for (GLfloat c=-0.5; c<=0.0; c+=0.01){
        glColor3f(0.25, 0.25, 0.25);
        glRotatef (rotate_x, 0.0 , 0.1 , 0.0 );
        glTranslatef (X, Y, Z);
        glTranslated(0.7f, c, 0.0f);
        glutSolidCube(0.01);
        glPopMatrix();
        glPushMatrix();
    } 


    glEnd();//Terminando dibujo
    glFlush();
    glutSwapBuffers();

}
void specialKeys ( int key, int x, int y){
    //Flecha arriba: Rotación en eje X positivo
    if (key == GLUT_KEY_RIGHT)
            rotate_x +=4; 
    //Flecha abajo: Rotación en eje X negativo
    if (key == GLUT_KEY_LEFT)
            rotate_x -=4;

    //Flecha Abajo: Eje Y Positivo
    if (key== GLUT_KEY_UP)
            if (Y <= 0.25 ){
                Y +=0.01f ;
            }
    //Flecha Abajo: Eje Y Negativo
    if (key== GLUT_KEY_DOWN)
            if (Y >=-0.1){
                Y -=0.01f ; 
            }
    glutPostRedisplay ();
}

int main(int argc, char* argv[]){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    glutCreateWindow("Parcial 2 - RH13026");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
}