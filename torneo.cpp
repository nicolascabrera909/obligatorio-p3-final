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
    t[v][u]=1;
}

//Muestro si el torneo termino
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

//Verificar si dos jugadores jugaron un partido
bool JugaronPartido(torneo t,int v,int u)
{
    return t[u][v]>0;
}

