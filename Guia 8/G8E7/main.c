/*7. Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
c) media matriz (triángulo superior)*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct nodo{
    int etiueta;
    struct nodo*sig;}nodo;
typedef nodo*TLista;

typedef struct {
    int etiueta;
    TLista lista;}reg;

void cargamat(int M[][MAX]);
void cargalista(reg Vec[]);

int gradoA(int M[][MAX],int v);
int gradoB(reg Vec[],int v);
int gradoC(int M[][MAX],int v);

int main() //grafo simple
{
    int v,M[MAX][MAX];
    reg Vec[MAX];

    cargamat(M);
    cargalista(Vec);

    printf("ingrese vertice  mostrar grado\n");
    scanf("%d",&v);
    printf("El gardo del vertice %d es %d\n",v,gradoA(M,v));//matriz ady
    printf("El gardo del vertice %d es %d\n",v,gradoB(Vec,v));//lista ady
    printf("El gardo del vertice %d es %d\n",v,gradoC(M,v));//media matriz (sup)

    return 0;
}
void cargalista(reg Vec[]){}
void cargamat(int M[][MAX]){}

int gradoA(int M[][MAX],int v){
    int j,gr=0;

    for(j=0;j<MAX;j++){
        if (M[v-1][j]!=0)
            gr++;
    }
    return gr;
}

int gradoB(reg Vec[],int v){
    TLista aux;
    int gr=0;

    aux=Vec[v-1].lista;
    while(aux!=NULL){
        gr++;
        aux=aux->sig;
    }
   return gr;
}

int gradoC(int M[][MAX],int v){
    int i,j,gr=0;

    for(j=v;j<MAX;j++){
        if(M[v-1][j]!=0)
            gr++;
    }
    for(i=0;i<v-1;i++){
        if(M[i][v-1]!=0)
            gr++;
    }
    return gr;
}
