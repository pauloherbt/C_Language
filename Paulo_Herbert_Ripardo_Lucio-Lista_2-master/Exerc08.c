#include<stdio.h>
#include<stdlib.h>
void fibonnaci(int n){
    int x=1,y=1,i,c;
    printf("%d %d",x,y);
    for(i=2;i<n;i++){
        c=x+y;
        printf(" %d",c);
        x=y;
        y=c;
    }
}
int main(){
    int i,n;
    puts("Quantos termos da sequencia vc quer exibir?");
    scanf("%d",&n);
    fibonnaci(n);
    return 0;
}
