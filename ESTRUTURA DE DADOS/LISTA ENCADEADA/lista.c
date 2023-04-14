#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

typedef struct lista {
    int info;
    Lista* prox;
}Lista;

Lista* lst_cria(){
    return NULL;
}

int lst_vazia(Lista* l){
    return (l==NULL);
}

Lista* lst_insere(Lista* l, int info){
    Lista* lstaux= (Lista*)malloc(sizeof(Lista));
    lstaux->info=info;
    lstaux->prox=l;
    return lstaux;
}

Lista* lst_busca(Lista* l, int info){
    Lista* laux=l;
    while(laux!=NULL){
        if(laux->info==info){
            return laux;
        }
        laux=laux->prox;
    }
    return NULL;
}

 void lst_imprime(Lista* l){
    Lista* laux=l;
    while(laux!=NULL){
        printf("Info: %d\n", laux->info);
        laux=laux->prox;
    }
    printf("debug");
 }

 Lista* lst_remove(Lista* l, int info){
    if(l!=NULL){ //caso lista vazia
        Lista* laux=l->prox;
        if(l->info==info){ //caso elemento a ser removido seja o primeiro da lista
            free(l);
            return laux;
        }
    
        else{ //caso em que o elemento esta no meio||fim da lista
            Lista* lant=l;
            while(laux!=NULL){
                if(laux->info==info){
                    lant->prox=laux->prox;
                    free(laux);
                    break;
                }
                else{
                    lant=laux;
                    laux=laux->prox;
                }
            }
            }
    }
    return l;
}

void lst_libera(Lista* l){
    Lista* lprox;
    while(l!=NULL){
        lprox=l->prox;
        free(l);
        l=lprox;
    }
}
