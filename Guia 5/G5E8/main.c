/*8. Desarrollar un programa que sume dos números enteros positivos, permitiendo una cantidad
de dígitos mayor a la que soportan los tipos numéricos. Los números pueden tener diferente
magnitud y deben ser ingresados comenzando desde su dígito más significativo (en orden).
Utilizar pilas de caracteres.*/

#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void armarpila(TPila *p);
void sumapilas(TPila *p1, TPila *p2,TPila *p3);
int caracteranumero(char c);
char numeroacaracter(int n);
void mostrar(TPila *p);
void mostrarinv(TPila *p);

int main()
{
    TPila p1,p2,p3;
    armarpila(&p1);
    armarpila(&p2);
    sumapilas(&p1,&p2,&p3);
    printf("numero 1: ");
    mostrarinv(&p1);
    printf("\n");
    printf("numero 2: ");
    mostrarinv(&p2);
    printf("\n");
    printf("la suma de estos numeros es : ");
    mostrar(&p3);
    return 0;
}

void armarpila(TPila *p){
    char c;
    printf("ingrese numero\n");
    scanf(" %c",&c);
    iniciaP(p);
    while (c>='0' && c<='9'){
        poneP(p,c);
        scanf(" %c",&c);
    }
}
void sumapilas(TPila *p1, TPila *p2,TPila *p3){
    char x1,x2,x3;
    int n1,n2,n3,aux=0;
    TPila aux1,aux2;
    iniciaP(p3);iniciaP(&aux1);iniciaP(&aux2);
    while (!VaciaP(*p1)||!VaciaP(*p2)){
        if(!VaciaP(*p1)&&!VaciaP(*p2)){
            sacaP(p1,&x1);
            poneP(&aux1,x1);
            n1=caracteranumero(x1);
            sacaP(p2,&x2);
            poneP(&aux2,x2);
            n2=caracteranumero(x2);
            n3=n1+n2+aux;
            if (n3>9){
                n3-=10;
                aux=1;
            }
            else
                aux=0;
            x3=numeroacaracter(n3);
            poneP(p3,x3);
        }
        else
            if (!VaciaP(*p1)){
                sacaP(p1,&x1);
                poneP(&aux1,x1);
                n1=caracteranumero(x1)+aux;
                x3=numeroacaracter(n1);
                aux=0;
                poneP(p3,x3);
            }
            else
                if (!VaciaP(*p2)){
                    sacaP(p2,&x2);
                    poneP(&aux2,x2);
                    n2=caracteranumero(x2)+aux;
                    x3=numeroacaracter(n2);
                    aux=0;
                    poneP(p3,x3);
                }
    }
    while (!VaciaP(aux1)){
        sacaP(&aux1,&x1);
        poneP(p1,x1);
    }
    while (!VaciaP(aux2)){
        sacaP(&aux2,&x2);
        poneP(p2,x2);
    }

}
int caracteranumero(char c){
    int num;
    switch(c){
    case '0': num=0;
            break;
    case '1': num=1;
            break;
    case '2': num=2;
            break;
    case '3': num=3;
            break;
    case '4': num=4;
            break;
    case '5': num=5;
            break;
    case '6': num=6;
            break;
    case '7': num=7;
            break;
    case '8': num=8;
            break;
    case '9': num=9;
            break;
    }
    return num;
}

char numeroacaracter(int n){
    char c;
    switch(n){
    case 0: c='0';
            break;
    case 1: c='1';
            break;
    case 2: c='2';
            break;
    case 3: c='3';
            break;
    case 4: c='4';
            break;
    case 5: c='5';
            break;
    case 6: c='6';
            break;
    case 7: c='7';
            break;
    case 8: c='8';
            break;
    case 9: c='9';
            break;
    }
    return c ;
}
void mostrar(TPila *p){
    TElementoP x;
    if (!VaciaP(*p)){
        sacaP(p,&x);
        printf("%c",x);
        if (!VaciaP(*p)){
            mostrar(p);
        }

        poneP(p,x);
    }
}
void mostrarinv(TPila *p){
    TElementoP x;
    if (!VaciaP(*p)){
        sacaP(p,&x);
        if (!VaciaP(*p)){
            mostrarinv(p);

        }
        printf("%c",x);
        poneP(p,x);
    }
}
