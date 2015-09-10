#include <stdlib.h>
#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


static int slices = 16;
static int stacks = 16; 

float posPernaDireita = 150, anguloPernaDireita = 150, countPernaDireita,angulo=100;
float posPernaEsquerda = 150, anguloPernaEsquerda = 150, countPernaEsquerda;
float posPeDireitoX = -0.5, posPeDireitoY = -1, posPeDireitoZ = -6, anguloPeDireito = 90, countPeDireito;
float posPeEsquerdoX = 0.5, posPeEsquerdoY = -1,posPeEsquerdoZ = -6, anguloPeEsquerdo = 0, countPeEsquerdo;
float posBracoDireito = 0, anguloBracoDireito = 0, countBracoDireito;
float posBracoEsquerdo = 0, anguloBracoEsquerdo = 0, countBracoEsquerdo;
float posCorpo = 0, anguloCorpo = 0, countCorpo;
float posCabeca = 0, anguloCabeca = 0, countCabeca;

GLUquadricObj *pernaDireita;
GLUquadricObj *pernaEsquerda;
GLUquadricObj *bracoDireito;
GLUquadricObj *bracoEsquerdo; 



static void desenhaBoneco(void){ 
glColor3f(0.0,0.0,1.0);
pernaDireita = gluNewQuadric();
pernaEsquerda = gluNewQuadric();
bracoDireito = gluNewQuadric();
bracoEsquerdo = gluNewQuadric();
	
/* *DEFINIÇÃO INICIAL DO CORPO DO BONECO */
//Cabeca do Boneco *
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,texture[6]);
glTranslatef(- 14,   5.0, 16.3);
glScalef(0.65,0.65,1);
glutSolidSphere(1,slices,stacks);
glPopMatrix();
glDisable(GL_TEXTURE_2D);


//Corpo do Boneco *
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,texture[7]);
glTranslatef(-14,4 ,16.3);
glutSolidSphere(1,slices,stacks);
glPopMatrix();
glDisable(GL_TEXTURE_2D);



/* *Braço DIREITo do boneco */
glPushMatrix();
glColor4d(AMARELO); 
glTranslatef(-13.2,4 ,16.8);
glRotatef(anguloPernaDireita,1,0,0);
gluCylinder( pernaDireita, 0.2, 0.2, 0.8, slices, stacks);
glPopMatrix();

/* *Braço ESQUERDo do boneco */
glPushMatrix();
glTranslatef(-14.9,4 ,16.8);
glRotatef(anguloPernaEsquerda,1,0,0);
gluCylinder( pernaEsquerda, 0.2, 0.2, 0.8, slices, stacks);
glPopMatrix();

//* *Perna direita do boneco */
glPushMatrix();
glColor4d(CASTANHO); 
glTranslatef(-13.2,3.2 ,15);
glRotatef(0,1,0,0);
gluCylinder( pernaDireita, 0.2, 0.2, 1, slices, stacks);
glPopMatrix();

/* *Perna Esquerda do boneco */
glPushMatrix();
glTranslatef(-14.5,3.2,15.1);
glRotatef(0,1,0,0);
gluCylinder( pernaEsquerda, 0.2, 0.2, 0.8, slices, stacks);
glPopMatrix();


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Boneco 2
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,texture[6]);
glTranslatef(- 14,   5.0, 6.8);
glScalef(0.65,0.65,1);
glutSolidSphere(1,slices,stacks);
glPopMatrix();
glDisable(GL_TEXTURE_2D);


//Corpo do Boneco *
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,texture[7]);
glTranslatef(-14,4 ,6.8);
glutSolidSphere(1,slices,stacks);
glPopMatrix();
glDisable(GL_TEXTURE_2D);



/* *Braço DIREITo do boneco */
glPushMatrix();
glColor4d(AMARELO); 
glTranslatef(-13.2,4 ,6.8);
glRotatef(angulo,1,0,0);
gluCylinder( pernaDireita, 0.2, 0.2, 0.8, slices, stacks);
glPopMatrix();

/* *Braço ESQUERDo do boneco */
glPushMatrix();
glTranslatef(-14.9,4 ,6.8);
glRotatef(angulo,1,0,0);
gluCylinder( pernaEsquerda, 0.2, 0.2, 0.8, slices, stacks);
glPopMatrix();

//* *Perna direita do boneco */
glPushMatrix();
glColor4d(CASTANHO); 
glTranslatef(-13.2,3.2 ,6.8);
glRotatef(0,1,0,0);
gluCylinder( pernaDireita, 0.2, 0.2, 1, slices, stacks);
glPopMatrix();

/* *Perna Esquerda do boneco */
glPushMatrix();
glTranslatef(-14.5,3.2,6.8);
glRotatef(0,1,0,0);
gluCylinder( pernaEsquerda, 0.2, 0.2, 0.8, slices, stacks);
glPopMatrix();



	}
