#include "informes.h"


int listarBicicletasColor(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC,
                          eCliente clientes[], int tamCl)
{
    int color;
    int indice;
    int flag=0;
    int isOk=0;

    if(lista != NULL && tam>0 && tipos != NULL && tamT >0 && colores != NULL && tamC >0 && clientes != NULL && tamCl > 0)
    {
        system("cls");
        printf("    Informe de Bicicletas de un color\n");
        listarColores(colores, tamC);
        pedirEntero(&color, "Ingrese Id Color ", "Error.");
        indice = buscarColor(colores, tamC, color);
        while(indice == -1)
        {
            pedirEntero(&color, "Ingrese Id Color ", "Error.");
            indice = buscarColor(colores, tamC, color);
        }
        printf("                        Lista de bicicletas segun color: %s\n", colores[indice].nombreColor);
        printf("----------------------------------------------------------------\n");
        printf("id\t     Marca        Tipo         Color    Rodado    Cliente\n");

        for(int i =0; i<tam; i++)
        {
            if(lista[i].idColor == color && lista[i].isEmpty == 0)
            {
                mostrarBicicleta(lista[i], tam, tipos, tamT, colores, tamC, clientes, tamCl);
                flag = 1;
            }

        }
        if(!flag)
        {
            printf("No hay bicicletas con ese color\n");
        }
        isOk=1;
    }
    return isOk;
}
int mostrarBiciPorTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                       int tamC, eCliente clientes[], int tamCl)
{
    int tipo;
    int indice;
    int flag=0;
    int isOk=0;

    if(lista != NULL && tam>0 && tipos != NULL && tamT >0 && colores != NULL && tamC >0 && clientes != NULL && tamCl > 0)
    {
        system("cls");
        printf("    Informe de Bicicletas de un tipo\n");
        listarTipos(tipos, tamT);
        pedirEntero(&tipo, "Ingrese Id tipo ", "Error.");
        indice = buscarTipo(tipos, tamT, tipo);
        while(indice == -1)
        {
            pedirEntero(&tipo, "Ingrese Id Tipo ", "Error.");
            indice = buscarTipo(tipos, tamT, tipo);
        }
        printf("                        Lista de bicicletas segun tipo: %s\n", tipos[indice].descripcion);
        printf("----------------------------------------------------------------\n");
        printf("id\t     Marca        Tipo         Color    Rodado    Cliente\n");

        for(int i =0; i<tam; i++)
        {
            if(lista[i].idTipo == tipo && lista[i].isEmpty == 0)
            {
                mostrarBicicleta(lista[i], tam, tipos, tamT, colores, tamC, clientes, tamCl);
                flag = 1;
            }

        }
        if(!flag)
        {
            printf("No hay bicicletas con ese tipo\n");
        }
        isOk=1;
    }
    return isOk;
}
int mostrarMenorRodado(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC,
                       eCliente clientes[], int tamCl)
{
    int isOk=0;
    float menorRodado;
    int flag=1;
    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(flag || lista[i].rodado < menorRodado )
            {
                menorRodado = lista[i].rodado;
                flag=0;
            }

        }
        printf("                        Lista de bicicletas con el menor rodado: \n");
        printf("----------------------------------------------------------------\n");
        printf("id\t     Marca        Tipo         Color    Rodado    Cliente\n");

        for(int j=0; j<tam; j++)
        {
            if(lista[j].rodado == menorRodado)
            {
                mostrarBicicleta(lista[j], tam, tipos, tamT, colores, tamC, clientes, tamCl);
                isOk=1;
            }
        }


    }
    return isOk;
}
int listarBiciSegunTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                        int tamC, eCliente clientes[], int tamCl)
{
    int flag;
    int isOk=0;

    if(lista != NULL && tam>0 && tipos != NULL && tamT >0 && colores != NULL && tamC >0 && clientes != NULL && tamCl > 0)
    {
        system("cls");
        printf("    ****Informe de Bicicletas de por tipo******\n");

        for(int i=0; i<tamT; i++)
        {
            printf("                        Lista de bicicletas tipo: %s\n", tipos[i].descripcion);
            printf("----------------------------------------------------------------\n");
            printf("id\t     Marca        Tipo         Color    Rodado    Cliente\n");
            flag=0;
            for(int j =0; j<tam; j++)
            {
                if(lista[j].idTipo == tipos[i].id && lista[j].isEmpty == 0)
                {
                    mostrarBicicleta(lista[j], tam, tipos, tamT, colores, tamC, clientes, tamCl);
                    flag = 1;
                }
            }
            if(!flag)
            {
                printf("No hay bicicletas con este tipo\n");
            }


        }
        isOk=1;
    }
    return isOk;
}
int mostrarBiciTipoYColor(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                          int tamC, eCliente clientes[], int tamCl)
{
    int tipo;
    int indiceTipo;
    int color;
    int indiceColor;
    int flag=0;
    int isOk=0;
    int contadorBici=0;

    if(lista != NULL && tam>0 && tipos != NULL && tamT >0 && colores != NULL && tamC >0 && clientes != NULL && tamCl > 0)
    {
        system("cls");
        printf("    \n***Informe de Bicicletas de un tipo y Color***\n");
        listarTipos(tipos, tamT);
        pedirEntero(&tipo, "Ingrese Id tipo ", "Error.");
        indiceTipo = buscarTipo(tipos, tamT, tipo);
        while(indiceTipo == -1)
        {
            pedirEntero(&tipo, "Ingrese Id Tipo ", "Error.");
            indiceTipo = buscarTipo(tipos, tamT, tipo);
        }
        listarColores(colores, tamC);
        pedirEntero(&color, "Ingrese Id color ", "Error.");
        indiceColor = buscarColor(colores, tamC, color);
        while(indiceColor == -1)
        {
            pedirEntero(&tipo, "Ingrese Id Color ", "Error.");
            indiceColor = buscarColor(colores, tamC, color);
        }

        for(int i =0; i<tam; i++)
        {
            if(lista[i].idTipo == tipo && lista[i].idColor == color && lista[i].isEmpty == 0)
            {
                contadorBici++;
                flag = 1;
            }

        }
        if(!flag)
        {
            printf("No hay bicicletas con ese tipo y color\n");
        }
        printf("  Hay %d bicicleta/s tipo: %s y color: %s\n", contadorBici, tipos[indiceTipo].descripcion,
               colores[indiceColor].nombreColor);
        isOk=1;
    }
    return isOk;

}
int mostrarColorMasElegido(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC,
                           eCliente clientes[], int tamCl)
{
    int contadorRojo=0;
    int contadorGris=0;
    int contadorBlanco=0;
    int contadorNegro=0;
    int contadorAzul=0;
    int isOk=0;

    if(lista != NULL && tam>0 && tipos != NULL && tamT >0 && colores != NULL && tamC >0 && clientes != NULL && tamCl > 0)
    {
        system("cls");
        printf("    Informe de Bicicletas del color mas elegido\n");

        for(int i =0; i<tam; i++)
        {
            for(int j=0; j<tamC; j++)
            {
                if(lista[i].idColor == colores[j].id && lista[i].isEmpty == 0)
                {
                    switch(colores[j].id)
                    {
                    case 5003:
                        contadorAzul++;
                        break;
                    case 5002:
                        contadorBlanco++;
                        break;
                    case 5001:
                        contadorNegro++;
                        break;
                    case 5000:
                        contadorGris++;
                        break;
                    case 5004:
                        contadorRojo++;
                        break;
                    }
                }

            }
        }
        if(contadorAzul > contadorBlanco && contadorAzul > contadorGris && contadorAzul > contadorNegro && contadorAzul > contadorRojo)
        {
            printf(" El color mas elegido es Azul\n");
        }
        else if(contadorBlanco >= contadorAzul && contadorBlanco > contadorGris && contadorBlanco > contadorNegro && contadorBlanco > contadorRojo)
        {
            printf(" El color mas elegido es Blanco\n");
        }
        else if(contadorGris >= contadorBlanco && contadorGris >= contadorAzul && contadorGris > contadorNegro && contadorGris > contadorRojo)
        {
            printf(" El color mas elegido es Gris\n");
        }
        else if(contadorNegro >= contadorBlanco && contadorNegro >= contadorAzul && contadorNegro > contadorGris && contadorNegro > contadorRojo)
        {
            printf(" El color mas elegido es Negro\n");
        }
        else
        {
            printf(" El color mas elegido es Rojo\n");
        }
        isOk=1;
    }
    return isOk;
}
int mostrarTrabajosBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                             int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                             eServicio servicios[], int tamS)
{
    int isOk=0;
    int idBicicleta;
    if(lista != NULL && tam>0 && tipos != NULL && tamT >0 && colores != NULL && tamC >0 && clientes != NULL && tamCl > 0)
    {
        listarBicicletas(lista, tam, tipos, tamT, colores, tamC, clientes, tamCl);
        pedirEntero(&idBicicleta, "Ingresar id Bicicleta: ", "Error. ");

        printf("                        Lista de Trabajos  \n");
        printf("----------------------------------------------------------------\n");
        printf("id   ID Bicicleta    Servicio    Fecha de trabajo\n");
        for(int i=0; i<tamTr; i++)
        {
            if(trabajos[i].idBicicleta == idBicicleta)
            {
                mostrarTrabajo(trabajos[i], tamTr, servicios, tamS);
            }
            isOk=1;
        }
    }
    return isOk;
}
int mostrarImportesBici(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                        int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                        eServicio servicios[], int tamS)
{
    int isOk=0;
    int idBicicleta;
    float importe=0;
    if(lista != NULL && tam>0 && tipos != NULL && tamT >0 && colores != NULL && tamC >0 && clientes != NULL && tamCl > 0)
    {
        listarBicicletas(lista, tam, tipos, tamT, colores, tamC, clientes, tamCl);
        pedirEntero(&idBicicleta, "Ingresar id Bicicleta: ", "Error. ");

        for(int i=0; i<tam; i++)
        {
            if(lista[i].id == idBicicleta && !lista[i].isEmpty)
            {
                for(int j=0; j<tamTr; j++)
                {
                    if(trabajos[j].idBicicleta == lista[i].id && !trabajos[j].isEmpty)
                    {
                        for(int k=0; k<tamS; k++)
                        {
                            if(servicios[k].id == trabajos[j].idServicio)
                            {
                                importe += servicios[k].precio;
                            }
                        }
                    }
                }
            }
            isOk=1;
        }
        printf("Total Importe Servicios bicicleta: $%.2f\n", importe);
    }
    return isOk;
}
//Pedir un servicio y mostrar las bicicletas a las que se les realizo ese servicio y la fecha.
int mostrarServiciosBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                              eServicio servicios[], int tamS)
{
    int servicio;
    int indice;
    int flag=0;
    int isOk=0;

    if(lista != NULL && tam>0 && tipos != NULL && tamT >0 && colores != NULL && tamC >0 && clientes != NULL && tamCl > 0)
    {
        printf("    Informe de Bicicletas con un serivicio\n");
        listarServicios(servicios, tamS);
        pedirEntero(&servicio, "Ingrese Id servicio ", "Error.");
        indice = buscarServicio(servicios, tamS, servicio);
        while(indice == -1)
        {
            pedirEntero(&servicio, "Ingrese Id servicio ", "Error.");
            indice = buscarServicio(servicios, tamS, servicio);
        }
        printf("                        Lista de bicicletas segun servicio: %s\n", servicios[indice].descripcion);
        printf("----------------------------------------------------------------\n");

        for(int j=0; j<tamTr; j++)
        {
            if(trabajos[j].idServicio == servicio && !trabajos[j].isEmpty)
            {

                for(int i =0; i<tam; i++)
                {
                    if(lista[i].id == trabajos[j].idBicicleta && lista[i].isEmpty == 0)
                    {
                        printf(" %02d/%02d/%d:\n", trabajos[j].fecha.dia, trabajos[j].fecha.mes, trabajos[j].fecha.anio);
                        printf("---------------------------\n");
                        printf("id\t     Marca        Tipo         Color    Rodado    Cliente\n");
                        mostrarBicicleta(lista[i], tam, tipos, tamT, colores, tamC, clientes, tamCl);
                        flag = 1;
                    }

                }
                if(!flag)
                {
                    printf("No hay bicicletas con ese color\n");
                }
            }
        }
        isOk=1;
    }
    return isOk;
}
//Pedir una fecha y mostrar todos los servicios realizados en la misma.
