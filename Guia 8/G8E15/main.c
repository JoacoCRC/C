/*15. Calcular el camino más corto entre todos los pares de vértices, para el digrafo representado por
la siguiente matriz de adyacencia, aplicando:
a) el algoritmo de Dijkstra
b) el algoritmo de Floyd */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void dijkstra(int Ma[][MAX],int VecDis[],int V,int vi);
int todosvisitados(int S[],int V);
int minimo(int VecDis [],int S[],int V);

void floyd(int Md[][MAX],int V,int Pf[][MAX]);
void dijkstra2(int Ma[][MAX],int VecDis[],int V,int vi,int Pd[]);

int main()
{
    int Ma[MAX][MAX]={{0,30,0,13},{22,0,10,12},{0,25,0,0},{13,6,0,0}},V,vi,VecDis[MAX],i,j;
    int Md[MAX][MAX]={{0,30,0,13},{22,0,10,12},{0,25,0,0},{13,6,0,0}};
    int Pd[MAX],Pf[MAX][MAX];

    printf("Ingrese cantidad de vertices y vertice inicial\n");
    scanf("%d %d",&V,&vi);


    for(i=0;i<V;i++)
        for(j=0;j<V;j++){
            if(i!=j && Ma[i][j]==0){
                Ma[i][j]=999;
                Md[i][j]=999;
            }
            if(Ma[i][j]==999)
                Pf[i][j]=999;
            else
                Pf[i][j]=0;
        }

    for(i=0;i<V;i++){
        VecDis[i]=Ma[vi-1][i];
        if (Ma[vi-1][i]==999)
            Pd[i]=999;
        else
            Pd[i]=0;
    }
    /*dijkstra(Ma,VecDis,V,vi);
    for(i=0;i<V;i++)
        printf("para ir del vertice %d al vertice %d se necesita %d\n",vi,i+1,VecDis[i]);
*/
    floyd(Md,V,Pf);
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            printf("para ir del vertice %d al vertice %d se necesita %d\n",i+1,j+1,Md[i][j]);
        }
    }
    /*for(i=0;i<V;i++){
        VecDis[i]=Ma[vi-1][i];
    }*/
    dijkstra2(Ma,VecDis,V,vi,Pd);
    for(i=0;i<V;i++)
        printf("para ir del vertice %d al vertice %d se necesita %d\n",vi,i+1,VecDis[i]);

    return 0;
}

void dijkstra(int Ma[][MAX],int VecDis[],int V,int vi){
    int S[V],i,pos;

    for(i=0;i<V;i++)
        S[i]=0;
    S[vi-1]=1;
    while(!todosvisitados(S,V)){
        pos=minimo(VecDis,S,V);
        S[pos]=1;
        for(i=0;i<V;i++)
            if(i!=vi-1)
                if(VecDis[i]>VecDis[pos]+Ma[pos][i])
                    VecDis[i]=VecDis[pos]+Ma[pos][i];
        //for(i=0;i<V;i++)
        //    printf("%d\t",VecDis[i]);
       // printf("\n");
    }
}

int todosvisitados(int S[],int V){
    int i=0;
    while (i<V && S[i]==1)
        i++;
    return (i<V)?0:1;
}

int minimo(int VecDis [],int S[],int V){
    int i,min=999,pos;

    for(i=0;i<V;i++){
        if(VecDis[i]!=0 && S[i]==0 && VecDis[i]<min ){
            min=VecDis[i];
            pos=i;
        }
    }
    return pos;
}

void floyd(int Md [][MAX],int V,int Pf[][MAX]){
    int i,j,k;

    for(k=0;k<V;k++)
        for(i=0;i<V;i++)
            for(j=0;j<V;j++)
                if(Md[i][k] + Md[k][j] < Md[i][j]){
                    Md[i][j] = Md[i][k] + Md[k][j];
                    if (Pf[i][j]==999||Pf[i][j]==0)
                        Pf[i][j]=k;
                }
}

void dijkstra2(int Ma[][MAX],int VecDis[],int V,int vi,int Pd[]){
    int i,j;

    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            if(VecDis[j]+Ma[j][i]<VecDis[i]){
                VecDis[i]=VecDis[j]+Ma[j][i];
                Pd[i]=j;
            }
}

