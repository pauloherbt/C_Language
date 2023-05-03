#include<stdio.h>
#include<stdlib.h>
#include"fila.h"
#define MAX 3
typedef struct fila{
    int n;
    int ini; //salva o indice do elemento inicial
    int v[MAX];
}Fila;

Fila* fila_cria(){
    Fila* f= (Fila*)malloc(sizeof(Fila));
    f->n=0;
    f->ini=0;

    return f;
}
void fila_insere(Fila *f, int info){
   if(f->n>=MAX){
    exit(1);
   }
    int fim=(f->ini+f->n)%MAX;
    f->v[fim]=info;
    f->n++;
}
int fila_vazia(Fila *f){
    return f->n==0;
}
int fila_remove(Fila *f){
    int a=f->v[f->ini];
    f->ini=(f->ini+1)%MAX;
    f->n--;
    return a;
}
void fila_imprime(Fila *f){
    int i=f->ini;
    for (int n = 0; n<f->n; n++)
    {
        printf("info: %d\n",f->v[i]);
        i=(i+1)%MAX;
    }
    
}


