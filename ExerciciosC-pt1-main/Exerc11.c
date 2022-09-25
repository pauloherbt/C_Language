#include<stdio.h>
#include<math.h>
main()
{
	int n,r,resultado=0,pot,cont=0;
	printf("Digite um numero na forma binaria\n");
	scanf("%d",&n);
	do
	{	
	if(n%10==0)
	{
		r=n%10;
		n=n/10;
		pot=r*pow(2,cont);
	}
	else if(n%10==1)
	{
		r=n%10;
		n=n/10;
		pot = r*pow(2,cont);
	}
	else
	{
		printf("Digite um numero na forma binaria!");
		return(0);
	}
	cont++;
	resultado+=pot;
	}
	while(n!=0);
	printf("O resultado na forma decimal eh de %d", resultado);
}
