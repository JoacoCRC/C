#define MAX 15

typedef char tnombre[MAX];
typedef char ttel[MAX];

typedef tnombre tvnombre[MAX];
typedef ttel tvtel[MAX];

void agregarcontacto(int *i,tnombre nomb,ttel tel,tvnombre vnombre,tvtel vtel);

void listar(int i,tvnombre vn,tvtel vt);

void buscarpornombre(int i,tvnombre vn,tvtel vt,tnombre nomb);
