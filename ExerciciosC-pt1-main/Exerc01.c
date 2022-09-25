#include<stdio.h>
main()
{
	float valor_fabrica, valor_final;
	printf("Digite o valor de fabrica\n");
	scanf("%f", &valor_fabrica);
	valor_final=valor_fabrica + (valor_fabrica*28/100) + (valor_fabrica*45/100);
	printf("O valor final do carro eh de R$%.2f",valor_final);
}
