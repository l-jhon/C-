	#include <GL/glut.h>
	#define Cos(th) cos(PI/180*(th))
	#define Sin(th) sin(PI/180*(th))
	#define PI 3.1415926535898
	
	#include <iostream>
	#include <math.h>
	
	//GLfloat angle, fAspect;
	GLfloat ASPECTO, ANGULO;
	int x_ini,y_ini, bot;
	
    static double t = 0;
    static double a = 0;
    static double var = 0;
    static double braco_esquerdo = -90;
	static double braco_direito = 90;
	static double perna_direita = 0;

    bool fechar_janela = false;

	
	GLfloat obsX, obsY, obsZ, rotX, rotY;
	GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
	GLfloat escalaX, escalaY, escalaZ;
	#define SENS_ROT 10.0
	#define SENS_OBS 10.0
	#define SENS_TRANS 10.0   
		
		void capturarTecla(unsigned char key, int x, int y){
			if(key == 'd'){
								
				if(var == 0){
					fechar_janela = false;
				}
				
				if(!fechar_janela){
					if(var == -90){
						fechar_janela = true;
					}
					else{
						var -= 1;
					}
				}
				else{
					var += 1;
				}			
			}
			else{
				if(key=='q'){
		    		exit(0);
                    //break;
				}
			}
	}
	
	void discoC(GLfloat raioInf, GLfloat raioSup, GLfloat alt){
		GLUquadricObj* q = gluNewQuadric();
		gluQuadricDrawStyle(q, GLU_FILL);
		gluQuadricNormals(q, GLU_SMOOTH);
		gluQuadricTexture(q, GL_TRUE);
		gluCylinder(q, raioInf, raioSup, alt, 60,60);
		gluDeleteQuadric(q);
	}
	
// // Fun??o callback chamada para fazer o desenho
// void Desenha_Human(void){

// 	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// 	 //glClear(GL_COLOR_BUFFER_BIT);
          
// 	 	glPushMatrix(); //0
// 	 		//glTranslatef(25,0.25,0);
			
// 			// Início do Tronco inferior
//     		glPushMatrix();
// 				glTranslatef(0.0,-1.5,0.0);

//    	   	   	    glPushMatrix();//-------------------- 1

// 					glColor3f(1.0, 1.0, 1.0);
// 					glutSolidSphere(0.5,50.0,50.0); // Ponto G
// 					glPopMatrix();
	  	  
// 			        glBegin(GL_LINES);
// 				   	glVertex3f(-2.5, -4.0, 0.0);
// 				   	glVertex3f(-0.3, 0.0, 0.0);
// 			        glEnd();

					
// 				    glPushMatrix(); // Inicio perna esquerda
// 				    	glTranslatef(-2.0,-1.0,0); // Primeiro nó da perna esquerda

// 					    glPushMatrix();//-------------------- 1
// 				            glColor3f(0.0, 1.0, 0.0);
// 							//Primeira linha após o primeiro nó da perna esquerda		
// 							//glTranslatef(0.0,0.0,0.0);
// 				            glBegin(GL_LINES);
// 					    	glVertex3f(-0.5, -10, 0.0); 
// 					    	glVertex3f(-0.5, -3.0, 0.0);
// 				            glEnd();
				            
// 				            //Segundo nó da perna esquerda
// 					        glPushMatrix();
// 					        	glTranslatef(-0.5,-3,0.0);
// 					        	glutSolidSphere(0.5,50.0,50.0);        	
// 					        glPopMatrix(); 
					        
// 				            //antebra?o
// 				     		glPushMatrix(); //-------------------- 2
// 					      //       glBegin(GL_LINES);
// 						    	// glVertex3f(3.0, -20.0, 0.0);
// 						    	// glVertex3f(3.0, -30.0, 0.0);
// 					      //       glEnd();
					            
// 								//m?o
// 					            glPushMatrix();
// 						        	glColor3f(1.0, 0.0, 0.0);
// 						        	glTranslatef(-0.5,-10.0,0.0);
// 						        	glutSolidSphere(0.5,50.0,50.0);

// 						        	glPushMatrix();
// 						        		glColor3f(1.0, 0.0, 0.0);
// 						        		glTranslatef(-2.0,-1.0,0.0);
// 						        		glutSolidSphere(0.5,50.0,50.0);
// 						        	glPopMatrix();

// 						        glPopMatrix();
								 
// 				  	       glPopMatrix(); // 2
				          
// 					    glPopMatrix(); // 1

// 					glPopMatrix(); // Fim perna esquerda

// 					// glPushMatrix(); // Inicio perna direita
// 				 //    	glTranslatef(10,10,0); // Primeiro nó da perna direita

// 					//     glPushMatrix();//-------------------- 1
// 				 //            glColor3f(0.0, 1.0, 1.0);
// 					// 		//Primeira linha após o primeiro nó da perna direita		
// 					// 		glTranslatef(0.0,0.0,0.0);
// 				 //      //       glBegin(GL_LINES);
// 					//     	// glVertex3f(10.0, 10.0, 0.0);
// 					//     	// glVertex3f(3, -20.0, 0.0);
// 				 //      //       glEnd();
				            
// 				 //            //Segundo nó da perna direita
// 					//         glPushMatrix();
// 					//         	glTranslatef(3.0,-20.0,0.0);
// 					//         	glutSolidSphere(1.0,50.0,50.0);        	
// 					//         glPopMatrix(); 
					        
// 				 //            //antebra?o
// 				 //     		glPushMatrix(); //-------------------- 2
// 					//       //       glBegin(GL_LINES);
// 					// 	    	// glVertex3f(3.0, -20.0, 0.0);
// 					// 	    	// glVertex3f(3.0, -30.0, 0.0);
// 					//       //       glEnd();
					            
// 					// 			//m?o
// 					//             glPushMatrix();
// 					// 	        	glColor3f(1.0, 0.0, 0.0);
// 					// 	        	glTranslatef(3,-30.0,0.0);
// 					// 	        	glutSolidSphere(1.5,50.0,50.0);        	
// 					// 	        glPopMatrix();
								 
// 				 //  	       glPopMatrix(); // 2
				          
// 					//     glPopMatrix(); // 1

// 					// glPopMatrix(); // Fim perna direita

// 				glPopMatrix();

// 			glPopMatrix(); // Fim parte inferior

// 		glPopMatrix();
									
// 	glPopMatrix(); // 0
        
// 	glutSwapBuffers();
// }


	void Desenha_Human(void){

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 //glClear(GL_COLOR_BUFFER_BIT);
          
	 	glPushMatrix(); //0
	 		glScaled(0.1, 0.1, 0.1);
	 		glColor3f(1.0,0.0,0.0);
	 		glTranslatef(80,40,200);

 			// cabe?a
	 		glPushMatrix();//-------------------- 1
	            glColor3f(1.0, 1.0, 0.0); 
				glutSolidSphere(3.0,50.0,50.0);
				glTranslatef(0.0,-10.0,0.0);
				
	            glBegin(GL_LINES);
		    	glVertex3f(0.0, 0.0, 0.0);
		    	glVertex3f(0.0, 10.0, 0.0);
	            glEnd();


		 		// pesco?o
		 		glPushMatrix();//M10
		            glColor3f(1.0, 0.0, 0.0); 
					glutSolidSphere(1.0,50.0,50.0);
					
		            glBegin(GL_LINES);
			    	glVertex3f(0.0, 0.0, 0.0);
			    	glVertex3f(10.0, 0.0, 0.0);
		            glEnd();

		            glBegin(GL_LINES);
			    	glVertex3f(0.0, 0.0, 0.0);
			    	glVertex3f(-10.0, 0.0, 0.0);
		            glEnd();


			 		// In?cio Ombro Direito
			 		glPushMatrix();
						glTranslatef(10,0,0);

						glPushMatrix();//M9
				            glColor3f(0.0, 0.0, 1.0);
							//ombro 
							glutSolidSphere(1.5,50.0,50.0);
							
							
							//bra?o			
							glRotated(braco_esquerdo,0,0,1);
				            glBegin(GL_LINES);
					    	glVertex3f(0.0, 0.0, 0.0);
					    	glVertex3f(7.0, 0.0, 0.0);
				            glEnd();
				            
				            //cotovelo
					        glPushMatrix();//M8
					        	glTranslatef(7.0,0.0,0.0);
					        	glutSolidSphere(1.0,50.0,50.0);        	
					        glPopMatrix(); //M8
					        
				            //antebra?o
				     		glPushMatrix(); //M7
					            glTranslatef(7.0,0.0,0.0);
								glRotated(-10,0,0,1);
					            glBegin(GL_LINES);
						    	glVertex3f(0.0, 0.0, 0.0);
						    	glVertex3f(7.0, 0.0, 0.0);
					            glEnd();
					            
								//m?o
					            glPushMatrix(); //M6
						        	glColor3f(1.0, 0.0, 0.0);
						        	glTranslatef(7.0,0.0,0.0);
						        	glutSolidSphere(1.0,50.0,50.0);        	
						        glPopMatrix();//M6
								 
				  	       glPopMatrix(); // M7
				          
					    glPopMatrix(); // M9

					glPopMatrix();//M10 
					// Fim do Ombro Direito

				    // In?cio do Ombro Esquerdo
				    glPushMatrix();//M5
				    	glTranslatef(-10,0,0);

					    glPushMatrix();// M4
				            glColor3f(1.0, 1.0, 0.0);
							//ombro Esquerdo
							glutSolidSphere(1.5,50.0,50.0);
							
							
							//bra?o			
							glRotated(braco_direito,0,0,1);
				            glBegin(GL_LINES);
					    	glVertex3f(0.0, 0.0, 0.0);
					    	glVertex3f(-7.0, 0.0, 0.0);
				            glEnd();
				            
				            //cotovelo
					        glPushMatrix(); // M3
					        	glTranslatef(-7.0,0.0,0.0);
					        	glutSolidSphere(1.0,50.0,50.0);        	
					        glPopMatrix(); // M3
					        
				            //antebra?o
				     		glPushMatrix(); //M2
					            glTranslatef(-7.0,0.0,0.0);
								glRotated(10,0,0,1);
					            glBegin(GL_LINES);
						    	glVertex3f(0.0, 0.0, 0.0);
						    	glVertex3f(-7.0, 0.0, 0.0);
					            glEnd();
					            
								//m?o
					            glPushMatrix(); // M1
						        	glColor3f(1.0, 0.0, 0.0);
						        	glTranslatef(-7.0,0.0,0.0);
						        	glutSolidSphere(1.0,50.0,50.0);        	
						        glPopMatrix(); // M1
								 
				  	       glPopMatrix(); // M2
				          
					    glPopMatrix(); // M4

					glPopMatrix();//M5
					// Fim do Ombro Esquerdo

				glPopMatrix(); // pesco?o

			glPopMatrix(); // cabe?a
			
			// Início do Tronco inferior
    		glPushMatrix();
				glTranslatef(0.0,-20.0,0.0);

   	   	   	    glPushMatrix();//-------------------- 1

			      glColor3f(1.0, 1.0, 1.0);
				  //ombro direito
				  glutSolidSphere(1.5,50.0,50.0);
				  glPopMatrix();
	  	  
					//bra?o			
					//glRotated(braco_direito,1,0,0);
			        glBegin(GL_LINES);
				   	glVertex3f(0.0, 0.0, 0.0);
				   	glVertex3f(0.0, 10.0, 0.0);
			        glEnd();

			        glBegin(GL_LINES);
				   	glVertex3f(0.0, 0.0, 0.0);
				   	glVertex3f(0.0, 10.0, 0.0);
			        glEnd();

					
				    glPushMatrix(); // Inicio perna esquerda
				    	glTranslatef(-10,10,0); // Primeiro nó da perna esquerda

					    glPushMatrix();//-------------------- 1
				            glColor3f(0.0, 1.0, 0.0);
							//Primeira linha após o primeiro nó da perna esquerda		
							glTranslatef(0.0,0.0,0.0);
				            glBegin(GL_LINES);
					    	glVertex3f(10.0, -10.0, 0.0);
					    	glVertex3f(3, -20.0, 0.0);
				            glEnd();
				            
				            //Segundo nó da perna esquerda
					        glPushMatrix();
					        	glTranslatef(3.0,-20.0,0.0);
					        	glutSolidSphere(1.0,50.0,50.0);        	
					        glPopMatrix(); 
					        
				            //antebra?o
				     		glPushMatrix(); //-------------------- 2
					            glBegin(GL_LINES);
						    	glVertex3f(3.0, -20.0, 0.0);
						    	glVertex3f(3.0, -30.0, 0.0);
					            glEnd();
					            
								//m?o
					            glPushMatrix();
						        	glColor3f(1.0, 0.0, 0.0);
						        	glTranslatef(3,-30.0,0.0);
						        	glutSolidSphere(1.5,50.0,50.0);        	
						        glPopMatrix();
								 
				  	       glPopMatrix(); // 2
				          
					    glPopMatrix(); // 1
					     
					// glPopMatrix(); // 1 // Fim perna esquerda

				 //    glPushMatrix(); // Inicio perna direita
				 //    	glTranslatef(-10,10.0,0); // Primeiro nó da perna direita

					//     glPushMatrix();//-------------------- 1
				 //            glColor3f(0.0, 1.0, 0.0);
					// 		//Primeira linha após o primeiro nó da perna direita		
					// 		glTranslatef(0,0.0,0.0);
				 //            glBegin(GL_LINES);
					//     	glVertex3f(10.0, 10.0, 0.0);
					//     	glVertex3f(3, 20.0, 0.0);
				 //            glEnd();
				            
				 //            //Segundo nó da perna direita
					//         glPushMatrix();
					//         	glTranslatef(3.0,20.0,0.0);
					//         	glutSolidSphere(1.0,50.0,50.0);        	
					//         glPopMatrix(); 
				          
					//     glPopMatrix(); // 1
					     
					// glPopMatrix(); // 1

				glPopMatrix();// Fim do Tronco inferior							
						
			glPopMatrix();
			// Fim do Ombro Direto
									
	    glPopMatrix(); // 0
        
	glutSwapBuffers();
}

	// Fun??o callback chamada para fazer o desenho
	void Desenha(void)
	{
		// Limpa a janela e o depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		 glClear(GL_COLOR_BUFFER_BIT);
	   //  glRotated(a,0,1,0);
			// Parede externa lateral ? esquerda 
			glPushMatrix();

				glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(0, 0, 0);
					glVertex3f(0, 6, 0);
					glVertex3f(0, 6, 12);
					glVertex3f(0, 0, 12);
					glEnd();
		        glPopMatrix();
			
				// Parte de cima da parede externa lateral ? esquerda
				glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
					glBegin(GL_QUADS);
					glVertex3f(0, 6, 0);
					glVertex3f(0, 6, 12);
					glVertex3f(0, 12, 12);
					glVertex3f(0, 12, 0);
					glEnd();
		        glPopMatrix();
		        
		        // Se??o relativa ? parede da frente mais da torre esquerda da casa
				// Parede da frente do primeiro andar
					// Terceiro retangulo (de baixo para cima) ao lado esquerdo da janela
					glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(0, 0, 12);
						glVertex3f(1, 0, 12);
						glVertex3f(1, 2, 12);
						glVertex3f(0, 2, 12);
						glEnd();
			        glPopMatrix();
			        
	    
	    			// ---- BULE --- 
					glPushMatrix();
						glTranslatef(12,2.4,5.0);
						glutSolidTeapot(.5);
						glFlush();
					glPopMatrix();
			        			//--------------------------------------- MESA --------------------------------------
		
							//Mesa
							glPushMatrix();
								glColor3f(1.0, 0.4, 0.0);
								glBegin(GL_QUADS);
								glVertex3f(9.3, 2, 0);
								glVertex3f(9.3, 2, 6);
								glVertex3f(15.5, 2, 6);
								glVertex3f(15.5, 2, 0);
								glEnd();
						    glPopMatrix();
		
							 // Pés da mesa
						    glPushMatrix();
						    glColor3f(1.0, 0.4, 0.0);
						    glTranslatef(15.0, 2.0, 5.0);
						    glRotatef(90,1,0,0);
							discoC(0.1, 0.1, 2.0);
							glPopMatrix();
		
							// Pés da mesa
						    glPushMatrix();
						    glColor3f(1.0, 0.4, 0.0);
						    glTranslatef(15.0, 2.0, 1.0);
						    glRotatef(90,1,0,0);
							discoC(0.1, 0.1, 2.0);
							glPopMatrix();
		
		
							// Pés da mesa
						    glPushMatrix();
						    glColor3f(1.0, 0.4, 0.0);
						    glTranslatef(10.0, 2.0, 5.0);
						    glRotatef(90,1,0,0);
							discoC(0.1, 0.1, 2.0);
							glPopMatrix();
		
							// Pés da mesa
						    glPushMatrix();
						    glColor3f(1.0, 0.4, 0.0);
						    glTranslatef(10.0, 2.0, 1.0);
						    glRotatef(90,1,0,0);
							discoC(0.1, 0.1, 2.0);
							glPopMatrix();
			        
			        //-------------------- Desenho das Janelas e porta -------------------------
					
		
						
						//Frente da casa Janela Superior Lado Direito
					glPushMatrix();
						glTranslated(15, 8, 12);
						glRotated(var, 0, 1, 0);
			        	glColor4f(1.0, 1.0, 0.9, 0.5);
			        	glBegin(GL_QUADS);
			        	glVertex3f(0, 0, 0);
			        	glVertex3f(0, 2, 0);
			        	glVertex3f(4, 2, 0);
			        	glVertex3f(4, 0, 0);
			        	glEnd();
			        glPopMatrix();
			        
			        //Frente da casa Janela superior esquerda.
			        glPushMatrix();
			        	glTranslated(15, 2, 12);
			        	glRotated(var, 0, 1, 0);
			        	glColor4f(1.0, 1.0, 0.9, 0.5);
			        	glBegin(GL_QUADS);
			        	glVertex3f(0, 0, 0);
			        	glVertex3f(0, 2, 0);
			        	glVertex3f(4, 2, 0);
			        	glVertex3f(4, 0, 0);
			        	glEnd();
					 glPopMatrix();
			        
			        	//Frente da casa janela esquerda inferior.
					glPushMatrix();
						glTranslated(1, 2, 12);
						glRotated(var, 0, 1, 0);
			        	glColor4f(1.0, 1.0, 0.9, 0.5);
			        	glBegin(GL_QUADS);
			        	glVertex3f(0, 0, 0);
			        	glVertex3f(0, 2, 0);
			        	glVertex3f(4, 2, 0);
			        	glVertex3f(4, 0, 0);	        	
			        	glEnd();
			        glPopMatrix();
			        
			        	//Frente da casa janela esquerda superior.
					glPushMatrix();
						glTranslated(1, 8, 12);
						glRotated(var, 0, 1, 0);
			        	glColor4f(1.0, 1.0, 0.9, 0.5);
			        	glBegin(GL_QUADS);
			        	glVertex3f(0, 0, 0);
			        	glVertex3f(0, 2, 0);
			        	glVertex3f(4, 2, 0);
			        	glVertex3f(4, 0, 0);	        	
			        	glEnd();
			        glPopMatrix();	        
					
					//Lado direto da casa janela esquerda inferior.
					glPushMatrix();			
						glTranslated(20, 2, 7);
						glRotated(var,0, 1, 0);
						glColor4f(1.0, 1.0, 0.9, 0.5);
			        	glBegin(GL_QUADS);
			        	glVertex3f(0, 0, 4);
			        	glVertex3f(0, 2, 4);
			        	glVertex3f(0, 2, 0);
			        	glVertex3f(0, 0, 0);
			        	glEnd();
			        glPopMatrix();
					
					//Lado direto da casa janela Direita inferior.
					glPushMatrix();
						glTranslated(20, 2, 1);
						glRotated(var,0, 1, 0);
			        	glColor4f(1.0, 1.0, 0.9, 0.5);
			        	glBegin(GL_QUADS);
			        	glVertex3f(0, 0, 5);
			        	glVertex3f(0, 2, 5);
			        	glVertex3f(0, 2, 0);
			        	glVertex3f(0, 0, 0);
			        	glEnd();
			        glPopMatrix();
					
						//Lado direto da casa janela esquerda superior.
					glPushMatrix();
			            glTranslated(20, 8, 7);
						glRotated(var,0, 1, 0);
			        	glColor4f(1.0, 1.0, 0.9, 0.5);
			        	glBegin(GL_QUADS);
			        	glVertex3f(0, 0, 4);
			        	glVertex3f(0, 2, 4);
			        	glVertex3f(0, 2, 0);
			        	glVertex3f(0, 0, 0);
			        	glEnd();
			        glPopMatrix();
									
					//Lado direto da casa janela direita superior.
					glPushMatrix();
					//glutSolidSphere(5, 5, 5);
					//glTranslated(20, 8, 1);
					//glRotated(var, 0, 1, 0);
					//glutSolidSphere(5, 5, 5);
						glTranslated(20, 8, 1);
						glRotated(var,0, 1, 0);
			        	glColor4f(1.0, 1.0, 0.9, 0.5);
			        	glBegin(GL_QUADS);
			        	glVertex3f(0, 0, 5);
			        	glVertex3f(0, 2, 5);
			        	glVertex3f(0, 2, 0);
			        	glVertex3f(0, 0, 0);
			        	glEnd();
			        glPopMatrix();		
				
					
						//Porta
					glPushMatrix();
						glTranslated(9, 0, 12);
						glRotated(var, 0, 1, 0);
			        	glColor3f(0.8, 0.7, 0.6);
			        	glBegin(GL_QUADS);
			        	glVertex3f(0, 0, 0);
			        	glVertex3f(0, 3, 0);
			        	glVertex3f(2, 3, 0);
			        	glVertex3f(2, 0, 0);
			        	glEnd();
			        glPopMatrix();	
			        
			        
					
					//---------------------Fim Janelas e Porta--------------------------					  	        	
			        	
			        
					// Segundo retangulo (de baixo para cima) ao lado esquerdo da janela
					glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(0, 2, 12);
						glVertex3f(1, 2, 12);
						glVertex3f(1, 4, 12);
						glVertex3f(0, 4, 12);
						glEnd();
			        glPopMatrix();        
			       
			        
		            // Primeiro retangulo (de baixo para cima) ao lado esquerdo da janela
					glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(0, 4, 12);
						glVertex3f(1, 4, 12);
						glVertex3f(1, 6, 12);
						glVertex3f(0, 6, 12);
						glEnd();
			        glPopMatrix();
					
					// Retangulo sobre a janela do primeiro andar
		            glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(1, 6, 12);
						glVertex3f(1, 4, 12);
						glVertex3f(5, 4, 12);
						glVertex3f(5, 6, 12);
						glEnd();
			        glPopMatrix();
			        
		            // Primeiro retangulo (de baixo para cima) ao lado direito da janela
					glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(5, 6, 12);
						glVertex3f(6, 6, 12);
						glVertex3f(6, 4, 12);
						glVertex3f(5, 4, 12);
						glEnd();
			        glPopMatrix();
		
					// Segundo retangulo (de baixo para cima) ao lado direito da janela
					glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(5, 4, 12);
						glVertex3f(6, 4, 12);
						glVertex3f(6, 2, 12);
						glVertex3f(5, 2, 12);
						glEnd();
			        glPopMatrix();
			        
		   			// Terceiro retangulo (de baixo para cima) ao lado direito da janela
					glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(5, 2, 12);
						glVertex3f(6, 2, 12);
						glVertex3f(6, 0, 12);
						glVertex3f(5, 0, 12);
						glEnd();
			        glPopMatrix();
			        
		            // Retangulo debaixo da janela do primeiro andar
					glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
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
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(0, 6, 12);
						glVertex3f(1, 6, 12);
						glVertex3f(1, 8, 12);
						glVertex3f(0, 8, 12);
						glEnd();
			        glPopMatrix();
			        
		            // Segundo retangulo (de baixo para cima) ao lado esquerdo da janela
					glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(0, 8, 12);
						glVertex3f(0, 10, 12);
						glVertex3f(1, 10, 12);
						glVertex3f(1, 8, 12);
						glEnd();
			        glPopMatrix();  
					
					
				    // Primeiro retangulo (de baixo para cima) ao lado esquerdo da janela
					glPushMatrix();
						glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(0, 10, 12);
						glVertex3f(0, 12, 12);
						glVertex3f(1, 12, 12);
						glVertex3f(1, 10, 12);
						glEnd();
			        glPopMatrix();     
					
					 // Retangulo debaixo da janela do primeiro andar
					glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(1, 6, 12);
						glVertex3f(1, 8, 12);
						glVertex3f(5, 8, 12);
						glVertex3f(5, 6, 12);
						glEnd();
			        glPopMatrix();
			        
			        // Primeiro retangulo(de cima para baixo) ao lado direito da janela
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(5, 12, 12);
						glVertex3f(6, 12, 12);
						glVertex3f(6, 10, 12);
						glVertex3f(5, 10, 12);
						glEnd();
			        glPopMatrix();
			        
			        // Segundo retangulo(de cima para baixo) ao lado direito da janela
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(5, 10, 12);
						glVertex3f(6, 10, 12);
						glVertex3f(6, 8, 12);
						glVertex3f(5, 8, 12);
						glEnd();
			        glPopMatrix();
			        
		            // Terceiro retangulo(de cima para baixo) ao lado direito da janela
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(5, 8, 12);
						glVertex3f(6, 8, 12);
						glVertex3f(6, 6, 12);
						glVertex3f(5, 6, 12);
						glEnd();
			        glPopMatrix();
			        
		   			// Retangulo acima da janela do primeiro andar
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(1, 12, 12);
						glVertex3f(5, 12, 12);
						glVertex3f(5, 10, 12);
						glVertex3f(1, 10, 12);
						glEnd();
			        glPopMatrix();
			        // FIM - Parede da frente do segundo andar
			        // INICIO - Parede de tr?s (torre ? esquerda)
					glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(6, 0, 0);
						glVertex3f(6, 12, 0);
						glVertex3f(0, 12, 0);
						glVertex3f(0, 0, 0);
						glEnd();
			        glPopMatrix();
			        // FIM - Parede de tr?s (torre ? esquerda)
			        // INICIO - Retangulo da parede direita (torre ? esquerda)
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(6, 12, 12);
						glVertex3f(6, 12, 0);
						glVertex3f(6, 6, 0);
						glVertex3f(6, 6, 12);
						glEnd();
			        glPopMatrix();
			        // FIM - Retangulo da parede direita (torre ? esquerda)
			        // INICIO - Retangulo do teto do c?modo entre as torres
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(6, 6, 0);
						glVertex3f(6, 6, 12);
						glVertex3f(14, 6, 12);
						glVertex3f(14, 6, 0);
						glEnd();
			        glPopMatrix();
			        // FIM - Retangulo do teto do c?modo entre as torres
			        // INICIO - Quadrado parede de tr?s do c?modo entre as torres
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(14, 6, 0);
						glVertex3f(6, 6, 0);
						glVertex3f(6, 0, 0);
						glVertex3f(14, 0, 0);
						glEnd();
			        glPopMatrix();
			        // FIM - Quadrado parede de tr?s do c?modo entre as torres
			        // INICIO - Retangulo superior da parede ? direita do c?modo entre as torres
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(14, 12, 0);
						glVertex3f(14, 12, 12);
						glVertex3f(14, 6, 12);
						glVertex3f(14, 6, 0);
						glEnd();
			        glPopMatrix();
			        // FIM - Retangulo superior da parede ? direita do c?modo entre as torres
			        // INICIO - Ret?ngulo da parede de tr?s da torre ? direita
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(14, 12, 0);
						glVertex3f(20, 12, 0);
						glVertex3f(20, 0, 0);
						glVertex3f(14, 0, 0);
						glEnd();
			        glPopMatrix();
			        // FIM - Ret?ngulo da parede de tr?s da torre ? direita
			        // INICIO - Ret?ngulo da parede ? esquerda da porta
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(6, 6, 12);
						glVertex3f(6, 0, 12);
						glVertex3f(9, 0, 12);
						glVertex3f(9, 6, 12);
						glEnd();
			        glPopMatrix();
			        // FIM - Ret?ngulo da parede ? esquerda da porta
			        // INICIO - Ret?ngulo da parede acima da porta
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(9, 6, 12);
						glVertex3f(11, 6, 12);
						glVertex3f(11, 3, 12);
						glVertex3f(9, 3, 12);
						glEnd();
			        glPopMatrix();
			        // FIM - Ret?ngulo da parede acima da porta
			        // INICIO - Ret?ngulo da parede ? direita da porta
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(11, 6, 12);
						glVertex3f(14, 6, 12);
						glVertex3f(14, 0, 12);
						glVertex3f(11, 0, 12);
						glEnd();
			        glPopMatrix();
			        // FIM - Ret?ngulo da parede acima da porta
			        // INICIO - Teto da torre ? direita
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(14, 12, 0);
						glVertex3f(20, 12, 0);
						glVertex3f(20, 12, 12);
						glVertex3f(14, 12, 12);
						glEnd();
			        glPopMatrix();
			        // FIM - Teto da torre ? direita
			       /* // INICIO - Parede direita da torre ? direita
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(20, 12, 12);
						glVertex3f(20, 12, 0);
						glVertex3f(20, 0, 0);
						glVertex3f(20, 0, 12);
						glEnd();
			        glPopMatrix();
			        // FIM - Parede direita da torre ? direita*/
			        // INICIO - Retangulo superior da janela da torre direita na parede lateral
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
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
					glColor4f(0.0, 0.0, 0.0, 1.0);
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
					glColor4f(0.0, 0.0, 0.0, 1.0);
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
					glColor4f(0.0, 0.0, 0.0, 1.0);
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
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(20, 2, 7);
						glVertex3f(20, 0, 7);
						glVertex3f(20, 0, 12);
						glVertex3f(20, 2, 12);
						glEnd();
			        glPopMatrix();	   
					// FIM - Retangulo inferior da primeira janela da torre direita na parede lateral									
			        // INICIO - Teto da torre ? esquerda
			        glPushMatrix();
					glColor4f(0.0, 0.0, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(0, 12, 0);
						glVertex3f(6, 12, 0);
						glVertex3f(6, 12, 12);
						glVertex3f(0, 12, 12);
						glEnd();
			        glPopMatrix();
			        // FIM - Teto da torre ? esquerda
			        // Inicio parede do primeiro andar da torre ? direita
			        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar
			        	glPushMatrix();
							glColor4f(0.0, 0.0, 0.0, 1.0);
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
							glColor4f(0.0, 0.0, 0.0, 1.0);
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
							glColor4f(0.0, 0.0, 0.0, 1.0);
							glBegin(GL_QUADS);
							glVertex3f(14, 4, 12);
							glVertex3f(15, 4, 12);
							glVertex3f(15, 6, 12);
							glVertex3f(14, 6, 12);
							glEnd();
					    glPopMatrix();
			        	// Fim - Primeiro retangulo de cima para baixo do primeiro andar
			        	// Inicio - Ret?ngulo acima da janela do primeiro andar
			        	glPushMatrix();
							glColor4f(0.0, 0.0, 0.0, 1.0);
							glBegin(GL_QUADS);
							glVertex3f(15, 4, 12);
							glVertex3f(15, 6, 12);
							glVertex3f(19, 6, 12);
							glVertex3f(19, 4, 12);
							glEnd();
					    glPopMatrix();
			        	// Fim - Ret?ngulo acima da janela do primeiro andar 
			        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar (direita)
			        	glPushMatrix();
							glColor4f(0.0, 0.0, 0.0, 1.0);
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
							glColor4f(0.0, 0.0, 0.0, 1.0);
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
							glColor4f(0.0, 0.0, 0.0, 1.0);
							glBegin(GL_QUADS);
							glVertex3f(19, 2, 12);
							glVertex3f(20, 2, 12);
							glVertex3f(20, 0, 12);
							glVertex3f(19, 0, 12);
							glEnd();
					    glPopMatrix();
			        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
						// Inicio - Ret?ngulo abaixo da janela do primeiro andadr (torre direita)
			        	glPushMatrix();
							glColor4f(0.0, 0.0, 0.0, 1.0);
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
							glColor3f(0.9, 0.8, 0.8);
							glBegin(GL_QUADS);
							glVertex3f(0, 0, 0);
							glVertex3f(20, 0, 0);
							glVertex3f(20, 0, 12);
							glVertex3f(0, 0, 12);
							glEnd();
					    glPopMatrix();
			        	// Fim - Piso primeiro andar
					// Janela do segundo andar da torre ? direita
			        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar
			        	glPushMatrix(); 
							glColor4f(0.0, 0.0, 0.0, 1.0);
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
							glColor4f(0.0, 0.0, 0.0, 1.0);
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
							glColor4f(0.0, 0.0, 0.0, 1.0);
							glBegin(GL_QUADS);
							glVertex3f(14, 8, 12);
							glVertex3f(15, 8, 12);
							glVertex3f(15, 6, 12);
							glVertex3f(14, 6, 12);
							glEnd();
					    glPopMatrix();
			        	// Fim - Primeiro retangulo de cima para baixo do primeiro andar
			        	// Parte relativa ?s janelas da parede lateral da torre
			        		// Janelas da parte inferior
				        	// Inicio - Ret?ngulo acima da janela do primeiro andar
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(15, 12, 12);
								glVertex3f(19, 12, 12);
								glVertex3f(19, 10, 12);
								glVertex3f(15, 10, 12);
								glEnd();
						    glPopMatrix();
				        	// Fim - Ret?ngulo acima da janela do primeiro andar 
				        	// Inicio - Terceiro retangulo de cima para baixo do primeiro andar (direita)
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
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
								glColor4f(0.0, 0.0, 0.0, 1.0);
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
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(19, 8, 12);
								glVertex3f(20, 8, 12);
								glVertex3f(20, 6, 12);
								glVertex3f(19, 6, 12);
								glEnd();
						    glPopMatrix();
				        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
							// Inicio - Ret?ngulo abaixo da janela do primeiro andadr (torre direita)
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(15, 8, 12);
								glVertex3f(19, 8, 12);
								glVertex3f(19, 6, 12);
								glVertex3f(15, 6, 12);
								glEnd();
						    glPopMatrix();
				        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
							// Fim - Janelas do andar inferior - torre ? direita
							// Janelas do andar superior - torre ? direita
							// Inicio - Ret?ngulo lateral da primeira janela do segundo andar
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(20, 6, 12);
								glVertex3f(20, 6, 11);
								glVertex3f(20, 12, 11);
								glVertex3f(20, 12, 12);
								glEnd();
						    glPopMatrix();
				        	// Fim - Ret?ngulo lateral da primeira janela do segundo andar
				        	// Inicio - Ret?ngulo abaixo das janelas (direita)
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(20, 8, 12);
								glVertex3f(20, 8, 0);
								glVertex3f(20, 6, 0);
								glVertex3f(20, 6, 12);
								glEnd();
						    glPopMatrix();
				        	// Fim - Ret?ngulo abaixo das janelas direita
				        	// Inicio - Ret?ngulo acima das janelas (direita)
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(20, 12, 1);
								glVertex3f(20, 12, 0);
								glVertex3f(20, 6, 0);
								glVertex3f(20, 6, 1);
								glEnd();
						    glPopMatrix();
						    
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(20, 6, 1);
								glVertex3f(20, 6, 0);
								glVertex3f(20, 0, 0);
								glVertex3f(20, 0, 1);
								glEnd();
						    glPopMatrix();
												    
						    // Fim - Ret?ngulo acima das janelas direta 
						    //Inicio - Ret?ngulo entre as janelas
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(20, 12, 7);
								glVertex3f(20, 12, 6);
								glVertex3f(20, 6, 6);
								glVertex3f(20, 6, 7);
								glEnd();
						    glPopMatrix();				    
						    //Fim - Ret?ngulo entre as janelas
				        	// Inicio - Ret?ngulo acima das janelas direita
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(20, 8, 12);
								glVertex3f(20, 6, 12);
								glVertex3f(20, 6, 7);
								glVertex3f(20, 8, 7);
								glEnd();
						    glPopMatrix();		
							//Fim - Ret?ngulo acima das janelas direita					        	
				        	// Inicio - Ret?ngulo acima das janelas direita
				        	glPushMatrix();
								glColor4f(0.0, 0.0, 0.0, 1.0);
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
								glColor3f(1.0, 0.6, 0.1);
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
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_CYLINDER);
								glVertex3f(20, 6, 0);
								glVertex3f(20, 6, 12);
								glVertex3f(26, 6, 12);
								glVertex3f(26, 6, 0);
								glEnd();
						    glPopMatrix();*/   
						    
						    // Pilastra ? esquerda
						    glPushMatrix();
						    glTranslatef(25.0, 6.0, 10.0);
						    glRotatef(90,1,0,0);
							discoC(0.2, 0.2, 6.0);
							glPopMatrix();
		
							// Pilastra ? esquerda
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
								glColor4f(0.0, 0.0, 0.0, 1.0);
								glBegin(GL_QUADS);
								glVertex3f(19, 8, 12);
								glVertex3f(20, 8, 12);
								glVertex3f(20, 6, 12);
								glVertex3f(19, 6, 12);
								glEnd();
						    glPopMatrix();
				        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar
							// Inicio - Ret?ngulo abaixo da janela do primeiro andadr (torre direita)
				        	glPushMatrix();
								glColor3f(1.0, 0.9, 0.7);
								glBegin(GL_QUADS);
								glVertex3f(15, 8, 12);
								glVertex3f(19, 8, 12);
								glVertex3f(19, 6, 12);
								glVertex3f(15, 6, 12);
								glEnd();

								Desenha_Human();

						    glPopMatrix();


				glPopMatrix();        	// Fim - Terceiro retangulo de cima para baixo do primeiro andar


		    glutSwapBuffers(); // 
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
	    a = t*90.0; //angulo randomico
	    glutPostRedisplay();
	}		
			
	// Programa Principal
	int main(int argc, char *argv[])
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInit(&argc, argv);
		glutInitWindowSize(600,600);
		glutCreateWindow("Casa"); 
		glEnable( GL_BLEND ); 
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glClearColor(0.0,0.0,0.0,0.0); 
		glutDisplayFunc(Desenha);
	    glutReshapeFunc(AlteraTamanhoJanela);
		glutMouseFunc(GerenciaMouse);
		glutMotionFunc(motion);
		glutIdleFunc(idle);
		glutKeyboardFunc(capturarTecla);
		Inicializa();
		glutMainLoop();
	}