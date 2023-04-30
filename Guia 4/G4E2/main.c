/*2. Desarrollar funciones (algunas pueden ser void) para:
a) calcular el producto de dos números enteros positivos a partir de sumas sucesivas.
b) calcular cociente y resto entre dos números enteros positivos a partir de restas sucesivas
c) hallar el máximo elemento de un vector de enteros (realizar una versión void y otra int)*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int producto(int x, int y);
void divicion(int x, int y,int *cociente, int *resto);
void mayorvoid(int v[], int n,int *maximo);
int mayorint(int v[],int n);

int main()
{
    int n1=24,n2=4,cos=0,res;
    int v[MAX]={1211,9,5,741,2,3,90,924},maximo=-999999;

    printf("El producto entre %d y %d es %d\n",n1,n2,producto(n1,n2));
    divicion(n1,n2,&cos,&res);
    printf("El cociente entre %d y %d es %d y su resto es %d\n",n1,n2,cos,res);
    mayorvoid(v,7,&maximo);
    printf("El valor maximo en el vecotr es %d\n",maximo);
    printf("el valor mayor en el vector es %d\n",mayorint(v,7));

    return 0;
}

int producto(int x, int y){
    if (y==0)
        return 0;
    else
        return x+producto(x,y-1);

}

void divicion(int x,int y, int *cociente, int *resto){
    if (x<y)
        *resto=x;
    else{
        (*cociente)++;
        divicion(x-y,y,cociente,resto);
        //(*cociente)++;
    }
}
void mayorvoid(int v[], int n, int *maximo){
    if (n>=0){
        if (*maximo<v[n])
            *maximo= v[n];
        //*maximo=(*maximo<v[n])?v[n]:*maximo ;
        mayorvoid(v,n-1,maximo);
    }
}
int mayorint(int v[],int n){
    int max;
    if (n==0)
        return v[0];
    else{
        max=mayorint(v,n-1);
        if (v[n]>max)
            return v[n];
        else
            return max;
    }
}

   /*if (n<0)
        return maximo;
   else{
        if (v[n]>maximo)
            maximo=v[n];
        return mayorint(v,n-1,maximo);
    */


