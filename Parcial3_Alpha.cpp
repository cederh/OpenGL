/******Dibujar sombras mediante Blend
******Parcial #3 de Rafael Mariona
******/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


//Inicializacion de variables para iluminacion.
GLfloat mat_diffuse [] = {0.0, 0.0, 0.0, 1.0};
GLfloat mat_specular [] = {0.5, 0.5, 0.5, 1.0};
GLfloat mat_shininess [] = {50};
GLfloat mat_emission [] = {0.5, 0.2, 0.2, 1.0};


void iluminacion(void){

	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
	glLightfv(GL_LIGHT0,GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

}

void display(void){

      glClearColor(0.0, 0.0, 0.0 ,0.0); // Borrar pantalla y Z-buffer.
      glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();// Resetear transformaciones-

      iluminacion();

      //Dibujamos la base.
      glBegin(GL_QUADS);
      glVertex3f(-100.0f,-100.0f,0.0f);
      glVertex3f(-100.0f, 100.0f,0.0f);
      glVertex3f( 100.0f, 100.0f,0.0f);
      glVertex3f( 100.0f,-100.0f,0.0f);
      glEnd();

      //Esfera.
      glPushMatrix();
      glEnable (GL_BLEND);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

      glColor4f(0,0,0,0.05);
      glTranslatef(-40.0f, 3.0f, 0.0f);
      glutSolidSphere(5,40,40);
      glPopMatrix();

      glPushMatrix();
      glColor4f(1.0, 0.0, 0.0,0.95);
      glTranslatef(-40.0f, 0.0f, 0.0f);
      glutSolidSphere(5,40,40);
      glDisable(GL_BLEND);
      glPopMatrix();

      //Cubo.
      glPushMatrix();
      glEnable(GL_BLEND);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

      glColor4f(0,0,0,0.05);
      glTranslatef(-20.0f, 3.0f, 0.0f);
      glutSolidCube(8);
      glPopMatrix();

      glPushMatrix();
      glColor4f(0.0, 0.0, 1.0,0.95);
      glTranslatef(-20.0f, 0.0f, 0.0f);
      glutSolidCube(8);
      glDisable(GL_BLEND);
      glPopMatrix();

      //Cono
      glPushMatrix();
      glEnable(GL_BLEND);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

      glColor4f(0,0,0,0.05);
      glTranslatef(0.0f,1.0f,0.0f);
      glutSolidCone(5,10,20,20);
      glPopMatrix();

      glPushMatrix();
      glColor4f(0.0, 1.0, 0.0,0.95);
      glTranslatef(0.0f, -2.0f, 0.0f);
      glutSolidCone(5,10,20,20);
      glDisable(GL_BLEND);
      glPopMatrix();

      //Tetera.
      glPushMatrix();
      glEnable(GL_BLEND);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

      glColor4f(0,0,0,0.05);
      glTranslatef(20.0f, 3.0f, 0.0f);
      glutSolidTeapot(5);
      glPopMatrix();

      glPushMatrix();
      glColor4f(1.0, 1.0, 0.0,0.95);
      glTranslatef(20.0f, 0.0f, 0.0f);
      glutSolidTeapot(5);
      glDisable(GL_BLEND);
      glPopMatrix();

      //Torus.
      glPushMatrix();
      glEnable(GL_BLEND);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

      glColor4f(0,0,0,0.05);
      glTranslatef(40.0f, 3.0f, 0.0f);
      glutSolidTorus(2,4,10,10); 
      glPopMatrix();

      glPushMatrix();
      glColor4f(0.0, 1.0, 1.0,0.95);
      glTranslatef(40.0f, 0.0f, 0.0f);
      glutSolidTorus(2,4,10,10); 
      glDisable(GL_BLEND);
      glPopMatrix();


      glFlush();
}


void reshape(int w, int h)
{
	  glShadeModel (GL_SMOOTH);
      glOrtho(-400.0,400.0,-400.0,400.0,-400.0,400.0);
      glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
      glViewport(0,0,(GLsizei)w,(GLsizei)h);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(90.0f, (GLfloat)w/(GLfloat)h, 0.0f, 1.0f);
      gluLookAt(0.0,-30.0,45.0,  0.0,0.0,0.0, 0.0,1.0,0.0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
}

int main(int argc, char** argv)
{
      glutInit(&argc, argv);//Inicializacion del glut.
      glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);//Modo de visualizacion inicial.
      glutInitWindowSize (800, 600);//Tamaño de la ventana.
      glutInitWindowPosition(400,100);//Posicion de la ventana en el monitor.
      glutCreateWindow ("Parcial 3");//Nombre de la ventana.
      glutDisplayFunc(display);//Establece la devolución de llamada de visualización de la ventana actual.
      glutReshapeFunc(reshape);//Control de ventanas.
      glutMainLoop();//Bucle de procesamiento de eventos de GLUT.
      return 0;
}
