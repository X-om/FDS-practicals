#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define size 10

int queue[size];
int front = -1;
int rear = -1;

int enqueue(int value){
    if((rear == size - 1 && front == 0) || (rear == (front - 1)%(size - 1) )){
        return false;
    }
    if(front == -1){
        front = rear = 0;
    }
    else if (rear == size - 1 && front != 0){
        rear = 0;
    }
    else{
        rear++;
    }
    queue[rear] = value;
    return true;
}

int dequeue(){
    if(front == -1){
        return -1;
    }

    int ans = queue[front];
    queue[front] = 0;

    if(front == rear){
        front = rear = -1;
    }   
    else if(front == size - 1){
        front = 0;
    }
    else{ 
        front++;
    }
    return ans;  
}

void display(){
    printf("[ ");
    for (int i = 0; i < size; i++){
        printf("%d ",queue[i]);
    }
    printf("]\n\n");
    
}

int main(){
    system("clear");
    int ch;
    bool flag = true;
    while (flag){
        printf("1.push\n2.pop\n3.display\n4.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        printf("\n");
        switch (ch)
        {
        case 1:{
            int elm;
            printf("Enter the element : ");
            scanf("%d",&elm);
            if(enqueue(elm) == true)
                printf("Inserted successfully ! \n\n");
            else
                printf("queue is full ! \n\n");
            break;
        }
        case 2:{
            int check = dequeue();
            if(check == -1)
                printf("Queue is empty !\n\n");
            else
                printf("%d\n\n",check);
            break;
        }
            

        case 3:
            display();
            break;
        case 4:
            flag = false;
            printf("Terminated successfully !");
            break;
        default:
            printf("Invalid Input Try Again !");
            break;
        }
        
    }
    

}