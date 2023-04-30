/*1. Recodificar en el lenguaje C los siguientes ejercicios de Programación I desarrollados en Pascal:
a) Sea V un arreglo de enteros, se pide:
I. Calcular e informar la suma de sus elementos.
II. Mostrar sus elementos.
III. Mostrar sus elementos en orden inverso.
b) Sea A un arreglo de reales y un valor X real ingresado por teclado, se pide determinar en
que posición se encuentra la primera ocurrencia de X o 0 en caso de no encontrarlo.
Implementar:
I. Considerando el arreglo desordenado, una búsqueda lineal recursiva.
II. Para un arreglo ordenado en forma ascendente, una búsqueda binaria recursiva.
c) Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada.
d) Desarrollar un procedimiento recursivo que devuelva en un arreglo los máximos de cada fila
de una matriz de MxN.
e) Dado dos arreglos de enteros A y B ordenados ascendentemente, mezcle ambos arreglos en
otro C manteniendo el orden pero sin pasar los elementos repetidos. */

#include <stdio.h>
#include <stdlib.h>


int suma(int vec[10],int n);
void mostrar(int vec[10],int n);
void mostrarinvers(int vec[10],int n);
int busuedalineal(int vec[10],int n,int val);

int main()
{
    int v[6]={1,8,3,5,2,9},val,pos;
    printf("La suma de los elementos del vector es %d\n",suma(v,5));
    mostrar(v,5);
    printf("\n");
    mostrarinvers(v,5);
    printf("ingrese valor buscado en el vector\n");
    scanf("%d",&val);
    /*pos=busuedalineal(v,6,val);
    if (pos==0)
        printf("no se encontro valor\n");
    else
        printf("el valor se econtro en la posicion %d\n",pos);
    return 0;*/
}

int suma(int vec[10],int n){
    if(n==0)
        return vec[n];
    else{
        return vec[n]+suma(vec,n-1);
    }
    /*if (n<0)
        return 0;
    else
        return vec[n]+suma(vec,n-1);*/

}
void mostrar(int vec[10],int n){
    if(n==0)
        printf("%d\t",vec[n]);
    else{
        mostrar(vec,n-1);
        printf("%d\t",vec[n]);
    }
}
void mostrarinvers(int vec[10],int n){
    if (n==0){
        printf("%d\n",vec[n]);
    }
    else{
        printf("%d\t",vec[n]);
        mostrarinvers(vec,n-1);

    }
}

