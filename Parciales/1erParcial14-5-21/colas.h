
#define MAX 50

typedef struct {
    char patente[8],tipo[3];
    int litros;}TElementoC;

typedef struct {
    TElementoC datos[MAX];
    int pri, ult; } TCola;

void IniciaC (TCola * C);

int VaciaC (TCola C);

TElementoC consultaC (TCola C);

void sacaC (TCola *C, TElementoC* x);

void poneC (TCola *C, TElementoC x);
