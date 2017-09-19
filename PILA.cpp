/*PILAS.C
         PROGRAMA EL CUAL SE MUESTRA EL USO DE LA PILA IMPLEMENTADA
         UTILIZANDO UN ARREGLO DE 100 ELEMENTOS. LA FUNION main() ES UNA
         FUNCION SENCILLA EN LA CUAL SE LE DA AL USUARIO LA OPORTUNIDAD DE 
         INTRODUCIR/SACAR 5 ELEMENTOS DE LA PILA*/
         
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define STACKSIZE 100
         
/*Definicion de tipo de datos*/
         typedef char STACKELEMENT;
typedef struct {
        int top;
        STACKELEMENT items[STACKSIZE];
        }STACK;
/*prototipos de funciones de la pila*/
void Clear(STACK *);
int Empty(STACK *);
int Full(STACK *);
STACKELEMENT Pop(STACK *);
void Push(STACK *,STACKELEMENT);

int main(){
    STACKELEMENT a;
    int p,i;
    STACK b;
    STACK *c=&b;
    b.top=-1;
/*Da la oportunidad de introducir o sacar elementos de la pila 5 veces*/
for(i=0;i<=4;i++){
                  printf("\n1.Introducir Elemento\n2.Sacar elemento\n");
                  scanf("%d",&p);
                  fflush(stdin);
                  if(p==1){
                           printf("Elemento a introducir\n");
                           scanf("%c",&a);
                           Push(c,a);
                           puts("Elemento introducido con exito!\n");
                           }else{
                                 if(p==2){
                                          if(Empty(c)){
                                                       printf("Error: Pila vacia!!\n");
                                                       getch();
                                                       exit(1);
                                                       }
                                                       else{
                                                            a=Pop(c);
                                                            printf("Elemento sacado de la pila %c\n",a);
                                                            }
                                          }
                                 else
                                     puts("Debe digitar 1 o 2\n");
                                 }
                  }
    
    
}

/*Limpia la pila*/
void Clear(STACK *ps){
     ps->top=-1;
     }
     
/*Verifica si la pila esta vacia*/
int Empty(STACK *ps){
    if(ps->top=-1)
                  return (TRUE);
    else
                  return (FALSE);
}

/*Verifica si la pila esta llena, si ya no se pueden introducir mas elementos en el arreglo*/
int Full(STACK *ps){
    if(ps->top==STACKSIZE-1)
                            return (TRUE);
    else
                            return (FALSE);
}      

/*Introduce un elemento en la pila*/
void Push(STACK *ps, STACKELEMENT x){
     if(Full(ps)){
                  printf("%s","Pila desbordada\n");
                  exit(1);
                  }
     else
                  ps->items[++(ps->top)]=x;
}   

/*Quita un elemento de la pila y lo devuelve*/
STACKELEMENT Pop(STACK *ps){
             if(Empty(ps)){
                           printf("%s","Pila subdesbordada!\n");
                           exit(1);
                           }
             return(ps->items[(ps->top)--]);
}
