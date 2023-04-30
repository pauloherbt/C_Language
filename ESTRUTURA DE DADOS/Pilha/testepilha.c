#include<stdlib.h>
#include<stdio.h>
#include"pilha_com_Lista.h"
int main(int argc, char const *argv[])
{
    Pilha* p= pilha_cria();
    pilha_push(p,3);
    pilha_push(p,2);
    pilha_push(p,1);
    pilha_imprime(p);
    pilha_pop(p);
    pilha_imprime(p);
    pilha_pop(p);
    pilha_push(p,0);
    pilha_imprime(p);
    if(pilha_vazia(p));
        puts("ta vazia fiote");
    return 0;
}
