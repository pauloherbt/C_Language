#include<stdio.h>
main()
{
	int a,b,c;
	printf("Digite os valores dos lados do triangulo ");
	scanf("%d %d %d", &a,&b,&c);
	if(a<b+c && b<a+c && c<a+b)
	{
		printf("Forma um triangulo!");
	}
	else
	printf("Nao forma um triangulo!");
}
