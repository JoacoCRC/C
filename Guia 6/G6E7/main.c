/*7. Implementar un programa de biblioteca que administre la siguiente estructura: un arreglo de
listas simples ordenadas alfabéticamente con los autores que comiencen con la misma letra, o
sea que habrá un elemento del arreglo por cada letra del abecedario, aunque no existan
autores que comiencen con dicha letra. Para cada autor existe una sublista, ordenada por
título, con los libros disponibles para ser prestados de cada autor:
• Autor
• Sublista de libros de dicho autor
    o Titulo
    o Año de edición
Se debe poder agregar libros a esta estructura.
Además, gestionar una lista de socios con una sublista de libros prestados. Permitir las
operaciones de registrar préstamos (mover el nodo de la sublista del autor al final de la sublista
de libros prestados para el socio) y devoluciones (mover nodo del libro prestado de dicha
sublista a la sublista del autor de acuerdo al orden indicado). Dicha lista posee la siguiente
estructura:
• Socio
• Sublista de libros prestados
    o Titulo
    o Año de edición*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABC 27
#define MAX 20

typedef struct nodito{
    char titulo[MAX];
    int anio;
    struct nodito *sig;} nodito;
typedef nodito *SubLista;

typedef struct nodoA{
    char autor[MAX];
    SubLista subA;
    struct nodoA *sig;}nodoA;
typedef nodoA *TListaA;

typedef struct nodoS{
    int socio;
    SubLista subS;
    struct nodoS *sig;}nodoS;
typedef nodoS *TListaS;

int posvec(char car);
//void agregarlibro(TListaA *LA,char autor[]);
void armararrglo(TListaA arr[]);
void agregaautor(TListaA *LA,char autor[],char titulo[],int anio);

int main()
{
    TListaA arr[ABC];
    TListaS LS;
    int res,i;
    char autor[MAX];



    armararrglo(arr);


    printf("Agregar libro(1) Registrar prestamo(2) Registrar devolucion(3)\n");
    scanf("%d",&res);
    while (res==1 || res==2 ||res==3){
        if (res==1){
            printf("ingrese autor del libro a agregar\n");
            scanf("%s",autor);
            agregarlibro(&arr[posvec(autor[0])],autor);
        }
        else
            if(res==2)
                prestamo();
            else
                devolucion();
    }
    return 0;
}

void armararrglo(TListaA arr[]){
    FILE *archt;
    char autor[MAX],titulo[MAX];
    TListaA nuevoA,actA;
    int pos,anio;
    SubLista nuevoL;

    for(i=0;i<ABC;i++)
        arr[i]=NULL;

    archt=fopen("autores.txt","r");
    if (archt==NULL)
        printf("error\n");
    else{
        fscanf(archt,"%s%s %d",autor,titulo,anio);
        while(!feof(archt)){
            //agregaautor(arr[posvec(autor[0])],autor,titulo,anio);
            if (arr[posvec(autor[0])==NULL);
            fscanf(archt,"%s%s %d",autor,titulo,anio);
        }

        fclose(archt);
    }
}

int posvec(char car){
    switch (car){
    case 'a':return 0;
        break;
    case 'b':return 1;
        break;
    case 'c':return 2;
        break;
    case 'd':return 3;
        break;
    case 'e':return 4;
        break;
    case 'f':return 5;
        break;
    case 'g':return 6;
        break;
    case 'h':return 7;
        break;
    case 'i':return 8;
        break;
    case 'j':return 9;
        break;
    case 'k':return 10;
        break;
    case 'l':return 11;
        break;
    case 'm':return 12;
        break;
    case 'n':return 13;
        break;
    case 'ñ':return 14;
        break;
    case 'o':return 15;
        break;
    case 'p':return 16;
        break;
    case 'q':return 17;
        break;
    case 'r':return 18;
        break;
    case 's':return 19;
        break;
    case 't':return 20;
        break;
    case 'u':return 21;
        break;
    case 'v':return 22;
        break;
    case 'w':return 23;
        break;
    case 'x':return 24;
        break;
    case 'y':return 25;
        break;
    case 'z':return 26;
        break;
    }
}

void agregarlibro(TListaA *LA,char autor[]){
    TListaA actA,nuevoA,antA;
    SubLista nuevoL,actL,antL;

}
void agregaautor(TListaA *LA,char autor[],char titulo[],int anio){
    TListaA nuevo,ant,act;

    nuevo=(TListaA)malloc(sizeof(nodoA));
    strcpy(nuevo->autor,autor);
    if (autor==NULL || strcmp(autor,nuevo->autor)<0){
        nuevo->sig=*LA;
        *LA=nuevo;
    }
    else{
        ant=NULL;
        act=*LA;
        while()
    }
}
