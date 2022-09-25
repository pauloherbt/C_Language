#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int dia,mes,ano,diastotal,dif;
}data;
//funcao pra converter a data em dias
int todias(data *data,int i){
    int dias=0;
    return dias=data[i].dia+(data[i].mes*30)+(data[i].ano*365);
}
int main(){
    data referencia;
    int diasref,n,i;
    puts("Insira uma data de referencia no formato(dd/mm/aaaa) separe por /");
    scanf("%d/%d/%d",&referencia.dia,&referencia.mes,&referencia.ano);
    diasref=referencia.dia+(referencia.mes*30)+(referencia.ano*365);
    puts("Quantas datas?");
    scanf("%d",&n);
    data datas[n];
    for(i=0;i<n;i++){
        puts("Digite uma data no formato[dd/mm/aaaa] separe por /");
        scanf("%d/%d/%d",&datas[i].dia,&datas[i].mes,&datas[i].ano);
        datas[i].diastotal=todias(datas,i); //armazena os dias totais de cada data
        if(diasref>datas[i].diastotal){ // calculo a diferenca de dias entre as datas
            datas[i].dif=diasref-datas[i].diastotal;
        }
        else
            datas[i].dif=datas[i].diastotal-diasref;
    }
    int menor=datas[0].dif,indice=0;
    for(i=0;i<n;i++){ //comparo qual a data mais proxima da data de ref, com base na diferenca de dias
        if(datas[i].dif<menor){
            menor=datas[i].dif;
            indice=i;
       }
    }
    printf("A data mais proxima de %d/%d/%d\n",referencia.dia,referencia.mes,referencia.ano);
    printf("Eh %d/%d/%d",datas[indice].dia,datas[indice].mes,datas[indice].ano);
    return 0;
}