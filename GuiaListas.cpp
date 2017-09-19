#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>
#define NumNode 10
#define TRUE 1
#define FALSE 0

struct nodetype{
       char info[30];
       int next;
       };
int getnode(struct nodetype *, int *);
void insafter(int *,char *,struct nodetype *,int *);
void freenode(int p,struct nodetype *);
void imprimir_lista(int,struct nodetype *);
int ultimo_lista(int, struct nodetype *);
int isempty(int);
int previo_lista(int,struct nodetype *,char *, int *);
char * delafter(int,struct nodetype *, int *);
char * remover(int *,struct nodetype *,int *);
char * leer_valor(void);

int main(){
     struct nodetype node[NumNode];
     int avail=0;
     int i,r,enc,paises=-1,herramientas=-1,alumnos=-1;
     char pais[30];
     char herra[30];
     char alum[30];     
     int salir=FALSE,opcion;
     /*Inicializacion del arreglo de nodos*/
     for(i=0;i<NumNode;i++){
     strcpy(node[NumNode-1].info,"");
     node[NumNode-1].next=-1;
     /*Menu de opciones*/
     while(!salir){
       void clrscr();  
       printf("ARREGLO CON 3 LISTAS\n");
       printf("1.Agregar pais\n2.Agregar herramienta\n");
       printf("3.Agregar nombre\n4.Imprimir listas\n");
       printf("5.Imprimir vector\n6.Borrar Pais\n7.Salir\n\n");
       puts("Seleccione una opcion: ");
       scanf("%d",&opcion);
       if(opcion==1){
       strcpy(pais,leer_valor());
       insafter(&herramientas, herra,node,&avail);
       }
       if(opcion==2){
       strcpy(herra,leer_valor());
       insafter(&herramientas,herra,node,&avail);
       }
       if(opcion==3){
       strcpy(alum,leer_valor());
       insafter(&alumnos,alum,node,&avail);
       }
       if(opcion==4){
        printf("\nPaises...\n\n");
        imprimir_lista(paises,node);
        printf("\nHerrramientas...\n\n");
        imprimir_lista(herramientas,node);
        printf("\nNombres...\n\n");
        imprimir_lista(alumnos,node);
        getch();        
       }
       if(opcion==5){
          for(i=0;i<NumNode;i++){
          printf("Node[%d]=%s %d\n,i,node[i].info,node[i].next");
          
          }
          printf("\nInicio de lista PAISES: %d\n",paises);
          printf("\nInicio de lista HERRAMIENTAS: %d\n",herramientas);
          printf("\nInicio de lista ALUMNOS: %d\n",alumnos);
          getch();
       }
       if(opcion==6){
           if(!(isempty(paises))){
                                  imprimir_lista(paises,node);
                                  printf("\nDigite nombre de pais a borrar\n");
                                  fflush(stdin);
                                  gets(pais);
                                  r=previo_lista(paises,node,pais,&enc);
                                  if(enc){
                                          if(r!=-1 && enc){
                                                   strcpy(pais,delafter(r,node,&avail));
                                                   printf("El elemento borrado de la lista paises es: %s\n",pais);
                                                   cout<<pais;
                                                   getch();
                                                   }else{
                                          if(paises!=-1 && enc)
                                          {
                                                        strcpy(pais,remover(&paises,node,&avail));
                                                        printf("El elemento borrado de la lista paises es: %s\n",pais);
                                                        getch();
                                                        }
                                          }
                                  }else{
                                        printf("Revise la lista de paises mostrada, Ese pais no esta en la lista\n");
                                        getch();
                                        }
       }//Fin de proceso si pila no esta vacia
       else{
            printf("La lista esta vacia, no hay elementos a borrar\n");
            getch();
            }
     }
       if(opcion==7){
                     salir=TRUE;
       }
    }
    }
    return 0;
}
//Funciones

/*Recupera el siguiente nodo disponible, y asigna el siguiente node disponible*/    
int getnode(struct nodetype * node,int *avail){
    int nodo;
    nodo=*avail;
    *avail=node[*avail].next;
    return nodo;
}
/*Inserta un nodo al final de una lista*/
void insafter(int *lista,char x[30],struct nodetype * node,int* avail){
     int nodo,ultimo;
     if(*avail==-1){
     printf("Fallo la inserccion, Vector lleno\n");
     getch();
     return;
     }
     nodo=getnode(node,avail);
     strcpy(node[nodo].info,x);
     if(!isempty(*lista)) //si la lista no esta vacia
     {
       ultimo=ultimo_lista(*lista,node);
       node[ultimo].next=nodo;
       node[nodo].next=-1;
       }else //si la lista esta vacia
       {
             *lista=nodo;
             node[nodo].next=-1;
             }
}

void freenode(int posicion,struct nodetype * node,int * avail){
     node[posicion].next=*avail;
     strcpy(node[posicion].info,"");
     *avail=posicion;
}

/*Recorre una lista e imprime cada valor*/
void imprimir_lista(int lista,struct nodetype * node){
     int i;
     i=lista;
     while(i!=-1){
       printf("--> %s",node[i].info);
       printf("\n");
       i=node[i].next;
     }
     printf("\n\n");
}

//Devuelve la posicion del ultimo nodo en una lista
int ultimo_lista(int lista,struct nodetype * node){
    int i,next;
    i=lista;
    while(node[i].next!=-1)
    {
       i=node[i].next;
       }
       return i;
}

//Determina si una lista esta vacia
int isempty(int lista){
    if(lista==-1)
                 return TRUE;
    else
        return FALSE;
}

//Devuelve una cadena de caracteres leida
char *leer_valor(){
     char valor[30];
     printf("\n\nDigite valor: ");
     fflush(stdin);
     gets(valor);
     return valor;
}

//Elimina un nodo despues del nodo apuntado por p en la lista
char *delafter(int p,struct nodetype * node,int * avail){
     int q;
     char b[30];
     if((p==-1)|| (node[p].next==-1)){
        printf("Fallo eliminacion\n");
        return " ";
     }
     q=node[p].next;
     strcpy(b,node[q].info);
     node[p].next= node[q].next;
     freenode(q,node,avail);
     return b;
}

/*Devuelve la posici�n del nodo previo al buscado en una lista.
La variable encon devuelve cierto si fue encontrado y falso si no.*/
int previo_lista(int lista,struct nodetype * node, char *valor, int *encon){
    int i,prev=1;
    i=lista;
    *encon=FALSE;
    if(!(isempty(lista))){
      while(! *encon && i!=-1){
         if(strcmp(node[i].info,valor)==0){
            *encon=TRUE;
            return prev;
         }
      prev=i;
      i=node[i].next;
      }
    }
return prev;
}

//Elimina un nodo al frente de la lista
char * remover(int *p,struct nodetype * node, int *avail){
     char b[30]; 
     int q;
     if(*p==-1){
        printf("Fallo eliminacion\n");
        return " ";
     }
     q=*p;
     *p=node[q].next;
     strcpy(b,node[q].info);
     freenode(q,node,avail);
     return b;   
}
