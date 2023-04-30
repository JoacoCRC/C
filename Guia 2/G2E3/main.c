/*3. Implementar un programa que cree din�micamente 3 variables enteras, muestre su suma y su
producto. Asegurarse de administrar correctamente la memoria e implementar una funci�n
para evitar duplicaciones de c�digo en la creaci�n y lectura de cada variable. */

#include <stdio.h>
#include <stdlib.h>

void crea(int **x);

int main(){
    int *a,*b,*c;

    crea(&a);
    crea(&b);
    crea(&c);

    printf("LA SUMA ES %d\nEL PRODUCTO ES %d",*a+*b+*c,*a**b**c);
    free(a);free(b);free(c);
    a=NULL;b=NULL;c=NULL;
    return 0;
}

void crea(int **x){
    *x=(int*)malloc(sizeof(int));
    scanf("%d",*x);
}



