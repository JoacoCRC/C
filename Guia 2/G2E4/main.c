/*4. Desarrollar un programa que cree dinámicamente un arreglo de números reales que contenga
N elementos (N es ingresado por teclado). Ingresar sus elementos y mostrar aquellos que sean
positivos utilizando aritmética de punteros. Al finalizar, liberar la memoria solicitada en tiempo
de ejecución.*/

#include <stdio.h>
#include <stdlib.h>
int main(){ //ejercicio resuelto en el main
    int N,i;
    float *v;
    printf("ingrese cantidad de elementos\n");
    scanf("%d",&N);
    v=(float*)malloc(N*sizeof(float)); //asigno tantos espacios para el "vector" (espacio en memoria)
    for (i=0;i<N;i++){
        printf("ingrese valor\t");
        scanf("%f",v+i); //guardo el valor de leido en el espacio en memoria reservado variando la posicion con i
    }
    for(i=0;i<N;i++)
        if (*(v+i)>0)
            printf("%2.2f\t",*(v+i));
    free(v);
    return 0;
}
/*
void creavec(int n,int**v);
void muestravec(int n, int**v);

int main(){
    int n;
    int *v;
    printf("ingrese cantidad de elementos\n");
    scanf("%d",&n);
    creavec(n,&v);
    muestravec(n,&v);
    return 0;
}
void creavec(int n,int**v){
    int i;
    *v=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++){
        printf("ingrese valor\n");
        scanf("%d",*(v+i));
    }
}

void muestravec(int n,int **v){
    int i;
    for (i=0;i<n;i++)
        if(*(v+i)>0)
            printf("%d\n",**(v+i));
    for (i=0;i<n;i++)
        free(*(v+i));

}*/

