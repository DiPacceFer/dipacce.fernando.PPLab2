#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eTipo;


#endif // TIPO_H_INCLUDED

/**
* \brief Recorre el array tipos y devuelve la descripcion del id solicitado
* \ param int idTipo numero de id del tipo que se quiere obtener la descripcion
* \ param eTipo tipos array de tipos
* \ param int tamT tamaño del array tipos
* \ param char desc puntero donde debe cargar la descripcion del tipo
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int cargarDescripcionTipo(int idTipo, eTipo tipos[], int tamT, char desc[]);
/**
* \brief imprime un tipo
* \ param eTipo unTipo array que se quiere mostrar
* \ param int tamT tamaño del array tipos
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int mostrarTipo(eTipo unTipo, int tamT);
/**
* \brief imprime listado de tipos
* \ param eTipo lista array que se quiere mostrar listado
* \ param int tamT tamaño del array tipos
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int listarTipos(eTipo lista[], int tamT);
/**
* \brief busca un vector dentro del array tipo y devuelve el indice
* \ param eTipo lista array donde se realiza la busqueda
* \ param int tam tamaño del array lista
* \ param int idTipo numero de id que se desea buscar
* \
* \return Retorna el indice del tipo solicitado o -1 si no encontro
*/
int buscarTipo(eTipo lista[], int tamT, int idTipo);
