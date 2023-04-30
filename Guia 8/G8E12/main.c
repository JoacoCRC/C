/*12. Para el grafo del ejercicio 9:
a) encontrar el árbol abarcador de costo mínimo (AAM) mediante el algoritmo de Prim
b) encontrar el árbol abarcador de costo mínimo (AAM) mediante el algoritmo de Kruskal*/

#include <stdio.h>
#include <stdlib.h>
#define N 7

void AAMkruscal(int M[][N],int AAM[][N],int *costo);
void minimo(int M[][N],int vcc[],int *n,int *m);
int conexo(int vcc[]);

int main()
{
    int M[N][N]={{999,  3,  1,999,999,999,999},
                 {  3,999,  2,  4,999,999,999},
                 {  1,  2,999,  1,  3,999,999},
                 {999,  4,  1,999,  2,999,999},
                 {999,999,  3,  2,999,  1,  4},
                 {999,999,999,999,  1,999,999},
                 {999,999,999,999,  4,999,999}};
    int AMM[N][N]={0},costo=0;;

    AAMkruscal(M,AMM,&costo);
    printf("El costo minimo del arbol abarcador es %d\n",costo);
    return 0;
}

void AAMkruscal(int M[][N],int AAM[][N],int *costo){
    int vcc[N]={1,2,3,4,5,6,7};
    int i=0,j=0,k,aux;
    while (!conexo(vcc)){
        minimo(M,vcc,&i,&j);
        AAM[i][j]=M[i][j];
        *costo+=AAM[i][j];
        M[i][j]=999;
        aux=vcc[i];
        for (k=0;k<N;k++){
            if(vcc[k]==aux)  //en ultima ejecucion pregunta vcc[k=5]==vcc[i=5] y responde falso
                vcc[k]=vcc[j];
        }
    }
}

void minimo(int M[][N],int vcc[],int*n, int* m){
    int min=999,i,j;
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(M[i][j]<min){
                min=M[i][j];
                (*n)=i;
                (*m)=j;
            }
        }
    }
    if (vcc[*n]==vcc[*m]){
        M[*n][*m]=999;
        minimo(M,vcc,n,m);
    }
}

int conexo(int vcc[]){ //devuelve 1 si todos los vertices tienen misma componente conexa
    int i=0,comp;

    comp=vcc[i];
    i++;
    while(i<N && vcc[i]==comp)
        i++;
    return (i<N)?0:1;

}
