/*20. Dada la matriz de alcance correspondiente a un digrafo, realizar una función recursiva para
hallar el vértice alcanzado por la mayor cantidad de vértices. En el caso de que existan más de
uno, devolver el primero encontrado. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void masalcanzado(int R[][MAX],int i,int j,int V,int *max,int *vmax,int act);

int main()
{
    int R[MAX][MAX]={{0,1,1,1,1,1},{0,0,0,0,0,0},{0,1,0,0,0,0},{0,0,0,0,0,0},{0,1,0,1,0,0},{0,1,0,1,1,0}};// MATRIZ DE ALCANCE EJ 16
    int V=6,max=0,vmax=0;

    masalcanzado(R,V-1,V-1,V-1,&max,&vmax,0);
    printf("El vertice mas alcanzado es %d\n",vmax+1);
    return 0;
}

void masalcanzado(int R[][MAX],int i, int j,int V,int *max,int *vmax,int act){

    /*if(i<0 && j<=0){

    }*/
    if(i>=0||j>0){
        if(i<0){
            if(*max<act){
                *max=act;
                *vmax=j;
            }
            masalcanzado(R,V,j-1,V,max,vmax,0);
        }
        else{
            if(R[i][j]!=0)
                act++;
            masalcanzado(R,i-1,j,V,max,vmax,act);
        }
    }
}
