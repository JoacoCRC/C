

typedef struct{
    int num,den;} fraccion;

    fraccion crear(int num,int den);
    int numerador(fraccion frac);
    int denominador(fraccion frac);
    fraccion sumar(fraccion frac1, fraccion frac2);
    fraccion restar(fraccion frac1, fraccion frac2);
    fraccion multiplicar(fraccion frac1, fraccion frac2);
    fraccion dividir(fraccion frac1, fraccion frac2);
    fraccion simplificar(fraccion frac);
    int iguales(fraccion frac1, fraccion frac2);


