/* IMPLEMENTACION DE TAD RACIONAL CON FUNCIONES CREAR, SUMA Y PRODUCTO */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>  //ACA SE ENCUENTRA LA FUNCION MALLOC
typedef struct //DEFINICION DEL NUEVO TIPO DE DATO
        {
               int num; //numerador
               int deno; // denominador
               }racional;
racional* crear(int,int); //prototipo de funcion crear
racional* suma(racional*,racional*); //prototipo de suma
racional* resta(racional*,racional*); //prototipo de resta
racional* division(racional*,racional*); //prototipo de division
 racional* simplificar(racional *a);
 racional* simplificarres(racional *ptrres);

main() //inicio del Main
{
       int a,b,c,d,resNum,resDen,x=0;

       racional *ptra, *ptrb, *ptrsum, *ptrres, *ptrdiv, *ptrp, *ptrsimp, *ptrsimpl;
       //clrscr();
       printf("\n\nDIGITE EL NUM Y DENOM DE LA 1er FRACCCION\n");
       scanf("%i%i",&a,&b); //lectura de elementos del nuevo tipo de dato
       ptra=crear(a,b); //crea el primer racional

       printf("\n\nDIGITE EL NUM Y DENOM DE LA 2da FRACCION\n");
       scanf("%i%i",&c,&d);
       ptrb=crear(c,d);

       //Muestra los racionales creados
       printf("\nEl racional creado es:\t%i/%i",ptra->num,ptra->deno);
       printf("\nEl racional creado es:\t%i/%i\n\n\n",ptrb->num,ptrb->deno);

       ptrsum=suma(ptra,ptrb); //suma los dos racionales
       printf("\n++El racional sumado es:\t%i/%i",ptrsum->num,ptrsum->deno); //muestra el resultado de la suma

       ptrres=resta(ptra,ptrb);//resta los dos racionales
       printf("\n--El racional restado es\t%i/%i",ptrres->num,ptrres->deno);

       ptrdiv=division(ptra,ptrb);
       printf("\n--El racional dividido es\t%i/%i",ptrdiv->num,ptrdiv->deno);

       ptrsimp= simplificar(ptra);//simplifica el racional
       printf("\n\n\n^^El racional simplificado de la suma es: \t %i / %i", ptrsimp->num, ptrsimp->deno);
       ptrsimpl= simplificar(ptra);//simplifica el racional
       printf("\n\n\n^^El racional simplificado de la resta es: \t %i / %i", ptrsimpl->num, ptrsimpl->deno);
       
       getch();

} //FIN DEL MAIN

//FUNCION QUE RETORNARA UN PUNTERO RACIONAL Y RECIBE 2 ENTEROS COMO PARAMETROS
racional* crear(int a, int b)
{
  racional *res; //CREACION DE LA VARIABLE PUNTERO A RETORNAR
  res=(racional*)malloc(sizeof(racional));/* MALLOC: DEVUELVAME UNA CANTIDAD DE MEMORIA
                                            DEL TAMANO: (SIZEOF(RACIONAL))...*/

  res->num=a; //ACCESA AL COMPONENTE NUM DE RES Y LE ASIGNA EL VALOR DE a
  res->deno=b;//ACCESA AL COMPONENTE DENO DE RES Y LE ASIGNA EL VALOR DE b

return res;//RETORNA LA DIRECCION DEL NUEVO RACIONAL AL MAIN
}//FIN DE CREAR

/*DEFINICION DE LA FUNCION SUMA: RETORNARA UN PUNTERO
RACIONAL Y RECIBE 2 PUNTEROS DE TIPO RACIONAL COMO PARAMETROS */
racional* suma(racional* a,racional* b)

{

          racional* total; //creacion del puntero de retorno
          total=(racional*)malloc(sizeof(racional));
          total->num=(a->num)*(b->deno)+(a->deno)*(b->num);  //OPEACIONES A REALIZAR
          total->deno=(a->deno)*(b->deno);
          //OPERACIONES A REALIZAR

          return total;
}//FIN DE SUMA

/*DEFINICION DE LA FUNCION RESTA: RETORNARA UN PUNTERO RACIONAL
Y RECIBE 2 PUNTEROS DE TIPO RACIONAL COMO PARAMETROS*/
racional* resta(racional* a,racional* b)
{

          racional* total;
          total=(racional*)malloc(sizeof(racional));
          //OPERACION RESTA
          total->num=(a->num)*(b->deno)-(a->deno)*(b->num);
          total->deno=(a->deno)*(b->deno);
          // FIN DE OPERACION RESTA
          return total;
}//FIN DE RESTA

/*DEFINICION DE LA FUNCION DIVIDIR: RETORNARA UN PUNTERO RACIONAL, RECIBE DOS PUNTEROS DEL
TIPO RACIONAL COMO PARAMETROS PARA SU POSTERIOR DIVISION Y MOSTRAR EL RESULTADO */
racional* division(racional* a,racional* b)
{

          racional* total;
          total=(racional*)malloc(sizeof(racional));
          //DIVISION
          total->num = (a->num)*(b->num);
          total->deno = (a->deno)*(b->deno);
          return total;
          //FIN DE LA OPERACION DIVISION

}//FIN DE LA DIVISION


/*DEFINICION DE LA FUNCION SIMPLIFICAR:
             RECIBE 2 PUNTEROS DE TIPO RACIONAL Y DEVUELVE SU VALOR SIMPLIFICADO
*/


 racional* simplificar(racional *ptrsum)
           {
                   racional *total;//crea el puntero de retorno
                   total=(racional*)malloc(sizeof(racional));
                   total->num= ptrsum->num;
                   total->deno= ptrsum->deno;
                   int b=2;
                       if(total->deno==1){
                            return total;
                            }
                       else
                       {
                       int b=2;
                       while(b<=total->num){
                                if(total->deno%b==0 && total->num%b==0){
                                total->deno = total->deno/b;
                                total->num = total->num/b;
                        }else{
                       b++;
                        }
                    }
                }
        return total;
        }
 racional* simplificarres(racional *ptrres)
           {
                   racional *total;//crea el puntero de retorno
                   total=(racional*)malloc(sizeof(racional));
                   total->num= ptrres->num;
                   total->deno= ptrres->deno;
                   int b=2;
                       if(total->deno==1){
                            return total;
                            }
                       else
                       {
                       int b=2;
                       while(b<=total->num){
                                if(total->deno%b==0 && total->num%b==0){
                                total->deno = total->deno/b;
                                total->num = total->num/b;
                        }else{
                       b++;
                        }
                    }
                }
        return total;
        }

