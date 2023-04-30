#include <stdio.h>
#include <stdlib.h>

/*14. Desarrollar un subprograma que muestre un cuadrado con bordes de N numerales (N es
parámetro de entrada). Por ej: para N = 4 */

void cuadrado(int N);

int main()
{
    int N;
    printf("ingrese un numero ");
    scanf(" %d",&N);
    cuadrado(N);
    return 0;
}

void cuadrado(int N){
    int i,j;

    for(i=0;i<N;i++){
        j=1;
        if (i==0  || i==N-1){
            do{
                printf("#");
                j++;
            }
            while(j<=N);
            printf("\n");
        }
        else{
            printf("#");
            //j=2;
            /*while (j<N){
               printf(" ");
               j++;
            }*/
            for(j=2;j<N;j++){ //conviene while o for?
                printf(" ");
            }
            printf("# \n");
        }

    }
}
