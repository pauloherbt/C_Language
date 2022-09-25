#include<stdio.h>
main()
{
	int inicio, fim, duracao;
	printf("Digite a hora de inicio do jogo\n");
	scanf("%d", &inicio);
	printf("Digite a hora que o jogo acabou\n");
	scanf("%d", &fim);
	if(inicio>fim)
	{
		duracao=fim-inicio+24;
	}
	else
	{
		duracao=fim-inicio;
	}
	printf("A duracao da partida foi de: %d horas", duracao);
}
