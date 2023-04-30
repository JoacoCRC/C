/*c) Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int minimomat(int mat[MAX][MAX], int i,int j,int n);

int main()
{
    int mat[][MAX]={{3,-5,1,7},{5,11,-3,6},{1,2,3,6},{9,6,4,3}};
    int n=4;

    printf("El elemento minimo de la matriz es %d\n",minimomat(mat,n-1,n-1,n-1));


    return 0;
}
int minimomat(int mat[][MAX],int i, int j,int n){
    int min;
    if (i==0 && j==0)
        return mat[0][0];
    else{
        if (j==-1)
            min= minimomat(mat,i-1,n,n);
        else{
            min = minimomat(mat,i,j-1,n);

            if (mat[i][j]<min)
                min=mat[i][j];
        }
        return min;
    }

}


