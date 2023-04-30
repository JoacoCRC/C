/*14. Codificar soluciones para los algoritmos de Kruskal y de Prim, suponiendo grafos almacenados
en matriz de adyacencia */

#include <stdio.h>
#include <stdlib.h>
#define MAX 15


void AAMkruscal(int Ma[][MAX],int AAM[][MAX],int *costo,int  V);
void minimo(int Ma[][MAX],int vcc[],int *n,int *m,int V);
int conexo(int vcc[],int V);

void AAMprim(int Ma[][MAX],int AAM[][MAX],int *costo,int V,int vi);
int todosvisitados(int vec[],int V);
void minimovis(int Ma[][MAX],int vec[],int *n,int *m, int V);

int main()
{
    int Ma[MAX][MAX]={{999,5,50,80,90},{5,999,70,60,50},{50,70,999,8,20},{80,60,8,999,10},{90,50,20,10,999}};
    int V,AAM[MAX][MAX]={0},costo=0,vi,i,j;
    printf("ingrese cantidad de vertices\n");
    scanf("%d",&V);

   // AAMkruscal(Ma,AAM,&costo,V);
    //printf("El costo minimo del arbol abarcador es %d\n",costo);

    printf("ingrese el vertice inicial\n");
    scanf("%d",&vi);
   // for (i=0;i<V;i++)
   //     for(j=0;j<V;j++)
   //         AAM[i][j]=0;
   // costo=0;


    AAMprim(Ma,AAM,&costo,V,vi);
    printf("El costo minimo del arbol abarcador es %d\n",costo);

    return 0;
}

void AAMkruscal(int Ma[][MAX],int AAM[][MAX],int *costo,int  V){
    int vcc[V],i=0,j=0,k,aux;
    for (k=0;k<V;k++)
        vcc[k]=k+1;

    while(!conexo(vcc,V)){
        minimo(Ma,vcc,&i,&j,V);
        AAM[i][j]=Ma[i][j];
        *costo+=AAM[i][j];
        Ma[i][j]=999;
        aux=vcc[i];
        for (k=0;k<V;k++){
            if(vcc[k]==aux)
                vcc[k]=vcc[j];
        }
    }
}

int conexo(int vcc[],int V){ //devuelve 1 si todos los vertices tienen misma componente conexa
    int i=0,comp;

    comp=vcc[i];
    i++;
    while(i<V && vcc[i]==comp)
        i++;
    return (i<V)?0:1;

}

void minimo(int Ma[][MAX],int vcc[MAX],int*n, int* m,int V){
    int min=999,i,j;
    for(i=0;i<V;i++){
        for(j=i+1;j<V;j++){
            if(Ma[i][j]<min){
                min=Ma[i][j];
                (*n)=i;
                (*m)=j;
            }
        }
    }
    if (vcc[*n]==vcc[*m]){
        Ma[*n][*m]=999;
        minimo(Ma,vcc,n,m,V);
    }
}

void AAMprim(int Ma[][MAX],int AAM[][MAX],int *costo,int V,int vi){
    int vec[V],i=0,j=0,k;
    for (k=0;k<V;k++)
        vec[k]=0;
    vec[vi-1]=1;
    while (!todosvisitados(vec,V)){
        minimovis(Ma,vec,&i,&j,V);
        AAM[i][j]=Ma[i][j];
        *costo+=AAM[i][j];
        Ma[i][j]=999;
        Ma[j][i]=999;
        vec[i]=1;
        vec[j]=1;
    }
}

int todosvisitados(int vec[],int V){
    int i=0;
    while (i<V && vec[i]==1)
        i++;
    return (i<V)?0:1;
}

void minimovis(int Ma[][MAX],int vec[],int *n,int *m,int V){
    int min=999,i,j;
    for(i=0;i<V;i++)
        for(j=i+1;j<V;j++)
            if( (vec[j]==1 || vec[i]==1) && Ma[i][j]<min ){
                min=Ma[i][j];
                (*n)=i;
                (*m)=j;
            }

    if (vec[*n]==vec[*m]){
        Ma[*n][*m]=999;
        //Ma[*m][*n]=999;
        minimovis(Ma,vec,n,m,V);
    }
}
