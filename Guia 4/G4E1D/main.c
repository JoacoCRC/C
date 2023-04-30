/*d) Desarrollar un procedimiento recursivo que devuelva en un arreglo los máximos de cada fila
de una matriz de MxN. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void max_xfila(int mat[][MAX],int i,int j, int m, int v[],int *max);

int main()
{
    int mat[MAX][MAX]={{5,4,3,7,9,3},{9,10,5,6,7,99},{15,4,3,7,9,3},{5,4,3,77,9,3}};
    int v[MAX]={0}; //v tiene n elementos
    int n=4,m=6,i,max=-999999;

    max_xfila(mat,n-1,m-1,m-1,v,&max);
    printf("Vmax=\t");
    for (i=0;i<n;i++)
        printf("%d\t",v[i]);
    return 0;
}

void max_xfila(int mat[][MAX],int i,int j, int m, int v[],int*max){
    //int max;
    if (i==0 && j==0)
        *max= mat[0][0];
    else{
        if (j==0){
            max_xfila(mat,i-1,m,m,v,max);
            *max= mat[i][0];
        }
        else{
            max_xfila(mat,i,j-1,m,v,max);

            if (mat[i][j]>*max)
                *max= mat[i][j];

            if(j==m)
                v[i]=*max;
        }
    }
}

