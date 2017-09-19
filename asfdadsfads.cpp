#include <stdio.h>
#include <conio.h>
int resultado(int, int);
int main(){
    int num1,num2;
    int res;
    puts("Num 1:\t");
    scanf("%d",&num1);
    puts("Num 2:\t");
    scanf("%d",&num2);
    res=resultado(num1,num2);
    printf("\nTotal: %d",res);
getch();
return 0;
}
int resultado(int a, int b){
return a/b;
}
