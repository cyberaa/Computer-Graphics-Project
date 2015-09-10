#include "RgbImage.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
  

void criaDefineTexturas(){   
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~esfera-dia
	
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);	
	imag.LoadBmpFile("dia.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
	imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Terra	
	glGenTextures(1, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	imag.LoadBmpFile("relva.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);		//repetiçao horizontal 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);		//repetiçao vertical
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~chao
	
	glGenTextures(1, &texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	imag.LoadBmpFile("white.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	
   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Relva   

	glGenTextures(1, &texture[3]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	imag.LoadBmpFile("relva.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());	
		
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Terra	
	glGenTextures(1, &texture[4]);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	imag.LoadBmpFile("azul.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());	
			
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ñoite		
	glGenTextures(1, &texture[5]);
	glBindTexture(GL_TEXTURE_2D, texture[5]);	
	imag.LoadBmpFile("noite.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
	imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());	
	
	
	glGenTextures(1, &texture[6]);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	imag.LoadBmpFile("madeira.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
	imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
		
	
		//___________________________________________________
	int i;
    char res[10];
    for(i=4;i<13;i++){
        glGenTextures(1, &texture[i+3]);
    	glBindTexture(GL_TEXTURE_2D, texture[i+3]);
    	sprintf(res,"imag%d.bmp",i);
    	imag.LoadBmpFile(res);
    	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    	glTexImage2D(GL_TEXTURE_2D, 0, 3,
    	imag.GetNumCols(),
    		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
	    		imag.ImageData());

    }
	//______________________________Fundo maior_____________________________
 
 
	glGenTextures(1, &paredes[0]);
	glBindTexture(GL_TEXTURE_2D, paredes[0]);
	imag.LoadBmpFile("parede.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
		 
	glGenTextures(1, &paredes[1]);
	glBindTexture(GL_TEXTURE_2D, paredes[1]);
	imag.LoadBmpFile("parede.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
	glGenTextures(1, &paredes[2]);
	glBindTexture(GL_TEXTURE_2D, paredes[2]);
	imag.LoadBmpFile("parede.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
		
			
	glGenTextures(1, &paredes[3]);
	glBindTexture(GL_TEXTURE_2D, paredes[3]);
	imag.LoadBmpFile("parede.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
	imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
}   
  
  
void initchuva(void){
	
	/*INICIALIZAR AS GOTAS DE AGUA*/
	srand(getpid());
	int i;
	for(i=0;i<NUMEROPARTICULAS;i++){
		chuva[i].x = 1;
		chuva[i].y = (random()%25);
		chuva[i].z = (random()%30)-5;
		chuva2[i].x = 5;
		chuva2[i].y = (random()%25);
		chuva2[i].z = (random()%30)-5;
		
		while(chuva[i].Xspeed<=0 && chuva2[i].Xspeed<=0){
			chuva[i].Xspeed = random()%2;
			chuva2[i].Xspeed = random()%2;		
		}while(chuva[i].Yspeed<=0 && chuva2[i].Yspeed<=0){
			chuva[i].Yspeed = random()%4;
			chuva2[i].Yspeed = random()%4;
		}while(chuva[i].Zspeed<=0 && chuva2[i].Zspeed<=0){
			chuva[i].Zspeed = random()%2;
			chuva2[i].Zspeed = random()%2;
		}
		chuva[i].espacamento = random()%10;
		chuva2[i].espacamento = random()%10;
	}
	
}


void iluminacao(){
	if(ligaLuz)					//luz do tecto ambiente	
		glEnable(GL_LIGHT0);
	else
		glDisable(GL_LIGHT0);

	if(ligaFoco)				//luz do foco
		glEnable(GL_LIGHT1);
	else
		glDisable(GL_LIGHT1);
	
	if(ligaFoco2)				//luz do foco
		glEnable(GL_LIGHT2);
	else
		glDisable(GL_LIGHT2);

	glLightfv(GL_LIGHT1, GL_POSITION, focoPIni); 
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, focoDir);
	glLightfv(GL_LIGHT2, GL_POSITION, foco2PIni); 
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, foco2Dir);
	/*glLightfv(GL_LIGHT1, GL_POSITION, foco2PIni); 
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, foco2Dir);*/
	
	//initLights();
	glutPostRedisplay();
}
 
void updateVisao(){
	
	obsPfin[0] =obsPini[0]+rVisao*cos(aVisao);	
	obsPfin[2] =obsPini[2]-rVisao*sin(aVisao);
	obsPfin[1] =obsPini[1];
	
	
	/*focoPFin[0]=focoPIni[0]+rFoco*cos(aFoco);
	focoPFin[2]=focoPIni[2]-rFoco*sin(aFoco);	
	focoPFin[1]=focoPIni[1];
	
	focoDir[0] =focoPFin[0];
	focoDir[1] =focoPFin[1];
	focoDir[2] =focoPFin[2];
	*/
	glutPostRedisplay();
}
//base, top e height especificam o raio da base, o raio do topo e a altura do cilindro, respectivamente; slices stacks especificam o número de subdivisões ao redor do eixo z e ao longo do mesmo
void cilindro(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks){
	GLUquadricObj *quadric;	 
	quadric = gluNewQuadric();
	gluQuadricTexture(quadric, GL_TRUE);	
	gluCylinder(quadric, base, top, height,slices, stacks);
}


void  esfera1(int radius, int stacks, int  columns){        
    
	GLUquadric* quadObj = gluNewQuadric();    
	gluQuadricDrawStyle(quadObj, GLU_FILL);    
	gluQuadricNormals(quadObj, GLU_SMOOTH);    
	gluQuadricTexture(quadObj, GL_TRUE);  
	gluSphere(quadObj, radius, stacks, columns);    
	gluDeleteQuadric(quadObj);  
    
}

void nevoeiro(){
	glEnable (GL_FOG); //enable the fog
	glFogi (GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2          
	glFogfv (GL_FOG_COLOR, fogColor); //set the fog color to our color chosen above
	glFogf (GL_FOG_DENSITY, density); //set the density to the value above
	glFogf(GL_FOG_START,10);
	glFogf(GL_FOG_END,15);
	glHint (GL_FOG_HINT, GL_NICEST); // set the fog to look the nicest, may slow down on older cards
}



 





void objectos(){
	glPushMatrix();				//Cone Verde
		
		glTranslatef (-5, 0.0, 10);		
		glRotatef (-90,1, 0.0, 0.1);		
		glutSolidCone(1,4, 200,200);
	glPopMatrix();	
								
	
}
