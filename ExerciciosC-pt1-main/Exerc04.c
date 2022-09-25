#include<stdio.h>
main()
{
	float salario,salario_tot,vendas_tot,comissao1,comissao2;
	printf("Insira o valor do salario fixo, e do total de vendas efetuadas\n");
	scanf("%f %f",&salario, &vendas_tot);
	if(vendas_tot>1500)
	{
		comissao1=1500*0.03;
		comissao2=(vendas_tot-1500)*0.05;
		salario_tot=salario + comissao1 + comissao2;
		printf("O salario total do vendedor eh de R$%.2f",salario_tot);
	}
	else
	{
		comissao1=(vendas_tot*0.03);
		salario_tot = salario + comissao1;
		printf("O salario total do vendedor eh de R$%.2f", salario_tot);
	}
}
