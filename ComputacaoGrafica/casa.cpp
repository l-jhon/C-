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


void discoC(GLfloat raioInf, GLfloat raioSup, GLfloat alt){
GLUquadricObj* q = gluNewQuadric();
gluQuadricDrawStyle(q, GLU_FILL);
gluQuadricNormals(q, GLU_SMOOTH);
gluQuadricTexture(q, GL_TRUE);
gluCylinder(q, raioInf, raioSup, alt, 60,60);
gluDeleteQuadric(q);
}

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
        glPopMatrix();
        
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
		
		// Parede externa lateral à esquerda 
		glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
			glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 6, 0);
			glVertex3f(0, 6, 12);
			glVertex3f(0, 0, 12);
			glEnd();
        glPopMatrix();
	
		// Parte de cima da parede externa lateral à esquerda
		glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
			glBegin(GL_QUADS);
			glVertex3f(0, 6, 0);
			glVertex3f(0, 6, 12);
			glVertex3f(0, 12, 12);
			glVertex3f(0, 12, 0);
			glEnd();
        glPopMatrix();
        
        // Seção relativa à parede da frente mais da torre esquerda da casa
		// Parede da frente do primeiro andar
			// Terceiro retangulo (de baixo para cima) ao lado esquerdo da janela
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(0, 0, 12);
				glVertex3f(1, 0, 12);
				glVertex3f(1, 2, 12);
				glVertex3f(0, 2, 12);
				glEnd();
	        glPopMatrix();
	        
			// Segundo retangulo (de baixo para cima) ao lado esquerdo da janela
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(0, 2, 12);
				glVertex3f(1, 2, 12);
				glVertex3f(1, 4, 12);
				glVertex3f(0, 4, 12);
				glEnd();
	        glPopMatrix();
	        
            // Primeiro retangulo (de baixo para cima) ao lado esquerdo da janela
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(0, 4, 12);
				glVertex3f(1, 4, 12);
				glVertex3f(1, 6, 12);
				glVertex3f(0, 6, 12);
				glEnd();
	        glPopMatrix();
			
			// Retangulo sobre a janela do primeiro andar
            glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(1, 6, 12);
				glVertex3f(1, 4, 12);
				glVertex3f(5, 4, 12);
				glVertex3f(5, 6, 12);
				glEnd();
	        glPopMatrix();
	        
            // Primeiro retangulo (de baixo para cima) ao lado direito da janela
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(5, 6, 12);
				glVertex3f(6, 6, 12);
				glVertex3f(6, 4, 12);
				glVertex3f(5, 4, 12);
				glEnd();
	        glPopMatrix();

			// Segundo retangulo (de baixo para cima) ao lado direito da janela
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(5, 4, 12);
				glVertex3f(6, 4, 12);
				glVertex3f(6, 2, 12);
				glVertex3f(5, 2, 12);
				glEnd();
	        glPopMatrix();
	        
   			// Terceiro retangulo (de baixo para cima) ao lado direito da janela
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(5, 2, 12);
				glVertex3f(6, 2, 12);
				glVertex3f(6, 0, 12);
				glVertex3f(5, 0, 12);
				glEnd();
	        glPopMatrix();
	        
            // Retangulo debaixo da janela do primeiro andar
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(5, 2, 12);
				glVertex3f(5, 0, 12);
				glVertex3f(1, 0, 12);
				glVertex3f(1, 2, 12);
				glEnd();
	        glPopMatrix();
	    // FIM - Parede da frente do primeiro andar
		// INICIO - Parede da frente do segundo andar 	
            // Terceiro retangulo (de baixo para cima) ao lado esquerdo da janela
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(0, 6, 12);
				glVertex3f(1, 6, 12);
				glVertex3f(1, 8, 12);
				glVertex3f(0, 8, 12);
				glEnd();
	        glPopMatrix();
	        
            // Segundo retangulo (de baixo para cima) ao lado esquerdo da janela
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(0, 8, 12);
				glVertex3f(0, 10, 12);
				glVertex3f(1, 10, 12);
				glVertex3f(1, 8, 12);
				glEnd();
	        glPopMatrix();  
			
			
		    // Primeiro retangulo (de baixo para cima) ao lado esquerdo da janela
			glPushMatrix();
				glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(0, 10, 12);
				glVertex3f(0, 12, 12);
				glVertex3f(1, 12, 12);
				glVertex3f(1, 10, 12);
				glEnd();
	        glPopMatrix();     
			
			 // Retangulo debaixo da janela do primeiro andar
			glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(1, 6, 12);
				glVertex3f(1, 8, 12);
				glVertex3f(5, 8, 12);
				glVertex3f(5, 6, 12);
				glEnd();
	        glPopMatrix();
	        
	        // Primeiro retangulo(de cima para baixo) ao lado direito da janela
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(5, 12, 12);
				glVertex3f(6, 12, 12);
				glVertex3f(6, 10, 12);
				glVertex3f(5, 10, 12);
				glEnd();
	        glPopMatrix();
	        
	        // Segundo retangulo(de cima para baixo) ao lado direito da janela
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(5, 10, 12);
				glVertex3f(6, 10, 12);
				glVertex3f(6, 8, 12);
				glVertex3f(5, 8, 12);
				glEnd();
	        glPopMatrix();
	        
            // Terceiro retangulo(de cima para baixo) ao lado direito da janela
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(5, 8, 12);
				glVertex3f(6, 8, 12);
				glVertex3f(6, 6, 12);
				glVertex3f(5, 6, 12);
				glEnd();
	        glPopMatrix();
	        
   			// Retangulo acima da janela do primeiro andar
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(1, 12, 12);
				glVertex3f(5, 12, 12);
				glVertex3f(5, 10, 12);
				glVertex3f(1, 10, 12);
				glEnd();
	        glPopMatrix();
	        // FIM - Parede da frente do segundo andar
	        // INICIO - Parede de trás (torre à esquerda)
			glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(6, 0, 0);
				glVertex3f(6, 12, 0);
				glVertex3f(0, 12, 0);
				glVertex3f(0, 0, 0);
				glEnd();
	        glPopMatrix();
	        // FIM - Parede de trás (torre à esquerda)
	        // INICIO - Retangulo da parede direita (torre à esquerda)
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(6, 12, 12);
				glVertex3f(6, 12, 0);
				glVertex3f(6, 6, 0);
				glVertex3f(6, 6, 12);
				glEnd();
	        glPopMatrix();
	        // FIM - Retangulo da parede direita (torre à esquerda)
	        // INICIO - Retangulo do teto do cômodo entre as torres
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(6, 6, 0);
				glVertex3f(6, 6, 12);
				glVertex3f(14, 6, 12);
				glVertex3f(14, 6, 0);
				glEnd();
	        glPopMatrix();
	        // FIM - Retangulo do teto do cômodo entre as torres
	        // INICIO - Quadrado parede de trás do cômodo entre as torres
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(14, 6, 0);
				glVertex3f(6, 6, 0);
				glVertex3f(6, 0, 0);
				glVertex3f(14, 0, 0);
				glEnd();
	        glPopMatrix();
	        // FIM - Quadrado parede de trás do cômodo entre as torres
	        // INICIO - Retangulo superior da parede à direita do cômodo entre as torres
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(14, 12, 0);
				glVertex3f(14, 12, 12);
				glVertex3f(14, 6, 12);
				glVertex3f(14, 6, 0);
				glEnd();
	        glPopMatrix();
	        // FIM - Retangulo superior da parede à direita do cômodo entre as torres
	        // INICIO - Retângulo da parede de trás da torre à direita
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(14, 12, 0);
				glVertex3f(20, 12, 0);
				glVertex3f(20, 0, 0);
				glVertex3f(14, 0, 0);
				glEnd();
	        glPopMatrix();
	        // FIM - Retângulo da parede de trás da torre à direita
	        // INICIO - Retângulo da parede à esquerda da porta
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(6, 6, 12);
				glVertex3f(6, 0, 12);
				glVertex3f(9, 0, 12);
				glVertex3f(9, 6, 12);
				glEnd();
	        glPopMatrix();
	        // FIM - Retângulo da parede à esquerda da porta
	        // INICIO - Retângulo da parede acima da porta
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(9, 6, 12);
				glVertex3f(11, 6, 12);
				glVertex3f(11, 3, 12);
				glVertex3f(9, 3, 12);
				glEnd();
	        glPopMatrix();
	        // FIM - Retângulo da parede acima da porta
	        // INICIO - Retângulo da parede à direita da porta
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(11, 6, 12);
				glVertex3f(14, 6, 12);
				glVertex3f(14, 0, 12);
				glVertex3f(11, 0, 12);
				glEnd();
	        glPopMatrix();
	        // FIM - Retângulo da parede acima da porta
	        // INICIO - Teto da torre à direita
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(14, 12, 0);
				glVertex3f(20, 12, 0);
				glVertex3f(20, 12, 12);
				glVertex3f(14, 12, 12);
				glEnd();
	        glPopMatrix();
	        // FIM - Teto da torre à direita
	       /* // INICIO - Parede direita da torre à direita
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(20, 12, 12);
				glVertex3f(20, 12, 0);
				glVertex3f(20, 0, 0);
				glVertex3f(20, 0, 12);
				glEnd();
	        glPopMatrix();
	        // FIM - Parede direita da torre à direita*/
	        // INICIO - Retangulo superior da janela da torre direita na parede lateral
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(20, 6, 12);
				glVertex3f(20, 6, 0);
				glVertex3f(20, 4, 0);
				glVertex3f(20, 4, 12);
				glEnd();
	        glPopMatrix();	   
			// FIM - Retangulo superior da janela da torre direita na parede lateral
	        // INICIO - Retangulo inferior da janela da torre direita na parede lateral
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(20, 6, 12);
				glVertex3f(20, 0, 12);
				glVertex3f(20, 0, 11);
				glVertex3f(20, 6, 11);
				glEnd();
	        glPopMatrix();	   
			// FIM - Retangulo inferior da janela da torre direita na parede lateral
	        // INICIO - Retangulo no meio das duas janelas da torre direita na parede lateral
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(20, 6, 7);
				glVertex3f(20, 0, 7);
				glVertex3f(20, 0, 6);
				glVertex3f(20, 6, 6);
				glEnd();
	        glPopMatrix();	   
			// FIM - Retangulo inferior da janela da torre direita na parede lateral
	        // INICIO - Retangulo debaixo da segunda janela da torre direita na parede lateral
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(20, 2, 6);
				glVertex3f(20, 2, 0);
				glVertex3f(20, 0, 0);
				glVertex3f(20, 0, 6);
				glEnd();
	        glPopMatrix();	   
			// FIM - Retangulo inferior da segunda janela da torre direita na parede lateral			
	        // INICIO - Retangulo debaixo da primeira janela da torre direita na parede lateral
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(20, 2, 7);
				glVertex3f(20, 0, 7);
				glVertex3f(20, 0, 12);
				glVertex3f(20, 2, 12);
				glEnd();
	        glPopMatrix();	   
			// FIM - Retangulo inferior da primeira janela da torre direita na parede lateral									
	        // INICIO - Teto da torre à esquerda
	        glPushMatrix();
			glColor4f(1.0, 0.9, 0.7, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(0, 12, 0);
				glVertex3f(6, 12, 0);
				glVertex3f(6, 12, 12);
				glVertex3f(0, 12, 12);
				glEnd();
	        glPopMatrix();
	        // FIM - Teto da torre à esquerda
	        // Inicio parede do primeiro andar da torre à direita
	        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(14, 0, 12);
					glVertex3f(14, 2, 12);
					glVertex3f(15, 2, 12);
					glVertex3f(15, 0, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
	        	// Inicio - Segundo retangulo de cima para baixo do primeiro andar
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(14, 2, 12);
					glVertex3f(15, 2, 12);
					glVertex3f(15, 4, 12);
					glVertex3f(14, 4, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Segundo retangulo de cima para baixo do primeiro andar
	        	// Inicio - Primeiro retangulo de cima para baixo do primeiro andar
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(14, 4, 12);
					glVertex3f(15, 4, 12);
					glVertex3f(15, 6, 12);
					glVertex3f(14, 6, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Primeiro retangulo de cima para baixo do primeiro andar
	        	// Inicio - Retângulo acima da janela do primeiro andar
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(15, 4, 12);
					glVertex3f(15, 6, 12);
					glVertex3f(19, 6, 12);
					glVertex3f(19, 4, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Retângulo acima da janela do primeiro andar 
	        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar (direita)
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(19, 6, 12);
					glVertex3f(20, 6, 12);
					glVertex3f(20, 4, 12);
					glVertex3f(19, 4, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
	        	// Inicio - Segundo retangulo de cima para baixo do primeiro andar (direita)
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(19, 4, 12);
					glVertex3f(20, 4, 12);
					glVertex3f(20, 2, 12);
					glVertex3f(19, 2, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Segundo retangulo de cima para baixo do primeiro andar
	        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar (direita)
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(19, 2, 12);
					glVertex3f(20, 2, 12);
					glVertex3f(20, 0, 12);
					glVertex3f(19, 0, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
				// Inicio - Retângulo abaixo da janela do primeiro andadr (torre direita)
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(19, 2, 12);
					glVertex3f(19, 0, 12);
					glVertex3f(15, 0, 12);
					glVertex3f(15, 2, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
				// Inicio - Piso do primeiro andar
	        	glPushMatrix();
					glColor4f(0.9, 0.8, 0.8, 0.6);
					glBegin(GL_QUADS);
					glVertex3f(0, 0, 0);
					glVertex3f(20, 0, 0);
					glVertex3f(20, 0, 12);
					glVertex3f(0, 0, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Piso primeiro andar
			// Janela do segundo andar da torre à direita
	        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar
	        	glPushMatrix(); 
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(14, 12, 12);
					glVertex3f(15, 12, 12);
					glVertex3f(15, 10, 12);
					glVertex3f(14, 10, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
	        	// Inicio - Segundo retangulo de cima para baixo do primeiro andar
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(15, 10, 12);
					glVertex3f(14, 10, 12);
					glVertex3f(14, 8, 12);
					glVertex3f(15, 8, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Segundo retangulo de cima para baixo do primeiro andar
	        	// Inicio - Primeiro retangulo de cima para baixo do primeiro andar
	        	glPushMatrix();
					glColor4f(1.0, 0.9, 0.7, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(14, 8, 12);
					glVertex3f(15, 8, 12);
					glVertex3f(15, 6, 12);
					glVertex3f(14, 6, 12);
					glEnd();
			    glPopMatrix();
	        	// Fim - Primeiro retangulo de cima para baixo do primeiro andar
	        	// Parte relativa às janelas da parede lateral da torre
	        		// Janelas da parte inferior
		        	// Inicio - Retângulo acima da janela do primeiro andar
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(15, 12, 12);
						glVertex3f(19, 12, 12);
						glVertex3f(19, 10, 12);
						glVertex3f(15, 10, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Retângulo acima da janela do primeiro andar 
		        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar (direita)
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(19, 12, 12);
						glVertex3f(19, 10, 12);
						glVertex3f(20, 10, 12);
						glVertex3f(20, 12, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
		        	// Inicio - Segundo retangulo de cima para baixo do primeiro andar (direita)
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(19, 10, 12);
						glVertex3f(19, 8, 12);
						glVertex3f(20, 8, 12);
						glVertex3f(20, 10, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Segundo retangulo de cima para baixo do primeiro andar
		        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar (direita)
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(19, 8, 12);
						glVertex3f(20, 8, 12);
						glVertex3f(20, 6, 12);
						glVertex3f(19, 6, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
					// Inicio - Retângulo abaixo da janela do primeiro andadr (torre direita)
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(15, 8, 12);
						glVertex3f(19, 8, 12);
						glVertex3f(19, 6, 12);
						glVertex3f(15, 6, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
					// Fim - Janelas do andar inferior - torre à direita
					// Janelas do andar superior - torre à direita
					// Inicio - Retângulo lateral da primeira janela do segundo andar
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(20, 6, 12);
						glVertex3f(20, 6, 11);
						glVertex3f(20, 12, 11);
						glVertex3f(20, 12, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Retângulo lateral da primeira janela do segundo andar
		        	// Inicio - Retângulo abaixo das janelas (direita)
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(20, 8, 12);
						glVertex3f(20, 8, 0);
						glVertex3f(20, 6, 0);
						glVertex3f(20, 6, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Retângulo abaixo das janelas direita
		        	// Inicio - Retângulo acima das janelas (direita)
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(20, 12, 1);
						glVertex3f(20, 12, 0);
						glVertex3f(20, 6, 0);
						glVertex3f(20, 6, 1);
						glEnd();
				    glPopMatrix();
				    // Fim - Retângulo acima das janelas direta 
				    //Inicio - Retângulo entre as janelas
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(20, 12, 7);
						glVertex3f(20, 12, 6);
						glVertex3f(20, 6, 6);
						glVertex3f(20, 6, 7);
						glEnd();
				    glPopMatrix();				    
				    //Fim - Retângulo entre as janelas
		        	// Inicio - Retângulo acima das janelas direita
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(20, 8, 12);
						glVertex3f(20, 6, 12);
						glVertex3f(20, 6, 7);
						glVertex3f(20, 8, 7);
						glEnd();
				    glPopMatrix();		
					//Fim - Retângulo acima das janelas direita					        	
		        	// Inicio - Retângulo acima das janelas direita
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(20, 12, 12);
						glVertex3f(20, 12, 0);
						glVertex3f(20, 10, 0);
						glVertex3f(20, 10, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Segundo retangulo de cima para baixo do primeiro andar
		        	// Inicio - Teto da garagem
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(20, 6, 0);
						glVertex3f(20, 6, 12);
						glVertex3f(26, 6, 12);
						glVertex3f(26, 6, 0);
						glEnd();
				    glPopMatrix();
		        	// Fim - Teto da garagem
		        	// Inicio - Pilastra cilindrica
				/*	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_CYLINDER);
						glVertex3f(20, 6, 0);
						glVertex3f(20, 6, 12);
						glVertex3f(26, 6, 12);
						glVertex3f(26, 6, 0);
						glEnd();
				    glPopMatrix();*/   
				    
				    // Pilastra à esquerda
				    //glPushMatrix();
				    //glTranslatef(25.0, 6.0, 10.0);
				    //glRotatef(90,1,0,0);
					//discoC(0.2, 0.2, 6.0);
					//glPopMatrix();

					// Pilastra à esquerda
				    glPushMatrix();
				    glTranslatef(25.0, 6.0, 2.0);
				    glRotatef(90,1,0,0);
					discoC(0.2, 0.2, 6.0);
					glPopMatrix();

					
					//Cilindro utilizando dois quadrados				    
				/*    glPushMatrix();
				       glBegin(GL_QUAD_STRIP);
					   for (int j=0;j<=360;j+=1) {
					     glColor3f(1.0,1.0,0.0);
					     glVertex3f(Cos(j),0,Sin(j));
					     glColor3f(0.0,1.0,0.0);
					     glVertex3f(Cos(j),6,Sin(j)); // y-> altura
					   }
					   glEnd();
                     glPopMatrix();*/
					   
					// Fim - Pilastra cilindrica 	
		        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar (direita)
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(19, 8, 12);
						glVertex3f(20, 8, 12);
						glVertex3f(20, 6, 12);
						glVertex3f(19, 6, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
					// Inicio - Retângulo abaixo da janela do primeiro andadr (torre direita)
		        	glPushMatrix();
						glColor4f(1.0, 0.9, 0.7, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(15, 8, 12);
						glVertex3f(19, 8, 12);
						glVertex3f(19, 6, 12);
						glVertex3f(15, 6, 12);
						glEnd();
				    glPopMatrix();
		        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
											     	
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
	glutCreateWindow("Casa");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutMotionFunc(motion);
	Inicializa();
	glutMainLoop();
}