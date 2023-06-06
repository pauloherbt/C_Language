typedef struct arvb ArvB;
/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);
/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);
/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);
/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);
/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);
/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c);
int arv_altura(ArvB* a);
int folhas_primos(ArvB* a);
int dois_filhos(ArvB* a);
int nos_igual_altura(ArvB* a);
int iguais(ArvB* a, ArvB* b);