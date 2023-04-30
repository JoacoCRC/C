/*2. Desarrollar una agenda de contactos mediante un TDA. Para cada contacto se almacena
nombre y teléfono. Los contactos deben estar ordenados alfabéticamente. El TDA debe contar
con los siguientes operadores: agregar contacto, listar agenda, buscar por nombre (búsqueda
lineal).
Se solicitan dos implementaciones: una con arreglos paralelos y otra con arreglo de registros.
Mejorar el operador buscar por nombre, recodificándolo como búsqueda binaria. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacto.h"

int main(){
    tnombre nombre/*,vnombre[MAX]*/;
    ttel tel/*,vtel[MAX]*/;
    tvnombre vnombre;
    tvtel vtel;
    int i=0/*,dim*/;
    char res;

    FILE *archt;
    archt=fopen("DatosG3E2.txt","r");
    if (archt==NULL)
        printf("no se abrio el archivo\n");
    else{
        //fscanf(archt,"%s%s\n",nombre,tel);
        while (!feof(archt)){
            fscanf(archt,"%s%s\n",nombre,tel);
            strcpy(vnombre[i],nombre);
            strcpy(vtel[i],tel);
            i++;
            //fscanf(archt,"%s%s\n",nombre,tel);
        }
        //dim=i;
        fclose(archt);
    }

    /*for(i=0;i<dim;i++)
            printf("%s  %s\n",vnombre[i],vtel[i]);*/



    printf("ue desea hacer?\nAgregar contacto(1)\tListar agenda(2)\tBuscar por nombre(3)\tTerminar(cualuier tecla)\n");
    scanf("%c",&res);
    while (res=='1' ||res=='2' ||res=='3'){
        if (res=='1'){
            printf("ingrese nombre\n");
            scanf("%s",nombre);
            printf("ingrese telefono\n");
            scanf("%s",tel);
            agregarcontacto(&i,nombre,tel,vnombre,vtel);
            //printf("nombre: %s\ntelefono: %s\n",vnombre[i],vtel[i]);
            //dim=i;
            //printf("contactos =%d\n",i);
            /*for (i=0;i<dim;i++)
                printf("%s  %s\n",vnombre[i],vtel[i]);*/

        }
        else
            if (res=='2')
               listar(i,vnombre,vtel);

            else
                if (res=='3'){
                   printf("ingrese nombre de contacto buscado\t");
                   scanf("%s",nombre);
                   buscarpornombre(i,vnombre,vtel,nombre);
                }

        printf("ue desea hacer?\nAgregar contacto(1)\tListar agenda(2)\tBuscar por nombre(3)\tTerminar(cualuier tecla)\n");
        scanf(" %c",&res);
    }


    return 0;
}
