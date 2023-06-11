#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"algoritmos.h"
#define SIZE 1000000

int* gerarVetor(){
    srand(100);
    static int array[SIZE]; 
    for (int i = 0; i < SIZE; i++){
        array[i]=rand()%100000;
    }
    return array;
    
}
void imprimirarray(int n, int* v){
    for (int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    
}
int main(int argc, char const *argv[]){
    int* bubble=gerarVetor();
    clock_t start=clock();
    bubblesort(SIZE,bubble);
    clock_t end = clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time in seconds %f", time);
    /*int* quick=gerarVetor();
    quicksort(SIZE,quick);*/

    
    return 0;
}
