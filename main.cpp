int main()
{/*
    bool salir = false;
    //DECLARO VARIABLES GLOBALES
    torneo elTorneo;
    jugadores inscriptos;
    Make(inscriptos);
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
                break; //Fin case 2
            case 3:
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
                    printf ("Error: El torneo no ha finalizado.");
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
    while (!salir);*/

    string prueba;
    strCrear(prueba);
    printf ("Ingrese cedula: ");
    fflush(stdin);
    cargarString(prueba);
    if(esNumero(prueba))
        printf("\nCedula valida");
    else
        printf ("\nCedula invalida");
    }