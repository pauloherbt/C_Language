#include<stdio.h>
main()
{
	float n1,n2;
	printf("Digite o valor 1\n");
	scanf("%f",&n1);
	do
	{
		printf("Digite o valor 2\n");
		scanf("%f",&n2);
		if(n2==0)
		{
			printf("Valor invalido. Informe outro numero\n");
		}
	}
	while(n2==0);
	printf("O resultado da divisao entre %.2f e %.2f eh igual a %.2f",n1, n2, n1/n2);
}

