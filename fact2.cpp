#include <stdio.h>
#include <conio.h>
int factoria(int);
int main(){
    int a=5;
    int b;
    b=factoria(5);
    printf("%d",b);
    getch();
}
int factoria(int a){
    if(a==0 || a==1)
            return 1;
    else
    return a*factoria(a-1);
}
