#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int raizes(float A, float B, float C, float *X1, float *X2){
    float delta;
    delta=(pow(B,2))-(4*A*C);
    if(delta>0){
        *X1=(-B+sqrt(delta))/2*A;
        *X2=(-B-sqrt(delta))/2*A;
        return 2;
    }
    if(delta==0){
        *X1=(-B+sqrt(delta))/2*A;
        *X2=(-B-sqrt(delta))/2*A;
        return 1;
    }
    else
    return 0;
}
int main(){
    float a,b,c,x,y;
    int qtd;
    printf("Insira o valor de a\n");
    scanf("%f",&a);
    printf("O valor de b\n");
    scanf("%f",&b);
    printf("e o valor de c\n");
    scanf("%f",&c);
    //chamada da funcao direto no printf
    printf("A quantidade de raizes reais eh %d\n",raizes(a,b,c,&x,&y));
    printf("Raiz 1: %.2f\nRaiz 2: %.2f",x,y);
    return 0;
}
