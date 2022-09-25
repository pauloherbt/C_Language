/*Trabalho equipe 538560*/

/*Bibliotecas utilizadas*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<time.h>
#define MAX 5 /*limite de players*/
#define MAXINT 1000000000 /*defino o limite maximo do numero escolhido e sorteado*/

/*O numero sorteado e o numero escolhido são os maiores inteiros que conseguimos representar desprezando o sinal, por isso ambos
sao do tipo unsigned long long int*/

typedef struct{ /* estrutura para armazenar os dados de cada jogador*/
		char nome[50]; /* nome do jogador*/
		float banca,aposta; /*saldo inicial e valor da aposta*/
		int md; /*escolha da modalidade*/
		unsigned long long int num_esc; /*numero que o jogador escolhe para apostar*/
		float total; /*valor que o jogador recebeu na aposta, que depois será acrescido ao saldo inicial*/
	}dados;
	
/*FUNÇÕES AUXILIARES*/	
void tabela(void){ /*funcao que cria a tabela com o nome dos bichos e seu respectivo intervalo*/
	
	int i,j,aux=1,A[25][4]; /*matriz com todos os intervalos*/
	char strings[25][15]={{"Avestruz"},{"Águia"},{"Burro"},{"Borboleta"},/*matriz de strings com o nome de todos os animais*/
						  {"Cachorro"},{"Cabra"},{"Carneiro"},{"Camelo"},
						  {"Cobra"},{"Coelho"},{"Cavalo"},{"Elefante"},
						  {"Galo"},{"Gato"},{"Jacaré"},{"Leão"},
						  {"Macaco"},{"Porco"},{"Pavão"},{"Peru"},
						  {"Touro"},{"Tigre"},{"Urso"},{"Veado"},{"Vaca"}};
	for(i=0;i<25;i++){ /*preenche a matriz com numeros de 1 até 100*/
		for(j=0;j<4;j++){
			A[i][j]=aux; /*incrementando a variavel aux de 1 em 1 e atribuindo o valor a posicao correta*/
			aux++;	
		}
	}
	A[24][3]=0;	/*defino a ultima posicao da matriz como 0, pois o 100 atrapalharia os calculos*/
	
	/*Aqui é onde a tabela será exibida na tela*/
	printf("%-10s %s","Animal","Intervalo\n");
	for(i=0;i<25;i++){ /*para cada linha da matriz, corresponde a um animal*/
		printf("%-10s",strings[i]);/*imprime o nome do animal correspondente*/
		for(j=0;j<4;j++){
			printf(" %d ",A[i][j]); /*imprime o intervalo de numeros do animal ex burro: 1 2 3 4*/
		}
		printf("\n");
		}
	system("pause");
	system("cls");
}

float game(int a,unsigned long long int num_esc,unsigned long long int num_sort,float aposta){/*funcao com as modalidades do jogo, com exceçao da modalidade grupo*/
	/*entro com o o inteiro que representa a modalidade escolhida, entro com o numero escolhido, 
	o numero sorteado e o valor da aposta como parâmetros da funcao, que retorna o valor total,
	sendo o valor da aposta x o premio da modalidade*/
	float tot=0;
	switch (a) { /* cada case representa a modalidade*/
		case 1: /*unidades*/
			if((num_esc%10)==(num_sort%10)){ /* ultimo algarismo do numero escolhido for igual ao ultimo algarismo do numero sorteado*/
				tot=aposta*2;
			}
			break;
		case 2: /*dezena*/
			if((num_esc%100)==(num_sort%100)){ /* os dois ultimos algarismos forem iguais ao do numero sorteado*/
				tot=aposta*60;
			}
			break;
		case 3:/*centena*/
			if((num_esc%1000)==(num_sort%1000)){ /*os tres ultimos algarismos forem iguais ao do numero sorteado*/
				tot=aposta*600;
			}
			break;
		case 4:/*milhar*/
			if((num_esc%10000)==(num_sort%10000)){ /*os quatro ultimos algarismos forem iguais ao do numero sorteado*/
				tot=aposta*4000;
			}
			break;
								
	}
	return(tot); /*retorna o quanto o jogador ganhou*/
}

float grupo(unsigned long long int x,unsigned long long int y,float aposta){ /*funcao da modalidade grupo*/
	/* entro com os valores do numero escolhido(x), do numero sorteado(y) e da aposta
	a funcao me retorna o valor total ganho pelo usuario, caso tenha acertado o grupo
	imprime na tela o numero sorteado, o numero escolhido e identifica qual grupo cada
	um deles pertence*/
	
	int A[25][4],i,j,aux=1,grupo,grupo2;
	float tot=0;
	char strings[25][15]={{"Avestruz"},{"Águia"},{"Burro"},{"Borboleta"},
						  {"Cachorro"},{"Cabra"},{"Carneiro"},{"Camelo"},
						  {"Cobra"},{"Coelho"},{"Cavalo"},{"Elefante"},
						  {"Galo"},{"Gato"},{"Jacaré"},{"Leão"},
						  {"Macaco"},{"Porco"},{"Pavão"},{"Peru"},
						  {"Touro"},{"Tigre"},{"Urso"},{"Veado"},{"Vaca"}};
	for(i=0;i<25;i++){ /*preencho a matriz com numeros de 1 a 100 e faco a atribuicao do ultimo numero como 0 para facilitar os calculos*/
		for(j=0;j<4;j++){
			A[i][j]=aux;
			aux++;	
		}
	}
	A[24][3]=0;	
	
	for(i=0;i<25;i++){ /* verifica qual grupo o numero escolhido pertence*/
		for(j=0;j<4;j++){
			if(A[i][j]==(x%100)){ /* %100 pois o grupo é indicado pelos 2 algarismos finais*/
				grupo=i; /* a variavel grupo armazena o valor da linha, que o numero escolhido pertence,onde cada linha corresponde a um grupo*/
			}	
		}
	}	
	for(i=0;i<25;i++){ /* verifica qual grupo o numero sorteado pertence*/
		for(j=0;j<4;j++){
			if(A[i][j]==(y%100)){
				grupo2=i; /*variavel grupo2 armazena o valor da linha, que corresponde ao grupo do numero sorteado*/
			}	
		}
	}
	/* depois de verificar os grupos, imprime na tela cada numero e seu respectivo grupo que pertence*/
	printf("O numero escolhido %d pertence ao grupo %s\n",x,strings[grupo]); 
	printf("O numero sorteado %d pertece ao grupo %s\n",y,strings[grupo2]);
	if(grupo==grupo2){ /*caso ambos pertencam ao mesmo grupo o jogador recebe o premio*/
		tot=aposta*18;
	}
	return tot; /* e a funcao retorna o valor ganho*/
	}

/*PRINCIPAL*/	
int main(){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));/* gera um valor semente para a funcao rand sortear um numero aleatorio a cada inicializacao do programa*/
	int qtd,op,flag=1,i,j; /*qtd de jogadores, opcao do menu, e flag que controla a repeticao do menu inicial*/
	unsigned long long int num_sort =11111111;
	char verificador; /* outra flag*/
	dados players[MAX]; /*vetor da estrutura que vai armazenar os dados de cada player*/
	while(flag=1){ /*while que repete o menu inicial, assim que ele retornar da opcao 2-tabela*/
		puts("Bem Vindo ao Ambiente de Apostas Virtual");
		puts("Escolha uma opção");
		puts("[1]-Jogar");
		puts("[2]-Ver Tabela");
		puts("[3]-Sair");
		printf("-> ");
		do{ /*filtro de opcao valida*/
			scanf("%d",&op);
			if(op>3){
				printf("Insira uma opção válida\n->");
			}
		}while(op>3);
		system("cls");
		if(op==1){ /* esse if contem toda a execucao do jogo*/
			puts("Digite a quantidade de jogadores (max 5) ");
			do{ /* filtro maximo de jogadores*/
				scanf("%d",&qtd);
				if(qtd>5)
					printf("Número muito alto de jogadores!\nDigite novamente\n->");
			}while(qtd>5);
			system("cls");
			for(i=0;i<qtd;i++){ /* esse for coleta os dados iniciais dos jogadores*/
				printf("Jogador %d digite seu nome\n",i+1);
				fflush(stdin);					
				gets(players[i].nome);
				puts("Insira seu saldo inicial ");
				scanf("%f",&players[i].banca);
				system("cls");
			}
			do{ /* while para controlar a repetição do jogo, mantendo os dados iniciais*/
				for(i=0;i<qtd;i++){ /* esse for vai ser executado de acordo com a quantidade de jogadores*/
					num_sort=(rand()%MAXINT); /* numsorteado recebe um valor aleatorio entre 0 e a constante MAXINT, se quiser testar um valor predefinido basta atribui-lo no lugar da funcao rand*/
					puts("Lista de Modalidades");
					puts("[1]-Unidades");
					puts("[2]-Dezenas");
					puts("[3]-Centenas");
					puts("[4]-Milhar");
					puts("[5]-Grupo");
					printf("%s Digite o numero correspondente a modalidade de aposta que deseja\n",players[i].nome);
					printf("-> ");
					do{ /* filtro de opcao invalida*/
						scanf("%d",&players[i].md);
						if(players[i].md>5||players[i].md==0)
							printf("Opção inválida!\nDigite novamente\n->");
					}while(players[i].md>5 || players[i].md==0);
					system("cls");
					if(players[i].md<5 && players[i].md !=0){ /* caso tenha escolhido uma modalidade que nao seja a 5*/
						printf("%s digite o numero que deseja apostar\n",players[i].nome);
						do{ /* filtra o tamanho maximo do numero escolhido*/
							players[i].num_esc=0;
							scanf("%d",&players[i].num_esc);
							if(players[i].num_esc>MAXINT)
								printf("Número grande demais!\nInsira outro número\n");
						}while(players[i].num_esc>MAXINT);	
						do{ /*verifica se o jogador esta apostando um valor dentro do limite do saldo inicial*/
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
						/*chamo a funcao game que funciona pra todas as modalidades, exceto a 5
						o campo da struct recebe a funcao que retorna o valor total que o jogador ganhou com a aposta
						e passo os dados do jogador correspondente como parametro*/ 
						players[i].total=game(players[i].md,players[i].num_esc,num_sort,players[i].aposta);
					
						printf("O número escolhido foi %d\n",players[i].num_esc);
						printf("O número sorteado foi %d\n",num_sort);
						/* verifica se o jogador vai receber um saldo positivo*/
						if(players[i].total>0){
							players[i].banca=(players[i].banca-players[i].aposta)+players[i].total; /* saldo do jogador acrescido do lucro da aposta*/
							printf("Você ganhou %.2f\n",players[i].total);
						}
						else{ /* caso nao tenha ganhado nada o seu saldo e descontado o valor da aposta*/
							players[i].banca=(players[i].banca-players[i].aposta);
							printf("Você não ganhou nada!\n");
						}
					/* caso a modalidade escolhida tenha sido a 5-grupo*/	
					}else if(players[i].md==5){
						printf("%s digite o numero que deseja apostar\n",players[i].nome);
						do{/*filtro limite pro numero escolhido*/
							scanf("%d",&players[i].num_esc);
							if(players[i].num_esc>MAXINT)
								printf("Número longo demais\nDigite novamente\n");
						}while(players[i].num_esc>MAXINT);
						do{ /*verifica se possui saldo para realizar a aposta*/
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
						}while(players[i].aposta>players[i].banca); /*loop enquanto o player nao tiver saldo suficiente*/
						system("cls");
						/*chamada da funcao grupo que identifica o grupo dos numeros sorteado e escolhido
						e retorna o valor ganho pelo jogador caso tenha acertado os grupos
						para o campo .total da struct*/
						
						players[i].total=grupo(players[i].num_esc,num_sort,players[i].aposta);
						/* verifica se o jogador ganhou algo ou seja maior que 0*/
						if(players[i].total>0){
							players[i].banca=(players[i].banca-players[i].aposta)+players[i].total;/*saldo do jogador se ele acertou a aposta*/
							printf("Você ganhou %.2f\n",players[i].total);
						}
						else{ /* caso nao tenha ganhado nada é descontado o valor da aposta do saldo restante do jogador correspondente*/
							players[i].banca-=players[i].aposta;
							printf("Você não ganhou nada!\n");
						}
					}
		/* apos a execuçao da rodada o programa imprime o saldo do jogador*/			
		printf("%s seu saldo é de %.2f\n",players[i].nome,players[i].banca);
		system("pause");
		system("cls");
				}			
		fflush(stdin);	/* apos os jogadores jogarem, a maquina pergunta se deseja jogar novamente
						nesse caso, mantendo os nomes e o saldo que restou a cada rodada*/
		puts("Deseja jogar novamente?[S/N]");
		verificador=toupper(getchar());
		flag=0;/* flag recebe 0 para evitar que o primeiro while execute e volte pro menu inicial*/
		system("cls");
			}while(verificador=='S'); /* do while para executar a partir dos dados iniciais ja inseridos*/
		}
		if(op==2){ /* caso o jogador escolha ver a tabela, executa a chamada da funcao*/
			tabela();
		}
		if(op==3) /*opcao de sair*/
			return 0;
		if(flag==0){ /* verifica o valor da flag e executa o break para sair do while que volta ao menu inicial*/
			break;
		}	
	}
return 0;
}
