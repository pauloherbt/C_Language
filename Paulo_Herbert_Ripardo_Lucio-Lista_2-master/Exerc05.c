#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char nome[20];
    unsigned long long int telefone;
    int aniversario;
}dados;
int main(){
    int i,n;
    int ref;
    puts("Quantas pessoas?");
    scanf("%d",&n);
    dados pessoas[n];
    for(i=0;i<n;i++){
        puts("digite o nome");
        fflush(stdin);
        gets(pessoas[i].nome);
        puts("digite o telefone");
        scanf("%d",&pessoas[i].telefone);
        puts("Digite a data de aniversario [dd/mm]");
        scanf("%d",&pessoas[i].aniversario);
    }
    puts("Qual a data de referencia?[dd/mm]");
    scanf("%d",&ref);//data para pesquisa
    puts("Pessoas que fazem aniversario nessa data:");
    printf("Nome\tTelefone\n");
    for(i=0;i<n;i++){
        if(pessoas[i].aniversario==ref){
            printf("%s\t%d\n",pessoas[i].nome,pessoas[i].telefone);
        }
    }
    return 0;
}