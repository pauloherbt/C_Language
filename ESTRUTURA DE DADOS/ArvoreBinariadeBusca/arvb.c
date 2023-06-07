#include<stdio.h>
#include<stdlib.h>
#include"arvb.h"

typedef struct arvb{
    int info;
    ArvB* esq;
    ArvB* dir;

}ArvB;

ArvB* arvb_cria_vazia(){
    return NULL;
}

int arvb_vazia(ArvB* a){
    return a==NULL;
}

ArvB* arvb_insere(ArvB* a,int c){
    if(arvb_vazia(a)){
        ArvB* arv= (ArvB*)malloc(sizeof(ArvB));
        arv->info=c;
        arv->dir=NULL;
        arv->esq=NULL;
        return arv;
    }
    if(c<a->info)
        a->esq=arvb_insere(a->esq,c);
    else
        a->dir=arvb_insere(a->dir,c);
    return a;        
}
void arvb_imprime(ArvB* a){
    if(!arvb_vazia(a)){
        arvb_imprime(a->esq);
        printf("%d ",a->info);
        arvb_imprime(a->dir);
    }
}
ArvB* arvb_busca(ArvB* a, int c){
    if(arvb_vazia(a))
        return NULL;
    if(c<a->info){
        return arvb_busca(a->esq,c);
    }
    else if(c>a->info){
        return arvb_busca(a->dir,c);
    }
    else
        return a;    
}
void arvb_libera(ArvB* a){
    if(!arvb_vazia(a)){
        arvb_libera(a->esq);
        arvb_libera(a->dir);
        free(a);
    }

}
ArvB* arvb_remove(ArvB* a, int c){
    if(arvb_vazia(a))
        return NULL;
    if(c<a->info){
        a->esq=arvb_remove(a->esq,c);
    }
    else if(c>a->info){
        a->dir=arvb_remove(a->dir,c);
    }
    else{
        if(a->dir==NULL&&a->esq==NULL){ //no folha
            free(a);
            a=NULL;
        }
        else if(a->dir==NULL){ //so filho a esq
            ArvB* aux= a;
            a=a->esq;
            free(aux);
        }   
        else if(a->esq==NULL){ //so filho a dir
            ArvB* aux=a;
            a=a->dir;
            free(aux);
        }
        else{
            ArvB* aux=a->esq; //sae
            while (aux->dir!=NULL){
                aux=aux->dir;
            }
            a->info=aux->info;
            aux->info=c;
            a->esq=arvb_remove(a->esq,c);
        }      
    }
    return a;    
}
int arv_altura(ArvB* a){
    if(arvb_vazia(a))
        return -1;
    int hsae=arv_altura(a->esq);
    int hsad= arv_altura(a->dir);
    if(hsae>hsad)
        return 1+hsae;    
    else
        return 1+hsad;    
}

int folhas_primos(ArvB* a){
    if(arvb_vazia(a)){
        return 0;
    }
    else if(a->esq==NULL&&a->dir==NULL){
        //verifico se e primo
        if(a->info<=1){ //n e primo
            return 0;
        }
        for(int i=2;i*i<=a->info;i++){
            if(a->info%i==0){ // nao e primo pois teve uma div
                return 0;
            }
        }
        return 1; //n teve divs ent e primo 
    }
    else
        return folhas_primos(a->esq)+ folhas_primos(a->dir);
}

int dois_filhos(ArvB* a){
    if(arvb_vazia(a))
        return 0;
    if(a->esq!=NULL&&a->dir!=NULL){
        return 1+dois_filhos(a->esq)+dois_filhos(a->dir);
        }
    else
        return dois_filhos(a->esq)+dois_filhos(a->dir);
    return 0;  
}

int nos_igual_altura(ArvB* a){
    if(arvb_vazia(a)){
        return 0;
    }
    int sae=nos_igual_altura(a->esq);
    int sad= nos_igual_altura(a->dir);
    if(a->esq!=NULL&&a->dir!=NULL){
        if(arv_altura(a->esq)==arv_altura(a->dir)){
            return 1+sae+sad;
        }
    }
    return sae+sad;
}

int iguais(ArvB* a, ArvB* b){
    if(arvb_vazia(a)&&arvb_vazia(b)){
        return 1;
    }
    if(arvb_vazia(a)||arvb_vazia(b))
       return 0;
    return a->info==b->info&&(iguais(a->esq,b->esq)&&iguais(a->dir,b->dir));
}    

