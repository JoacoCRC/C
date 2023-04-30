/*1. Realizar un TDA para números fraccionarios, es decir aquellos que se expresan como el
cociente de dos números enteros. Las operaciones que deberá soportar el TDA son:
◦ crear(entero numerador, entero denominador) retorna fracción.
◦ numerador(fracción f) retorna entero.
◦ denominador(fracción f) retorna entero.
◦ sumar(fracción f1, fracción f2) retorna fracción.
◦ restar(fracción f1, fracción f2) retorna fracción.
◦ multiplicar(fracción f1, fracción f2) retorna fracción.
◦ dividir(fracción f1, fracción f2) retorna fracción.
◦ simplificar(fracción f) retorna fracción simplificada.
◦ iguales(fracción f1, fracción f2) retorna verdadero o falso.
*/


#include <stdio.h>
#include <stdlib.h>

#include "Fracciones.h"

int main(){
    int num,den;
    fraccion frac1,frac2,frac3;
    printf("ingrese numerador\n");
    scanf("%d",&num);
    printf("ingrese denominador\n");
    scanf("%d",&den);
    frac1=crear(num,den);
    //frac1=simplificar(frac1);
    printf("ingrese numerador\n");
    scanf("%d",&num);
    printf("ingrese denominador\n");
    scanf("%d",&den);
    frac2=crear(num,den);
    //frac2=simplificar(frac2);
    printf("fraccion 1:  %d/%d\n",numerador(frac1),denominador(frac1));
    printf("fraccion 2:  %d/%d\n",numerador(frac2),denominador(frac2));
    frac3=sumar(frac1,frac2);
    frac3=simplificar(frac3);
    printf("La suma de %d/%d y %d/%d es %d/%d\n",frac1.num,frac1.den,frac2.num,frac2.den,frac3.num,frac3.den);
    frac3=restar(frac1,frac2);
    frac3=simplificar(frac3);
    printf("La resta de %d/%d y %d/%d es %d/%d\n",frac1.num,frac1.den,frac2.num,frac2.den,frac3.num,frac3.den);
    frac3=multiplicar(frac1,frac2);
    frac3=simplificar(frac3);
    printf("La multiplicacion de %d/%d y %d/%d es %d/%d\n",frac1.num,frac1.den,frac2.num,frac2.den,frac3.num,frac3.den);
    frac3=dividir(frac1,frac2);
    frac3=simplificar(frac3);
    printf("La divicion de %d/%d y %d/%d es %d/%d\n",frac1.num,frac1.den,frac2.num,frac2.den,frac3.num,frac3.den);
    frac1=simplificar(frac1);
    frac2=simplificar(frac2);
    if (iguales(frac1,frac2))
        printf("las fracciones %d/%d y %d/%d son iguales",frac1.num,frac1.den,frac2.num,frac2.den);
    else
        printf("las fracciones %d/%d y %d/%d no son iguales",frac1.num,frac1.den,frac2.num,frac2.den);
    return 0;
}
