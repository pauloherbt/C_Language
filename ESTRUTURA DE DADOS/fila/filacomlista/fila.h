typedef struct fila Fila;
typedef struct lista Lista;

Fila* fila_cria();
int fila_vazia(Fila *f);
void fila_insere(Fila *f, int info);
int fila_remove(Fila *f);
void fila_imprime(Fila *f);
void fila_libera(Fila *f);
int qtd_maior(Fila* f, int n);
int pares(Fila* f);
Fila* inverte(Fila* f);
Lista* percorrerLista(Lista* l,Fila* faux);

