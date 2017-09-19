#include <stdio.h>
#include <conio.h>
int sumaTotal(int x);
int main(){
    int a,b;
    puts("Numero: ");
    scanf("%i",&a);
    b=sumaTotal(a);
    printf("total\t%d",b);
    getch();              
}
int sumaTotal(int x){
    if(x==0)
            return 0;
    else
    return x+sumaTotal(x-1);
}
