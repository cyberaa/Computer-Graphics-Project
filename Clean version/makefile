
FLAGS  = -lglut -lm -lGLU
CC     = g++
PROG   = cena
OBJS   = cena.o RgbImage.o

all:	${PROG}

clean:
	rm ${OBJS} ${PROG}
  
${PROG}:	${OBJS}
	${CC} ${FLAGS} ${OBJS} -o $@

.c.o:
	${CC} ${FLAGS} $< -c

##########################


RgbImage.o: RgbImage.cpp RgbImage.h
cena.o: cena.cpp

cena: cena.o RgbImage.o

