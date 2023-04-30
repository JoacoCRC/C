#include <stdio.h>
#include <stdlib.h>
/*12. Desarrollar un programa que muestre la suma de un conjunto de números naturales ingresados
por teclado. La serie finaliza al ingresar el número 0.*/

int main()
{
    int N,Sum=0;
    printf("Ingrese un numero ");
    scanf("%d",&N);
    //Sum=0;
    while(N!=0){
        Sum +=N;
        printf("Ingrese un numero ");
        scanf("%d",&N);
    }
    printf("La suma de los numeros ingresados es %d",Sum);

    return 0;
}
