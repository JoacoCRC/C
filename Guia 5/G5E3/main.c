/*3. Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes
a. en orden inverso, comenzando por el último votante.
b. en el orden que sufragaron. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"


//void cargapila(TPila *p);
void leerArchivo(TPila *p);

void muestra(TPila *p,int n);

int main()
{
    TPila p;
    int N;

    //cargapila(&p);
    leerArchivo(&p);
    printf("ingrese cantidad de votantes a mostrar\n");
    scanf("%d",&N);

    muestra(&p,N);

    return 0;
}

void leerArchivo(TPila *p)
{

    char nombre[20], apellido[20], dni[10];

    FILE *archt;

    archt = fopen("DatosG5E3.txt","r");

    if (archt == NULL)
    {

        printf("no se encontro archivo\n");

    }
    else
    {

        fscanf(archt, "%s", nombre);

        while(!feof(archt))
        {

            fscanf(archt, "%s", apellido);
            fscanf(archt, "%s", dni);

            printf("%s,%s,%s \n", nombre, apellido, dni);

            fscanf(archt, "%s", nombre);

        }

        fclose(archt);
    }
}

/*void cargapila(TPila *p){
    TElementoP votante;
    char nombre[20],apellido[20],dni[10];
    FILE *archt;

    archt=fopen("DatosG5E3.txt","r");
    if (archt==NULL)
        printf("no se encontro archivo\n");
    else{
        iniciaP(p);*/
        /*fscanf(archt,"%s",nombre);          con lectura adelantada no me guarda la ultima linea del .txt
        fscanf(archt,"%s",apellido);          agregando los strcpy y el poneP fuera del ciclo si lo guarda.
        fscanf(archt,"%s\n",dni);*/   //de la forma ue lo dejo presentado ahor, sin lectura adelantada, me lee correctamente
     /*   while(!feof(archt)){
            fscanf(archt,"%s",nombre);
            fscanf(archt,"%s",apellido);
            fscanf(archt,"%s\n",dni);
            strcpy(votante.nombre,nombre);
            strcpy(votante.apellido,apellido);
            strcpy(votante.dni,dni);
            poneP(p,votante);*/

            /*fscanf(archt,"%s",nombre);
            fscanf(archt,"%s",apellido);
            fscanf(archt,"%s\n",dni);*/
       // }
        /*strcpy(votante.nombre,nombre);
        strcpy(votante.apellido,apellido);
        strcpy(votante.dni,dni);
        poneP(p,votante);*/
      /*  fclose(archt);
    }
}*/

void muestra(TPila *p,int n){
    TPila aux;
    int aux1=n;
    TElementoP votante;

    iniciaP(&aux);
    printf("ultimos votantes\n");
    while(n>0 && !VaciaP(*p) ){  //MUESTRA ORDEN INVERSO
        sacaP(p,&votante);
        printf("%s %s\n",votante.nombre,votante.apellido);
        poneP(&aux,votante);
        n--;
    }
    while (!VaciaP(*p)){ //DOY VUELTA LA PILA PARA MOSTRAR EN ORDEN
        sacaP(p,&votante);
        poneP(&aux,votante);
    }
    n=aux1;
    printf("primeros votantes\n");
    while (n>0 && !VaciaP(aux)){  //MUESTRO EN ORDEN
        sacaP(&aux,&votante);
        printf("%s %s\n",votante.nombre,votante.apellido);
        poneP(p,votante);
        n--;
    }
    while (!VaciaP(aux)){ //RECUPERO PILA
        sacaP(&aux,&votante);
        poneP(p,votante);
    }

}
