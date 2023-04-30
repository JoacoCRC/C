#define MAX 50
typedef struct{
    char nombre[20];
    char apellido[20];
    char dni[10];} TElementoP;

typedef struct{
   TElementoP datos[MAX];
   int tope;} TPila;

void iniciaP (TPila * P);

void poneP (TPila * P, TElementoP x);

void sacaP (TPila * P, TElementoP * x);

TElementoP consultaP(TPila P);

int VaciaP (TPila P);
