/*4. Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void grafosubyacente(int Mady[][MAX],int n);

int main()
{
    int Mady[MAX][MAX],n=4;

    grafosubyacente(Mady,n);


    return 0;
}

void grafosubyacente(int Mady[][MAX],int n){
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(Mady[i][j]==1)
                Mady[j][i]=1;
        }
    }
}
