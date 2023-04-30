#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"
#define MAX 5

typedef struct pilha{
    int n;
    int v[MAX];
}Pilha;

Pilha* pilha_cria(){
    Pilha* p= (Pilha*)malloc(sizeof(Pilha));
    p->n=0;
    return p;
}

void pilha_push(Pilha* p, int info){
    p->v[p->n]=info;
    p->n+=1;
}

int pilha_pop(Pilha* p){
    p->n-=1;
    return p->v[p->n];
}
void pilha_imprime(Pilha* p){
    for(int i=p->n-1;i>=0;i--){
        printf("%d\n", p->v[i]);
    }
}
int pilha_vazia(Pilha* p){
    return p->n==0;
}
void pilha_libera(Pilha* p){
    free(p);
}

//questoes
int topo(Pilha* p){
    if(!pilha_vazia(p))
        return p->v[p->n-1];
    printf("PILHA VAZIA");
    exit(1);    
}
int impares(Pilha* p){
    int count=0;
    for(int i=p->n-1;i>=0;i--){
        if(!(p->v[i]%2==0))
            count++;
    }
    return count;
}
Pilha* empilha_pares(Pilha* p1, Pilha* p2) {
    Pilha* aux = pilha_cria();
    int valor;
    for(int k=p1->n-1;k>=0;k--) { 
        valor = p1->v[k]; //corresponde ao topo da p1
        if (valor % 2 == 0) {
            if (pilha_vazia(p2) || valor >= topo(p2)) { 
                pilha_push(p2, valor);
            } else {
                while (!pilha_vazia(p2) && valor < topo(p2)) {
                    pilha_push(aux, pilha_pop(p2)); //removo da p2 e guardo na aux
                }
                pilha_push(p2, valor);
                for(int i=aux->n-1;i>=0;i--){
                    if(aux->v[i]%2==0) //devolvo apenas os elementos pares da aux para a p2
                        pilha_push(p2,aux->v[i]);
                }
            }
        } else {
            pilha_push(aux, valor); //guardo os impares na aux
        }
    }
    pilha_libera(aux);
    return p2;
}
