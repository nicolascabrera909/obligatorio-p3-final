#include "jugadores.h"


//Crear un abb de jugadores vacio
void Make(jugadores &a)
{
    a = NULL;
}

//Verificar si ABB jugadores es vacio
bool hayJugadores(jugadores a)
{
    return (bool)(a == NULL); ///Retorna true si no hay jugadores en el torneo
}

//Inserto un jugador en el arbol según algoritmo de inserción en un ABB (usando el documento como identificador)
void Insert (jugadores &a, jugador elJugador)
{
    if(a == NULL)
    {
        a = new nodoA;
        a->info = elJugador;
        a->hizq=NULL;
        a->hder=NULL;
    }
    else
    {
        if(obtengoCedula(elJugador) < obtengoCedula(a->info))
            Insert(a->hizq,elJugador);
        else
            Insert(a->hder,elJugador);
    }
}

//Buscar si existe un jugador dada una ci
bool Member(jugadores a,int cedula)
{
    if(a!=NULL)
    {
        if(obtengoCedula(a->info)==cedula)
            return true;
        else
        {
            if(obtengoCedula(a->info)>cedula)
                return Member(a->hizq, cedula);
            else
                return Member(a->hder, cedula);
        }

    }
    else
        return false;
}

//Dado un documento devuelvo un jugador, precondicion el jugador existe
jugador Find(jugadores a,int cedula)
{
    if(obtengoCedula(a->info)==cedula)
        return a->info;
    else
    {
        if(obtengoCedula(a->info)>cedula)
            return Find(a->hizq, cedula);
        else
            return Find(a->hder, cedula);
    }
}

//Modifico los datos del jugador, cambio un tipo de jugador por otro. Precondicion el jugador existe
void Modify(jugadores a, jugador elJugador)
{
    while(a!=NULL)
    {
        if(obtengoCedula(a->info)==obtengoCedula(elJugador))
            a->info=elJugador;
        else
        {
            if(obtengoCedula(a->info)>obtengoCedula(elJugador))
                a=a->hizq;
            else
                a=a->hder;
        }
    }
}

//Borro jugador del diccionario
void Delete(jugadores a,jugador elJugador )
{
    if (a != NULL)
    {
        Delete (a -> hizq,elJugador);
        Delete (a -> hder,elJugador);
        if(obtengoCedula(elJugador)==obtengoCedula(a->info))
        {
            delete a;/////falta acaß
            a = NULL;
        }

    }
}

//Muestro el ABB jugadores en orden por pantalla nodo a nodo
void mostrarJugadores (jugadores a)
{
    if (a != NULL)
    {
        mostrarJugadores(a -> hizq);
        mostrarJugador(a->info);
        mostrarJugadores (a -> hder);
    }
}

//Cargar los datos de todos los jugadores que participan del torneo. Esta operación se ejecutará
//solamente una vez, al comienzo del torneo. Los jugadores serán inscriptos respetando el
//orden de llegada, y ordenados por cédula de identidad.
void cargarJugadores (jugadores &losJugadores) ///PREGUNTAR A FEDE SI SE PUEDE HACER ASI O TIENE QUE SER DE ALGUNA OTRA MANERA EL CARGAR LOS DATOS
{
    jugador elJugador;
    int cedula;
    string nombre, apellido, departamento;
    strCrear (nombre);
    strCrear (apellido);
    strCrear (departamento);
    int cantJugadores = 0;
    while (cantJugadores < N)
    {
        printf ("\nIngrese cedula del jugador: ");
        fflush(stdin);
        scanf("%d",&cedula);
        if (!Member(losJugadores, cedula))
            {
                printf ("Ingrese nombre del jugador: ");
                fflush(stdin);
                cargarString(nombre);
                printf ("Ingrese apellido del jugador: ");
                fflush(stdin);
                cargarString(apellido);
                printf ("Ingrese departamento del jugador: ");
                fflush(stdin);
                cargarString(departamento);
                crearJugador(elJugador,cantJugadores,cedula,nombre,apellido,departamento);
                Insert(losJugadores, elJugador);
                cantJugadores++;
            }
        else
            printf ("\nEl jugador ya esta inscripto en el torneo.");

    }
}

//Imprimir por pantalla los jugadres que pertenecen al departamento
void jugadoresDepartamentos (string departamento, jugadores a,int &contador)
{
    if (a != NULL)
    {
        jugadoresDepartamentos(departamento, a->hizq,contador);
        string deptoJugador;
        strCrear (deptoJugador);
        obtengoDepartamento(a->info, deptoJugador);
        if (comparoString(deptoJugador,departamento))
        {
            mostrarJugador(a->info);
            contador++;
        }
        //liberarMemoriaString(deptoJugador);
        jugadoresDepartamentos(departamento, a->hder,contador);
    }
}
/*
void jugadoresDepartamentos (string departamento, jugadores a, int &cant)
{
    if (a != NULL)
    {
        jugadoresDepartamentos(departamento, a->hizq, cant);
        muestroJugadorDepartamento (a, departamento, cant);
        jugadoresDepartamentos(departamento, a->hder, cant);
    }
}

void muestroJugadorDepartamento (jugadores j, string departamento, int &cant)
{
    string depto;
    strCrear(depto);
    obtengoDepartamento(j->info,depto);
    if (comparoString(depto, departamento))
    {
        mostrarJugador(j->info);
        cant++;
    }
}*/


//agregar un procedimiento que devuelva el jugador con la maxima cantidad de partidas y la cantidad de partidas correspondiente, precondicion la partida tiene que estar terminada
jugador jugadorGanador(jugadores j,int maximo)
{
    if(j!=NULL)
    {
        if(obtengoCantidadGanadas(j->info) > maximo)
        {
            maximo=obtengoCantidadGanadas(j->info);
            jugadorGanador(j->hizq,maximo);
            jugadorGanador(j->hder,maximo);
        }
        return  jugadorGanador(j->hizq,maximo) +
        jugadorGanador(j->hder,maximo);
    }
    return j->info;
}

//Dada la cédula de un jugador, listar todos sus datos, incluyendo además
//la cantidad de partidas que lleva disputadas y la cantidad de partidas que lleva ganadas hasta el momento.
void mostrarJugadorCI (jugadores j, int cedula)
{
    if (!hayJugadores(j))
        if (Member(j, cedula))
            mostrarJugador(Find(j, cedula));
        else
            printf ("\nEl jugador no esta registrado.");
    else
        printf ("\nNo hay jugadores registrados en el torneo.");
}


