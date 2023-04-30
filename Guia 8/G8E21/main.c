/*21. Desarrollar un subprograma para mostrar el camino del vértice origen al vértice v (dato) a partir
del vector P generado por el algoritmo de Dijkstra.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10



int main()
{
    int P[MAX]={0,0,4,0,3},V=5,vi=1,i;

    printf("El vertice origen es %d\n",vi);
    for(i=0;i<V;i++){
        if(i!=vi-1){
            if(P[i]==0)
                printf("Al vertice %d se llega desde el vertice %d\n",i+1,vi);
            else
                printf("Al vertice %d se llega desde el vertice %d\n",i+1,P[i]+1);
        }
    }


    return 0;
}

