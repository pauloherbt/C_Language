#include<stdio.h>
#include<stdlib.h>    
#include"fila.h"
typedef struct lista {
    int info;
    Lista* prox;
}Lista;

typedef struct fila {
    Lista* ini;
    Lista* fim;
}Fila;

Fila* fila_cria(){
    Fila* f=(Fila*)malloc(sizeof(Fila));
    f->ini=NULL;
    f->fim=NULL;
}
int fila_vazia(Fila* f){
    return f->ini==NULL;
}
void fila_insere(Fila* f, int info){
    Lista* l=(Lista*) malloc(sizeof(Lista));
    l->info=info;
    l->prox=NULL;
    if(fila_vazia(f))
        f->ini=l;
    else
        f->fim->prox=l;
    f->fim=l;
}

int fila_remove(Fila* f){
    if(!fila_vazia(f)){
        Lista* laux=f->ini;
        int elemento=f->ini->info;
        f->ini=f->ini->prox;
        free(laux);
        if(fila_vazia(f)){
            f->fim=NULL;
        }
        return elemento;
    }
    printf("fila vazia");
    exit(1);
}
void fila_imprime(Fila* f){
    if(fila_vazia(f)){
        printf("fila vazia");
        exit(1);
    }
    Lista* laux=f->ini;
    while(laux!=NULL){
        printf("info: %d\n",laux->info);
        laux=laux->prox;
    }
}
void fila_libera(Fila* f){
    Lista* laux=f->ini;
    while(laux!=NULL){
        Lista* rmv=laux->prox;
        free(laux);
        laux=rmv;
    }
    free(f);
}
int qtd_maior(Fila* f, int n){
    if(fila_vazia(f)){
        printf("fila vazia");
        exit(1);
    }
    int contador=0;
    for(Lista* laux=f->ini;laux!=NULL;laux=laux->prox){
        if(laux->info>n)
            contador++;
    }
    return contador;
}
int pares(Fila* f){
    if(fila_vazia(f)){
        printf("fila vazia");
        exit(1);
    }
    int pares=0;
    for(Lista* laux=f->ini;laux!=NULL;laux=laux->prox){
        if(laux->info%2==0)
            pares++;
    }
    return pares;
}

Lista* percorrerLista(Lista* l, Fila* faux){
    if(l==NULL){
        return l;
    }
    percorrerLista(l->prox,faux);
    fila_insere(faux,l->info);
}
Fila* inverte(Fila* f){
    Fila* f_inv=fila_cria();
    percorrerLista(f->ini,f_inv);
    return f_inv;
    
}
