#include <stdio.h>
#include <conio.h>
int main(){
    
    float nota1,nota2,nota3,nota4,nota5;

    puts("nota: ");
    scanf("%f",&nota1);
    
    puts("nota: ");
    scanf("%f",&nota2);
    
    puts("nota: ");
    scanf("%f",&nota3);
    
    puts("nota: ");
    scanf("%f",&nota4);
    
    puts("nota: ");
    scanf("%f",&nota5);
    
    float total=(nota1*.2)+(nota2*.15)+(nota3*.25)+(nota4*.25)+(nota5*.15);
    printf("+++ %.2f +++",total);
    getch();
    return 0;

}
