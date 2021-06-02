#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"


char descripcion[4][20]={
            "Rutera",
            "Carrera",
            "Mountain",
            "BMX"
};


int cargarDescripcionTipo(int idTipo, eTipo tipos[], int tamT, char desc[])
{
    int todoOk=0;
    if(idTipo>=1000 && idTipo<=1003 && tipos != NULL && tamT > 0 && desc != NULL)
    {

    for(int i=0;i<tamT;i++)
    {
        if(tipos[i].id == idTipo)
        {
            strcpy(desc, tipos[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    }
    return todoOk;
}
int listarTipos(eTipo lista[], int tamT)
{
    int isOk=0;

    if(lista != NULL && tamT>0)
    {

    printf("          Lista de Tipos  \n");
    printf("-----------------------------------\n");
    printf("id\t  Descripcion\n");

    for(int i=0; i<tamT; i++)
    {
        mostrarTipo(lista[i], tamT);
    }
    isOk =1;
    }
    return isOk;
}
int mostrarTipo(eTipo unTipo, int tamT)
{
    int isOk = 0;

    if(tamT >0)
    {
    printf("%d     %10s\n",unTipo.id, unTipo.descripcion);
    isOk=1;
    }
    return isOk;
}
int buscarTipo(eTipo lista[], int tamT, int idTipo)
{
     int indice=-1;

    for(int i=0;i<tamT;i++)
    {
        if(lista[i].id == idTipo)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
