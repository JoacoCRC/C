#include <stdio.h>
#include "Fracciones.h"


fraccion crear(int num,int den){
    fraccion frac;
    frac.num=num;
    frac.den=den;
    return frac;
}
int numerador(fraccion frac){
    return frac.num;
}
int denominador(fraccion frac){
    return frac.den;
}
fraccion sumar(fraccion frac1, fraccion frac2){
    fraccion frac;
    frac.den=frac1.den*frac2.den;
    frac.num=frac2.den*frac1.num+frac1.den*frac2.num;
    return frac;
}
fraccion restar(fraccion frac1, fraccion frac2){
    fraccion frac;
    frac.den=frac1.den*frac2.den;
    frac.num=frac2.den*frac1.num-frac1.den*frac2.num;
    return frac;
}
fraccion multiplicar(fraccion frac1, fraccion frac2){
    fraccion frac;
    frac.den=frac1.den*frac2.den;
    frac.num=frac1.num*frac2.num;
    return frac;
}
fraccion dividir(fraccion frac1, fraccion frac2){
    fraccion frac;
    frac.den=frac1.den*frac2.num;
    frac.num=frac1.num*frac2.den;
    return frac;
}


int iguales(fraccion frac1, fraccion frac2){
    if (frac1.num==frac2.num && frac1.den==frac2.den)
        return 1;
    else
        return 0;
}

fraccion simplificar(fraccion fracc){
    int i=2;
    fraccion frac;
    frac.num=fracc.num;
    frac.den=fracc.den;
    while (i<=frac.num && i<=frac.den){
        if (frac.den%i==0 && frac.num%i==0){
            frac.num=frac.num/i;
            frac.den=frac.den/i;
        }
        else
            i++;


    }
    return frac;
}

