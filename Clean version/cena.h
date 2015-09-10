#include <OpenGL/gl.h>
#include <GLUT/glut.h>

//--------------------------------- Definir cores
#define AZUL     0.0, 0.0, 1.0, 0.5
#define AZUL2     0.0, 0.0, 0.8, 0.5
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define AMARELO  1.0, 1.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0, 1.0
#define VERDEE   0.1,0.3,0.1,1.0
#define LARANJA  1.0, 0.5, 0.1, 1.0
#define CASTANHO  0.3, 0.2, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define WHITE2    1.0, 1.0, 1.0, 0.65
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY1    0.2, 0.2, 0.2, 1.0
#define GRAY2    0.93, 0.93, 0.93, 1.0

//================================================================================
//===========================================================Variaveis e constantes

//Game Variables ...


GLint actual_pos = 0;
GLint plorder = 0; // 0 jogador 1 senao jogador 2
GLint p1_jogados = 0; // numero de vezes jogadas
GLint p2_jogados = 0;


//Player 1 moves
GLint pl1_pos1 = 0;
GLint pl1_pos2 = 0;
GLint pl1_pos3 = 0;
GLint pl1_pos4 = 0;
GLint pl1_pos5 = 0;
GLint pl1_pos6 = 0;
GLint pl1_pos7 = 0;
GLint pl1_pos8 = 0;
GLint pl1_pos9 = 0;
//Player 2 moves
GLint pl2_pos1 = 0;
GLint pl2_pos2 = 0;
GLint pl2_pos3 = 0;
GLint pl2_pos4 = 0;
GLint pl2_pos5 = 0;
GLint pl2_pos6 = 0;
GLint pl2_pos7 = 0;
GLint pl2_pos8 = 0;
GLint pl2_pos9 = 0;




//==============ESTRUTURA DA CHUVA
typedef struct gota{
	int x;
	int y;
	int z;
	float Yspeed;
	float Xspeed;
	float Zspeed;
	int espacamento; //para cada gota criar 10 outros objectos iguais mas com um determinado espacamento
}gota;

int NUMEROPARTICULAS = 100;
gota chuva[100]; //array de cada gota para simular a chuva
gota chuva2[100]; //array de cada gota para simular a chuva


//------------------------------------------------------------ Sistema Coordenadas
GLfloat   xC=45.0, yC=20.0, zC=40.0;
GLint     wScreen=800, hScreen=600;

//------------------------------------------------------------ Objectos/cena

GLfloat   pistaC=40.0;				//comprimento da pista
GLfloat   pistaL=20.0;				//largura da pista
GLfloat   pistaP[]= {40, 0, 10};		//posiaçao da pista


GLfloat   angarC=30.0;				//comprimento da angar
GLfloat   angarL=60.0;				//largura da angar
GLfloat   angarP[]= {40, 0, 10};		//posiaçao da angar

GLfloat   relvaC=40.0;				//comprimento da relva
GLfloat   relvaL=20.0;				//largura da relva
GLfloat   relvaP[]= {70, 0, 0};		//posiaçao da relva


GLfloat   terraC=5.0;				//comprimento da relva
GLfloat   terraL=60.0;				//largura da relva
GLfloat   terraP[]= {-10, 0, 15};		//posiaçao da relva


GLint repeatPH=4;
GLint repeatPH2=12;
GLint repeatPV=2;
GLfloat PI=3.14159;
//------------------------------------------------------------ Observador


GLfloat  rVisao=3.0, aVisao=0.5*PI, incVisao=0.1;
GLfloat  obsPini[] ={-5, 2.0, 0.25*xC};
GLfloat  obsPfin[] ={obsPini[0]-rVisao*cos(aVisao), obsPini[1], obsPini[2]-rVisao*sin(aVisao)};


//Perspective change

GLint game_on = 0;
GLint defineProj=1;
GLfloat  angZoom=90;
GLfloat  incZoom=3;

//Variaveis
char dia [10]="dia";
GLint   msec=10;			//.. definicao do timer (actualizacao) 
GLint   rain=1;
int numQuadro = 0;
GLint   joga=1;
GLint continua = 1;

//nevoeiro
GLfloat density = 0.04; //density 0.3 -> thick
GLfloat fogColor[4] = {0.5, 0.5, 0.5, 0.0}; //set fog color to grey

//aviao
GLfloat incX = 2.0;
GLfloat posX = -50.0;
GLfloat posY=25;
GLfloat posZ=0;
GLfloat angRot=90;
GLint roda=1;

//Mesa
GLfloat   mesa=4.0;
GLfloat   mesaP[]= {-20.0, 0.0, 20.0};

//Quadrado
GLfloat quadTam = 3.0;				//tamanho
GLfloat	quadRot = -20;				//angulo de rotacao
GLfloat	quadPos[] = {-5,0,2};		//posicao


//texturas
GLuint texture[10];
GLuint paredes[6];

//------------------------------------------------------------ Iluminacao
//------------------------------------------------------------ Global (ambiente)
GLint   noite=0;
GLfloat luzGlobalCor[4]={1.0,1.0,1.0,1.0}, focoPini;

//Lampada tecto (ambiente local)
GLint   ligaLuz=0;
GLfloat localCor[4] ={0.1,0.1,0.1,1.0}; 			//luz ambiente local
GLfloat localCorDif[4] ={ 1, 1, 1, 1.0}; 			//reflexao difusa
GLfloat localPos1[4] ={0.0, 0.0, 0.0, 0.0};			//O valor zero indica que os 3 primeiros atributos de position formam um vetor que indica a direção da luz.
GLfloat localPos2[4] ={-1.0, 15.0, 20.0, 1.0};
GLfloat localAttCon =1.0;
GLfloat localAttLin =0.05;
GLfloat localAttQua =0.0;



GLfloat aFoco = aVisao;
GLfloat rFoco = 1.1;
GLfloat incH = 0.0, incV = 0.0;
GLfloat focoPIni[] = {0, 10, 0, 1.0};			//foco posicao inicial

GLfloat focoDir[] = {-7, 0, 5,0.0};	//direccao foco
GLfloat focoang = 30.0;			//angulo 0-90
GLfloat focoConc = 5.0;					//concentração de luz [0;128]
GLfloat focoCorEsp[] = {1.0, 1.0, 1.0, 1.0};				//foco reflexao especular //efeito espelho
GLfloat focoCorDif[] = {0.85, 0.85, 0.85, 1.0};				//foco reflexao difusa
bool colorM = true;
GLfloat INC_MAX_H = 0.5, INC_MAX_V = 0.35;
bool ligaFoco = false;



//Foco2
GLfloat aFoco2 = aVisao;
GLfloat rFoco2 = 1.1;
GLfloat foco2PIni[] = {0, 1, 0, 1.0};			//foco posicao inicial

GLfloat foco2Dir[] = {1, 0, 1};	//direccao foco
GLfloat foco2ang = 90.0;			//angulo 0-90
GLfloat foco2Conc = 20.0;					//concentração de luz [0;128]
GLfloat foco2CorEsp[] = {1.0, 1.0, 1.0, 1.0};				//foco reflexao especular //efeito espelho
GLfloat foco2CorDif[] = {0.85, 0.85, 0.85, 1.0};				//foco reflexao difusa
bool ligaFoco2 = false;
bool colorM2 = true;



//Materiais
GLfloat matAmbiente[] = {1.0,1.0,1.0,1.0};	  
GLfloat matDifusa[]   = {1.0,1.0,1.0,1.0};	  
GLfloat matEspecular[]= {1.0, 1.0, 1.0, 1.0}; 
GLint   especMaterial = 20;

GLint raioC=0.5;	//raio do cilindro do jato;

void desenhavencedor(char *string, GLfloat x, GLfloat y,GLfloat z);
void desenha_torus(float x, float y,float z);
void drawmodel(float x,float y, float z, float x_2,float y_2, float z_2);
int check_move(int existentes_array[],int actual);
void objectos();
void initchuva(void);
void compoe_jato(void);
void DrawRocket();
void compoe_jato2(void);
void DesenhaCirculo(GLfloat raio, int num_linhas);
void initLights(void);
void iluminacao();
void cilindro(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);
void nevoeiro();
void esfera1(int radius, int stacks, int  columns);
void updateVisao();
void init(void);
void drawScene();
void resizeWindow(GLsizei w, GLsizei h);
void criaDefineTexturas();
void display(void);
void keyboard(unsigned char key, int x, int y);
void teclasNotAscii(int key, int x, int y);
void Desenha(float x, float y, float z);
void DesenhaMesa(float x, float y, float z);
