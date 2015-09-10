 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif
/*GETPID*/
#include <sys/types.h> 
#include <unistd.h>
/*------*/
#include "cena.h"
#include "RgbImage.h"
RgbImage imag;
#include "drawObjects.cpp"
#include "boneco.cpp"
#include "glm.cpp"



//================================================================================
//=========================================================================== INIT
 

  char texto[30];
  
  
  GLMmodel* pmodel;
  GLMmodel* grelha;
  GLMmodel* ball;
  GLMmodel* arvore;
 

void draw_cross(float x,float y, float z, float x_2,float y_2, float z_2){

	glPushMatrix();	
	glTranslatef( x, y, z);
	//glPushMatrix();
	glRotatef(90,0,1,0);
	glRotatef(180,0,0,1);
	//glPopMatrix();
	glScalef(x_2,y_2,z_2);
	if (!pmodel) {
		pmodel = glmReadOBJ("cross.obj");
		if (!pmodel) 
			exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);


	}
		glmDraw(pmodel, GLM_SMOOTH);
		glPopMatrix();

	}
	void draw_gamebase(float x,float y, float z, float x_2,float y_2, float z_2){
	
	glPushMatrix();	
	glTranslatef( x, y, z);
	//glPushMatrix();
	glRotatef(90,0,1,0);
	glRotatef(180,0,0,1);
	//glPopMatrix();
	glScalef(x_2,y_2,z_2);
	if (!grelha) {
		grelha = glmReadOBJ("gamebase.obj");
		if (!grelha) 
			exit(0);
	glmUnitize(grelha);
	glmFacetNormals(grelha);
	glmVertexNormals(grelha, 90.0);
	
	
	}
		glmDraw(grelha, GLM_SMOOTH);
		glPopMatrix();
	
	}
	void draw_ball(float x,float y, float z, float x_2,float y_2, float z_2){
	
	glPushMatrix();	
	glTranslatef( x, y, z);
	//glPushMatrix();
	glRotatef(90,0,1,0);
	glRotatef(180,0,0,1);
	//glPopMatrix();
	glScalef(x_2,y_2,z_2);
	if (!ball) {
		ball = glmReadOBJ("b.obj");
		if (!ball) 
			exit(0);
	glmUnitize(ball);
	glmFacetNormals(ball);
	glmVertexNormals(ball, 90.0);
	
	
	}
		glmDraw(ball, GLM_SMOOTH);
		glPopMatrix();
	
	}
	
	void drawArvore(float x,float y, float z, float x_2,float y_2, float z_2){
	
	glPushMatrix();	
	glTranslatef( x, y, z);
	//glPushMatrix();
	//glRotatef(90,0,1,0);
	//glRotatef(180,0,0,1);
	//glPopMatrix();
	glScalef(x_2,y_2,z_2);
	if (!arvore) {
		arvore= glmReadOBJ("arvore.obj");
		if (!arvore) 
			exit(0);
	glmUnitize(arvore);
	glmFacetNormals(arvore);
	glmVertexNormals(arvore, 90.0);
	
	
	}
		glmDraw(arvore, GLM_SMOOTH);
		glPopMatrix();
	
	}
	
 void desenhaTexto(char *string, GLfloat x, GLfloat y,GLfloat z) 
 {  
 	glRasterPos3f(x,y,z); 
 	while (*string)
 		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++); 
 }
 void desenhavencedor(char *string, GLfloat x, GLfloat y,GLfloat z) 
  {  
 	glColor4f(AMARELO);
  	glRasterPos3f(x,y,z); 
  	while (*string)
  		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++); 
  }
 
 
 

void drawScene(){
	glColor3f(0,0,0.97);
	sprintf(texto, "x = %lf", obsPini[0]);
	desenhaTexto(texto, -28.6, 14,6);
	sprintf(texto, "y = %lf", obsPini[1]);
	desenhaTexto(texto, -28.6, 13,6);
	sprintf(texto, "z = %lf", obsPini[2]);
	desenhaTexto(texto, -28.6, 12,6);
	
	if (colorM){
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //(Face,Mode) //possibilities: ambient, difuse, specular, emission
		glEnable(GL_LIGHTING);
	}
	else{
		glDisable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING);
		initLights();	
	}
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~esfera-ceu
    
    if(noite){		//noite
		glEnable(GL_TEXTURE_2D);		
		glBindTexture(GL_TEXTURE_2D,texture[5]);	
		glPushMatrix();
			glRotatef (100, 0, 0, 1);		
			esfera1(60,60,60);	
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		 
	}else{		//dia
		glEnable(GL_TEXTURE_2D);		
		glBindTexture(GL_TEXTURE_2D,texture[0]);	
		glPushMatrix();			
			glRotatef (100, 0, 0, 1);		
			esfera1(60,60,60);	
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);	
	}
	
	if(rain){
		/*DESENHA AS PARTICULAS DA CHUVA*/
		int i;
		for(i=0;i<NUMEROPARTICULAS;i++){
			
			
			int j;
			for(j=0;j<5;j++){
				GLUquadric* quadric;
				glPushMatrix();
					glTranslatef(chuva[i].x,chuva[i].y,chuva[i].z-chuva[i].espacamento);
					glScalef(0.05,0.2,0.05);
					quadric=gluNewQuadric();
					glColor3f(0.1,0.1,0.1);		
					gluSphere(quadric,0.5,12,12);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(chuva[i].x,chuva[i].y,chuva[i].z+chuva[i].espacamento);
					glScalef(0.05,0.2,0.05);
					quadric=gluNewQuadric();
					glColor3f(0.1,0.1,0.1);		
					gluSphere(quadric,0.5,12,12);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(chuva2[i].x,chuva2[i].y,chuva2[i].z-chuva2[i].espacamento);
					glScalef(0.05,0.2,0.05);
					quadric=gluNewQuadric();
					glColor3f(0.1,0.1,0.1);		
					gluSphere(quadric,0.5,12,12);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(chuva2[i].x,chuva2[i].y,chuva2[i].z+chuva2[i].espacamento);
					glScalef(0.05,0.2,0.05);
					quadric=gluNewQuadric();
					glColor3f(0.1,0.1,0.1);		
					gluSphere(quadric,0.5,12,12);
				glPopMatrix();
			}
		} 
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Caminho
	glNormal3f(0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[6]);
	glPushMatrix();		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); 					glVertex3i( 0,   0, pistaL); 
			glTexCoord2f(repeatPH*1.0f,0.0f); 			glVertex3i( pistaC,  0, pistaL); 
			glTexCoord2f(repeatPH*1.0f,repeatPH*1.0f); 	glVertex3i( pistaC, 0, 0); 
			glTexCoord2f(0.0f,repeatPH*1.0f); 			glVertex3i( 0, 0, 0); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Relva1
	glNormal3f(0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[3]);
	glPushMatrix();		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); 					glVertex3i( 0, 0, 0); 
			glTexCoord2f(repeatPH*1.0f,0.0f); 			glVertex3i( relvaC,  0, 0); 
			glTexCoord2f(repeatPH*1.0f,repeatPH*1.0f); 	glVertex3i( relvaC, 0, -relvaL); 
			glTexCoord2f(0.0f,repeatPH*1.0f); 			glVertex3i( 0, 0, -relvaL); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Relva2
	glNormal3f(0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[3]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); 					glVertex3i( 0, 0, pistaL+relvaL); 
			glTexCoord2f(repeatPH*1.0f,0.0f); 			glVertex3i( relvaC,  0, pistaL+relvaL); 
			glTexCoord2f(repeatPH*1.0f,repeatPH*1.0f); 	glVertex3i( relvaC, 0, pistaL); 
			glTexCoord2f(0.0f,repeatPH*1.0f); 			glVertex3i( 0, 0, pistaL); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~terra
	glNormal3f(0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[4]);
	glPushMatrix();		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); 					glVertex3i(pistaC , 0, terraL-relvaL); 
			glTexCoord2f(repeatPH2*1.0f,0.0f); 			glVertex3i( pistaC+terraC,  0, terraL-relvaL); 
			glTexCoord2f(repeatPH2*1.0f,repeatPH2*1.0f); 	glVertex3i( pistaC+terraC, 0,-relvaL); 
			glTexCoord2f(0.0f,repeatPH2*1.0f); 			glVertex3i( pistaC, 0, -relvaL); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~chao
	glNormal3f(0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[2]);
	glPushMatrix();		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i( -angarC,   0, angarC*2); 
			glTexCoord2f(1.0f,0.0f); glVertex3i( 0,  0, angarC*2); 
			glTexCoord2f(1.0f,1.0f); glVertex3i( 0, 0, -angarC); 
			glTexCoord2f(0.0f,1.0f); glVertex3i( -angarC, 0, -angarC); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	 
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Face posterior
	glNormal3f(1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,paredes[0]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); 		glVertex3i(-30.0, 0.0, 40.0);     
			glTexCoord2f(3*1.0f,0.0f); 		glVertex3i(-30.0, 0.0, -20.0); 
			glTexCoord2f(3*1.0f,1.0f); 		glVertex3i(-30.0, 20.0, -20.0);
			glTexCoord2f(0.0f,1.0f); 		glVertex3i(-30.0, 20.0, 40.0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);		
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Face superior
	glNormal3f(0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[4]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i(0.0, 20.0, 40.0);
			glTexCoord2f(repeatPH*1.0f,0.0f); glVertex3i(0.0, 20.0, -20.0);
			glTexCoord2f(repeatPH*1.0f,repeatPH*1.0f); glVertex3i(-30.0, 20.0, -20.0); 
			glTexCoord2f(0.0f,repeatPH*1.0f); glVertex3i(-30.0, 20.0, 40.0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
		//-------------------------------------------------------------------------------------------MESA
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[7]);
	glPushMatrix();		
		glTranslatef( mesaP[0], mesaP[1]+mesa/2, mesaP[2]);
		glRotatef (       90, -1, 0, 0);
		GLUquadricObj*  y = gluNewQuadric ( );
		gluQuadricDrawStyle ( y, GLU_FILL   );
		gluQuadricNormals   ( y, GLU_SMOOTH );
		gluQuadricTexture   ( y, GL_TRUE    );
		gluSphere ( y, 0.5*mesa, 150, 150);
		gluDeleteQuadric ( y );
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Face lateral esquerda
	glNormal3f(0.0, 0.0, 1.0);
	glClearColor(0,0,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,paredes[3]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i(-30.0, 0.0, 40.0); 
			glTexCoord2f(1.0f,0.0f); glVertex3i(0.0, 0.0, 40.0);
			glTexCoord2f(1.0f,1.0f); glVertex3i(0.0, 20.0, 40.0);
			glTexCoord2f(0.0f,1.0f); glVertex3i(-30.0, 20.0, 40.0); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Face lateral direita
	glNormal3f(0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,paredes[3]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i(-30.0, 0.0, -20.0); 
			glTexCoord2f(1.0f,0.0f); glVertex3i(0.0, 0.0, -20.0);
			glTexCoord2f(1.0f,1.0f); glVertex3i(0.0, 20.0, -20.0);
			glTexCoord2f(0.0f,1.0f); glVertex3i(-30.0, 20.0, -20.0); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Face frontal 1
	glNormal3f(1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,paredes[2]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i(0.0, 0.0, 40.0); 
			glTexCoord2f(1.0f,0.0f); glVertex3i(0.0, 0.0, 20.0);
			glTexCoord2f(1.0f,1.0f); glVertex3i(0.0, 20.0, 20.0);
			glTexCoord2f(0.0f,1.0f); glVertex3i(0.0, 20.0, 40.0); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Face frontal 2
	glNormal3f(1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,paredes[1]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i(0.0, 0.0, 0.0); 
			glTexCoord2f(1.0f,0.0f); glVertex3i(0.0, 0.0, -20.0);
			glTexCoord2f(1.0f,1.0f); glVertex3i(0.0, 20.0, -20.0);
			glTexCoord2f(0.0f,1.0f); glVertex3i(0.0, 20.0, 0.0); 
		glEnd(); 
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~õbjectos
	
	
	glPushMatrix();				//Donut 1
		if (colorM)
			glColor4f(LARANJA);
		//else
			//initMateriais(material[1]);
		glTranslatef (2, 0.0, 0.4);		
		glutSolidTorus(0.45,1.2,100,100);
	glPopMatrix(); 

	//----------------------------------------------------------------------Quadros
		glNormal3f(0.0, 0.0, 1.0);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[numQuadro]);
			glPushMatrix();
				glBegin(GL_QUADS);
					glTexCoord2f(0.0f,0.0f); glVertex3i(-5.0, 7.0, -19.9999); 
					glTexCoord2f(1.0f,0.0f); glVertex3i(-10, 7.0, -19.9999);
					glTexCoord2f(1.0f,1.0f); glVertex3i(-10, 12.0, -19.9999);
					glTexCoord2f(0.0f,1.0f); glVertex3i(-5.0, 12.0, -19.9999); 
				glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
		
		glNormal3f(0.0, 0.0, 1.0);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[numQuadro]);
			glPushMatrix();
				glBegin(GL_QUADS);
					glTexCoord2f(0.0f,0.0f); glVertex3i(-17.0, 7.0, -19.9999); 
					glTexCoord2f(1.0f,0.0f); glVertex3i(-22, 7.0, -19.9999);
					glTexCoord2f(1.0f,1.0f); glVertex3i(-22, 12.0, -19.9999);
					glTexCoord2f(0.0f,1.0f); glVertex3i(-17.0, 12.0, -19.9999); 
				glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
	//--------------------------------------------------------------Quadros na parede do fundo
	
	//++++++++++++++++++++++++++++++++ Quadro do meio
	glNormal3f(1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[numQuadro]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); 		glVertex3i(-29, 7.0, 16.0);     
			glTexCoord2f(1.0f,0.0f); 		glVertex3i(-29, 7.0, 10.0); 
			glTexCoord2f(1.0f,1.0f); 		glVertex3i(-29, 12.0, 10.0);
			glTexCoord2f(0.0f,1.0f); 		glVertex3i(-29, 12.0, 16.0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	//+++++++++++++++++++++++++++++++++++Quadro do lado direito
	glNormal3f(1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[numQuadro]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); 		glVertex3i(-29, 7.0, -10.0);     
			glTexCoord2f(1.0f,0.0f); 		glVertex3i(-29, 7.0, -5.0); 
			glTexCoord2f(1.0f,1.0f); 		glVertex3i(-29, 12.0, -5.0);
			glTexCoord2f(0.0f,1.0f); 		glVertex3i(-29, 12.0, -10.0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	//++++++++++++++++++++++++++++++++Quadro lado esquerdo
	glNormal3f(1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[numQuadro]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); 		glVertex3i(-29, 7.0, 35.0);     
			glTexCoord2f(1.0f,0.0f); 		glVertex3i(-29, 7.0, 30.0); 
			glTexCoord2f(1.0f,1.0f); 		glVertex3i(-29, 12.0, 30.0);
			glTexCoord2f(0.0f,1.0f); 		glVertex3i(-29, 12.0, 35.0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cadeiras
	glNormal3f(0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[6]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i(-15.0, 3.0, 5); 
			glTexCoord2f(1.0f,0.0f); glVertex3i(-13 ,3.0, 5);
			glTexCoord2f(1.0f,1.0f); glVertex3i(-13, 6.0, 5);
			glTexCoord2f(0.0f,1.0f); glVertex3i(-15.0, 6.0, 5); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	//-----------------------------------------------------------------------Assento
	glNormal3f(0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[6]);
	glPushMatrix();		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i( -15,   3.0, 7); 
			glTexCoord2f(1.0f,0.0f); glVertex3i( -13,  3.0, 7); 
			glTexCoord2f(1.0f,1.0f); glVertex3i( -13, 3.0, 5); 
			glTexCoord2f(0.0f,1.0f); glVertex3i( -15, 3.0, 5); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	 
	 //---------------------------------------------------------------------------Cadeira 2


	glNormal3f(0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[6]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i(-15.0, 3.0, 18); 
			glTexCoord2f(1.0f,0.0f); glVertex3i(-13 ,3.0, 18);
			glTexCoord2f(1.0f,1.0f); glVertex3i(-13, 6.0, 18);
			glTexCoord2f(0.0f,1.0f); glVertex3i(-15.0, 6.0, 18); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	//-----------------------------------------------------------------------Assento
	glNormal3f(0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[6]);
	glPushMatrix();		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3i( -15,   3.0, 18); 
			glTexCoord2f(1.0f,0.0f); glVertex3i( -13,  3.0, 18); 
			glTexCoord2f(1.0f,1.0f); glVertex3i( -13, 3.0, 16); 
			glTexCoord2f(0.0f,1.0f); glVertex3i( -15, 3.0, 16); 
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	 
	//---------------------------------------------------------------------------Pernas
	
	
	Desenha(-14.9,   0.0, 6.9);
	Desenha(-13.2,   0.0, 6.9);
	Desenha(-13.2,   0.0, 5.2);
	Desenha(-14.9,   0.0, 5.2);
	
	Desenha(-14.9,   0.0, 17.8);
	Desenha(-13.2,  0.0, 17.8);
	Desenha(-13.2, 0.0, 16.1);
	Desenha(-14.9, 0.0, 16.1);
	
	Desenha(-17.9,   0.0, 13.8);
	Desenha( -13.2,  0.0, 13.8);
	Desenha(-13.2,0.0,8.1);
	Desenha(-17.9, 0.0, 8.1);
	
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Face frontal 3/Porta(TRANSPARENCIA)
	glNormal3f(1.0, 0.0, 0.0);
	glDisable(GL_LIGHTING);  
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
	glPushMatrix();	
		glColor4f(WHITE2);
		glBegin(GL_QUADS);
			glVertex3i( 0, 0, 10);
			glVertex3i( 0, 0, 0);
			glVertex3i( 0, 20, 0);   
			glVertex3i( 0, 20, 10); 
		glEnd();
	glPopMatrix();
	
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);	
	DesenhaMesa(3.0,   1.0, -2);
	desenhaBoneco();
	
	//----------------------------------------------------------- game
	//----draw cross 
	/*
	glPushMatrix();
	draw_cross(-14.8,3.5, 10.91, 0.2, 0.2, 0.2);
	glPopMatrix(); */
	
	glPushMatrix();
	draw_gamebase(-15.583858,3.25, 10.95, 1, 1, 1);
	glPopMatrix();
	//int continua = 1;
	if( joga){
		
	
		if(pl1_pos4 ==1){
			glPushMatrix();
			//posicao 4
			draw_cross(-15.583858,3.5, 11.50, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl1_pos5 == 1){
			//posicao 5
			glPushMatrix();
			draw_cross(-15.6,3.5, 10.86, 0.2, 0.2, 0.2);
			glPopMatrix();
			
			
		}
		if(pl1_pos6 == 1){
			//posicao 6
			glPushMatrix();
			draw_cross(-15.6,3.5, 10.3, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl1_pos7 == 1){
			//posicao 7
			glPushMatrix();
			draw_cross(-14.83,3.5, 11.50, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl1_pos9 == 1){
			//posicao 9
			glPushMatrix();
			draw_cross(-14.83,3.5, 10.3, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl1_pos1 == 1){
			//posicao 1
			glPushMatrix();
			draw_cross(-16.2,3.5, 11.49, 0.2, 0.2, 0.2);
			glPopMatrix();
	
		}
		if(pl1_pos2 == 1){
			//posicao 2
			glPushMatrix();
			draw_cross(-16.2,3.5, 10.86, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl1_pos3 == 1){
			//posicao 3
			glPushMatrix();
			draw_cross(-16.2,3.5, 10.3, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl1_pos8 == 1){
			//posicao 9
			glPushMatrix();
			draw_cross(-14.8,3.5, 10.91, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		//pl2
		if(pl2_pos3 == 1){
			//posicao 3
			glPushMatrix();
			draw_ball(-16.2,3.5, 10.3, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl2_pos2 == 1){
			//posicao 2
			glPushMatrix();
			draw_ball(-16.2,3.5, 10.86, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl2_pos1 == 1){
			//posicao 1
			glPushMatrix();
			draw_ball(-16.2,3.5, 11.49, 0.2, 0.2, 0.2);
			glPopMatrix();
		
		}
		if(pl2_pos9 == 1){
			//posicao 9
			glPushMatrix();
			draw_ball(-14.83,3.5, 10.3, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl2_pos7 == 1){
			//posicao 7
			glPushMatrix();
			draw_ball(-14.83,3.5, 11.50, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl2_pos6 == 1){
			//posicao 6
			glPushMatrix();
			draw_ball(-15.6,3.5, 10.3, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		if(pl2_pos5 == 1){
			//posicao 5
			glPushMatrix();
			draw_ball(-15.6,3.5, 10.86, 0.2, 0.2, 0.2);
			glPopMatrix();
			
			
		}
		if(pl2_pos4 ==1){
			glPushMatrix();
			//posicao 4
			draw_ball(-15.583858,3.5, 11.50, 0.2, 0.2, 0.2);
			glPopMatrix(); 
			
		}
		if(pl2_pos8 == 1){
			//posicao 9
			glPushMatrix();
			draw_cross(-14.8,3.5, 10.91, 0.2, 0.2, 0.2);
			glPopMatrix();
			
		}
		
		
	

	
		if((pl1_pos1 ==1) && (pl1_pos2 == 1) && (pl1_pos3 == 1)){
			sprintf(texto, "O JOGADOR 1 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		}
		if((pl1_pos1 ==1) && (pl1_pos4 == 1) && (pl1_pos7 == 1)){
			sprintf(texto, "O JOGADOR 1 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
	
		}
		if((pl1_pos1 ==1) && (pl1_pos5 == 1) && (pl1_pos9 == 1)){
			sprintf(texto, "O JOGADOR 1 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
	
		}
		if((pl1_pos2 == 1) && (pl1_pos5 == 1) && (pl1_pos8 == 1)) {
			sprintf(texto, "O JOGADOR 1 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
	
		} 
		if((pl1_pos3 == 1)&& (pl1_pos6 == 1) && (pl1_pos9 == 1)){
			sprintf(texto, "O JOGADOR 1 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
	
		}
		if((pl1_pos3 == 1)&& (pl1_pos5 == 1) && (pl1_pos7 == 1)){
			sprintf(texto, "O JOGADOR 1 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
	
		}
		if((pl1_pos7 == 1)&& (pl1_pos8 == 1) && (pl1_pos9 == 1)){
			sprintf(texto, "O JOGADOR 1 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
	
		}
		if((pl1_pos4 == 1)&& (pl1_pos5 == 1) && (pl1_pos6 == 1)){
			sprintf(texto, "O JOGADOR 1 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
	
		}
		
		//pl2
		
		if((pl2_pos1 ==1) && (pl2_pos2 == 1) && (pl2_pos3 == 1)){
			sprintf(texto, "O JOGADOR 2 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		}
		if((pl2_pos1 ==1) && (pl2_pos4 == 1) && (pl2_pos7 == 1)){
			sprintf(texto, "O JOGADOR 2 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		}
		if((pl2_pos1 ==1) && (pl2_pos5 == 1) && (pl2_pos9 == 1)){
			sprintf(texto, "O JOGADOR 2 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		}
		if((pl2_pos2 == 1) && (pl2_pos5 == 1) && (pl2_pos6 == 1)) {
			sprintf(texto, "O JOGADOR 2 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		} 
		if((pl2_pos3 == 1)&& (pl2_pos6 == 1) && (pl2_pos9 == 1)){
			sprintf(texto, "O JOGADOR 2 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		}
		if((pl2_pos3 == 1)&& (pl2_pos5 == 1) && (pl2_pos7 == 1)){
			sprintf(texto, "O JOGADOR 2 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		}
		if((pl2_pos7 == 1)&& (pl2_pos8 == 1) && (pl2_pos9 == 1)){
			sprintf(texto, "O JOGADOR 2 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		}
		if((pl2_pos4 == 1)&& (pl2_pos5 == 1) && (pl2_pos6 == 1)){
			sprintf(texto, "O JOGADOR 2 Ganhou ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		}
		if(actual_pos == 9){
			sprintf(texto, "Empataram ");
			desenhavencedor(texto, -16.2,5,11);
			continua = 0;
			game_on = 0;
		}
	}
	
	glPushMatrix();
	 drawArvore(30,10,pistaL+relvaL,10,10,1);
	drawArvore(40,10,pistaL+relvaL,10,10,1);
	//drawArvore(35,5,pistaL+relvaL,10,10,1);
	drawArvore(20,10,pistaL+relvaL,10,10,1);
	//drawArvore(25,10,pistaL+relvaL,10,10,1);
	drawArvore(15,10,pistaL+relvaL,10,10,1);
	drawArvore(10,10,pistaL+relvaL,10,10,1);
	drawArvore(30,10,pistaL,10,10,1);
	drawArvore(20,10,pistaL,10,10,1);
	drawArvore(15,10,pistaL,10,10,1);
	drawArvore(10,10,pistaL,10,10,1);
	drawArvore(5,10,pistaL,10,10,1);
	 glPopMatrix();
		
	//draw_ball(-12.583858,5, 10.95, 0.2, 0.2, 0.2);
	/*
	glPopMatrix();
	draw_gamebase(-14.583858,4, 10.95, 10, 10, 10);
	glPushMatrix();*/
	
}

void init(void){
	glClearColor(WHITE);
	glShadeModel(GL_SMOOTH);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT,luzGlobalCor);
	//Faces visiveis
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); 
	criaDefineTexturas( );
	initLights();
	glEnable(GL_TEXTURE_2D);	 
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);   
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);	
	glEnable(GL_LIGHT2);
	glEnable(GL_DEPTH_TEST);
	
	
	/*INICIALIZAR AS GOTAS DE AGUA*/	
	initchuva();
}
void desenha_base(float x,float y,float z){
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D,texture[6]);
}
void desenha_torus(float x, float y,float z){
	glPushMatrix();
		glTranslatef(x,y,z);
		glPushMatrix();
			glRotatef(180,0,1,0);
		glPopMatrix();
		glColor4f(WHITE);
		glutSolidTorus(0.1, 0.2, 2.5, 20);
	glPopMatrix();
}
void DesenhaMesa(float x, float y, float z)
{


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[6]);
	glPushMatrix();	
	glBegin(GL_QUADS);			// Face superior
			// Normal da face
		glTexCoord2f(0.0f,0.0f); glVertex3i( -18,   3.0, 14);
		glTexCoord2f(1.0f,0.0f); glVertex3i( -13,  3.0, 14);
		glTexCoord2f(1.0f,1.0f); glVertex3i( -13, 3.0, 8); 
		glTexCoord2f(0.0f,1.0f); glVertex3i( -18, 3.0, 8); 

	glEnd();
	glPopMatrix();

}
// Desenho Cubo

void Desenha(float x, float y, float z)
{

	glPushMatrix();	
	glColor4f(AZUL);
	 glTranslatef(x,y,z);
	// Desenha um cubo
	glBegin(GL_QUADS);			// Face frontal
		glNormal3f(0.0, 0.0, -1.0); 	// Normal da face
		glVertex3f(0.1, 3, 0.0);
		glVertex3f(0.1, -3.0, 0.0);
		glVertex3f(0.0, -3.0, 0.0);
		glVertex3f(0.0, 3.0, 0.0);
	glEnd();
	glBegin(GL_QUADS);			// Face lateral esquerda
		glNormal3f(-1.0, 0.0, 0.0); 	// Normal da face
		glVertex3f(0.0, 3.0, 0.1);
		glVertex3f(0.0, 3.0, 0.0);
		glVertex3f(0.0, -3.0, 0.0);
		glVertex3f(0.0, -3.0, 0.1);
	glEnd();
	glBegin(GL_QUADS);			// Face lateral direita
		glNormal3f(1.0, 0.0, 0.0);	// Normal da face
		glVertex3f(0.0, 3.0, 0.1);
		glVertex3f(0.0, -3.0, 0.1);
		glVertex3f(0.0, -3.0, 0.0);
		glVertex3f(0.0, 3.0, 0.0);
	glEnd();
	glPopMatrix();
	//glutSwapBuffers();
}


void resizeWindow(GLsizei w, GLsizei h)
{
	wScreen=w;
	hScreen=h;
	glutPostRedisplay();	
}
void display(void){

	if(noite){
		glClearColor(GRAY1);
		nevoeiro();
	}else{
		glClearColor(GRAY2);
		glDisable (GL_FOG);
	}
	//if(game_on ==0){
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Apagar ]
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glEnable(GL_LIGHTING);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Janela Visualizacao ]
		
		glViewport (0, 0, wScreen, hScreen);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Projeccao]
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		
		
	switch (defineProj) {
		case 1: gluPerspective(100.0,(GLdouble)(wScreen/hScreen),0.1,100.0);	 
					glMatrixMode(GL_MODELVIEW);
					glLoadIdentity();
					gluLookAt(obsPini[0], obsPini[1], obsPini[2], obsPfin[0], obsPfin[1], obsPfin[2], 0, 1, 0);
					//gluLookAt(-10,5,10,-10,2,40,0,1,0);
					
		break;
		default: 
					//glOrtho ();
					//glOrtho (-10, 10, -2, 5,2,20);
					gluPerspective(angZoom,(GLdouble)(wScreen/hScreen),0.1,100.0);	 
					glMatrixMode(GL_MODELVIEW);
					glLoadIdentity();	
					gluLookAt(-15.5,7,10,-15,3,10,0,-1,0);
			break;
	}

		
		 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Objectos ]
		
		
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[Iluminacao]
		iluminacao();
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Objectos ]
		
		
		drawScene(); 
	/*}else{
		
					// right bottom
			glViewport (wScreen/4, 0, 3*wScreen/4, hScreen);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(100.0, wScreen/hScreen, 0.1, 3*zC);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(obsPini[0], obsPini[1], obsPini[2], 0,0,0, 0, 1, 0);
			drawScene();
			
			//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Actualizacao
			glutSwapBuffers();
		
	}
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	*/
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Actualizacao
	glutSwapBuffers();
} 

 //Iluminacao
void initLights(void)
{       
	//Ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor); //luz branca intensidade maxima
   
	// Tecto 
	//iluminacao ambiente local
	glLightfv(GL_LIGHT0, GL_POSITION,      localPos1 );   	//posicao do foco
	glLightfv(GL_LIGHT0, GL_AMBIENT,       localCor );   	//luz ambiente local
	glLightfv(GL_LIGHT0, GL_DIFFUSE,       localCorDif );   //reflexao difusa
	glLightf (GL_LIGHT0, GL_CONSTANT_ATTENUATION, localAttCon);
	glLightf (GL_LIGHT0, GL_LINEAR_ATTENUATION,   localAttLin);         
	glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION,localAttQua);
	

	
 
 
	//Definição das propriedades do foco1	
	glLightfv(GL_LIGHT1, GL_POSITION, focoPIni); 		//posicao do foco
	glLightf (GL_LIGHT1, GL_SPOT_EXPONENT, focoConc); 	//intensidade de distribuicao da luz //concentracao
	glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, focoang); 		//angulo de abertura da luz
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, focoDir);	//direcao da luz
	glLightfv(GL_LIGHT1, GL_DIFFUSE, focoCorDif);		//reflexao difusa (0.85, 0.85, 0.85, 1.0) (r,g,b,intensidade)
	glLightfv(GL_LIGHT1, GL_SPECULAR, focoCorEsp);		//reflexao especular (1,1,1,1) (r,g,b,intensidade)
	
	//Definição das propriedades do foco2	
	
	glLightfv(GL_LIGHT2, GL_POSITION, foco2PIni); 		//posicao do foco
	glLightf (GL_LIGHT2, GL_SPOT_EXPONENT, foco2Conc); 	//intensidade de distribuicao da luz //concentracao
	glLightf (GL_LIGHT2, GL_SPOT_CUTOFF, foco2ang); 		//angulo de abertura da luz
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, foco2Dir);	//direcao da luz
	glLightfv(GL_LIGHT2, GL_DIFFUSE, foco2CorDif);		//reflexao difusa (0.85, 0.85, 0.85, 1.0) (r,g,b,intensidade)
	glLightfv(GL_LIGHT2, GL_SPECULAR, foco2CorEsp);		//reflexao especular (1,1,1,1) (r,g,b,intensidade)
	
}   
  
 //======================================================================== ILUMINACAO



 
//......................................................................Timer 
  
void Timer(int value)  
{ 
		if (roda==1){
			if(posX>40){
				posX=-50;
				posY=25;
				posZ=0;
				angRot=90.0;
			}else	
				posX=posX+incX;
				
			if(posX>0){
				posY-=0.5;
				posZ+=1;
				angRot-=0.5;
			}
		}
       /*ACTUALIZA A POSICAO DAS PARTICULAS DE CHUVA*/ 
		int i;
		for(i=0;i<NUMEROPARTICULAS;i++){
			if(chuva[i].y<0)
				chuva[i].y = (random()%25);
			
			if(chuva2[i].y<0)
				chuva2[i].y = (random()%25);
				 
			chuva[i].y = chuva[i].y-chuva[i].Yspeed;
			chuva2[i].y = chuva2[i].y-chuva2[i].Yspeed;
			
			int limiar = random()%10;
			if(limiar>5){
				//chuva[i].x = ((int)(chuva[i].x-chuva[i].Xspeed))%2;
				chuva[i].z = ((int)(chuva[i].z-chuva[i].Zspeed))%25;
				chuva2[i].z = ((int)(chuva2[i].z-chuva2[i].Zspeed))%25;
			}else{
				//chuva[i].x = ((int)(chuva[i].x+chuva[i].Xspeed))%2;
				chuva[i].z = ((int)(chuva[i].z+chuva[i].Zspeed))%25;
				chuva2[i].z = ((int)(chuva2[i].z+chuva2[i].Zspeed))%25;
			}
		}
       
		glutPostRedisplay(); 
		glutTimerFunc(msec,Timer, 1); 
} 
  
//======================================================= EVENTOS
void keyboard(unsigned char key, int x, int y){
		
	switch (key) {
	//----------------------------aviao a passar
	case 'a':		
	case 'A':
		roda= !roda;
		glutPostRedisplay();
		break;	
		
		
	//numbers
	case'1':
		if((game_on == 1)){
			if(actual_pos<=9){
				if((plorder == 0) && pl2_pos1 ==0)	
					{
						actual_pos +=1;
						plorder = 1;
						pl1_pos1 = 1;
						//p1_jogados++;
						//printf("%d\n",pl1_pos1);
					}
					else{
						if(pl1_pos1 == 0){
							actual_pos +=1;
							plorder = 0;
							pl2_pos1 = 1;
							p2_jogados++;
							printf("%d\n",pl2_pos1);
						}

						
					}	
			}
			else{

				
			}
			
		}
	
				
		break;
		
		case'2':
		if((game_on == 1)){
			if(actual_pos<9){
				if((plorder == 0)&& pl2_pos2 ==0){
					actual_pos +=1;
					plorder = 1;
					pl1_pos2 = 1;
					p1_jogados++;
					printf("%d\n",pl1_pos2);
				}
				else{
					if(pl1_pos2 == 0){
						actual_pos +=1;
						plorder = 0;
						pl2_pos2 = 1;
						p2_jogados++;
						printf("%d\n",pl2_pos2);
					}
	
					
				}
		}
		
			
		}
			
		break;
		case'3':
		if((game_on == 1)){
			if(actual_pos<9){
				if((plorder == 0)&& pl2_pos3 ==0){
					actual_pos +=1;
					plorder = 1;
					pl1_pos3 = 1;
					p1_jogados++;
					printf("%d\n",pl1_pos3);
				}
				else{
					if(pl1_pos3 == 0){
						actual_pos +=1;
						plorder = 0;
						pl2_pos3 = 1;					
						p2_jogados++;
						printf("%d\n",pl2_pos3);
					}
					
				}
			}
		
			
		}
		
		break;
		case'4':
		if((game_on == 1)){
			if(actual_pos<9){
				if((plorder == 0)&& pl2_pos4 ==0){
					actual_pos +=1;
					plorder = 1;
					pl1_pos4 = 1;
					p1_jogados++;
					printf("%d\n",pl1_pos4);
				}
				else{
					if(pl1_pos4 == 0){
						actual_pos +=1;
						plorder = 0;
						pl2_pos4 = 1;
						p2_jogados++;
						printf("%d\n",pl2_pos4);
							
					}
				}
			}
			
				
			}	
		
		break;
		
		case'5':
		if((game_on == 1)){
			if(actual_pos<9){
				if((plorder == 0)&& pl2_pos5 ==0){
					actual_pos +=1;
					plorder = 1;
					pl1_pos5 = 1;
					p1_jogados++;
					printf("%d\n",pl1_pos5);
				}
				else{
					if(pl1_pos5 == 0){
						actual_pos +=1;
						plorder = 0;
						pl2_pos5 = 1;
						p2_jogados++;
						printf("%d\n",pl2_pos5);
					}

					
				}
				
			}
			
		}
		break;
		
		case'6':
		if((game_on == 1)){
			if(actual_pos<9){
				if((plorder == 0)&& pl2_pos6 ==0){
					actual_pos +=1;
					plorder = 1;
					pl1_pos6 = 1;
					p1_jogados++;
					printf("%d\n",pl1_pos6);
				}
				else{
					if(pl1_pos6 == 0){
						actual_pos +=1;
						plorder = 0;
						pl2_pos6 = 1;
						p2_jogados++;
						printf("%d\n",pl2_pos6);
					}

					
				}
			}
		
			
		}
				
		
		break;
		case'7':
		if((game_on == 1)){
			if(actual_pos<9){
				if((plorder == 0)&& pl2_pos7 ==0){
					actual_pos +=1;
					plorder = 1;
					pl1_pos7 = 1;
					p1_jogados++;
					printf("%d\n",pl1_pos7);
				}
				else{
					if(pl1_pos7 == 0){
						actual_pos +=1;
						plorder = 0;
						pl2_pos7 = 1;
						p2_jogados++;
						printf("%d\n",pl2_pos7);	
					}
					
				}
			}
		
			
		}
		
		
		break;
		case'8':
		if((game_on == 1)){
			if(actual_pos<9){
				if((plorder == 0)&& pl2_pos8 ==0){
					actual_pos +=1;
					plorder = 1;
					pl1_pos8 = 1;
					p1_jogados++;
					printf("%d\n",pl1_pos8);
				}
				else{
					if(pl1_pos8 == 0){
						actual_pos +=1;
						plorder = 0;
						pl2_pos8 = 1;
						p2_jogados++;
						printf("%d\n",pl2_pos8);	
					}
					
				}
			}
			
		}
		
		
		break;
		case'9':
		if((game_on == 1)){
			if(actual_pos<9){
				if((plorder == 0)&& pl2_pos9 ==0){
					actual_pos +=1;
					plorder = 1;
					pl1_pos9 = 1;
					p1_jogados++;
					printf("%d\n",pl1_pos9);
				}
				else{
					if(pl1_pos9 == 0){
						actual_pos +=1;
						plorder = 0;
						pl2_pos9 = 1;
						p2_jogados++;
						printf("%d\n",pl2_pos9);	
					}
					
				}
			}
			
		}
		
		
		break;
		
		case 'h':
		case 'H':
				joga = !joga;
				joga = 1;
				game_on = 1;
				//Player 1 moves
				pl1_pos1 = 0;
				pl1_pos2 = 0;
				pl1_pos3 = 0;
				pl1_pos4 = 0;
				pl1_pos5 = 0;
				pl1_pos6 = 0;
			    pl1_pos7 = 0;
				 pl1_pos8 = 0;
				 pl1_pos9 = 0;
				//Player 2 moves
				 pl2_pos1 = 0;
				 pl2_pos2 = 0;
				 pl2_pos3 = 0;
				 pl2_pos4 = 0;
				 pl2_pos5 = 0;
				 pl2_pos6 = 0;
				 pl2_pos7 = 0;
				 pl2_pos8 = 0;
				 pl2_pos9 = 0;
				continua = 1;
				actual_pos = 0;

				//printf("-------%d",joga);
				glutPostRedisplay();
		break;
		
	//-----------------------------chuva

	case 'v':		
	case 'V':
		roda= !roda;
		glutPostRedisplay();
		break;
	case 'm':
	case 'M':
		numQuadro++;
		if(numQuadro==12)
			 numQuadro=7;
		glutPostRedisplay();
		break;
		
	case 'c':		 
	case 'C':
		rain=!rain;
		if(!rain)
			msec=400;
		else
			msec=400;
		glutPostRedisplay();
		break;
	//--------------------------------------ligar foco
	case 'f':
	case 'F':
		ligaFoco = !ligaFoco;
		ligaFoco2= !ligaFoco2;
		glutPostRedisplay();
	break;
	//--------------------------- mudar de dia/noite
	case 'n':
	case 'N':
		noite=!noite;
		if (noite){
			luzGlobalCor[0]=0.2;   
			luzGlobalCor[1]=0.2;   
			luzGlobalCor[2]=0.2;  
			
		}
		else{
			luzGlobalCor[0]=1.0;
			luzGlobalCor[1]=1.0;
			luzGlobalCor[2]=1.0; 
			ligaLuz=0;
		}
			 
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor);	//luz ambiente 
		glutPostRedisplay(); 		
		break;
		
	//---------------------------Mudar perspectiva para jogo
	case 'p':
	case 'P':
	game_on = 1;
	if(game_on){
		p1_jogados = 0;
		p2_jogados = 0;
	}
	else{
		
	}
	defineProj=defineProj+1;
	defineProj=defineProj%2;
		glutPostRedisplay();	
	break;
		
		
	//--------------------------- Luz do tecto
	case 't':		
	case 'T':
		if(noite)
			ligaLuz= !ligaLuz;
		glutPostRedisplay();
		break;
	//--------------------------- Escape=terminar
	case 27: 
		exit(0);
		break;
			
		case 'z':
		case 'Z':
			angZoom=angZoom+incZoom;
			if (angZoom>150)
				angZoom=150;
			glutPostRedisplay();
			break;
  }
} 

int check_move(int existentes_array[],int actual){
	int i = 0;
	for(i = 0;i<actual;i++){
		if(existentes_array[i] == actual){
			return 1;
		}
	}
	return 0;
}
 
void teclasNotAscii(int key, int x, int y){
	
	//Movimento do Observador 
	
	if(key == GLUT_KEY_UP){
		printf("x:%lf,y:%lf,z%lf \n",obsPini[0],obsPini[1],obsPini[2]); 
		if(obsPini[0]+incVisao*cos(aVisao)>-29 && obsPini[0]+incVisao*cos(aVisao)<-1)
			obsPini[0]=obsPini[0]+incVisao*cos(aVisao); 
	    if(obsPini[2]-incVisao*sin(aVisao)>-29  && obsPini[2]-incVisao*sin(aVisao)> -19 )
			obsPini[2]=obsPini[2]-incVisao*sin(aVisao);

			
		
	}
	if(key == GLUT_KEY_DOWN){
		// ir para frente e para trás
		if(obsPini[0]-incVisao*sin(aVisao)>-29  && obsPini[0]-incVisao*sin(aVisao)<-1 )
			obsPini[0]=obsPini[0]-incVisao*cos(aVisao); 
		//if(obsPini[2]+incVisao*cos(aVisao)>-19 && obsPini[2]+incVisao*cos(aVisao)<19 )
			//obsPini[2]=obsPini[2]+incVisao*sin(aVisao);	
	} 
	if(key == GLUT_KEY_LEFT){
		aVisao=aVisao+0.1; 
		//aFoco=aFoco-0.1;
	} 
	if(key==GLUT_KEY_RIGHT){ 
		aVisao=aVisao-0.1;
		//aFoco=aFoco+0.1;
	} 
	  
	 
	//printf("x=%f  z=%f\n",obsPini[0],obsPini[2]);
	updateVisao();	
}

//======================================================= MAIN
int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize (wScreen, hScreen); 
	glutInitWindowPosition (100, 100); 
	glutCreateWindow ("Iris e Joao(left,right,up,down, 'a','c','f','n','t') ");
  
	init();
	
	glutSpecialFunc(teclasNotAscii); 
	glutDisplayFunc(display); 
	glutReshapeFunc(resizeWindow);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(msec, Timer, 1); 

	glutMainLoop();

	return 0;
}
