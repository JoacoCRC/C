#include <stdio.h>
#include <stdlib.h>

/*18. Desarrollar un subprograma que duplique los elementos de un vector ubicados en las
posiciones pares. Implementar 3 veces utilizando for, while y do while*/

void dobleenpares( int v[]);

int main()
{
    int i,v[]={1,2,3,4,5,6,7,8,9};
    for (i=0;i<9;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    dobleenpares(v);
    for (i=0;i<9;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}

void dobleenpares(int v[]){
    int i;
    /*for (i=0;i<9;i+=2){
        v[i]*=2;
    }*/

    /*i=0;
    while (i<9){
       v[i]*=2;
       i+=2;
    }*/

    i=0;
    do{
        v[i]*=2;
        i+=2;
    }while (i<9);
}
