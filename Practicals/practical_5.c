#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct student{
    int Roll_No;
    char name[20];
    struct student * next;
};
struct student * Addmember(struct student * head,int Roll,char NAME[]){
    struct student * newMember = (struct student *)malloc(sizeof(struct student));
    newMember->Roll_No = Roll;
    strcpy(newMember->name,NAME);
    newMember->next = head;
    return newMember;
}
struct  student* deleteMember(struct student * head,int Roll){
    struct student * current = head;
    struct student * prev = NULL;
    while(current != NULL && Roll != current->Roll_No){
        prev = current;
        current = current->next;
    }
    if(current != NULL){
        if(prev == NULL)
            head = current->next;
        else
            prev->next = current->next;

        free(current);
    }
    
    return head;
}
int countMember(struct student * head){
    int count = 0;
    struct student * current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;
}
struct student* sort(struct student * head){
    struct student * current;
    struct student * nextNode;
    int current_Roll;
    int next_Roll;
    char TempName[20];
    for(current = head; current!=NULL; current = current->next){
        for(nextNode = current->next; nextNode!=NULL; nextNode = nextNode->next){
            current_Roll = current->Roll_No;
            next_Roll = nextNode->Roll_No;
            
            if(current_Roll > next_Roll){
                current->Roll_No = next_Roll;
                nextNode->Roll_No = current_Roll;

                strcpy(TempName,current->name);
                strcpy(current->name,nextNode->name);
                strcpy(nextNode->name,TempName);
            }
        }
    }
    return head;
}
struct student* Reverse(struct student * head){
    struct student * current = head;
    struct student * nextnode;
    struct student * prev = NULL;
    while (current!=NULL){
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    return prev;
}
struct student* MergeList(struct student * head,struct student * new){
    struct student * current = head;
    struct student * current2 = new;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = current2;

    return head;
}
void display(struct student * head){
    struct student * current = head;
    while(current != NULL){
        printf("Roll No : %d\n",current->Roll_No);
        printf("Name : %s\n",current->name);
        current = current->next;
        printf("\n");
    }
}
int main(){
    system("clear");
    struct student * head = NULL;
    int Roll;
    char NAME[20];
    int choice;
    bool flag = true;
    while(flag){
        printf("1.Add Member\n2.Display\n3.Delete\n4.Count Member\n5.sort\n6.Reverse\n7.Merge Another List\n8.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\n\n");
            printf("Roll No : ");
            scanf("%d",&Roll);
            printf("Name : ");
            scanf("%s",NAME);
            head = Addmember(head,Roll,NAME);
            printf("\n");
            break;
        case 2:
            printf("\n\n");
            display(head);
            printf("\n");
            break;
        case 3:
            printf("Enter the roll No You Want To delete : ");
            scanf("%d",&Roll);
            head = deleteMember(head,Roll);
            printf("\n\n");
            break;
        case 4:{
            int count;
            count =  countMember(head);
            printf("The current count of list is : %d\n\n",count);
            break;
        }
        case 5:
            head = sort(head);
            printf("\n");
            break;
        case 6:
            head = Reverse(head);
            printf("\n");
            break;
        case 7:{
            struct student * new = NULL;
            new = Addmember(new,5,"Shital");
            new = Addmember(new,6,"vikas");
            
            head = MergeList(head,new);
            printf("\n\n");
            break;
        }
        case 8:
            flag = false;
            break;
        default:
            break;
        }
    }
}