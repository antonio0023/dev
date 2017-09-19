#include <stdio.h>
#include <conio.h>
typedef struct{
        int num;
        int centavo;
        }dinero;
int main(){
    dinero a;
    puts("Son ");
    scanf("%i",a.num);
    puts("con ");
    scanf("%i",a.centavo);
    printf("%i %i",a.num,a.centavo);
    getch();
    return 0;
}
