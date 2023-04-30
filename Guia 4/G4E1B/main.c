/*b) Sea A un arreglo de reales y un valor X real ingresado por teclado, se pide determinar en
que posición se encuentra la primera ocurrencia de X o 0 en caso de no encontrarlo.
Implementar:
I. Considerando el arreglo desordenado, una búsqueda lineal recursiva.
II. Para un arreglo ordenado en forma ascendente, una búsqueda binaria recursiva. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int busuedalineal(float v[MAX],float x, int aux,int dim);
int busuedabinaria(float v[MAX],float x, int pri, int ult, int med);

int main()
{
    float v[MAX]={1,5,2.3,4.1,2.2,99,34.5},x;
    float v1[MAX]={1.1,1.5,3,6.3,6.9,7.1,9.7};

    printf("ingrese el valor buscado\n");
    scanf("%f",&x);
    printf("el valor se encuentra en la posicion (0 si no se encuentra) %d\n",busuedalineal(v,x,0,6));

    printf("ingrese el valor buscado\n");
    scanf("%f",&x);
    printf("el valor se encuentra en la posicion (0 si no se encuentra) %d\n",busuedabinaria(v1,x,0,6,3));


    return 0;
}
int busuedalineal(float v[MAX],float x, int aux, int dim){
  if (aux>dim)
    return 0;
  else
    if (x==v[aux])
        return aux+1;
    else
        return busuedalineal(v,x,aux+1,dim);

}

int busuedabinaria(float v[MAX],float x,int pri, int ult,int med){   //pri 0; ult 6(dim-1); med  3 (pri+ult)/2
    if (pri>ult)
            return 0;
    else
        if(x==v[med])
            return med+1;
        else
            if (x<v[med])
                return busuedabinaria(v,x,pri,med-1,(pri+med-1)/2);
            else
                return busuedabinaria(v,x,med+1,ult,(med+1+ult)/2);


}
