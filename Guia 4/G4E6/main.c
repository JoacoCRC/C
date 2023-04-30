/*6. Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void cumple(int mat[][MAX],int i,int j, int m, int *sumanterior,int *sumaactual,int *cond);

int main()
{
    int mat[MAX][MAX]={{1,2,2},{1,2,5}};
    int n=2,m=3,cond=1,aux1,aux2;
    cumple(mat,n-1,m-1,m-1,&aux1,&aux2,&cond);
    if (cond)
        printf("La matriz cumple las condiciones\n");
    else
        printf("La matriz no cumple las condiciones\n");

    return 0;
}

void cumple(int mat[][MAX],int i,int j,int m,int *sumanterior,int *sumactual,int *cond){
    if (*cond!=0){
        if (i==0 && j==0){
            *sumanterior=0;
            *sumactual=mat[0][0];
            //*cond=1;
        }
        else{
            if (j==0){
                cumple(mat,i-1,m,m,sumanterior,sumactual,cond);
                *sumanterior=*sumactual;
                *sumactual=mat[i][0];
            }
            else{
                cumple(mat,i,j-1,m,sumanterior,sumactual,cond);
                *sumactual+=mat[i][j];
            }
            if (j==m){
                if (i==0){
                    if (*sumanterior%2!=0)
                        *cond=0;
                    }
                else
                    if (*sumanterior>=*sumactual)
                        *cond=0;
            }
        }
    }
}

   /* if (i==0 && j==0)
        *sumactual= mat[0][0];
    else{
        if (j==-1){
            cumple(mat,i-1,m,m,sumanterior,sumactual);

        }
        else{
            cumple(mat,i,j-1,m,sumanterior,sumactual);
            *sumactual+= mat[i][j];
            if(j==m)
                if (i==0){
                    *sumanterior=*sumactual;
                    if (*sumactual%2!=0)
                        return 0;
                }
                else
                    if (*sumanterior>*sumactual)
                        return 0;
                    else
                        *sumanterior=*sumactual;
        }

*/




    /*if (i==0 && j==0)
        *sumactual=mat[0][0];
    else{
        if (j==0)
            return cumple(mat,i-1,m,m,sumanterior,sumactual);
        else {
            return cumple(mat,i,j-1,m,sumanterior,sumactual);
            *sumactual+=mat[i][j];
            if (j==m){
                if (i==0)
                    if (*sumactual%2!=0)
                        return 0;
                    else
                        *sumanterior=*sumactual;
                else
                    if (*sumanterior>*sumactual)
                        return 0;
                    else{
                        if (i==j) //ultimo elemento de la matriz
                            return 1;
                        else
                            *sumanterior=*sumactual;
                    }
            }
        }
    }*/
