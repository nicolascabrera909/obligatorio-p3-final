
//Cargar los datos de todos los jugadores que participan del torneo.
//Esta operación se ejecutará solamente una vez, al comienzo del torneo.
//Los jugadores serán inscriptos respetando el orden de llegada, y ordenados por cédula de identidad.

#include "torneo.h"
#include "partidas.h"
#include "jugadores.h"

/*int pruebaReq1 ()
{
    jugadores inscriptos;
    Make(inscriptos);
    cargarJugadores(inscriptos);
    printf("\n\n");
    mostrarJugadores(inscriptos);
}
*/

///PRUEBA 2

int prueba2Req1 ()
{
    jugador elJugador;
    int cedula;
    string nombre, apellido, departamento;
    strCrear (nombre);
    strCrear (apellido);
    strCrear (departamento);
    int canJugadores = 1;
    jugadores inscriptos;
    Make(inscriptos);
    Partidas partidasJugadas;
    Make(partidasJugadas);
    torneo elTorne;
    Crear(elTorne);

    while (canJugadores <= N)
    {
        printf ("\nIngrese cedula del jugador: ");
        fflush(stdin);
        scanf("%d",&cedula);
        printf ("Ingrese nombre del jugador: ");
        fflush(stdin);
        cargarString(nombre);
        printf ("Ingrese apellido del jugador: ");
        fflush(stdin);
        cargarString(apellido);
        printf ("Ingrese departamento del jugador: ");
        fflush(stdin);
        cargarString(departamento);
        crearJugador(elJugador,canJugadores,cedula,nombre,apellido,departamento);
        Insert(inscriptos, elJugador);
        canJugadores++;
    }
    printf("\n\n");
    mostrarJugadores(inscriptos);
    string departamentoB;
    strCrear(departamentoB);
    printf ("\nIngrese departamento para buscar los jugadores: ");
    cargarString(departamentoB);
    jugadoresDepartamentos (departamentoB,inscriptos);
}



