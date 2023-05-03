#include<stdio.h>
#include<stdlib.h>
#include"fila.h"
int main()
{
    Fila* f=fila_cria();
    fila_insere(f,1);
    fila_insere(f,2);
    fila_insere(f,3);
    fila_imprime(f);
    fila_remove(f);
    fila_imprime(f);
    return 0;
}
