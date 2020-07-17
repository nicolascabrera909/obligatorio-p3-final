/*
2. Dadas las cédulas de dos jugadores, iniciar una nueva partida entre ellos.
El número de la nueva partida será consecutivo al de la última partida registrada hasta el momento.
En caso de que esos mismos dos jugadores ya hayan disputado una partida, la operación será cancelada, emitiendo un mensaje de error.
Lo mismo en caso de que alguno de los dos jugadores no exista o de que un jugador pretenda jugar consigo mismo.

#include "torneo.h"
#include "partidas.h"
#include "jugadores.h"

void pruebaReq2 ()
{
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
            printf ("\nNo existen jugadores inscriptos");


    }
    else
        printf ("\nNo se puede crear mas partidas, el torneo esta por finalizar");



}
*/

