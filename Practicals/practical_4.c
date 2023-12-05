#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
void bucketSort(int arr[],int size){
    int bucket[MAX];
    for(int i = 0; i < MAX; i++)
        bucket[i] = 0;
    for(int j = 0; j < size; j++){
        ++bucket[arr[j]];
    }
    for(int i = 0,j =0; i < MAX; i++){
        for(;bucket[i] > 0; --bucket[i]){
            arr[j] = i;
            j++;
        }
    }
}
int getMax(int arr[],int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}
void radixSort(int arr[],int size){
    int max = getMax(arr,size);
    for(int pos = 1; (max/pos) > 0; pos *= 10){
        const int BASE = 10;
        int * output = (int *)calloc(size,sizeof(int));
        int * count = (int *)calloc(BASE,sizeof(int));

    for(int i = 0; i < size; i++){
        count[arr[i]/pos % BASE]++;
    }
    for(int i = 1; i < BASE; i++){
        count[i] += count[i-1];
    }
    for(int i = size-1; i >= 0; i--){
        output[--count[arr[i]/pos % BASE]] = arr[i];    
    }
    free(count);
    for(int i = 0; i < size; i++){
        arr[i] = output[i];
    }
    free(output);
    }
}

void display(int arr[],int size){   
    printf("[ ");
    for(int i = 0; i < size; i++)
        printf("%d ",arr[i]);
    printf("]\n");
}
int main(){

    int arr[10] = {3,1,4,1,5,9,2,6,5,4};
    int size = 10;
    // bucketSort(arr,size);
    radixSort(arr,size);
    display(arr,size);
}