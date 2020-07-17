#include "partida.h"

//Crear partida
void crearPartida(partida &a, int numero,int ci1, int ci2)
{
    //Buscar en el arreglo con tope, el ultimo id y sumarle uno
    a.numeroPartida = numero;
    a.cedulaJ1 = ci1;
    a.cedulaJ2 = ci2;
    a.finalizada=false;
}

//Imprimir partida
void mostraPartida(partida a)
{
    printf("Numero Partida: %d",a.numeroPartida);
    printf("Ci de los jugadores: %d y %d",a.cedulaJ1, a.cedulaJ2);
    printf("Ganador de la partida: %d",a.cedulaGanador);
    if(a.finalizada)
        printf("La partida esta finalizada");
    else
        printf("La partida esta en juego");
}

//Verifico si la ci del J1 es igual a la ci del J2
bool ciIguales (int ciJ1, int ciJ2)
{
    return ciJ1 == ciJ2;
}


//Devuelvo numero Partida
int obtengoNPartida(partida a)
{
    return a.numeroPartida;
}

//Devuelvo las cedula de los jugadores
void obtengoJugadores(partida a,int &ciJ1,int &ciJ2)
{
    ciJ1=a.cedulaJ1;
    ciJ2=a.cedulaJ2;
}

//Ingreso la cedula del ganador en la partida
int ingresarGanador (partida &a)
{
    return 0;
}


//Obtengo ganador de la partida
int obtengoGanador(partida a)
{
    return a.cedulaGanador;
}


//Verifico si la partida termino
bool partidaFinalizada(partida a)
{
    return a.finalizada;
}

//Finaliza una partida
void finalizarLaPartida (partida &p)
{
    p.finalizada = true;
}


/*
//Carga la cedula del ganador
void cargarGanador (partida &p)
{
    int opcion;
    bool ganador = false;
    printf("\nCI Jugador 1: ");
    mostrarString(partida.cedulaJ1);
    printf("\nCI Jugador 2: ");
    mostrarString(partida.cedulaJ2);
    while (!ganador)
    {
        printf("\nIngrese el numero del jugador ganador (1/2): ");
        scanf("%d",&opcion);
        if (opcion == 1)
        {
            p.cedulaGanador = p.cedulaJ1;
            ganador = true;
        }
        else
        {
            if (opcion == 2)
            {
                p.cedulaGanador = p.cedulaJ2;
                ganador = true;
            }
        }

    }
}*/


//Carga la cedula del ganador
void cargarGanador (partida &p,int ganador)
{
    p.cedulaGanador=ganador;
}

