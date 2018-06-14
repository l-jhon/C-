
					//Mesa
					glPushMatrix();
						glColor4f(1.0, 0.4, 0.0, 1.0);
						glBegin(GL_QUADS);
						glVertex3f(9.3, 2, 0);
						glVertex3f(9.3, 2, 6);
						glVertex3f(15.5, 2, 6);
						glVertex3f(15.5, 2, 0);
						glEnd();
				    glPopMatrix();

					 // Pés da mesa
				    glPushMatrix();
				    glTranslatef(15.0, 2.0, 5.0);
				    glRotatef(90,1,0,0);
					discoC(0.1, 0.1, 2.0);
					glPopMatrix();

					// Pés da mesa
				    glPushMatrix();
				    glTranslatef(15.0, 2.0, 1.0);
				    glRotatef(90,1,0,0);
					discoC(0.1, 0.1, 2.0);
					glPopMatrix();


					// Pés da mesa
				    glPushMatrix();
				    glTranslatef(10.0, 2.0, 5.0);
				    glRotatef(90,1,0,0);
					discoC(0.1, 0.1, 2.0);
					glPopMatrix();

					// Pés da mesa
				    glPushMatrix();
				    glTranslatef(10.0, 2.0, 1.0);
				    glRotatef(90,1,0,0);
					discoC(0.1, 0.1, 2.0);
					glPopMatrix();