#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct student
{
    int Roll_no;
    char name[20];
    char panel;
    float FDS;
    float MMC;
    float DBMS;
};
struct class 
{
    int num;
    struct student * s;
};

void pline(int x){
    for(int i = 1; i <= x; i++){
        printf("-");
    }
    printf("\n");
}
void swap(struct class * c,int i,int j){
    struct student temp;
    // temp=(struct student*)malloc(sizeof(struct student));
    temp.Roll_no = c->s[i].Roll_no;
    strcpy(temp.name,c->s[i].name);
    temp.panel = c->s[i].panel;
    temp.FDS = c->s[i].FDS;
    temp.MMC = c->s[i].MMC;
    temp.DBMS = c->s[i].DBMS;

    c->s[i].Roll_no =  c->s[j].Roll_no;
    strcpy(c->s[i].name,c->s[j].name);
    c->s[i].panel = c->s[j].panel;
    c->s[i].FDS = c->s[j].FDS;
    c->s[i].MMC = c->s[j].MMC;
    c->s[i].DBMS = c->s[j].DBMS;

    c->s[j].Roll_no = temp.Roll_no;
    strcpy(c->s[j].name,temp.name);
    c->s[j].panel = temp.panel;
    c->s[j].FDS = temp.FDS;
    c->s[j].MMC = temp.MMC;
    c->s[j].DBMS = temp.DBMS;

}
void create(struct class *c){
    printf("Enter the number of students in the class : ");
    scanf("%d",&c->num);
    c->s = (struct student *)calloc(c->num,sizeof(struct student));
    printf("\n");
    pline(50);
    printf("Enter the information of students !\n(press esc to exit)\n");
    pline(20);
    for(int i = 0 ; i < c->num; i++){
       printf("Roll No : ");
       scanf("%d",&c->s[i].Roll_no);
       printf("Name : ");
       scanf("%s",&c->s[i].name);
       printf("Panel : ");
       scanf("%s",&c->s[i].panel);
       printf("FDS : ");
       scanf("%f",&c->s[i].FDS);
       printf("MMC : ");
       scanf("%f",&c->s[i].MMC);
       printf("DBMS : ");
       scanf("%f",&c->s[i].DBMS);
       pline(20);
    }
}
void display(struct class *c){
    printf("\n");
    pline(53);
    printf("Roll\tName\t\tPanel\tFDS\tMMC\tDBMS\n");
    pline(53);
    for(int i = 0; i < c->num; i++){
       printf("%d\t",c->s[i].Roll_no);
       printf("%s\t\t",c->s[i].name);
       printf("%c\t",c->s[i].panel);
       printf("%0.2f\t",c->s[i].FDS);
       printf("%0.2f\t",c->s[i].MMC);
       printf("%0.2f\n",c->s[i].DBMS);
    }
    pline(53);
}
void linearSearch(struct class *c,int key){
    bool flag = false;    
    int j;
    for(int i = 0; i < c->num; i++){
        if(c->s[i].Roll_no == key){
            j = i;
            flag = true;
        }        
    }
    if(flag == true)
        printf("student is present !");
    else 
        printf("student is Absent !");
}
// binary search 
int BinarySearch(struct class *c , int key){
    int start = 0;
    int end = c->num - 1;
    int mid = (start+end)/2;
    while (start<=end)
    {
        if(c->s[mid].Roll_no == key)
            return 1;
        if(key > c->s[mid].Roll_no)
            start = mid + 1;
        
        else if(key < c->s[mid].Roll_no)
            end = mid - 1;
        
        mid = (start+end)/2;
    }
    return -1;
    
}
void bubleSort(struct class *c){
    for(int i = 0; i < (c->num - 1); i++){
        for(int j = 0; j < (c->num - 1); j++){
            if(c->s[j].Roll_no > c->s[j+1].Roll_no){
                swap(c,j,j+1);
            }
        }
    }
}
int main(){
    system("clear");
    struct class E;
    create(&E);
    display(&E);
    int key;
    printf("Enter the Roll no of student : ");
    scanf("%d",&key);
    linearSearch(&E,key);
    printf("\n");
    printf("%d",BinarySearch(&E,key));
    printf("\n");
    bubleSort(&E);
    display(&E);

}
