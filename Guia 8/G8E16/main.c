/*16. Para un digrafo G(V,E) la Matriz de Alcance R de define como:
R =  1 si vk es alcanzable desde vi.
     0 si vk no es alcanzable desde vi.
a) Determinar la dimensión de R
b) Construir R para el siguientes digrafo: */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void alcanza(int Ma[][MAX],int i, int j, int *alc,int V,int vv[]);

int main()
{
    int Ma[MAX][MAX]={{0,0,1,0,1,0},{1,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,0},{0,0,0,0,0,1},{0,0,0,0,0,0}};
    int vv[MAX],i,j,k,alc,R[MAX][MAX]={0},V=6;

    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            alc=0;
            for(k=0;k<V;k++)
                vv[k]=0;
            vv[i]=1;

            alcanza(Ma,i,j,&alc,V,vv);
            if (alc)
               R[i][j]=1;

        }
    }

    for(i=0;i<V;i++){
        printf("\n");
        for (j=0;j<V;j++)
            printf("%d\t",R[i][j]);
    }


    return 0;
}

void alcanza(int Ma[][MAX],int i, int j, int *alc,int V,int vv[]){
    int k;

    if(Ma[i][j]!=0)
        *alc=1;
    else{
        k=0;
        while(*alc==0 && k<V){
            if(Ma[i][k]!=0){
                vv[k]=1;
                alcanza(Ma,k,j,alc,V,vv);
            }
            k++;
        }
    }
}
