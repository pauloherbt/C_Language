typedef struct fila Fila;

Fila* fila_cria();
int fila_vazia(Fila *f);
void fila_insere(Fila *f, int info);
int fila_remove(Fila *f);
void fila_imprime(Fila *f);
void fila_libera(Fila *f);
