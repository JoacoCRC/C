/*4. Dada una matriz A de NxM float, retornar la cantidad de veces que un valor X aparece en A
(realizar una versión void y otra int)*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int contx(float A[][MAX],int i, int j, int m, float x);
void contxvoid(float A[][MAX],int i, int j, int m, float x, int *cont);

int main()
{
    float A[MAX][MAX]={{3.3,5.6,12,1.1},{0.5,15,9,4},{5.1,3.3,4,0.5}};
    int n=3,m=4,cont;
    float x;

    printf("ingrese valor\n");
    scanf("%f",&x);
    printf("el valor %5.2f aparece %d veces en la matriz\n",x,contx(A,n-1,m-1,m-1,x));

    contxvoid(A,n-1,m-1,m-1,x,&cont);
    printf("el valor %5.2f aparece %d veces en la matriz\n",x,cont);

    return 0;
}

int contx(float A[][MAX],int i, int j, int m, float x){
    if (i<0)
        return 0;
    else
        if(j<0)
            return contx(A,i-1,m,m,x);
        else
            if (A[i][j]==x)
                return 1+contx(A,i,j-1,m,x);
            else
                return contx(A,i,j-1,m,x);
}

void contxvoid(float A[][MAX],int i, int j, int m, float x, int *cont){
    if (i<0)
        *cont=0;
    else
        if (j<0)
            contxvoid(A,i-1,m,m,x,cont);
        else{
            contxvoid(A,i,j-1,m,x,cont);
            if (A[i][j]==x)
                (*cont)++;
        }
}

