#include <GL/glut.h>

//GLfloat angle, fAspect;
GLfloat ASPECTO, ANGULO;
int x_ini,y_ini, bot;
GLfloat obsX, obsY, obsZ, rotX, rotY;
GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
GLfloat escalaX, escalaY, escalaZ;
#define SENS_ROT 10.0
#define SENS_OBS 10.0
#define SENS_TRANS 10.0   

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 glClear(GL_COLOR_BUFFER_BIT);
	    
    	/*glPushMatrix();
            glColor3f(1.0, 0.0, 0.0);	 
	    	glBegin(GL_POLYGON);
	    	glVertex2f(0.0, 0.0);
	    	glVertex2f(0.0, 10.0);
	    	glVertex2f(10.0, 10.0);
	    	glVertex2f(10.0, 0.0);
	    	glEnd();
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.0, 1.0, 0.0);	 
	    	glBegin(GL_QUADS);
	    	glVertex2f(10.0, 10.0);
	    	glVertex2f(10.0, 20.0);
	    	glVertex2f(20.0, 20.0);
	    	glVertex2f(20.0, 10.0);
	    	glEnd();
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.0, 0.0, 1.0);
            glPointSize(5);
            glBegin(GL_POINTS);
	    	glVertex2f(-0.0, 0);
	    	glVertex2f(-5.0, 0);
	    	glVertex2f(-10.0,0);
            glEnd(); 
	    glPopMatrix();

        glPushMatrix();
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_LINES);
	    	glVertex2f(-5.0, 1.0);
	    	glVertex2f(-5.0, 10.0);
	    	glVertex2f(-10.0,1.0);
            glVertex2f(-10.0,10.0);
            glEnd(); 
	    glPopMatrix();

        glPushMatrix();
            glColor3f(0.5, 0.5, 0.5);
            glBegin(GL_TRIANGLES);
	    	glVertex2f(0.0, 10.0);
	    	glVertex2f(-5.0, 15.0);
	    	glVertex2f(-10.0,10.0);
            glEnd(); 
	    glPopMatrix();

        glPushMatrix();
            glColor3f(0.5, 0.5, 0.5);
            glBegin(GL_TRIANGLES);
	    	glVertex2f(0.0, 10.0);
	    	glVertex2f(-5.0, 15.0);
	    	glVertex2f(-10.0,10.0);
            glEnd(); 
	    glPopMatrix();

        glPushMatrix();
            glColor3f(0.5, 0.5, 0.5);
            glBegin(GL_TRIANGLES);
	    	glVertex2f(0.0, 10.0);
	    	glVertex2f(-5.0, 15.0);
	    	glVertex2f(-10.0,10.0);
            glEnd(); 
	    glPopMatrix();

        glPushMatrix();
            glColor3f(0.5, 0.5, 0.0);
            glTranslatef(-15.0,10.0,0.0);
        	glRotatef (45.0, 0.0, 0.0, 1.0);
            glutSolidCube(4);
	    glPopMatrix();

        glPushMatrix();
            glColor3f(0.0, 0.5, 0.5);
            glTranslatef(-25.0,10.0,0.0);
            glutSolidSphere(5.0,50.0,50.0);
	    glPopMatrix();

        glPushMatrix();
            glColor3f(0.5, 0.0, 0.5);
            glTranslatef(-25.0,25.0,0.0);
            glutSolidTorus(1.0,4.0,50.0,50.0);
	    glPopMatrix();

		glPushMatrix();
            glColor3f(0.9, 0.9, 0.9); //Quantidade de vermelho, verde e azul 
            glBegin(GL_LINES); //Toda e qualquer primitiva que colocarmos, nasce na origem
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(0.0, 300.0, 0.0);
            glEnd(); 
	    glPopMatrix();
     
		glPushMatrix();
            glColor3f(0.9, 0.9, 0.9);
            glBegin(GL_LINES);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(300.0, 0.0, 0.0);
            glEnd(); 
	    glPopMatrix();
		
		glPushMatrix();
            glColor3f(0.9, 0.9, 0.9);
            glBegin(GL_LINES); // desenha uma linha
	    	glVertex3f(0.0, 0.0, 0.0); // inicio da linha
	    	glVertex3f(0.0, 0.0, 300.0); // termina a linha
            glEnd(); 
	    glPopMatrix();
	    
	    glPushMatrix();
            glColor3f(1.0, 0.0, 0.0);
            glTranslatef(20.0,0.0,0.0);
            glutSolidSphere(1.0,50.0,50.0);
	    glPopMatrix();
	    
	    glPushMatrix();
            glColor3f(0.0, 1.0, 0.0);
            glTranslatef(0.0,20.0,0.0);
            glutSolidSphere(1.0,50.0,50.0);
	    glPopMatrix();
	    
    	glPushMatrix();
            glColor3f(0.0, 0.0, 1.0);
            glTranslatef(0.0,0.0,20.0);
            glutSolidSphere(1.0,50.0,50.0);
	    glPopMatrix();
	    
   		glPushMatrix();
            glColor3f(0.0, 1.0, 1.0);
            glTranslatef(0.0,20.0,20.0);
            glutSolidSphere(1.0,50.0,50.0);
	    glPopMatrix();
	    
  		glPushMatrix();
            glColor3f(1.0, 1.0, 0.0);
            glTranslatef(20.0,20.0,0.0);
            glutSolidSphere(1.0,50.0,50.0);
	    glPopMatrix();
	    
 		glPushMatrix();
            glColor3f(1.0, 0.0, 1.0);
            glTranslatef(20.0,0.0,20.0);
            glutSolidSphere(1.0,50.0,50.0);
	    glPopMatrix();
	    
   		glPushMatrix();
            glColor3f(1.0, 1.0, 1.0);
            glTranslatef(20.0,20.0,20.0);
            glutSolidSphere(1.0,50.0,50.0);
	    glPopMatrix();
	    
  		glPushMatrix();
            glColor3f(0.0, 0.0, 0.0);
            glutSolidSphere(1.0,50.0,50.0);
	    glPopMatrix();
	    
		glEnable(GL_BLEND); // Responsavel pela transparencia
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		// ALPHA - transparencia

        /*glPushMatrix();
            glColor4f(1.0, 1.0, 1.0, 0.5);	 
	    	glBegin(GL_QUADS);
	    	glVertex3f(-10.0, 10.0, 10.0);
	    	glVertex3f(-10.0, 20.0, 10.0);
	    	glVertex3f(30.0, 20.0, 10.0);
	    	glVertex3f(30.0, 10.0, 10.0);
	    	glEnd();
        glPopMatrix();*/
      /*  
  		glPushMatrix();
            glColor4f(0.99, 0.99, 0.99, 0.099); //R,G,B e ALPHA	 
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(20.0, 0.0, 0.0);
	    	glVertex3f(20.0, 20.0, 0.0);
	    	glVertex3f(0.0, 20.0, 0.0);
	    	glEnd();
        glPopMatrix();
        
  		glPushMatrix();
            glColor4f(1.00, 1.00, 0, 0.2);	 
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 0.0, 40.0);
	    	glVertex3f(40.0, 0.0, 40.0);
	    	glVertex3f(40.0, 40.0, 40.0);
	    	glVertex3f(0.0, 40.0, 40.0);
	    	glEnd();
        glPopMatrix();*/
        
  		glPushMatrix();
            glColor4f(1, 1, 0, 0.099); //R,G,B e ALPHA - Amarelo 
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(120.0, 0.0, 0.0);
	    	glVertex3f(120.0, 40.0, 0.0); 
	    	glVertex3f(0.0, 40.0, 0.0);
	    	glEnd();
        glPopMatrix();

        glPushMatrix();
            glColor4f(1, 1, 0, 0.099); //R,G,B e ALPHA - Amarelo 2
	    	glBegin(GL_QUADS);
	    	glVertex3f(40.0, 0.0, 40.0);
	    	glVertex3f(120.0, 0.0, 40.0);
	    	glVertex3f(120.0, 40.0, 40.0); 
	    	glVertex3f(40.0, 40.0, 40.0);
	    	glEnd();
        glPopMatrix();

  		glPushMatrix();
            glColor4f(0, 1, 0, 0.099); //R,G,B e ALPHA - Verde
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(0.0, 40.0, 0.0);
	    	glVertex3f(0.0, 40.0, 80.0);
	    	glVertex3f(0.0, 0.0, 80.0);
	    	glEnd();
        glPopMatrix();


        glPushMatrix();
            glColor4f(0, 1, 0, 0.099); //R,G,B e ALPHA - Verde 2
	    	glBegin(GL_QUADS);
	    	glVertex3f(40.0, 0.0, 40.0);
	    	glVertex3f(40.0, 40.0, 40.0);
	    	glVertex3f(40.0, 40.0, 80.0);
	    	glVertex3f(40.0, 0.0, 80.0);
	    	glEnd();
        glPopMatrix();         	

  		glPushMatrix();
            glColor4f(0, 0, 1, 0.099); //R,G,B e ALPHA - Azul
	    	glBegin(GL_QUADS);
	    	glVertex3f(120.0, 0.0, 0.0);
	    	glVertex3f(120.0, 0.0, 40.0);
	    	glVertex3f(120.0, 40.0, 40.0);
	    	glVertex3f(120.0, 40.0, 0.0);
	    	glEnd();
        glPopMatrix();   		

  		glPushMatrix();
            glColor4f(0.5, 0, 0.5, 0.099); //R,G,B e ALPHA - Roxo
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 40.0, 80.0);
	    	glVertex3f(40.0, 40.0, 80.0);
	    	glVertex3f(40.0, 0.0, 80.0);
	    	glVertex3f(0.0, 0.0, 80.0);
	    	glEnd();
        glPopMatrix();  
        
        
  		glPushMatrix();
            glColor4f(0.3, 0.3, 0.3, 0.099); //R,G,B e ALPHA - Cinza
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(120.0, 0.0, 0.0);
	    	glVertex3f(120.0, 0.0, 40.0);
	    	glVertex3f(0.0, 0.0, 40.0);
	    	glEnd();
        glPopMatrix();

        glPushMatrix();
            glColor4f(0.3, 0.3, 0.3, 0.099); //R,G,B e ALPHA - Cinza 2 
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(40.0, 0.0, 0.0);
	    	glVertex3f(40.0, 0.0, 80.0);
	    	glVertex3f(0.0, 0.0, 80.0);
	    	glEnd();
        glPopMatrix();         
        
        
  		// glPushMatrix();
    //         glColor3f(0, 0.5, 1); //R,G,B e ALPHA	 
	   //  	glBegin(GL_TRIANGLES);
	   //  	glVertex3f(0.0, 40.0, 0.0);
	   //  	glVertex3f(40.0, 40.0, 0.0);
	   //  	glVertex3f(20.0, 60.0, 0.0);
	   //  	glEnd();
    //     glPopMatrix();
		
  		// glPushMatrix();
    //         glColor3f(0.5, 0.0, 1); //R,G,B e ALPHA	 
	   //  	glBegin(GL_TRIANGLES);
	   //  	glVertex3f(0.0, 40.0, 40.0);
	   //  	glVertex3f(40.0, 40.0, 40.0);
	   //  	glVertex3f(20.0, 60.0, 40.0);
	   //  	glEnd();
    //     glPopMatrix();	
		
  		// glPushMatrix();
    //         glColor4f(0, 0, 1, 0.099); //R,G,B e ALPHA	 
	   //  	glBegin(GL_QUADS);
	   //  	glVertex3f(40.0, 40.0, 40.0);
	   //  	glVertex3f(40.0, 40.0, 0.0);
	   //  	glVertex3f(20.0, 60.0, 0.0);
	   //  	glVertex3f(20.0, 60.0, 40.0);
	   //  	glEnd();
    //     glPopMatrix(); 	
		
  		// glPushMatrix();
    //         glColor4f(0, 0, 1, 0.099); //R,G,B e ALPHA	 
	   //  	glBegin(GL_QUADS);
	   //  	glVertex3f(0.0, 40.0, 40.0);
	   //  	glVertex3f(0.0, 40.0, 0.0);
	   //  	glVertex3f(20.0, 60.0, 0.0);
	   //  	glVertex3f(20.0, 60.0, 40.0);
	   //  	glEnd();
    //     glPopMatrix();				   			
						        
/*        glPushMatrix();
            glColor4f(0, 0, 0, 0.99);	 
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 0.0, 40.0);
	    	glVertex3f(40.0, 0.0, 40.0);
	    	glVertex3f(40.0, 40.0, 40.0);
	    	glVertex3f(0.0, 40.0, 40.0);
	    	glEnd();
        glPopMatrix();*/
        
/* 		glPushMatrix();
            glColor4f(0.99, 0.99, 0.99, 0.099);	 
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 20.0, 0.0);
	    	glVertex3f(20.0, 20.0, 0.0);
	    	glVertex3f(20.0, 20.0, 20.0);
	    	glVertex3f(0.0, 20.0, 20.0);
	    	glEnd();
        glPopMatrix();
        
   		glPushMatrix();
            glColor4f(0.99, 0.99, 0.99, 0.099);	 
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(20.0, 0.0, 0.0);
	    	glVertex3f(20.0, 0.0, 20.0);
	    	glVertex3f(0.0, 0.0, 20.0);
	    	glEnd();
        glPopMatrix();
        
  		glPushMatrix();
            glColor4f(0.99, 0.99, 0.99, 0.099);	 
	    	glBegin(GL_QUADS);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(0.0, 20.0, 0.0);
	    	glVertex3f(0.0, 20.0, 20.0);
	    	glVertex3f(0.0, 0.0, 20.0);
	    	glEnd();
        glPopMatrix();
        
 		glPushMatrix();
            glColor4f(0.99, 0.99, 0.99, 0.099);	 
	    	glBegin(GL_QUADS);
	    	glVertex3f(20.0, 0.0, 0.0);
	    	glVertex3f(20.0, 20.0, 0.0);
	    	glVertex3f(20.0, 20.0, 20.0);
	    	glVertex3f(20.0, 0.0, 20.0);
	    	glEnd();
        glPopMatrix();
        
  */      
	    glutSwapBuffers(); // 
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

        void motion(int x, int y){
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
	glutCreateWindow("Teste 2017");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutMotionFunc(motion);
	Inicializa();
	glutMainLoop();
}

