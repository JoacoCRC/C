#define MAX 50

typedef struct{
    char id[15];
    int tsol,tdur;} TElementoC;

typedef struct {
    TElementoC datos[MAX];
    int pri, ult; } TCola;

void IniciaC (TCola * C);

int VaciaC (TCola C);

TElementoC consultaC (TCola C);

void sacaC (TCola *C, TElementoC* x);

void poneC (TCola *C, TElementoC x);
