/*5. Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int GrE,GrS,Gr;}Tgrados;

void  grados(int M[][MAX],int n, int v);

int main()
{
    int M[MAX][MAX],n=4, v=2;//vertice numero dos, posicion 1 en la matriz

    grados(M,n,v);

    return 0;
}

void grados(int M[][MAX],int n,int v){
    int i;
    Tgrados r;

    for(i=0; i<MAX;i++){
        r.Gr=0;
        r.GrE=0;
        r.GrS=0;
    }
    for (i=0;i<n;i++){
        if(M[i][v-1]!=0)
            r.GrS++;
        if(M[v-1][i]!=0)
            r.GrE++;
    }
    r.Gr=r.GrE+r.GrS;
    if(M[v-1][v-1]!=0)
        r.Gr--;

    printf("El vertice %d tiene grado de entrada %d, de salida %d y grado %d\n",v,r.GrE,r.GrS,r.Gr);
}
