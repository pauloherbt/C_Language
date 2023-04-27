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
    if(!lst_vazia(l)){
        Lista* laux=l;
        while(laux!=NULL){
            printf("Info: %d\n", laux->info);
            laux=laux->prox;
        }
    }
    
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

//questoes
int comprimento(Lista* l){
    if(lst_vazia(l))
        return -1;

    Lista* laux=l;
    int contador=0;
    while(laux!=NULL){
        contador++;
        laux=laux->prox;
    }
    return contador;    
} 

int menores(Lista* l, int n){
    if(!lst_vazia(l)){
        Lista* laux=l;
        int contador=0;
        while(laux!=NULL){
            if(laux->info<n)
                contador++;
            laux=laux->prox;    
        }
        return contador;
    }
    return -1;
}

int soma(Lista* l){
    if(!lst_vazia(l)){
        return l->info+soma(l->prox);
    }
    return 0;
}

int primos(Lista* l){
    int contador=0;
    for (Lista* laux=l; laux!=NULL; laux=laux->prox){
        if(laux->info==2){
            contador++;
        }
        else{
            int cont_Div=0;
            for ( int n=laux->info-1; n >= 2; n--){
                if(laux->info%n==0){ //se houver um caso em que o numero dividido por um numero != dele, ele nao e primo
                    cont_Div++;
                }
            }
            if(cont_Div==0 && laux->info!= 1) //n saiu do loop com valor !=0 ent e primo
                contador++;
        }          
    }
    return contador;
}

Lista* lst_conc(Lista* l1, Lista* l2){
    Lista* l_resultante=lst_cria();
    Lista* laux=l1;
    Lista* lfim=NULL; //aponta para o fim da lista
    while (laux!=NULL)
    {
        if(l_resultante==NULL){
            l_resultante=lst_insere(l_resultante,laux->info);
            lfim=l_resultante;
        }
        else{
            lfim->prox=lst_insere(lfim->prox,laux->info);
            lfim=lfim->prox;
        }
        laux=laux->prox;
    }
    laux=l2;
    while (laux!=NULL)
    {
        if(l_resultante==NULL){
            l_resultante=lst_insere(l_resultante,laux->info);
            lfim=l_resultante;
        }
        else{
            lfim->prox=lst_insere(lfim->prox,laux->info);
            lfim=lfim->prox;
        }
        laux=laux->prox;
    }


    return l_resultante;
}
Lista* lst_diferenca(Lista* l1, Lista* l2){
    Lista* laux1=l1;
    for(Lista* laux2=l2;laux2!=NULL;laux2=laux2->prox){
        for (Lista* laux1 =l1; laux1!=NULL; laux1=laux1->prox){
            if(laux1->info==laux2->info){
                l1=lst_remove(l1,laux1->info);
                break;
            }
        }
    }
    return l1;
}


//recursivas
void lst_imprime_rec(Lista* l){
    if(!lst_vazia(l)){
        printf("info: %d\n",l->info);
        lst_imprime_rec(l->prox);
    }
    
}

void lst_imprime_invertida_rec (Lista* l){
    if(!lst_vazia(l)){
        lst_imprime_invertida_rec(l->prox);
        printf("info: %d\n",l->info);
    }
}

Lista* lst_remove_rec(Lista* l, int info){
    if(!lst_vazia(l)){
        if(l->info==info){
            Lista* laux=l;
            l=l->prox;
            free(laux);
        }
        else{
            l->prox=lst_remove_rec(l->prox,info);
        }
    }
    return l;
}
