typedef struct pilha Pilha;
typedef struct lista Lista;

Pilha* pilha_cria();

int pilha_vazia(Pilha* p);

void pilha_push(Pilha* p, int info);

int pilha_pop(Pilha* p);

void pilha_imprime(Pilha* p);

void pilha_libera(Pilha* p);

//questoes
int topo(Pilha* p);
int impares(Pilha* p);
Pilha* empilha_pares(Pilha* p1, Pilha* p2);
