#ifndef PARTIDAS_H_INCLUDED
#define PARTIDAS_H_INCLUDED
#include "partida.h"
#include "torneo.h"



typedef struct {partida arreglo[N*(N-1)/2];
                int tope;
               }Partidas;

//Crear partidas
void Make (Partidas &p);

//Inserta la partida al final de las partidas
void InsBack (Partidas &p, partida e);

//Dice si no hay partidas cargadas
bool Empty (Partidas p);

//Devuelve la primer partida creada
partida Front (Partidas p);

//devuelve una partida segun el numero de partida ingresado
partida obtengoPartida(Partidas p,int num);

//Devuelve las partidas sin la primer partida
void RemFront (Partidas &p);

//Dado un numero de partida, verificar si la partida existe
bool existePartida (int num, Partidas p);

//Obtengo el tope
int obtengoTope (Partidas p);

//verifico si puedo agregar mas partidas
bool partidasLlena(Partidas p);		

//Muestro todas las partidas
void muestroTodasPartidas (Partidas p);

//Dado el número que identifica a una partida, marcarla como finalizada
/*void finalizarPartida (int num, Partidas p, partida &a, jugador &ganador); ///aumenta la cantidad de partidas ganadas*/
//propuesta nico


#endif // PARTIDAS_H_INCLUDED
