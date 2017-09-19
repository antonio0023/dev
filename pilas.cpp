/* Estructura de datos pila, elementos fundamentales para operar:
              inicializar, ingresar un valor(apilar), eliminar un valor (desapilar)
              y mostrar la pila.
              
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nodo{
               char *dato;
               struct Nodo *siguiente;
        }Elemento;
typedef struct ListaUbicacion{
        Elemento *inicio;
        int tamanio;
        }Pila;
        
void inicializar(Pila *tas);
int apilar(Pila *tas, char *dato);
int desapilar(Pila *tas);
void mostrarPila(Pila *tas);
//aca el main, o cualquier funcion

void inicializar(Pila *tas){
     tas->inicio=NULL;
     tas->tamanio=0;
}
int apilar(Pila *tas, char *dato){
    Elemento  *nuevoElemento;
    if((nuevoElemento=(Elemento*)malloc(sizeof(Elemento)))==NULL)
                                                                 return -1;
    strcpy (nuevoElemento->dato,dato);
    nuevoElemento->siguiente= tas->inicio;
    tas->inicio= nuevoElemento;
    tas->tamanio++;            
}
int desapilar(Pila *tas){
    Elemento *supElemento;
    if(tas->tamanio==0)
                       return -1;
    supElemento= tas->inicio;
    tas->inicio=tas->inicio->siguiente;
    free(supElemento->dato);
    free(supElemento);
    tas->tamanio--;
    return 0;
}       
void mostrarPila(Pila *tas){
     Elemento *actual;
     int j;
     actual= tas->inicio;
     for(j=0;j<tas->tamanio;j++){
                                 printf("\t\t%s\n",actual->dato);
                                 actual=actual->siguiente;
                                 }
} 
        
