#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char nome[20];
    float notas[4];
    float media;
}notas;
void media(notas *alunos,int n){
    int i,j;
    float media;
    for(i=0;i<n;i++){
        float soma=0;
        for(j=0;j<4;j++){
            soma+=alunos[i].notas[j];
        }
        alunos[i].media=soma/4;    
    }
    for(i=0;i<n;i++){
        printf("A media de %s foi de %f\n",alunos[i].nome,alunos[i].media);
    }
}
void menornota(notas *alunos,int n){
    int i,j=0,prova;;
    for(i=0;i<n;i++){
        float menor=alunos[i].notas[j];
        prova=i+1;
        for(j=0;j<4;j++){
            if(alunos[i].notas[j]<menor){
                menor=alunos[i].notas[j];
                prova=j+1;
            }
        }
        printf("A menor nota de %s foi %f correspondente a prova %d\n",alunos[i].nome,menor,prova);
    }
}
void aprovados(notas *alunos,int n){
    int i,j;
    float media;
    for(i=0;i<n;i++){
        float soma=0;
        for(j=0;j<4;j++){
            soma+=alunos[i].notas[j];
        }
        alunos[i].media=soma/4;    
    }
    puts("Alunos aprovados por media:");
    for(i=0;i<n;i++){
        if(alunos[i].media>=7){
            printf("%s\n",alunos[i].nome);
        }
    }
}
int main(){
    int i,n,j;
    puts("Quantos alunos da turma?");
    scanf("%d",&n);
    notas alunos[n];
    for(i=0;i<n;i++){
        printf("Digite o nome do aluno %d\n",i+1);
        fflush(stdin);
        gets(alunos[i].nome);
        for(j=0;j<4;j++){
            printf("Digite a nota %d\n",j+1);
            scanf("%f",&alunos[i].notas[j]);
        }
    }
    media(alunos,n);
    menornota(alunos,n);
    aprovados(alunos,n); 
    return 0;
}