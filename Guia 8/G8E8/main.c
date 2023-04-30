/*8. Desarrollar funciones recursivas para:
a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.
b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
de adyacencia.
c) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia.
d) determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia
(triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).
e) generar un vector de registros con grado y vértice para aquellos vértices, de un grafo
almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int etiueta;
    struct nodo*sig;}nodo;
typedef nodo*TLista;

void vgrados(int M[][4],int i, int j,int n,int v[]);//falta inciso b
void maxgrae(int M[][4],int i,int j,int n,int *vertice,int *grmax,int gract);
void maxgraelista( TLista LA[],int gre[],int n);
int main(){
    int M[4][4]={{0,1,1,0},{1,0,1,1},{1,1,0,1},{0,1,1,0}},v[4]={0},i,vertice=-1,grmax=-1;
    int M1[4][4]={{0,1,1,0},{0,0,0,1},{1,1,0,0},{0,0,1,0}},gre[4]={0};
    TLista LA[4]={NULL};

    vgrados(M,3,3,3,v);         //a)
    /*for (i=0;i<4;i++){
        printf("%d\t",v[i]);
    }*/
    maxgrae(M1,3,3,3,&vertice,&grmax,0);        //b)
    printf("El vertice con mayor grado de salida es el numero %d\n",vertice+1);

    maxgraelista(LA,gre,3);
    return 0;
}

void vgrados(int M[][4],int i, int j,int n,int v[]){

    if(i>=0){
        if (M[i][j]!=0)
            v[i]++;
        if(j>0)
            vgrados(M,i,j-1,n,v);
        else
            vgrados(M,i-1,n,n,v);
    }
}

void maxgrae(int M[][4],int i,int j,int n,int *vertice,int *grmax,int gract){
    if(j>=0){
        if(i<0){
            if (gract>*grmax){
                *grmax=gract;
                *vertice=j;
            }
            maxgrae(M,n,j-1,n,vertice,grmax,0);
        }
        else{
            if(M[i][j]!=0)
                maxgrae(M,i-1,j,n,vertice,grmax,gract+1);
            else
                maxgrae(M,i-1,j,n,vertice,grmax,gract);
        }
    }
}

void maxgraelista(TLista LA[],int gre[],int n){
    TLista aux;

    if (LA[n]!=NULL){
        aux=LA[n];
    }

}
