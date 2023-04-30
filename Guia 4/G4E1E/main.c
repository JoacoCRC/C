/*e) Dado dos arreglos de enteros A y B ordenados ascendentemente, mezcle ambos arreglos en
otro C manteniendo el orden pero sin pasar los elementos repetidos. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void mezcla(int A[MAX],int B[MAX],int C[MAX],int na,int nb, int *nc,int maxa, int maxb);

int main()
{
    int A[MAX]={1,3,6,8,12,15},B[MAX]={1,2,5,8,12,13,16,19},C[MAX]={0};
    int nc=-1,i;

    mezcla(A,B,C,0,0,&nc,5,7);
    printf("C: ");
    for (i=0;i<=nc;i++)
        printf("%d\t",C[i]);


    return 0;
}

void mezcla(int A[MAX],int B[MAX],int C[MAX],int na,int nb, int *nc,int maxa, int maxb){
    if (na>maxa && nb>maxb)
        ;
    else{
        if(A[na]<B[nb] && na<=maxa){
            (*nc)++;
            C[*nc]=A[na];
            mezcla(A,B,C,na+1,nb,nc,maxa,maxb);
        }
        else{
            if (A[na]>B[nb] && nb<=maxb){
                (*nc)++;
                C[*nc]=B[nb];
                mezcla(A,B,C,na,nb+1,nc,maxa,maxb);
            }
            else{
                if (na<=maxa){
                    (*nc)++;
                    C[*nc]=A[na];
                    mezcla(A,B,C,na+1,nb+1,nc,maxa,maxb);
                }
                else{
                    (*nc)++;
                    C[*nc]=B[nb];
                    mezcla(A,B,C,na+1,nb+1,nc,maxa,maxb);
                }
            }
        }

    }
}
