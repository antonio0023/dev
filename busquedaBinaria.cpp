#include <stdio.h>
#include <conio.h>
int busqueda_bin(int [],int, int ,int);
int main(){
    int arre[]={1,3,7,15,21,22,36,78,95,106};
    int low, high, dig,pos;
    void clrscr();
    printf("Numero a buscar: (entre 24 y 2008)\n");
    scanf("%d",&dig);
    pos=busqueda_bin(arre,dig,0,9);
    if(pos!=-1)
               printf("El numero fue encontrado en la posicion %i del arreglo\n",pos);
    else
        printf("El numero no fue encontrado en ningun arreglo");
        
getch();
return 0;
}
/*Definicion de la funcion recursiva que realiza una busqueda binaria en un arreglo
** ordenado. Los parametros son: el arreglo, el valor que se busca, el subindice
** inferior y el subindice superior del arreglo que representa la zona donde se va a buscar */
int busqueda_bin(int a[],int p, int low, int high){
    int mid,aux;
    if(low>high)
                aux=-1;
    else
    {
        mid=(low+high)/2;
        if(p==a[mid])
                     aux=mid;
        else
        if(p<a[mid])
                    aux=busqueda_bin(a,p,low,mid-1);
        else
                    aux=busqueda_bin(a,p,mid+1,high);            
    }

return aux;
}
