#include <stdio.h>
#include <stdlib.h>	
/*funcoes auxiliares*/
void mostrarelemento(int m,int n, int **p){
	int i,j;
	printf("A matriz eh\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
}
void somaelementos(int m,int n,int **p){
	int i,j,soma=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			soma+=p[i][j];
		}
	}
	printf("A soma dos elementos da matriz eh de %d\n",soma);
}
void maiorelemento(int m,int n,int **p){
	int i,j,maior=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(p[i][j]>maior){
				maior=p[i][j];
			}
		}
	}
	printf("O maior elemento da matriz eh %d\n",maior);
}
void menorelemento(int m,int n,int **p){
	int i=0,j=0,menor=p[i][j];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(p[i][j]<menor){
				menor=p[i][j];
			}
		}
	}
	printf("O menor elemento da matriz eh %d\n",menor);	
}
void maiormenorelemento(int m,int n,int **p){
	int i=0,j=0,maior=0,menor=p[i][j];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(p[i][j]>maior){
				maior=p[i][j];
			}
			if(p[i][j]<menor){
				menor=p[i][j];
			}
		}
	}
	printf("O menor elemento da matriz eh %d e o maior elemento eh %d\n",menor,maior);
}
void maiorque50(int m,int n,int **p){
	int i,j;
	printf("Elementos maiores que 50: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(p[i][j]>50){
				printf("%d\t",p[i][j]);
			}
		}
	}
	puts("");
}
void elementospares(int m,int n,int **p){
	int i,j;
	printf("Elementos pares: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(p[i][j]%2==0){
				printf("%d\t",p[i][j]);
			}
		}
	}
	puts("");
}
void qtdpares(int m,int n,int **p){
	int i,j,qtd=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(p[i][j]%2==0){
				qtd+=1;
			}
		}
	}
	printf("Quantidade de elementos pares %d\n",qtd);
}	

int main(){
	int **p,m,n,i,j;/*matriz p*/
	puts("Quantas linhas ?");
	scanf("%d",&m);
	p=(int**)calloc(m,sizeof(int));
	puts("quantas colunas?");
	scanf("%d",&n);
	for(i=0;i<m;i++){
		p[i]=calloc(n,sizeof(int));
	}
	puts("digite os elementos");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&p[i][j]);
		}
	}
	/*chamada das funcoes*/		
	mostrarelemento(m,n,p);/*mostrar elementos*/
	somaelementos(m,n,p);/*soma dos elementos*/
	maiorelemento(m,n,p);/*maior elemento*/
	menorelemento(m,n,p);/*menor elemento*/
	maiormenorelemento(m,n,p);/*maior e menor elemento*/
	maiorque50(m,n,p);/*maiores que 50*/
	elementospares(m,n,p);/*exibir elementos pares*/
	qtdpares(m,n,p);/*quantidade de pares*/
	/*desaloca o espaço da matriz*/
	for(i=0;i<m;i++){
		free(p[i]);
	}
	free(p);
	return 0;
}

