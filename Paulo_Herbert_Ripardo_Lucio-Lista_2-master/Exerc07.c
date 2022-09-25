#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double fatorial(int x){
    int i;
    double fatorial=1;
    for(i=1;i<=x;i++){
        fatorial=fatorial*i;
    }
    return fatorial;
}
double senx(double x){
    int i=0,n=1;
    double seno=0,termo=pow(x,n)/fatorial(n);
    while(termo>pow(10,-12)){
        seno=seno+pow(-1,i)*termo;
        i++;
        n+=2;
        termo=pow(x,n)/fatorial(n);
    }
    return seno;
}
int main(){
    double x;
    puts("Digite um valor para x");
    scanf("%lf",&x);
    printf("Seno da funcao: %f\n",senx(x));
    printf("Seno  do math.h = %f",sin(x));
    return 0;
}