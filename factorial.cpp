#include <stdio.h>
#include <conio.h>
int factorial(int num);
int main(){
           int a,b;
           printf("Ingrese un numero entero positivo: ");
           scanf("%i",&a);
           b=factorial(a);
           printf("El factorial de %i es %i",a,b);
           getch();
           return 0;
}
int factorial(int num){
    if(num==0 || num==1)
              return 1;
    else
        return num*factorial(num-1);
}       
