#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main(void)
{
    Lista *L=lst_cria;
    for(int i=0;i<10;i++){
        L=lst_insere(L,i+1);
    }
    
    lst_imprime(L);
    printf("main");
    return 0;
}
