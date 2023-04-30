/*5. Determinar mediante una función “lógica” si una matriz cuadrada de dimensión NxN es
simétrica (aij = aji) con respecto a su diagonal.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int matsim(int mat[][MAX],int i,int j/*,int m*/);

int main()
{
    int mat[MAX][MAX]={{1,2,3,4},{2,5,4,5},{3,4,5,6},{4,5,6,7}};
    int n=4;
    if (matsim(mat,n-1,n-2/*,n-1*/))   // columna -2 para no estar en dp.
        printf("La matriz es simetrica\n");
    else
        printf("La matriz no es simetrica\n");

    return 0;
}

int matsim(int mat[][MAX],int i, int j/*, int m*/){
    if (i<0)
        return 1; //matriz simetrica
    else
        if(j<0)
            return matsim(mat,i-1,i-2/*,m-1*/);       //paso a la fila superior y columna de la diagonal principal
        else
            if (/*i==j ||*/ mat[i][j]==mat[j][i]) //si la posicion es simetrica o estoy en la diagonal principal
                return matsim(mat,i,j-1/*,m*/);                 //miro la siguiente posicion
            else
                return 0; //matriz no simetrica
}
