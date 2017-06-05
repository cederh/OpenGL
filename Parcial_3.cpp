#include <GL/gl.h>
#include <GL/glut.h>

//variables para dibujar los cuadrados
float px =21.87, a=0, pz=31.25;

void base(){

    GLfloat ejey=-150.0f,ejex=-150,px1=23.214f,pz1=31.25;

    for(int y=0; y<=8;y++){

        ejex=-150,a=0;

        for(int x=0; x<=12;x++){

           glColor3f(1.0, 1.0, 1.0);
           glBegin(GL_QUADS);
           glVertex3f(ejex,0,ejey);
           glVertex3f(ejex+px1,0,ejey);
           glVertex3f(ejex+px1,0,ejey+pz1);
           glVertex3f(ejex,0,ejey+pz1);
           glEnd();
           glFlush();
           ejex=ejex+px1;
        }
        ejey=ejey+pz1;
    }
}

void init(void){

	glShadeModel(GL_SMOOTH);

    // Ubicamos la fuente de luz en el punto
    GLfloat light_position[] = { -1.0, 1.0, 1.0, 1.0 };

    GLfloat luz_ambiental[] = { 0.1, 0.1, 0.1, 1.0 };

    // Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    
    //color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}


void display(void){
    // Propiedades del material

    GLfloat mat_ambient[] = { 0.0215f, 0.1745f, 0.0215f,1.0f };
    GLfloat mat_diffuse[] = { 0.07568f, 0.61424f, 0.07568f, 1.0f };
    GLfloat mat_specular[] = { 0.633f, 0.727811f, 0.633f, 1.0f };
    GLfloat shine[] = {50};

    // "Limpiamos" el frame buffer con el color de "Clear", en este

    // caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);


    glTranslatef(-10,-20,0);
    glRotatef(20,1,0,0);
    glRotatef(-15,0,1,0);

    //Dibujamos la base.
    base();
    
    //Para la Esfera.
    glTranslatef(0,75,110);
    glPushMatrix();

    GLfloat light_position[] = { -100, 100.0, 125.0, 1}; //agregamos luz
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);


    mat_ambient[0]= 0.329412f, mat_ambient[1]=0.225f, mat_ambient[2]= 0.027451f;
    mat_diffuse[0]= 0.780392, mat_diffuse[1]=0.568627f, mat_diffuse[2]= 0.113725f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glTranslatef(-90,0,0);
    glutSolidSphere(20,30,30);//Dibujamos la esfera.
    glPopMatrix();


    //Para el cubo.
    glPushMatrix();
    glRotatef(-25,0,1,0);
    glRotatef(10,1,0,0);
   
    mat_ambient[0]= 0.135f, mat_ambient[1]=0.225f, mat_ambient[2]= 0.1575f;
    mat_diffuse[0]= 0.135f, mat_diffuse[1]=0.225f, mat_diffuse[2]= 0.1575f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glTranslatef(-50,0,0);
    glutSolidCube(30); //Dibujamos el cubo.
    glPopMatrix();

    //Para el Cono.
    glPushMatrix();
    mat_ambient[0]= 0.1745f, mat_ambient[1]=0.01175f, mat_ambient[2]= 0.001175;
    mat_diffuse[0]= 0.61424f, mat_diffuse[1]=0.04136f, mat_diffuse[2]= 0.727811;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glTranslatef(10,0,0);
    glRotatef(-90,1,0,0);
    glutSolidCone(30,50,5,10); //Dibujamos el cono.
    glPopMatrix();

    //Para la tetera.
    glPushMatrix();
    mat_ambient[0]= 0.19125f, mat_ambient[1]=0.0735f, mat_ambient[2]= 0.0225f;
    mat_diffuse[0]= 0.7038f, mat_diffuse[1]=0.27048f, mat_diffuse[2]= 0.0828f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glTranslatef(70,0,0);
    glRotatef(10,1,0,0);
    glutSolidTeapot(20); //Dibujamos la tetera.
    glPopMatrix();

    //Para el Torus.
    glPushMatrix(); 
    mat_ambient[0]=  0.2125f, mat_ambient[1]=0.1275f, mat_ambient[2]= 0.054;
    mat_diffuse[0]= 0.714f, mat_diffuse[1]=0.4284f, mat_diffuse[2]= 0.18144;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glTranslatef(130,0,0);
    glRotatef(10,1,0,0);
    glutSolidTorus(10,20,10,10); //Dibujamos el Torus.
    glPopMatrix();
    glPushMatrix();
    
    glFlush();
    
     
}

void reshape(int w, int h){

    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
    //Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
    //"limpiamos" esta con la matriz identidad.
    glLoadIdentity();
    //Usamos proyeccion ortogonal.
    glOrtho(-200, 200, -200, 200, -200, 200);
    //Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
    //"Limpiamos" la matriz.
    glLoadIdentity();
}

int main(int argc, char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow ("Shadow Mapping");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

return 0;

}