#include "string.h"

//Crear string con puntero
void strCrear(string &s)
{
    s= new char[1];
    s[0]='\0';
}


//Cargar string ingresado por teclado
void cargarString (string &s)
{
    int i=0;
    char car;
    string auxS= new char[MAX];
    //Solicitar en el main el texto a cargar
    scanf ("%c", &car);
    while (car !='\n' && i < MAX-1)
    {
        auxS[i] = car;
        i++;
        scanf ("%c", &car);
    }
    auxS[i]='\0';
    liberarMemoriaString(s);
    s= new char[i];
    s=auxS;
}

//Mostrar string en pantalla
void mostrarString (string s)
{
    int i=0;
    //Soliciar en el main lo que se quiere mostrar
    while (s[i] != '\0')
    {
        printf("%c",s[i]);
        i++;
    }
}

//Largo del string
int strlar (string s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}


//Dice si el string es vacio
bool stringVacio (string s)
{

    bool resultado=false;
    //Soliciar en el main lo que se quiere mostrar
    if(s [0] == '\0')
        resultado=true;
    return resultado;
}

//Libera memoria dinamica del string
void liberarMemoriaString (string &s)
{
    delete []s ;
   // s = NULL;
    strCrear(s);
}

//Copiar el segundo string en el primero
void strcop(string &texto1, string  texto2)
{
    int i=0;
    liberarMemoriaString(texto1);
    int largo=strlar(texto2)+1;
    texto1=new char[largo];
    while(texto2[i]!='\0')
    {
        texto1[i]=texto2[i];
        i++;
    }
    texto1[i]='\0';
}

//Agrego de a un carater a un string
void agregoCharAString(char a, string &s)
{
    int largo=2;
    string auxS= new char[largo];
    auxS[0] = a;
    auxS[1]='\0';
    strcon(s,auxS);
    liberarMemoriaString(auxS);
}

//Concateno string, segundo en el primero
void strcon(string &texto1,string texto2)
{

    int i=0,j=0,largoT2=0,largoT1;
    string auxS;
    largoT2=strlar(texto2);
    largoT1=strlar(texto1);
    auxS=new char[largoT1+1];
    strcop(auxS,texto1);
    liberarMemoriaString(texto1);
    texto1=new char[largoT1+largoT2+1];
    while(auxS[i]!='\0')

    {
        texto1[i]=auxS[i];
        i++;
    }
    while(texto2[j]!='\0')
    {
        texto1[i]=texto2[j];
        i++;
        j++;
    }
    liberarMemoriaString(auxS);
    texto1[i]='\0';
}

bool comparoString(string texto1, string texto2)
{
    int i=0;
    bool resultado=true;
    while(texto1[i]!='\0' && texto2[i]!='\0' && resultado)
    {
        if(texto1[i]!=texto2[i])
            resultado=false;
        else
            i++;
    }
    if(texto1[i]!=texto2[i]&& resultado )
        resultado=false;
    return resultado;
}



