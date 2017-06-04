#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

GLfloat ballRadius = 0.4f;//Definimos el radio de la pelota.

//Definimos donde estara ubicada la pelota.
GLfloat xPos = -10.0f;//Para X.  
GLfloat yPos = 20.0f;//Para Y.

//Creamos variables para valores maximos y minimos.
GLfloat xPosMax, xPosMin, yPosMax, yPosMin;

//Creamos variables para valores de direccion.
GLdouble xLeft, xRight, yBottom, yTop;    

//Definimos los valores de velocidad de movimiento.
GLfloat xSpeed = 0.004f;//Para X.
GLfloat ySpeed = -.007f;//Para Y-

int refreshMillis = 5;//Refresh de 5 Milisegundos.    

//Inicializacion de variables para iluminacion.
GLfloat mat_diffuse [] = {0.0, 0.0, 0.0, 1.0};
GLfloat mat_specular [] = {0.5, 0.5, 0.5, 1.0};
GLfloat mat_shininess [] = {50};
GLfloat mat_emission [] = {0.5, 0.2, 0.2, 1.0};


//Funcion para la iluminacion.  
void iluminacion (){

GLfloat light_position[] = {-1.0, 1.0, -3.0, 0.0};//Punto de Luz.
glLightfv(GL_LIGHT0,GL_POSITION, light_position);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
glEnable (GL_LIGHTING);
glEnable (GL_LIGHT0);
glEnable(GL_COLOR_MATERIAL);

}
 
//Funcion de dibujo.
void display() {
 
    glClear(GL_COLOR_BUFFER_BIT);   
    glLoadIdentity();   
 
    //Traslacion para la posicion en X y en Y.
    glTranslatef(xPos, yPos, 0.0f); 
   
    iluminacion();//Llamamos la funcion iluminacion.

    glColor3f(1.0,0.0,0.0);//Color rojo para la pelota.
    glutSolidSphere(ballRadius, 100, 100);//Dibujamos la pelota.
    glFlush ();
    glutSwapBuffers(); 

   //Iniciamos animacion.
   xPos += xSpeed;
   yPos += ySpeed;
   

   //Comparacion del area. Lo cual nos sirve para que la pelota siempre rebote en el area que hemos definido.
   if (xPos > xPosMax) {
      xPos = xPosMax;
      xSpeed = -xSpeed;
   } else if (xPos < xPosMin) {
      xPos = xPosMin;
      xSpeed = -xSpeed;
   }
   if (yPos > yPosMax) {
      yPos = yPosMax;
      ySpeed = -ySpeed;
   } else if (yPos < yPosMin) {
      yPos = yPosMin;
      ySpeed = -ySpeed;
   }
 
} 	
void reshape(GLsizei weight, GLsizei height) 	
{
   if (height == 0) height = 1;              
   GLfloat aspect = (GLfloat)weight / height;  
   
   glViewport(0, 0, weight, height);
      
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();     

//Definimos el tamaño del area.
   if (weight <= height) {
      xLeft   = -1.0;
      xRight  = 1.0;
      yBottom = -1.0 / aspect;
      yTop    = 1.0 / aspect;
   } else {
      xLeft   = -1.0 * aspect;
      xRight  = 1.0 * aspect;
      yBottom = -1.0;
      yTop    = 1.0;
   }

   gluOrtho2D(xLeft, xRight, yBottom, yTop);//Proyeccion Ortogonal para 2 dimenciones.

   //Dando valores maximos y minimos a las variables antes creadas.
   xPosMin = xLeft + ballRadius;
   yPosMax = yTop - ballRadius;   
   xPosMax = xRight - ballRadius;
   yPosMin = yBottom + ballRadius;
   
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();          
}

//Funcion para el tiempo de refresh.
void Timer(int value) 	
{
   glutPostRedisplay();   
   glutTimerFunc(refreshMillis, Timer, 0);
}
 
int main(int argc, char** argv) 

{
   glutInit(&argc, argv);//Inicializacion del glut.
   glutInitWindowSize(800,600);//Tamaño de la ventana.
   glutInitWindowPosition(400,100);//Posicion de la ventana en el monitor.
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//         
   glutCreateWindow("Pelota");//Nombre de la ventana.
   glClearColor(0,0,0,0);//Especificar valores claros para el color del buffer. 
   glutDisplayFunc(display);//Establece la devolución de llamada de visualización de la ventana actual.
   glutReshapeFunc(reshape);//Llamando la funcion de Reshape.
   glutTimerFunc(0, Timer, 0);//Llamando la funcion tiempo.                
   glutMainLoop();//Bucle de procesamiento de eventos de GLUT.              
   return 0;
}
