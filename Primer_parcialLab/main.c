#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bicicleta.h"
#include "trabajo.h"
#include "color.h"
#include "validaciones.h"
#include "menu.h"
#include "tipo.h"
#include "servicio.h"
#include "informes.h"

#define TAMBICI 10
#define TAMTIPO 4
#define TAMCOLOR 5
#define TAMTRABAJO 14
#define TAMSERV 4
#define TAMCLIENTES 7

int main()
{

    eBicicleta bicicletas[TAMBICI]={
                {100, "Vaio", 1000, 5002, 20, 0, 7003},
                {101, "Carmen", 1003, 5001, 27.5, 0, 7005},
                {102, "Jose", 1003, 5000, 20, 0, 7000},
                {103, "Estilo", 1002, 5004, 26, 0, 7002},
                {104, "Vaio", 1001, 5002, 29, 0, 7002},
                {105, "Flic", 1002, 5004, 26, 0, 7000},
                {106, "Candado", 1003, 5002, 20, 0, 7002},
                {107, "Pino", 1000, 5000, 26, 0, 7001},
                {108, "Estilo", 1001, 5001, 27.5, 0, 7004},
                {109, "Flic", 1000, 5003, 20, 0, 7005}
    };

    eTrabajo trabajos[TAMTRABAJO]={
                {800, 102, 20003, {4,8,2008},0},
                {801, 102, 20000, {4,8,2008},0},
                {802, 101, 20001, {8,4,2017},0},
                {803, 100, 20000, {29,12,2014},0},
                {804, 104, 20001, {19,10,2020},0},
                {805, 103, 20002, {21,6,2019},0},
                {806, 102, 20002, {30,1,2020},0},
                {807, 109, 20000, {4,10,2021},0},
                {808, 107, 20002, {18,10,2019},0},
                {809, 106, 20002, {29,12,2021},0},
                {810, 105, 20003, {23,5,2014},0},
                {811, 109, 20001, {15,1,2019},0},
                {812, 106, 20003, {11,6,2021},0},
                {813, 108, 20000, {12,7,2017},0},
                 };
    eColor colores[TAMCOLOR]={
                {5000, "Gris"},
                {5001, "Negro"},
                {5002, "Blanco"},
                {5003, "Azul"},
                {5004, "Rojo"}
                };
    eTipo tipos[TAMTIPO]={
                {1000, "Rutera"},
                {1001, "Carrera"},
                {1002, "Mountain"},
                {1003, "BMX"}
                };
    eServicio servicios[TAMSERV]={
                {20000, "Limpieza",250},
                {20001, "Parche", 300},
                {20002, "Centrado", 400},
                {20003, "Cadena",350}
                };
    eCliente clientes[TAMCLIENTES]={
                {7000, "Fernando", 'm', 0},
                {7001, "Eugenia", 'f', 0},
                {7002, "Delfina", 'f', 0},
                {7003, "Carlos", 'm', 0},
                {7004, "Romina", 'f', 0},
                {7005, "Martin", 'm', 0},
                {7006, "Emilio", 'm', 0}
    };

    char salir = 'n';
    int nextBicicleta=100;
    int nextTrabajo=100;
    //int nexCliente = 7000;
    int flagBicicleta = 1;
    int flagTrabajos = 1;
    //inicializarBicicletas(bicicletas, TAMBICI);
    //inicializarTrabajo(trabajos, TAMTRABAJO);


    do
    {
            switch(menu())
            {
            case 'A':
                system("cls");
                altaBicicleta(bicicletas, TAMBICI, &nextBicicleta, clientes, TAMCLIENTES, colores, TAMCOLOR, tipos, TAMTIPO);
                flagBicicleta = 1;
                break;
            case 'B':
                system("cls");
                if(flagBicicleta)
                {
                    modificarBicicleta(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                    system("pause");
                }
                else
                {
                    printf("primero debe dar de alta bicicleta\n");
                    system("pause");
                }
                break;
            case 'C':
                system("cls");
                if(flagBicicleta)
                {
                    bajarBicicleta(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                    system("pause");
                }
                else
                {
                    printf("primero debe dar de alta bicicleta\n");
                    system("pause");
                }
                break;
            case 'D':
                system("cls");
                if(flagBicicleta)
                {
                    ordenarBicicletas(bicicletas, TAMBICI);
                    listarBicicletas(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                    system("pause");
                }
                else
                {
                    printf("primero debe dar de alta bicicleta\n");
                    system("pause");
                }
                break;
            case 'E':
                system("cls");
                listarTipos(tipos, TAMTIPO);
                system("pause");
                break;
            case 'F':
                system("cls");
                listarColores(colores, TAMCOLOR);
                system("pause");
                break;
            case 'G':
                system("cls");
                listarServicios(servicios, TAMSERV);
                system("pause");
                break;
            case 'H':
                system("cls");
                altaTrabajo(trabajos, TAMTRABAJO, &nextTrabajo, bicicletas, TAMBICI, servicios, TAMSERV, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                flagTrabajos=1;
                break;
            case 'I':
                system("cls");
                if(flagTrabajos)
                {
                    listarTrabajos(trabajos, TAMTRABAJO, servicios, TAMSERV);
                    system("pause");
                }
                else
                {
                    printf("primero debe dar de alta trabajo\n");
                    system("pause");
                }
                break;
            case 'J':
                listarBicicletasColor(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                system("pause");
                break;
            case 'K':
                mostrarBiciPorTipo(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                system("pause");
                break;
            case 'L':
                mostrarMenorRodado(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                system("pause");
                break;
            case 'M':
                listarBiciSegunTipo(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                system("pause");
                break;
            case 'N':
                mostrarBiciTipoYColor(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                system("pause");
                break;
            case 'O':
                mostrarColorMasElegido(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES);
                system("pause");
                break;
            case 'P':
                system("cls");
                mostrarTrabajosBicicleta(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES, trabajos, TAMTRABAJO, servicios, TAMSERV);
                system("pause");
                break;
            case 'Q':
                system("cls");
                mostrarImportesBici(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES, trabajos, TAMTRABAJO, servicios, TAMSERV);
                system("pause");
                break;
            case 'R':
                system("cls");
                mostrarServiciosBicicleta(bicicletas, TAMBICI, tipos, TAMTIPO, colores, TAMCOLOR, clientes, TAMCLIENTES, trabajos, TAMTRABAJO, servicios, TAMSERV);
                system("pause");
                break;
            case 'S':
                printf("falta\n");
                break;
            case 'T':
                salir = 's';
                break;
            default:
                printf("No es una opcion valida\n");
                system("pause");
                break;
                }



    }while(salir == 'n');


    return 0;
}
