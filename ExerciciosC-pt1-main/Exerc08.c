#include<stdio.h>
main()
{
	int mes,teste=1;
	printf("digite um valor correspondente ao mes\n");
	puts("[1]-Janeiro [2]-Fevereiro\n[3]-Marco   [4]-Abril\n[5]-Maio    [6]-Junho\n[7]-Julho   [8]-Agosto\n[9]-Setembro[10]-Outubro");
	puts("[11]-Novembro [12]-Dezembro");
	scanf("%d",&mes);
	switch (mes)
	{
		case 1 ... 3:
			printf("O mes %d pertence ao 1 trimestre",mes);
			break;
		case 4 ... 6:
			printf("O mes %d pertence ao 2 trimestre", mes);
			break;
		case 7 ... 9:
			printf("O mes %d pertence ao 3 trimestre",mes);
			break;
		case 10 ... 12:
			printf("O mes %d pertence ao 4 trimestre", mes);
			break;
		default:
			printf("Digite um mes valido");
			teste = 0;				
	}
	if(teste)
	{
		if(mes==2)
		{
			printf(" e tem 28 dias");
		}
		else if(mes==4 || mes==6 || mes==9 || mes==11)
		{
			printf(" e tem 30 dias");	
		}
		else
		{
			printf(" e tem 31 dias");
		}
	}
}
