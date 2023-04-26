#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main(void)
{
    Lista *L=lst_cria();
    Lista* L2=lst_cria();
    //printf("compriemnto: %d\n", comprimento(L));
    for(int i=0;i<5;i++){
        L=lst_insere(L,i+1);
        L2=lst_insere(L2,(i+6));
    }
    //lst_imprime(L);
    //lst_imprime(L2);
    Lista* l3=lst_conc(L,L2);
    lst_imprime(l3);
    //puts("pos funciton");
    //lst_remove(L,5);
    //lst_imprime(l3);
    //puts("l2");
    //lst_imprime(L2);
    /*printf("compriemnto: %d\n", comprimento(L));
    printf("qntd de nos menores q 11: %d\n",menores(L, 6));
    printf("A soma dos elementos eh %d\n", soma(L));
    printf("quiantidade de nuemros primos: %d\n", primos(L));
    */

    return 0;
}
