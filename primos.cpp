/*Programa que imprime n numeros primos*/
#include <stdio.h>
#include <conio.h>
int primo(int num);
//Principal
int main(){
   int n,i;   
   
     do{
      printf("Ingrese el numero\t");
      scanf("%d",&n);
      for(i=0;i<=n;i++)       
            if(primo(i)==1) printf("\n%d\n",i);
      printf("\n");              
   }while(n>0); //validamos que sea positivo, de ser negativo se detiene la ejecucion.
   return 0;
}
// funcion que determina si es primo
int primo(int num){
   int i,restr;      
      if(num!=1 && num!=0){ //Los primos inician en 2
         for(i=2;i<=num;i++)       
            if(num%i==0)
               if(num==i) restr=1;                
               else{ 
                  restr=0;
                  
               }
      }
      else restr=0;
   return restr;
}
