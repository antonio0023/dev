#include <stdio.h>
#include <conio.h>
int fibonacci(int);
int main(){
    int a,total;
    puts("Ingrese el numero de terminos: ");
    scanf("%i",a);
    total=fibonacci(a);
    printf("\nEl fibonaccio de %i es %i\n",a,total);
    getch();
    return 0;
}
int fibonacci(int n){
     if(n==0 || n==1)
             return n;
     else
     return fibonacci(n-1) + fibonacci(n-2);
     
}
