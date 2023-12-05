#include<stdio.h>
#include<stdbool.h>
#define size 3
int arr[size];
int qfront = 0;
int rear = 0;

int push(int data){
    if(rear == size)
        return -1;
    else{
        arr[rear] = data;
        rear++;
        return 1;
    }
}       

int pop(){
    if(qfront == rear)
        return -1;
    else{
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;   
        }
        return ans;
    }
        
}
bool isEmpty(){
    if(qfront == rear)
        return true;
    else
        return false;
}
bool isFull(){
    if (rear == size)
        return true;
    else
        return false;
}
int front(){
    if(qfront == rear)
        return -1;
    else
        return arr[qfront];
}

int main(){
   if(push(10) == -1)
        printf("Queue is full\n\n");
    else
        printf("inserted !\n\n");

    if(push(11) == -1)
        printf("Queue is full\n\n");
    else
        printf("inserted !\n\n");

    if(push(12) == -1)
        printf("Queue is full\n\n");
    else
        printf("inserted !\n\n");

    if(push(13) == -1)
        printf("Queue is full\n\n");
    else
        printf("inserted !\n\n");
    


    
    printf("%d\n\n",pop());
    printf("%d\n\n",pop());
    printf("%d\n\n",pop());

        

}