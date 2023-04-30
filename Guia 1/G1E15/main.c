#include <stdio.h>
#include <stdlib.h>
/*15. Desarrollar una función que reciba tres números enteros y devuelva si son consecutivos entre sí
o si no lo son. */


void consecutivos(int n1, int n2, int n3);


int main(){
    int n1,n2,n3;
    printf("Ingrese tres numeros\n");
    scanf("%d  %d  %d",&n1,&n2,&n3);
    consecutivos(n1,n2,n3);
    return 0;
}
void consecutivos(int n1, int n2, int n3){
    if (n1==n2+1)
            if (n3==n2-1 || n3==n1+1)
                    printf("Los numeros son consecutivos");
            else
                    printf("Los numeros no son consecutivos");

    else{
            if (n1==n2-1)
                if (n3==n2+1 || n3==n1-1)
                        printf("Los numeros son consecutivos");
                else
                        printf("Los numeros no son consecutivos");
            else{
                if(n1==n2+2)
                        if (n3==n1-1 && n3==n2+1)
                                printf("Los numeros son consecutivos");
                        else
                                printf("Los numeros no son consecutivos");
                else{
                        if(n1==n2-2)
                                if (n3==n1+1 && n3==n2-1)
                                    printf("Los numeros son consecutivos");
                                else
                                    printf("Los numeros no son consecutivos");
                        else
                                printf("Los numeros no son consecutivos");
                }
            }

    }


}
 /*switch (n1){
        case n2+1: if (n3==n2-1 || n3==n1+1)
                        printf("Los numeros son consecutivos");
                    else
                        printf("Los numeros no son consecutivos");
                    break;
        case n2-1: if (n3==n2+1 || n3==n1-1)
                        printf("Los numeros son consecutivos");
                    else
                        printf("Los numeros no son consecutivos");
                    break;
        case n2+2: if (n3==n1-1 && n3==n2+1)
                        printf("Los numeros son consecutivos");
                    else
                        printf("Los numeros no son consecutivos");
                    break;
        case n2-2: if (n3==n1+1 && n3==n2-1)
                        printf("Los numeros son consecutivos");
                    else
                        printf("Los numeros no son consecutivos");
                    break;
        default: printf("Los numeros no son consecutivos");
    }
*/

