#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#define MAX 5
typedef struct{
		char nome[50];
		float banca,aposta;
		int md;
		unsigned long long int num_esc;
		float total;
	}dados;
void tabela(void){
	int i,j,aux=1,A[25][4];
	char strings[25][15]={{"Avestruz"},{"Águia"},{"Burro"},{"Borboleta"},
						  {"Cachorro"},{"Cabra"},{"Carneiro"},{"Camelo"},
						  {"Cobra"},{"Coelho"},{"Cavalo"},{"Elefante"},
						  {"Galo"},{"Gato"},{"Jacaré"},{"Leão"},
						  {"Macaco"},{"Porco"},{"Pavão"},{"Peru"},
						  {"Touro"},{"Tigre"},{"Urso"},{"Veado"},{"Vaca"}};
	for(i=0;i<25;i++){
		for(j=0;j<4;j++){
			A[i][j]=aux;
			aux++;	
		}
	}
	A[24][3]=0;	
	printf("%-10s %s","Animal","Intervalo\n");
	for(i=0;i<25;i++){
		printf("%-10s",strings[i]);
		for(j=0;j<4;j++){
			printf(" %d ",A[i][j]);
		}
		printf("\n");
		}
	system("pause");
	system("cls");
}
float game(int a,unsigned long long int num_esc,unsigned long long int num_sort,float aposta){
	float tot=0;
	switch (a) {
		case 1:
			if((num_esc%10)==(num_sort%10)){
				tot=aposta*2;
			}
			break;
		case 2:
			if((num_esc%100)==(num_sort%100)){
				tot=aposta*60;
			}
			break;
		case 3:
			if((num_esc%1000)==(num_sort%1000)){
				tot=aposta*600;
			}
			break;
		case 4:
			if((num_esc%10000)==(num_sort%10000)){
				tot=aposta*4000;
			}
			break;
								
	}
	return(tot);
}
float grupo(int x,int y,float aposta){
	int A[25][4],i,j,aux=1,grupo,grupo2;
	float tot;
	char strings[25][15]={{"avestruz"},{"Águia"},{"burro"},{"borboleta"},
						  {"cachorro"},{"cabra"},{"carneiro"},{"camelo"},
						  {"cobra"},{"coelho"},{"cavalo"},{"elefante"},
						  {"galo"},{"gato"},{"jacaré"},{"leão"},
						  {"macaco"},{"porco"},{"pavão"},{"peru"},
						  {"touro"},{"tigre"},{"urso"},{"veado"},{"vaca"}};
	for(i=0;i<25;i++){
		for(j=0;j<4;j++){
			A[i][j]=aux;
			aux++;	
		}
	}
	A[24][3]=0;	
	for(i=0;i<25;i++){
		for(j=0;j<4;j++){
			if(A[i][j]==(x%100)){
				grupo=i;
			}	
		}
	}	
	for(i=0;i<25;i++){
		for(j=0;j<4;j++){
			if(A[i][j]==(y%100)){
				grupo2=i;
			}	
		}
	}
	printf("O numero escolhido %d pertence ao grupo %s\n",x,strings[grupo]);
	printf("O numero sorteado %d pertece ao grupo %s\n",y,strings[grupo2]);
	if(grupo==grupo2){
		tot=aposta*18;
	}
	return tot;
	}
	
int main(){
	setlocale(LC_ALL,"Portuguese");
	int qtd,md,op,aux=1,flag=1;
	unsigned long long int num_sort =11111111;
	int A[25][4],i,j;
	char verificador;
	dados players[MAX];
	while(flag=1){
		puts("Bem Vindo ao Ambiente de Apostas Virtual");
		puts("Escolha uma opção");
		puts("[1]-Jogar");
		puts("[2]-Ver Tabela");
		puts("[3]-Sair");
		printf("-> ");
		scanf("%d",&op);
		system("cls");
		if(op==1){
			puts("Digite a quantidade de jogadores (max 5) ");
			scanf("%d",&qtd);
			system("cls");
			for(i=0;i<qtd;i++){
				printf("Jogador %d digite seu nome\n",i+1);
				fflush(stdin);					
				gets(players[i].nome);
				puts("Insira seu saldo inicial ");
				scanf("%f",&players[i].banca);
				system("cls");
			}
			do{ /* while para controlar a repetição do jogo, mantendo os dados iniciais*/
				for(i=0;i<qtd;i++){ /* esse for vai ser executado de acordo com a quantidade de jogadores*/
					puts("Lista de Modalidades");
					puts("[1]-Unidades");
					puts("[2]-Dezenas");
					puts("[3]-Centenas");
					puts("[4]-Milhar");
					puts("[5]-Grupo");
					printf("%s Digite o numero correspondente a modalidade de aposta que deseja\n",players[i].nome);
					printf("-> ");
					scanf("%d",&players[i].md);
					system("cls");
					if(players[i].md<5 && players[i].md !=0){
						printf("%s digite o numero que deseja apostar\n",players[i].nome);
						scanf("%d",&players[i].num_esc);
						do{
							puts("Quanto voce quer apostar ?");
							scanf("%f",&players[i].aposta);
							if(players[i].aposta>players[i].banca){
								puts("Voce nao possui saldo suficiente!");
								puts("Deseja sair ?[S/N]");
								char aux;
								fflush(stdin);
								aux=toupper(getchar());
								system("cls");
								if(aux=='S'){
									return 0;
								}
							}
						}while(players[i].aposta>players[i].banca);
					system("cls");
					players[i].total=game(players[i].md,players[i].num_esc,num_sort,players[i].aposta);
					printf("O número escolhido foi %d\n",players[i].num_esc);
					printf("O número sorteado foi %d\n",num_sort);
					if(players[i].total>0){
						players[i].banca=(players[i].banca-players[i].aposta)+players[i].total;
						printf("Você ganhou %.2f\n",players[i].total);
					}
					else{
						players[i].banca=(players[i].banca-players[i].aposta);
						printf("Você não ganhou nada!\n");
					}
					}else if(players[i].md==5){
						printf("%s digite o numero que deseja apostar\n",players[i].nome);
						scanf("%d",&players[i].num_esc);
						do{
							puts("Quanto voce quer apostar ?");
							scanf("%f",&players[i].aposta);
							if(players[i].aposta>players[i].banca){
								puts("Voce nao possui saldo suficiente!");
								puts("Deseja sair ?[S/N]");
								char aux;
								fflush(stdin);
								aux=toupper(getchar());
								system("cls");
								if(aux=='S'){
									return 0;
								}
							}
						}while(players[i].aposta>players[i].banca);
						system("cls");
						players[i].total=grupo(players[i].num_esc,num_sort,players[i].aposta);
						if(players[i].total>0){
							players[i].banca=(players[i].banca-players[i].aposta)+players[i].total;/*saldo do jogador se ele acertou a aposta*/
							printf("Você ganhou %.2f\n",players[i].total);
						}
						else{
							players[i].banca-=players[i].aposta;
							printf("Você não ganhou nada!\n");
						}
					}
		printf("%s seu saldo é de %.2f\n",players[i].nome,players[i].banca);
		system("pause");
		system("cls");
				}
		fflush(stdin);
		puts("Deseja jogar novamente?");
		verificador=toupper(getchar());
		flag=0;
		system("cls");
			}while(verificador=='S');
		}
		if(op==2){
			tabela();
		}
		if(op==3)
			return 0;
		if(flag==0){
			break;
		}	
	}
return 0;
}
