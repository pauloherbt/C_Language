#include<stdio.h>
#include<stdlib.h>
#include"pilha_com_Lista.h""

typedef struct pilha{
    Lista* prim;
}Pilha;

Pilha* pilha_cria(){
    Pilha* p= (Pilha*)malloc(sizeof(Pilha));
    p->prim=NULL;
    return p;
}
typedef struct lista{
    int info;
    Lista* prox;
}Lista;


void pilha_push(Pilha* p, int info){
    Lista* l=(Lista*)malloc(sizeof(Lista));
    l->info=info;
    l->prox=p->prim;
    p->prim=l;
}

int pilha_pop(Pilha* p){
    Lista* l=p->prim;
    p->prim=p->prim->prox;
    int info=l->info;
    free(l);
    return info;
}
void pilha_imprime(Pilha* p){
    for(Lista* laux=p->prim;laux!=NULL;laux=laux->prox){
        printf("%d\n", laux->info);
    }
}

int pilha_vazia(Pilha* p){
    return p->prim==NULL;
}

void pilha_libera(Pilha* p){
    Lista* l=p->prim;
    Lista* laux;
    while(l!=NULL){
        laux=l->prox;
        free(l);
        l=laux;
    }
    free(p);
}


