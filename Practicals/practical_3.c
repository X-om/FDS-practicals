#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define max 50
struct class
{
    int Roll_no;
    char name[30];
    float FDS;
    float OS;
    float MMC;
};
void pline(int x){
    for(int i = 0; i < x; i++){
        printf("-");
    }
    printf("\n");
}
void swap(struct class c[],int i , int j){
    struct class temp; 

    temp.Roll_no = c[i].Roll_no;
    strcpy(temp.name,c[i].name);
    temp.FDS = c[i].FDS;
    temp.OS = c[i].OS;
    temp.MMC = c[i].MMC;

    c[i].Roll_no = c[j].Roll_no;
    strcpy(c[i].name,c[j].name);
    c[i].FDS = c[j].FDS;
    c[i].OS = c[j].OS;
    c[i].MMC = c[j].MMC;

    c[j].Roll_no = temp.Roll_no;
    strcpy(c[j].name,temp.name);
    c[j].FDS = temp.FDS;
    c[j].OS = temp.OS;
    c[j].MMC = temp.MMC;
}
void create(struct class c[],int size){
    printf("Enter the Information About student\n\n");
    for(int i = 0; i < size; i++){
        printf("Roll No : ");
        scanf("%d",&c[i].Roll_no);
        printf("Name : ");
        scanf("%s",c[i].name);
        printf("FDS : ");
        scanf("%f",&c[i].FDS);
        printf("OS : ");
        scanf("%f",&c[i].OS);
        printf("MMS : ");
        scanf("%f",&c[i].MMC);
        printf("\n\n");
    }
}
int linearSearch(struct class c[],int size,int key){
    for(int i = 0; i < size; i++){
        if(c[i].Roll_no == key)
            return i;
    }
    return -1;
}
int binarySearch(struct class c[],int size,int key){
    int start = 0;
    int end = size - 1;
    int mid = (end+start)/2;

    while(start<=end){
        if(c[mid].Roll_no == key)
            return mid;
        else if(key > c[mid].Roll_no)
            start = mid + 1;
        else 
            end = mid - 1;
        
        mid = (end+start)/2;
    }
    return -1;
}
void selectionSort(struct class c[] , int size){
    
    for(int i = 0; i < size - 1; i++){
        int  min = i;
        for(int j = i+1; j < size; j++){

            if(c[j].Roll_no < c[min].Roll_no)
                min = j;
        }
        if(min != i)
            swap(c,i,min);
    }
}
void insertionSort(struct class c[], int size){
    for(int i = 1; i < size; i++){
        struct class temp;
        temp.Roll_no = c[i].Roll_no; 
        strcpy(temp.name,c[i].name);
        temp.FDS = c[i].FDS;
        temp.OS = c[i].OS;
        temp.MMC = c[i].MMC;

        int j = i - 1;
        while (j>=0)
        {
            if(c[j].Roll_no > temp.Roll_no){
                c[j+1].Roll_no = c[j].Roll_no;
                strcpy(c[j+1].name,c[j].name);
                c[j+1].FDS = c[j].FDS;
                c[j+1].OS = c[j].OS;
                c[j+1].MMC = c[j].MMC;
            }
            else
                break;

            j--;
        }
        c[j+1].Roll_no = temp.Roll_no;
        strcpy(c[j+1].name,temp.name);
        c[j+1].FDS = temp.FDS;
        c[j+1].OS = temp.OS;
        c[j+1].MMC = temp.MMC;
    }
}
void shellSort(struct class c[],int size){
    int gap;
    for(gap = size/2 ; gap>=1; gap = gap/2){
        for(int j = gap; j < size; j++){
            for(int i = j - gap; i >=0; i = i-gap){
                if(c[i+gap].Roll_no > c[i].Roll_no)
                    break;
                else
                    swap(c,i,(i+gap));
            }
        }
    }
}
void display(struct class c[], int size){
    pline(70);
    printf("Roll\tName\tFDS\tOS\tMMC\n");
    pline(70);
    for(int i = 0; i < size; i++){
        printf("%d\t%s\t%0.2f\t%0.2f\t%0.2f\n",c[i].Roll_no,c[i].name,c[i].FDS,c[i].OS,c[i].MMC);

    }
    pline(70);
}
int main(){
    struct class c[max];
    bool flag = true;
    int size;
    do
    {
        int choice;
        printf("\n1.create\n2.LinearSearch\n3.BinarySearch\n4.Selection sort\n5.Insertion sort\n6.Shell sort\n7.Display\n8.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:{
                printf("Enter the number of student you have : ");
                scanf("%d",&size);        
                create(c,size);
                break;
            }
            case 2:{
                int key;
                int result;
                printf("Enter the Roll no of the student You want to search : ");
                scanf("%d",&key);
                result = linearSearch(c,size,key);
                if(result == -1)
                    printf("Student not Present\n\n");
                else
                    printf("student is present at position %d\n\n",result);
                break;
            }
            case 3:{
                int key;
                int result;
                printf("Enter the Roll no of the student You want to search : ");
                scanf("%d",&key);
                result = binarySearch(c,size,key);
                if(result == -1)
                    printf("Student not Present\n\n");
                else
                    printf("student is present at position %d\n\n",result);
                break;
            }
            case 4:{
                selectionSort(c,size);
                break;
            }
            case 5:{
                insertionSort(c,size);
                break;
            }
            case 6:{
                shellSort(c,size);
                break;
            }
            case 7:{
                display(c,size);
                break;
            }
            case 8:{
                flag = false;
                break;
            }
            default:
                printf("Invalid Choice\n\n");
                break;
        }

    } while (flag);
       
       
}