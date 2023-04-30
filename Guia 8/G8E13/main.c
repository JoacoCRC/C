#include <stdio.h>
#include <stdlib.h>
#define N 5


void AAMkruscal(int Ma[][N],int AAM[][N],int *costo);
void minimo(int Ma[][N],int vcc[],int *n,int *m);
int conexo(int vcc[]);

int main()
{
    int Ma[N][N]={{999,  5, 50, 80, 90},
                  {999,999, 70, 60, 50},
                  {999,999,999,  8, 20},
                  {999,999,999,999, 10},
                  {999,999,999,999,999}};

    int AAM[N][N]={0},costo=0;;

    AAMkruscal(Ma,AAM,&costo);
    printf("El costo minimo del arbol abarcador es %d\n",costo);
    return 0;
}

void AAMkruscal(int Ma[][N],int AAM[][N],int *costo){
    int vcc[N]={1,2,3,4,5};
    int i=0,j=0,k,aux;
    while (!conexo(vcc)){
        minimo(Ma,vcc,&i,&j);
        AAM[i][j]=Ma[i][j];
        *costo+=AAM[i][j];
        Ma[i][j]=999;
        aux=vcc[i];
        for (k=0;k<N;k++){
            if(vcc[k]==aux)  //en ultima ejecucion pregunta vcc[k=5]==vcc[i=5] y responde falso
                vcc[k]=vcc[j];
        }
    }
}

void minimo(int Ma[][N],int vcc[N],int*n, int* m){
    int min=999,i,j;
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(Ma[i][j]<min){
                min=Ma[i][j];
                (*n)=i;
                (*m)=j;
            }
        }
    }
    if (vcc[*n]==vcc[*m]){
        Ma[*n][*m]=999;
        minimo(Ma,vcc,n,m);
    }
}

int conexo(int vcc[N]){ //devuelve 1 si todos los vertices tienen misma componente conexa
    int i=0,comp;

    comp=vcc[i];
    i++;
    while(i<N && vcc[i]==comp)
        i++;
    return (i<N)?0:1;

}
