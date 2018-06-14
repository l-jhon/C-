#include <GL/glut.h>
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define PI 3.1415926535898

#include <math.h>

//GLfloat angle, fAspect;
GLfloat ASPECTO, ANGULO;
int x_ini,y_ini, bot;
GLfloat obsX, obsY, obsZ, rotX, rotY;
GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
GLfloat escalaX, escalaY, escalaZ;
#define SENS_ROT 10.0
#define SENS_OBS 10.0
#define SENS_TRANS 10.0

#define left_arm 20.0
#define left_arm_angle 45.0
#define left_forearm 10.0
#define left_forearm_angle 45.0

#define right_arm 10.0
#define right_arm_angle 45.0
#define right_forearm 10.0
#define right_forearm_angle 45.0

#define bust_angle_x 45.0
#define bust_angle_y 45.0

#define bust 10.0
#define head 10.0


void struct_left_arm(void)
{
glNewList(left_arm,GL_COMPILE);
// Shoulder
glTranslatef(1.1,0.25,0.0);
glScalef(0.5,0.5,0.5);
glColor3ub(128,128,128);
glutSolidSphere(0.5,20,20);
// Arm
glTranslatef(0.0,-1.10,0.0);
glScalef(0.5,1.5,0.5);
glColor3ub(255,255,255);
glutSolidCube(1.0);
glEndList();
}

void struct_right_arm(void)
{
glNewList(right_arm,GL_COMPILE);
// Shoulder
glTranslatef(1.1,0.25,0.0);
glScalef(0.5,0.5,0.5);
glColor3ub(128,128,128);
glutSolidSphere(0.5,20,20);
// Arm
glTranslatef(0.0,-1.10,0.0);
glScalef(0.5,1.5,0.5);
glColor3ub(255,255,255);
glutSolidCube(1.0);
glEndList();
}


void Desenha(void)
{
		// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClear(GL_COLOR_BUFFER_BIT);

	/*-------------BUST AND HEAD--------------*/
	glPushMatrix();
	glRotatef(bust_angle_y,0,1,0);
	glRotatef(bust_angle_x,1,0,0);
	glPushMatrix();
	glCallList(bust);
	glCallList(head);
	glPopMatrix();
	/*--------RIGHT ARM AND FOREARM---------*/
	glPushMatrix();
	glTranslatef(0,0.25,0);
	glRotatef(right_arm_angle,1,0,0);
	glTranslatef(0,-0.25,0);
	glPushMatrix();
	glCallList(right_arm);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.25,-0.7,0);
	glRotatef(right_forearm_angle,1,0,0);
	glTranslatef(-1.25,0.7,0);
	glCallList(right_forearm);
	glPopMatrix();
	glPopMatrix();
	/*---------LEFT ARM AND FOREARM---------*/
	glPushMatrix();
	glTranslatef(0,0.25,0);
	glRotatef(left_arm_angle,1,0,0);
	glTranslatef(0,-0.25,0);
	glPushMatrix();
	glCallList(left_arm);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.25,-0.7,0);
	glRotatef(left_forearm_angle,1,0,0);
	glTranslatef(-1.25,0.7,0);
	glCallList(left_forearm);
	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}


// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 20.0, 20.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

    //angle=45;
    ANGULO = 45;
    rotX = rotY = 0;
    obsX = obsY = 0;
    obsZ = 60;//Voltar para 10
    escalaX = escalaY = escalaZ = 1;
}


// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void) //equivalente ao posiciona observador
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    //gluPerspective(angle,fAspect,0.4,500);
    gluPerspective(ANGULO, ASPECTO, 0.4, 500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
    //gluLookAt(0,80,200, 0,0,0, 0,1,0);
    //gluLookAt(obsX, obsY, obsZ, 0,0,0, 0,1,0);
    glTranslatef(-obsX, -obsY, -obsZ);/*Translata a cÃ¢mera para essas variÃ¡veis*/
    glRotatef(rotX,1,0,0);/*Rotacionar a cÃ¢mera para essas coordenadas*/
    glRotatef(rotY,0,1,0); 
}


// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	//fAspect = (GLfloat)w/(GLfloat)h;
	ASPECTO = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	/*if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}*/
	if(state == GLUT_DOWN){
		x_ini = x;
        y_ini = y;
        obsX_ini = obsX;
        obsY_ini = obsY;
        obsZ_ini = obsZ;
        rotX_ini = rotX;
        rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void motion(int x, int y)
{
    if(bot == GLUT_LEFT_BUTTON){//RotaÃ§Ã£o
        int deltaX = x_ini - x;
        int deltaY = y_ini - y; 
        rotX = rotX_ini - deltaY/ SENS_ROT;
        rotY = rotY_ini - deltaX/ SENS_ROT;
     }
     else if (bot == GLUT_RIGHT_BUTTON){//Zoom
         int deltaZ = y_ini - y;
         obsZ = obsZ_ini + deltaZ/ SENS_OBS;
     }
     else if (bot == GLUT_MIDDLE_BUTTON){//Correr
         int deltaX = x_ini - x;
         int deltaY = y_ini - y;
         obsX = obsX_ini + deltaX/ SENS_TRANS;
         obsY = obsY_ini + deltaY/ SENS_TRANS;
     }
     EspecificaParametrosVisualizacao();
     glutPostRedisplay();
}


// Programa Principal
int main(int argc, char *argv[])
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(600,600);
	glutCreateWindow("Casa");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutMotionFunc(motion);
	Inicializa();
	glutMainLoop();
}