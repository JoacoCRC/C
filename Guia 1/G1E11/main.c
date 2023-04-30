#include <stdio.h>
#include <stdlib.h>
/*11. Desarrollar una macro que devuelva cada uno de los siguientes resultados:
a) Máximo de 2 números          b) Caracter es alfabético*/

#define max(a,b) (a<b)? b:a

#define caracter(a) ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))?1:0

int main()
{
    int n,m;
    char c;
    printf("ingrese dos numeros a comparar\n");
    scanf("%d %d",&n, &m);
    printf("el mayor numero es %d \n", max(n,m));
    printf("ingrese un caracter\n");
    fflush(stdin);
    scanf("%c",&c);
    //gets(&c);
    printf("el caracter ingresado es  %c\n", c);
    if (caracter(c))
        printf("el caracter es alfabetico\n");


    return 0;
}
