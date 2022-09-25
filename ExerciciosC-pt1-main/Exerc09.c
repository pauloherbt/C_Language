#include<stdio.h>
main()
{
	int n,n2,cont=0, positivo=0,npositivo=0;
	printf("Digite o numero de termos da sequencia\n");
	scanf("%d", &n);
	while (cont<n)
	{
		printf("Digite o %d numero ", cont+1);
		scanf("%d", &n2);
		if(n2>0)
		{
			positivo++;	
		}
		else
			npositivo++;
		cont++;		
	}
	printf("A quantidade de numeros positivos eh de %d\n", positivo);
	printf("A quantidade de numeros nao positivos eh de %d", npositivo);
	
}
