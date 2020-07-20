#include "jugadores.h"
#include "torneo.h"
#include "jugador.h"
#include "partidas.h"
#include <stdlib.h>



int main()
{
    bool salir = false;
    //DECLARO VARIABLES GLOBALES
    torneo elTorneo;
    Crear(elTorneo);
    jugadores inscriptos;
    Make(inscriptos);
    Partidas partidasJugadas;
    Make(partidasJugadas);
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
        fflush(stdin);
        string comando;
        cargarString(comando);
        if(!stringVacio(comando))
        {
            int opcion;
            opcion = convertirString(comando);
            switch (opcion)
            {
            case 1:
            {
                if (!hayJugadores(inscriptos))
                {
                    jugador elJugador;
                    string cedula, nombre, apellido, departamento;
                    strCrear (cedula);
                    strCrear (nombre);
                    strCrear (apellido);
                    strCrear (departamento);
                    int canJugadores = 1;
                    int ciJugador;
                    while (canJugadores <= N)
                    {
                        printf ("Ingrese cedula del jugador: ");
                        fflush(stdin);
                        cargarString(cedula);
                        if (esNumero(cedula))
                        {
                            ciJugador = convertirString(cedula);
                            if (!Member(inscriptos,ciJugador))
                            {
                                printf ("Ingrese nombre del jugador: ");
                                fflush(stdin);
                                cargarString(nombre);
                                if (esSoloLetras(nombre))
                                {
                                    printf ("Ingrese apellido del jugador: ");
                                    fflush(stdin);
                                    cargarString(apellido);
                                    if (esSoloLetras(apellido))
                                    {
                                        printf ("Ingrese departamento del jugador: ");
                                        fflush(stdin);
                                        cargarString(departamento);
                                        if (esSoloLetras(departamento))
                                        {
                                            crearJugador(elJugador, canJugadores, ciJugador, nombre, apellido, departamento);
                                            Insert(inscriptos,elJugador);
                                            canJugadores++;
                                            printf ("\n");

                                        }
                                        else
                                            printf ("Error: El departamento del jugador no es valido. Ingrese los datos nuevamente.\n");
                                    }
                                    else
                                        printf ("Error: El apellido del jugador no es valido. Ingrese los datos nuevamente.\n");
                                }
                                else
                                    printf ("Error: El nombre del jugador no es valido. Ingrese los datos nuevamente.\n");
                            }
                            else
                                printf ("Error: El jugador ya esta inscripto en el torneo. Ingrese los datos nuevamente.\n");
                        }
                        else
                            printf ("Error: La cedula del jugador no es correcta. Ingrese los datos nuevamente.\n");
                    }
                }
                else
                    printf ("Error: Los jugadores ya fueron inscriptos en el torneo.\n");
                system("cls");
                printf ("\n** Jugadores registrados en el torneo **");
                mostrarJugadores(inscriptos);
            }
            break; //Fin case 1
            case 2:
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

                    if(hayJugadores(inscriptos))
                    {
                        if (Member(inscriptos, ci1))
                            contadorExist++;
                        if(Member(inscriptos, ci2))
                            contadorExist=contadorExist+2;

                        switch (contadorExist)
                        {

                        case 0:
                            printf ("\nLos documentos ingresados son incorrectos ");
                            break;

                        case 1:
                            printf ("\nEl documento ingresado para el jugador2 no existe ");
                            break;

                        case 2:
                            printf ("\nEl documento ingresado para el jugador1 no existe ");
                            break;


                        case 3:
                            if(ci1==ci2)
                                printf ("\nLos documentos son iguales, ingrese dos documentos diferentes");
                            else
                            {
                                if(JugaronPartido(elTorneo,ci1,ci2))
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
                                    InsertarArista(elTorneo, id1, id2);
                                }
                            }
                            break;

                        default:
                            printf ("\nError");
                            break;
                        }
                    }
                    else
                        printf ("\nNo existen jugadores inscriptos");


                }
                else
                    printf ("\nNo se puede crear mas partidas, el torneo esta por finalizar");
                break; //Fin case 2
            case 3:
            {
                int numPartida=0;
                printf("\nIngrese el numero de partida que quiere finalizar:");
                scanf("%d",&numPartida);
                if(existePartida (numPartida, partidasJugadas))
                {
                    partida laPartida=obtengoPartida(partidasJugadas,numPartida);
                    if(partidaFinalizada(laPartida))
                    {
                        int opcion;
                        int j1,j2;
                        jugador ganador,perdedor;
                        obtengoCiJugadores(laPartida,j1,j2);
                        printf("\nCI Jugador 1: %d",j1);
                        printf("\nCI Jugador 2: %d",j2);
                        printf("\nIngrese el numero del jugador ganador (1/2): ");
                        scanf("%d",&opcion);
                        switch (opcion)
                        {
                        case 1:
                            finalizarLaPartida(laPartida);
                            cargarGanador(laPartida, j1);
                            ganador=Find(inscriptos,j1);
                            perdedor=Find(inscriptos,j2);
                            incrementarGanadas (ganador);
                            incrementarJugadas (ganador);
                            incrementarJugadas (perdedor);
                            break;

                        case 2:
                            finalizarLaPartida(laPartida);
                            cargarGanador(laPartida, j2);
                            ganador=Find(inscriptos,j2);
                            perdedor=Find(inscriptos,j1);
                            incrementarGanadas (ganador);
                            incrementarJugadas (ganador);
                            incrementarJugadas (perdedor);
                            break;

                        default:
                            printf("\nLa opcion ingresada no es correcta");
                            break;
                        }
                    }
                    else
                        printf("\nLa partida no esta finalizada");
                }
                else
                    printf("\nEl numero de partida ingresado no existe");
            }
            break; //Fin case 3
            case 4:
                break; //Fin case 4
            case 5:
                break; //Fin case 5
            case 6:
                break; //Fin case 6
            case 7:
                break; //Fin case 7
            case 8:
            {
                char opcSalir;
                printf("\nDesea salir del torneo? S/N: ");
                fflush(stdin);
                scanf("%c",&opcSalir);
                if (torneoFinalizado(elTorneo))
                {
                    switch (opcSalir)
                    {
                    case 'S':
                    case 's':
                        printf("Hasta la proxima!");
                        salir = true;
                    }
                }
                else
                    printf ("Error: El torneo no ha finalizado.\n");
            }
            break; //Fin case 8
            default:
                printf ("\nIngrese comando valido.");
            }
        }
        else
        {
            system("cls");
            printf("No ha digitado ningun comando, por favor ingrese uno.\n");
        }
    }
    while (!salir);
}


