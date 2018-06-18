#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

//GLfloat angle, fAspect;
GLfloat ASPECTO, ANGULO;
int x_ini,y_ini, bot;
GLfloat obsX, obsY, obsZ, rotX, rotY;
GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
GLfloat escalaX, escalaY, escalaZ;
#define SENS_ROT 10.0
#define SENS_OBS 10.0
#define SENS_TRANS 10.0

static double t = 0;
static double a = 0;
static double braco_direito = 0;
static double braco_esquerdo = 0;
static double perna_direita = 0;
static double perna_esquerda = 0;

bool mover_perna = false;

void capturarTecla(unsigned char key, int x, int y)
{
	if(key == 'a')
	{
		perna_esquerda = 20;
		perna_direita = -20;
		braco_esquerdo = 20;
		braco_direito = -20;

	}
	else if (key == 'b')
	{
		perna_esquerda = -20;
		perna_direita = 20;
		braco_esquerdo = -20;
		braco_direito = 20;
	}
	else if (key == 'p')
	{
		perna_esquerda = 0;
		perna_direita = 0;
		braco_esquerdo = 0;
		braco_direito = 0;
	}
}



void Desenha (void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(5.0);

	glPushMatrix();

		glPushMatrix();
			//  Tronco
	        glColor3f(0.0, 0.0, 1.0);
	        glTranslatef(0.0, -1.0, 0.0);
	        glutSolidSphere(0.5,  50.0,  50.0);

			glColor3f(1.0, 0.0, 0.0);
	        glBegin(GL_LINES);
	        glVertex3f(0.0, 2.0, 0.0);
	        glVertex3f(0.0, 0.0, 0.0);
	        glEnd();

	       	// Inicio perna esquerda 
	        glPushMatrix();
	            // Primeira parte da perna esquerda 
	            glColor3f(0.0, 0.0, 1.0);
	            glTranslatef(-0.5, -1.3, 0.0);
	            glRotatef(perna_esquerda, 1.0, 0.0, 0.0);
	            glutSolidSphere(0.2,  50.0,  50.0);  
	            
	            glColor3f(1.0, 0.0, 0.0);
	            glBegin(GL_LINES);
	            glVertex3f(0.3, 1.3, 0.0); //vertice do colo até a cintura  
	            glVertex3f(-0.5, -2.0, 0.0); // vertice do colo até o joelho
	            glEnd();


	            glPushMatrix();
	            	// Joelho
					glColor3f(0.0, 0.0, 1.0);
	            	glTranslatef(-0.5, -2.0, 0.0);
	            	//perna_direita = 0;
	            	glutSolidSphere(0.2,  50.0,  50.0);

	            	glPushMatrix();
	            		// Calcanhar
	            		glColor3f(0.0, 0.0, 1.0);
	            		glTranslatef(-0.5, -3.0, 0.0);
	            		glutSolidSphere(0.2,  50.0,  50.0);

	            		// vertice do calcanhar até o joelho
	            		glColor3f(1.0, 0.0, 0.0);
		            	glBegin(GL_LINES);
	            		glVertex3f(0.5, 3.0, 0.0);  
	            		glVertex3f(0.0, 0.0, 0.0); 
	            		glEnd();

	            		// Nó final do pé
	    				glColor3f(0.0, 0.0, 1.0);
	    				glTranslatef(0.0, 0.0, 1.0);
	    				glutSolidSphere(0.2,  50.0,  50.0);

	    				//vertice do calcanhar até o nó final do pé 
	    				glBegin(GL_LINES);
	            		glVertex3f(0.0, 0.0, -1.0);
	            		glVertex3f(0.0, 0.0, 0.0); 
	            		glEnd();

	            	glPopMatrix();
	            glPopMatrix();            	
	        glPopMatrix();


	        // Inicio perna direita

	        glPushMatrix();
	            // Primeira parte da perna direta
	            glColor3f(0.0, 0.0, 1.0);
	            glTranslatef(0.5, -1.3, 0.0);
	            glRotatef(perna_direita, 1.0, 0.0, 0.0);
	            glutSolidSphere(0.2,  50.0,  50.0);  
	            
	            glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_LINES);
	            glVertex3f(-0.3, 1.3, 0.0); //vertice do colo até a cintura  
	            glVertex3f(0.5, -2.0, 0.0); // vertice do colo até o joelho
	            glEnd();

			    glPushMatrix();
	            	// Joelho
					glColor3f(0.0, 0.0, 1.0);
	            	glTranslatef(0.5, -2.0, 0.0);
	            	//perna_esquerda = 0;
	            	glutSolidSphere(0.2,  50.0,  50.0);

	            	glPushMatrix();
	            		// Calcanhar
	            		glColor3f(0.0, 0.0, 1.0);
	            		glTranslatef(0.5, -3.0, 0.0);
	            		glutSolidSphere(0.2,  50.0,  50.0);

	            		// vertice do calcanhar até o joelho
	            		glColor3f(1.0, 0.0, 0.0);
		            	glBegin(GL_LINES);
	            		glVertex3f(-0.5, 3.0, 0.0);  
	            		glVertex3f(0.0, 0.0, 0.0); 
	            		glEnd();

	            		// Nó final do pé
	    				glColor3f(0.0, 0.0, 1.0);
	    				glTranslatef(0.0, 0.0, 1.0);
	    				glutSolidSphere(0.2,  50.0,  50.0);

	    				// vertice do calcanhar até o joelho 
	    				glBegin(GL_LINES);
	            		glVertex3f(0.0, 0.0, -1.0);
	            		glVertex3f(0.0, 0.0, 0.0); 
	            		glEnd();

	            	glPopMatrix();
	            glPopMatrix();          	
	        glPopMatrix(); // Fim da perna direita

	        // Inicio parte superior
	        glPushMatrix();
	        	// Pescoço
		        glColor3f(0.0, 0.0, 1.0);
		        glTranslatef(0.0, 2.0, 0.0);
		        glutSolidSphere(0.3,  50.0,  50.0);

		        // vertice que liga o pescoço ao ombro esquerdo
		        glColor3f(1.0, 0.0, 0.0);
		        glBegin(GL_LINES);
		        glVertex3f(-1.5, -0.2, 0.0);
		        glVertex3f(1.5, -0.2, 0.0);
		        glEnd();

		       	glColor3f(1.0, 0.0, 0.0);
		        glBegin(GL_LINES);
		        glVertex3f(0.0, 1.5, 0.0);
		        glVertex3f(0.0, 0.0, 0.0);
		        glEnd();


		        glPushMatrix(); // Inicio parte esquerda
		        	// Ombro
		        	glColor3f(0.0, 0.0, 1.0);
	            	glTranslatef(-1.5, -0.3, 0.0);
	            	glRotatef(braco_esquerdo, 1.0, 0.0, 0.0);
	            	glutSolidSphere(0.2,  50.0,  50.0);

	    		    // vertice que liga o ombro a mão
			        glColor3f(1.0, 0.0, 0.0);
			        glBegin(GL_LINES);
			        glVertex3f(-0.5, -2.0, 0.0);
			        glVertex3f(0.0, 0.0, 0.0);
			        glEnd();

	            	glPushMatrix();
	            		// Mão
	            		glColor3f(0.0, 0.0, 1.0);
	            		glTranslatef(-0.5, -2.0, 0.0);
	            		glutSolidSphere(0.2,  50.0,  50.0);
	            	glPopMatrix();
		        glPopMatrix(); // Fim parte esquerda

	    	    glPushMatrix(); // Inicio parte direita
	    	    	// Ombro
			    	glColor3f(0.0, 0.0, 1.0);
			    	glTranslatef(1.5, -0.3, 0.0);
			    	glRotatef(braco_direito, 1.0, 0.0, 0.0);
			    	glutSolidSphere(0.2,  50.0,  50.0);

				    // vertice que liga o ombro a mão
			        glColor3f(1.0, 0.0, 0.0);
			        glBegin(GL_LINES);
			        glVertex3f(0.5, -2.0, 0.0);
			        glVertex3f(0.0, 0.0, 0.0);
			        glEnd();

			    	glPushMatrix();
			    		// Mão
			    		glColor3f(0.0, 0.0, 1.0);
			    		glTranslatef(0.5, -2.0, 0.0);
			    		glutSolidSphere(0.2,  50.0,  50.0);
			    	glPopMatrix();
		        glPopMatrix(); // Fim da parte direita

		        glPushMatrix();
		        	// Cabeça 
		        	glColor3f(0.0, 0.0, 1.0);
			    	glTranslatef(0.0, 1.5, 0.0);
			    	glutSolidSphere(0.5,  50.0,  50.0);
			    glPopMatrix();

			glPopMatrix();

		glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

// Inicializa par?metros de rendering
void Inicializa (void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 20.0, 20.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela ser? preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	// Habilita o modelo de coloriza??o de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a reflet?ncia do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentra??o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par?metros da luz de n?mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a defini??o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina??o
	glEnable(GL_LIGHTING);  
	// Habilita a luz de n?mero 0
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

// Fun??o usada para especificar o volume de visualiza??o
void EspecificaParametrosVisualizacao(void) //equivalente ao posiciona observador
{
	// Especifica sistema de coordenadas de proje??o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje??o
	glLoadIdentity();

	// Especifica a proje??o perspectiva
    //gluPerspective(angle,fAspect,0.4,500);
    gluPerspective(ANGULO, ASPECTO, 0.4, 500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posi??o do observador e do alvo
    //gluLookAt(0,80,200, 0,0,0, 0,1,0);
    //gluLookAt(obsX, obsY, obsZ, 0,0,0, 0,1,0);
    glTranslatef(-obsX, -obsY, -obsZ);/*Translata a câmera para essas variáveis*/
    glRotatef(rotX,1,0,0);/*Rotacionar a câmera para essas coordenadas*/
    glRotatef(rotY,0,1,0); 
}

// Fun??o callback chamada quando o tamanho da janela ? alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis?o por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a corre??o de aspecto
	//fAspect = (GLfloat)w/(GLfloat)h;
	ASPECTO = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Fun??o callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
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

void motion(int x, int y){
    if(bot == GLUT_LEFT_BUTTON){//Rotação
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

static void idle(void){
t = glutGet(GLUT_ELAPSED_TIME) / 1000.0; //Tempo randomico
a = t*45.0; //angulo randomico
glutPostRedisplay();
}
		
// Programa Principal
int main(int argc, char *argv[])
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInit(&argc, argv);
	glutInitWindowSize(600,600);
	glutCreateWindow("Teste 2017");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutMotionFunc(motion);
	glutIdleFunc(idle);
	glutKeyboardFunc(capturarTecla);
	Inicializa();
	glutMainLoop();
}