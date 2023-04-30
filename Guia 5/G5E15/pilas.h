#define MAX 50
typedef struct{
    int num;
    char palo;} TElementoP;

typedef struct{
   TElementoP datos[MAX];
   int tope;} TPila;

void iniciaP (TPila * P);

void poneP (TPila * P, TElementoP x);

void sacaP (TPila * P, TElementoP * x);

TElementoP consultaP(TPila P);

int VaciaP (TPila P);