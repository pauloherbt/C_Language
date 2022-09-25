#include<stdio.h>
main()
{
	char letra;
	printf("Digite uma letra\n");
	scanf("%c", &letra);
	if(letra=='a'|| letra=='e' || letra== 'i' || letra=='o' || letra== 'u')
	{
		printf("eh vogal");
	}
	else if(letra=='A' || letra=='E' || letra=='I' || letra=='O' || letra=='U')
	{
		printf("eh vogal");	
	}
	else
	{
		printf("eh consoante");
	}
}

