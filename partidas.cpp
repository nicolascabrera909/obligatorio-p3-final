#include "partidas.h"

//Crear partidas
void Make (Partidas &p)
{
    p.tope = 0;
}

//Inserta la partida al final de las partidas
void InsBack (Partidas &p, partida e)
{
    p.arreglo[p.tope] = e;
    p.tope++;
}

//Dice si no hay partidas cargadas
bool Empty (Partidas p)
{
    return (bool) (p.tope == 0);
}

//Devuelve la primer partida creada
partida Front (Partidas p)
{
    return p.arreglo[0];
}

//devuelve una partida segun el numero de partida ingresado
partida obtengoPartida(Partidas p,int num)
{
    int i=0;
    bool encontre=false;
    while (i<p.tope && !encontre)
    {
        if(obtengoNPartida(p.arreglo[i])==num)
        {
            encontre=true;
        }
    }
    return p.arreglo[i];
}

//Devuelve las partidas sin la primer partida
void RemFront (Partidas &p)
{
    for (int i=0; i<p.tope-1; i++)
        p.arreglo[i] = p.arreglo[i+1];
    p.tope--;
}

//Dado un numero de partida, verificar si la partida existe
bool existePartida (int num, Partidas p)
{
    if (num > p.tope)
        return false;
    else if (num < 0)
        return false;
    else
        return true;
}

//Obtengo el tope, precondicion no esta lleno la secuencia
int obtengoTope (Partidas p)
{
    return p.tope;
}


//verifico si puedo agregar mas partidas
bool partidasLlena(Partidas p)
{
    return (N*(N-1)/2)==p.tope;
}


//Muestro todas las partidas ordenadas por numero de partida
void muestroTodasPartidas (Partidas p)
{
    for (int i=0; i<p.tope; i++)
    {
        mostraPartida(p.arreglo[i]);
    }
}

//Dado el numero que identifica a una partida, marcarla como finalizada,
//ingresando en ese momento la cédula del ganador e incrementando su cantidad de partidas ganadas.
//En caso de que la partida no exista o de que ya hubiera sido finalizada antes, la operacion debe ser cancelada, emitiendo un mensaje de error.
/*void finalizarPartida (int num, Partidas p, partida &a, jugadores j, jugador &ganador) ///aumenta la cantidad de partidas ganadas
{
    if (existePartida(num, p))
    {
        if (!partidaFinalizada(a))
        {
            finalizarLaPartida(p.arreglo[num]); ///SIN PROBAR, SE VE DE CABEZA QUE NO ANDA.. YA NO ME ANDA EL BOCHO, SALUDOS TOMI
            cargarGanador(p.arreglo[num]);
            incrementarPartidasGanador(j,ganador,p.arreglo[num].cedulaGanador);
        }
    }

    ///PRUEBA EMI: cambie num por num-1. Incrementar las partidas jugadas cuando se crea la partida y las ganadas cuando finaliza?
    if (existePartida(num,p))
    {
        if (!partidaFinalizada(a))
        {
            finalizarLaPartida(p.arreglo[num-1]);
            cargarGanador(p.arreglo[num-1]));
            incrementarGanadas(p.arreglo[num-1]);
        }
        else
        {
            printf("La partida indicada ya se encuentra finalizada");
        }
    }
    else
    {
        printf("La partida indicada no existe");
    }

}*/



