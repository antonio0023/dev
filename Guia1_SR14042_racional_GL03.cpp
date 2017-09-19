/*IMPEMENTACION DE TAD RACIONAL CON FUNCIONES CREAR,SUMA Y PRODUCTO*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>  //ACA SE ENCUENTRA LA FUNCION MALLOC

typedef struct //DEFINICION DEL NUEVO TIPO DE DATO
              {
                            int num; //componente del tipo de dato
                            int deno; //componente del tipo de dato
                            } racional;
racional* crear(int,int); // prototipo de funcion crear
racional* suma(racional*,racional*);
racional* resta(racional*, racional*);
racional* division(racional*, racional*);
racional* simplificar(racional*);
main() // inicio del main
{
       int a,b,c,d,resNum,resDen,x=0;
       
       racional *ptra,*ptrb,*ptrsum,*ptrp,*ptrr,*ptrd,*ptrsim;
       //clrscr();
       printf("\n\nDIGITE EL NUM Y DENOM DEL LA 1er FRACCION\n");
       scanf("%i %i",&a,&b);//LECTURA DE ELEMENTOS DEL NUEVO TIPO DE DATO
       ptra=crear(a,b);//CREA EL PRIMER RACIONAL
       
       printf("\n\nDIGITE EL NUM Y DENOM DEL LA 2a FRACCION\n");
       scanf("%i %i",&c,&d);//LECTURA DE ELEMENTOS DEL NUEVO TIPO DE DATO
       ptrb=crear(c,d);//CREA EL SEGUNDO RACIONAL
       
       //MUESTRA LOS RACIONALES CREADOS
       printf("\n\nEl racional creado es:\t %i /%i",ptra->num,ptra->deno);
       printf("\nEl racional creado es::\t %i / %i",ptrb->num,ptrb->deno);
       
       ptrsum=suma(ptra,ptrb);//SUMA LOS 2 RACIONALES
       //PRESENTA EL RESULTADO DE LA SUMA
       printf("\n\nEl racional sumado es: \t %i / %i",ptrsum->num,ptrsum->deno);
       
       ptrr=resta(ptra,ptrb);//resta los 2 racionales
       printf("\n\nEl racional restado es :\t %i / %i",ptrr->num,ptrr->deno);
       
       ptrd=division(ptra,ptrb);//divide los 2 racionales
       printf("\n\nEl racional dividido es: \t %i /%i",ptrd->num,ptrd->deno);
       
       ptrsim= simplificar(ptra);//simplifica el racional
    printf("\nEl racional simplificado es: \t %i / %i", ptrsim->num, ptrsim->deno); 

       
       getch();
       }//fin del main
       
 //FUNCION QUE RETORNARA UN PUNTERO RACIONAL Y RECIBE 2 ENTEROS COMO PARAMETROS                                  
 racional* crear(int a,int b)
 {
           racional *res;//CREACION DE LA VARIABLE PUNTERO A RETORNAR
           res=(racional*)malloc(sizeof(racional));/*MALLOC: DEVUELVE UN CANTIDAD DE MEMORIA DEL TAMAÑO:(SIZEOF(RACIONAL))...*/
           res->num=a;//ACCESA AL COMPONENTE NUM DE RES Y LE ASIGNA EL VALOR DE A
           res->deno=b;//ACCESA AL COMPONENTE DE DENO DE RES Y LE ASIGNA EL VALOR DE B
           while(res->deno==0){//verifica si el denominador es cero
           printf("\nError el denominador no puede ser cero.");
           printf("\nIngrese el denominador: ");
           scanf("%i", &b);
           res->deno=b;
   } 
           return res; //RETORNA LA DIRECCION DEL NUEVO RACIONAL AL MAIN
 }   //FIIN DEL CREAR
 
 /* DEFINICION DE LA FUNCION SUMA:RETORNARA UN PUNTERO
 RACIONAL Y RECIBE 2 PUNTEROS DE TIPO RACIONAL COMO PARAMETROS*/
 
 racional* suma(racional *a, racional *b)
 {
           int x,y;
           racional *res;//CREACION DEL PUNTERO DE RETORNO
           //printf("\n El racional sumado es:\t %i / %i",x,y);
           res=(racional*)malloc(sizeof(racional));
           res->num=(a->num) * (b->deno)+ (a->deno) * (b->num);//OPERADORES A REALIZAR
           res->deno=(a->deno)*(b->deno);//OPERACIONES A REALIZAR
           //printf("\nEl racional sumado es:\t %i / %i",res->num,res->deno);
           return res; //RETORNA LA DIRECCION DONDE SE ENCUENTRA EL RESUL DE LA SUMA
           }//fin suma
           
           
           racional* resta(racional *a, racional *b)
           {
            int x,y;
            racional *res;// creacion del puntero de retorno
            res=(racional*)malloc(sizeof(racional));
            res->num=(a->num) * (b->deno)-(a->deno) * (b->num);//operacion a realizar 
            res->deno=(a->deno)*(b->deno);//operacion a realizar
            return res;     //retorna la direcion donde se encuentra el resultado de la resta
                  }//fin de resta
                  
           
           racional* division(racional*a, racional*b)
           {
             racional *res;//Crea el puntero de retorno
             res=(racional*)malloc(sizeof (racional));
             res->num=(a->num)*(b->deno);//operaciones a realizar
             res->deno=(a->deno)*(b->num);//operaciones a realizar
             return res;//retorna la direccion donde se encuentra el resultado de la division
            }  //fin division

            racional* simplificar(racional *a)
           {       
                   racional *res;//crea el puntero de retorno
                   res=(racional*)malloc(sizeof(racional));
                   res->num= a->num;
                   res->deno= a->deno;
                   int b=2;          
                       if(res->deno==1){
                       return res;
                       }
                       else
                       {
                       int b=2;
                       while(b<=res->num){
                       if(res->deno%b==0 && res->num%b==0){
                       res->deno= res->deno/b;
                       res->num=res->num/b;
                       }else{
                       b++;
                 }
              }                
              }
        return res;
        }//fin simplificacion
               
