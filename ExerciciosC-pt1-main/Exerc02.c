#include<stdio.h>
main()
{
	int car_vendido;
	float tot_vendido,salario,taxa,salariof;
	printf("Digite a quantidade de carros vendidos,o valor total das vendas, o salario fixo e a taxa por carro vendido ");
	scanf("%d %f %f %f",&car_vendido,&tot_vendido,&salario,&taxa);
	salariof=salario + (taxa*car_vendido) + (tot_vendido*0.05);
	printf("O salario final eh de R$%.2f", salariof);
}
