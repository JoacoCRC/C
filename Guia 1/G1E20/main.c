#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*20. Realizar un programa iterativo que calcule e imprima el equivalente binario de un número
entero positivo dado. */

int main()
{
    unsigned int n,i,j;
    int v[20]={0};
    printf("ingrese un numero entero positivo\n");
    scanf("%d",&n);

    j=0;
    for (i=n;i>=2;){
       v[j]=i%2;
       j++;
       i/=2;
    }
    if (i/2==0)
        v[j]=1;
    else
        v[j]=0;

    for(;j>=0;j--){
        printf(" %d",v[j]);
    }
    return 0;
}
