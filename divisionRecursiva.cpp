#include <conio.h>
#include <stdio.h>
int division(int,int);
int main(){
    int a,b,c;
    puts("Numero 1: ");
    scanf("%i",&a);
    puts("Numero 2: ");
    scanf("%i",&b);
    c=division(a,b);
    printf("\n%d",c);
    getch();         
}
int division(int x, int y){
    if((x-y)<0)
               return 0;
    else
    return 1+division(x-y,y);
}
