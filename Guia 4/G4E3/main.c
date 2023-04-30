/*3. Dado un vector A de N elementos, obtener el promedio de sus elementos. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

float promedio(int v[MAX],int n,int ult);

int main()
{
    int v[MAX]={6,1,7,12},n=4;
    printf("El promedio es %3.2f\n", promedio(v,n,n-1));

    return 0;
}

float promedio(int v[MAX],int n,int ult){
    if (ult<0)
        return 0;
    else
        return (float)v[ult]/n +promedio(v,n,ult-1);

}

