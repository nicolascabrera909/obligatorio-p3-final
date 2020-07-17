#include "torneo.h"

//Crear un torneo vacio
void Crear(torneo &t)
{
   for(int i=0;i<N;i++)
   {
      for(int j=0;j<N;j++)
      {
      t[i][j]=0;
      }
   }
}


//Agregar una partida al torneo
void InsertarArista(torneo &t, int u, int v)
{
   t[u][v]=1;
   if(u!=v)
      t[v][u]=1;
}



//mustro si el torneo termino
bool torneoFinalizado(torneo t)
{
    bool finalizado = true;
    while(finalizado)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if ((i!=j) && (t[i][j]!=1))
                {
                    finalizado = false;
                }
            }
        }
    }
    return finalizado;
}








//Mostrar torneo
void mostrarTorneo (torneo t)
{
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
            printf("%d ",t[i][j]);
        printf ("\n");
    }

}




//Verificar si dos jugadores jugaron un partido
bool JugaronPartido(torneo t,int v,int u)
{
    return t[u][v]>0;
}





//Listar en pantalla las partidas de un jugador
void listarPartidasJugador(torneo &t,int v)
{
   //printf("vertices adyacentes:");
   for(int i=0;i<N;i++)
   {
      if(t[v][i]==1)
         printf("\n%d", i);
   }
}



//Determinar cuantos partidos jugo un jugador
int partidosJugadosJugador(torneo t,int v)
{
    int resultado=0;
    for (int i=0 ; i<N; i++)
    {
        if(t[v][i]==1)
            resultado=resultado+1;
    }
    return resultado;
}




//Dadas las cédulas de dos jugadores, iniciar una nueva partida entre ellos. El número de la
//nueva partida será consecutivo al de la última partida registrada hasta el momento.
void iniciarPartida (torneo &t,int id1, int id2)
{

}

//Listar por pantalla los datos de todas las partidas
///ordenadas en forma ascendente por número de partida.
void datosPartidas (torneo t)
{

}

/*
//Torneo finalizado
///Mostrar jugador ganador
void torneoFinalizado (torneo t)
{

}*/

