#include <stdio.h>
#include <stdlib.h>
/*23. Rehacer el ejercicio 12 suponiendo que los n�meros se encuentran en un archivo de texto,
todos en la misma l�nea. �Como modificar�a la lectura, si hubiera un valor por l�nea? */

/*12. Desarrollar un programa que muestre la suma de un conjunto de n�meros naturales ingresados
por teclado. La serie finaliza al ingresar el n�mero 0. */


int main()
{
    int suma=0,n;
    FILE *arch;
    arch=fopen("DatosG1E23.txt","r");
    if (arch==NULL)
        printf("archivo clientes no existe!\n");
    else{
        fscanf(arch,"%d",&n);
        while (n!=0 && !feof(arch)){
            suma +=n;
            fscanf(arch,"%d\n",&n);
        }
        printf("la suma de los numeros es:%d",suma);
    }

    fclose(arch);
    return 0;
}
