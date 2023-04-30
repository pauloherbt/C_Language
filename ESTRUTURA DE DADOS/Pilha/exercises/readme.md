Implemente o Tipo Abstrato de Dados (TAD) “pilha.h” usando Vetor (ver slides
sobre Pilha) e acrescente as seguintes funções:
a) função que receba uma pilha como argumento e retorne o valor armazenado em seu
topo. Essa função deve obedecer ao protótipo:int topo(Pilha* p);
Obs. Essa função não altera a pilha, apenas retorna uma cópia do valor armazenado no
seu topo.
b) função que retorne o número de elementos da pilha que possuem o campo info com
valor ímpar. Essa função deve obedecer ao protótipo:
int impares(Pilha* p);
c) função que verifique quais são os elementos pares de uma pilha p1 e que os empilhe
em ordem crescente em uma pilha p2. Essa função deve obedecer ao protótipo:
Pilha* empilha_pares(Pilha* p1, Pilha* p2);
Obs. a pilha p1 permanece inalterada após a execução da função.