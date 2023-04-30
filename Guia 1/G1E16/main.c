#include <stdio.h>
#include <stdlib.h>
/*16. Desarrollar un subprograma que reciba una cantidad de segundos y devuelva su equivalente en
el formato horas:minutos:segundos*/
int main()
{
    int n;
    //int s,m,h;
    printf("ingrese cantidad de segundos\n");
    scanf("%d", &n);
    //s= n%60;
    //m= (n/60)%60;
    //h= (n/60)/60;
    printf(" %d:%d:%d",(n/60)/60,(n/60)%60,n%60);
    return 0;
}
