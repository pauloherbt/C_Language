#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char item[10];
    int ponto;
}gabarito;
int main(){
    gabarito resp;
    int i,n,k;
    puts("Gabarito");
    for(i=0;i<10;i++){
        printf("Digite a resposta da %d questao: ",i+1);
        do{
            fflush(stdin);
            resp.item[i]=getchar();
            if(resp.item[i]!='a'&&resp.item[i]!= 'b'&&resp.item[i]!='c'&&resp.item[i]!='d'){
                puts("opcao invalida digite novamente");
            }
        }while(resp.item[i]!='a'&&resp.item[i]!= 'b'&&resp.item[i]!='c'&&resp.item[i]!='d');
    }
    puts("Digite quantos alunos cadastrar");
    scanf("%d",&n);
    gabarito alunos[n];
    for(i=0;i<n;i++){ //fluxo de alunos
        alunos[i].ponto=0;
        for(k=0;k<10;k++){ //fluxo de cada questao
            printf("Aluno %d Digite a resposta da %d questao: ",i+1,k+1);
            do{
                fflush(stdin);
                alunos[i].item[k]=getchar();
                if(alunos[i].item[k]!='a'&&alunos[i].item[k]!= 'b'&&alunos[i].item[k]!='c'&&alunos[i].item[k]!='d'){
                    puts("opcao invalida digite novamente");
                }
            }while(alunos[i].item[k]!='a'&&alunos[i].item[k]!= 'b'&&alunos[i].item[k]!='c'&&alunos[i].item[k]!='d');
            if(alunos[i].item[k]==resp.item[k]){ //verifica a resposta correta e incrementa a pontuacao
            alunos[i].ponto++;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("Aluno %d teve a nota :%d \n",i+1,alunos[i].ponto);
    }
    
    return 0;
}