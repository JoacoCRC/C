/*9. Ingresar una secuencia de caracteres terminada en punto que representa una expresión
aritmética.
a. Comprobar que los paréntesis estén balanceados, de no ser así informar si falta
izquierdo o derecho. Los paréntesis son los únicos símbolos a controlar.
b. Agregar a la expresión la presencia y comprobación de corchetes y llaves. */

#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void armarpila(TPila *p);
void mostrarinv(TPila *p);
void balanceada(TPila *p);

int main()
{
    TPila p;

    armarpila(&p);
    mostrarinv(&p);
    balanceada(&p);

    return 0;
}
void armarpila(TPila *p){
    TElementoP c;

    printf("ingrese operacion elemento a elemento, punto para finalizar\n");
    scanf("%c",&c);
    iniciaP(p);
    while (c!='.'){
        poneP(p,c);
        fflush(stdin);
        scanf("%c",&c);
    }
}
void mostrarinv(TPila *p){
    TElementoP c;
    if (!VaciaP(*p)){
        sacaP(p,&c);
        if (!VaciaP(*p))
            mostrarinv(p);
        printf("%c",c);
        poneP(p,c);
    }
}
void balanceada(TPila *p){
    TElementoP c;
    int cont_par=0,cont_cor=0,cont_llav=0,bal=1;

    while (!VaciaP(*p)&&bal){
        sacaP(p,&c);
        if ((c=='('&&!cont_par)||(c=='['&&!cont_cor)||(c=='{'&&!cont_llav))
                bal=0;
        else
            switch (c){
                case ')': cont_par++;
                    break;
                case ']': cont_cor++;
                    break;
                case '}': cont_llav++;
                    break;
                case '(': cont_par--;
                    break;
                case '[': cont_cor--;
                    break;
                case '{': cont_llav--;
                    break;
            }
    }
    if (VaciaP(*p)&&(cont_par>0||cont_cor>0||cont_llav>0))
        bal=0;

    if (bal)                    //dice bien si esta balanceada o no, pero marca mal el signo faltante
        printf("la ecuacion esta balanceada\n");
    else{
        printf("la ecuacion no esta balanceada,al menos  ");
        if(!cont_par)
            printf("falta un parentesi izuierdo");
        else
            if(cont_par)
                printf("falta un parentesi derecho");
            else
                if(!cont_cor)
                    printf("falta un corchete izuierdo");
                else
                    if(cont_cor)
                        printf("falta un corchete derecho");
                    else
                        if(!cont_llav)
                            printf("falta una llave izuierdo");
                        else
                            if(cont_llav)
                                printf("falta una llave derecho");
    }
}

/*void balanceada(TPila *p){     //inciso a)
    TElementoP c;
    int  parent_der=0,bal=1;
    printf("\n");
    while (!VaciaP(*p)&&bal){
        sacaP(p,&c);
        if (c=='('&&parent_der==0)
            bal=0;
        else
            if(c=='(')
                parent_der--;
            else
                if(c==')')
                    parent_der++;
    }
    if(VaciaP(*p)&&parent_der>0)
        bal=0;

    if (bal)
        printf("la ecuacion esta balanceada\n");
    else{
    printf("la ecuacion no esta balanceada, ");
    if (parent_der>0)
        printf("faltan parentecis izuierdos\n");
    else
        printf("faltan parentesis derechos\n");
    }

}*/
