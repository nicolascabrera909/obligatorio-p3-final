#include "torneo.h"
#include "partidas.h"
#include "jugadores.h"

/*int main()
{
    bool salir = false;
    do
    {
        printf("\n1 - Cargar los datos de todos los jugadores del torneo");
        printf("\n2 - Iniciar una nueva partida entre dos jugadores");
        printf("\n3 - Marcar como finalizada una partida");
        printf("\n4 - Mostrar los datos de todos los jugadores provenientes de un departamento");
        printf("\n5 - Mostrar los datos de un jugador");
        printf("\n6 - Mostrar los datos de todas las partidas, ordenadas en forma ascendente por el numero de partida");
        printf("\n7 - Verificar si el torneo finalizo y mostrar el jugador ganador");
        printf("\n8 - Salir");
        printf("\nIngrese un comando: ");
        int comando;
        scanf ("%d",&comando);
        if(!stringVacio(comando))
        {
            switch (comando)
            {
            case 1:
                jugador elJugador;
                int cedula;
                string ci, nombre, apellido, departamento;
                strCrear (ci);
                strCrear (nombre);
                strCrear (apellido);
                strCrear (departamento);
                int cantJugadores = 0;
                while (cantJugadores < N)
                {
                    printf ("\nIngrese cedula del jugador: ");
                    fflush(stdin);
                    cargarString(ci);
                    if (esNumero(ci))
                    {
                        cedula = convertirString(ci);
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
                            printf ("Error: El jugador ya esta inscripto en el torneo.");
                    }
                    else
                        printf ("Error: Ingrese una cedula valida.");
                }

            case 2:

            case 3:

            case 4:

            case 5:

            case 6:

            case 7:

            case 8:
            {
                char opcion;
                printf("\nDesea salir del torneo? S/N");
                scanf("%c",opcion);
                fflush(stdin);
                switch (opcion)
                {
                case "Y":
                case "y":
                    printf("Hasta la proxima!");
                    salir = true;
                }
            }

            }
        }
        else
        {
            printf("\nNo ha digitado ningun comando, por favor ingrese uno.");
        }
    }
    while (!salir);
}*/

int main ()
{
    Partidas partidasJugadas;
    jugadores inscriptos;
    torneo elTorne;
    if(!partidasLlena(partidasJugadas))
    {
        int ci1,ci2;
        printf ("\nIngrese cedula del jugador1: ");
        fflush(stdin);
        scanf("%d",&ci1);
        printf ("\nIngrese cedula del jugador2: ");
        fflush(stdin);
        scanf("%d",&ci2);
        int contadorExist=0;
        if (Member(inscriptos, ci1))
            contadorExist++;
        if(Member(inscriptos, ci2))
            contadorExist=contadorExist+2;

        switch (contadorExist)
        {
        case 1:
            printf ("\nEl documento ingresado para el jugador2 no existe: ");
            break;

        case 2:
            printf ("\nEl documento ingresado para el jugador1 no existe: ");
            break;

        case 3:
            if(ci1==ci2)
                printf ("\nLos documentos son iguales, ingrese dos documentos diferentes");
            else
            {
                if(JugaronPartido(elTorne,ci1,ci2))
                    printf ("\nLos jugadores ya jugaron una partida entre si");
                else
                {
                    int proximaPartida=obtengoTope(partidasJugadas);
                    partida nuevaPartida;
                    crearPartida(nuevaPartida, proximaPartida, ci1, ci2);
                    InsBack (partidasJugadas, nuevaPartida);
                    int id1,id2;
                    id1=obtengoIdentificador(Find(inscriptos,ci1));
                    id2=obtengoIdentificador(Find(inscriptos,ci2));
                    InsertarArista(elTorne, id1, id2);
                }
            }
            break;

        default:
            printf ("\nError");
            break;
        }
    }
    else
        printf ("\nNo se puede crear mas partidas, el torneo esta por finalizar");

return 0;

}





