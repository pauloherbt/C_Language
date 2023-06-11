#include<stdio.h>
#include<stdlib.h>
#include"algoritmos.h"

void bubblesort(int n, int *v){
    int i,j, temp;
    for(i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            if(v[j]>v[j+1]){
                temp = v[j];
                v[j]= v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

void quicksort(int n, int *v){
    if(n<=1){
        return;
    }
    int pivo=v[0],a=1,b=n-1;
    do{
        while(a<n&&v[a]<=pivo)
            a++;
        while (v[b]>pivo)
            b--;
        if(a<b){ //swap
            int temp=v[a];
            v[a]=v[b];
            v[b]=temp;
            a++;b--;
        }
    }while(a<=b);
    //swap pivo
    v[0]=v[b];
    v[b]=pivo;

    quicksort(b,v);
    quicksort(n-a,&v[a]); //sacada genial o subvetor dir e dado pelo endereco do 1 elemento maior q o pivo :O
}