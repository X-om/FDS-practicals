#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Element{
    int row;
    int col;
    int val;
};
struct sparse{
    int m;
    int n;
    int size;
    struct Element * e;
};
void create(struct sparse * s){
    printf("Enter the dimension of the Matrix : ");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter the total non-zero Elements in Sparse Matrix : ");
    scanf("%d",&s->size);
    s->e = (struct Element *)malloc((s->size+1)*sizeof(struct Element));
    printf("Enter the Values of Sparse Matrix As Follow : \n\n");  
    printf("R C V\n");
    printf("| | |\n");
    printf("v v v\n");
    for(int i = 1; i < s->size+1; i++){
        scanf("%d%d%d",&s->e[i].row,&s->e[i].col,&s->e[i].val);
    }
    int R[s->size];
    int C[s->size];
    for(int i = 1; i < s->size+1; i++)
        R[s->e[i].row]++;
    for(int j = 1; j < s->size+1; j++)
        C[s->e[j].col]++;

    int total_Row,total_Col;
    total_Row = total_Col = 0;

    for(int i = 0; i < s->size; i++){
        if(R[i] > 0)
            total_Row++;
        if(C[i] > 0)
            total_Col++;
    }

    s->e[0].row = total_Row;
    s->e[0].col = total_Col;
    s->e[0].val = s->size;

}
void display(struct sparse * s){
    int k = 1;
    for(size_t i = 0; i < s->m; i++){
        
        printf("[ ");
        
        for(size_t j = 0; j < s->n; j++){

            if(i == s->e[k].row && j == s->e[k].col)
                printf("%d ",s->e[k++].val);
        
            else
                printf("0 ");
        
        }
        
        printf("]\n");
    }
}
struct sparse * Add(struct sparse * s1,struct sparse * s2){
    struct sparse * sum;
    sum = (struct sparse *)malloc(sizeof(struct sparse));
    sum->e = (struct Element *)malloc(((s1->size+s2->size)+1)*sizeof(struct Element));
    sum->e[0].row = s1->e[0].row;
    sum->e[0].col = s1->e[0].col;
    int i,j,k;
    i=j=k=1;
    while (i < s1->size+1 && j < s2->size+1)
    {
        if(s1->e[i].row < s2->e[j].row)
            sum->e[k++] = s1->e[i++];
        else if(s1->e[i].row > s2->e[j].row)
            sum->e[k++] = s2->e[j++];
        else{
            if(s1->e[i].col < s2->e[j].col)
                sum->e[k++] = s1->e[i++];
            else if(s1->e[i].col > s2->e[j].col)
                sum->e[k++] = s2->e[j++];
            else{
                sum->e[k] = s1->e[i];
                sum->e[k++].val = s1->e[i++].val + s2->e[j++].val; 
            }
        }
    }
    for(;i<s1->size+1;i++)
        sum->e[k++] = s1->e[i];
    for(;j<s2->size+1;j++)
        sum->e[k++] = s2->e[j];
    
    sum->m = s1->m;
    sum->n = s1->n;
    sum->size = k;

    return sum;
} 
struct sparse * Sub(struct sparse * s1,struct sparse * s2){
    struct sparse * min;
    min = (struct sparse *)malloc(1*sizeof(struct sparse));
    min->e = (struct Element *)malloc(((s1->size+s2->size)+1)*sizeof(struct Element));
    min->e[0].row = s1->e[0].row;
    min->e[0].col = s1->e[0].col;
    int i,j,k;
    i=j=k=1;
    while (i < s1->size+1 && j < s2->size+1)
    {
        if(s1->e[i].row < s2->e[j].row)
            min->e[k++] = s1->e[i++];
        else if(s1->e[i].row > s2->e[j].row)
            min->e[k++] = s2->e[j++];
        else{
            if(s1->e[i].col < s2->e[j].col)
                min->e[k++] = s1->e[i++];
            else if(s1->e[i].col > s2->e[j].col)
                min->e[k++] = s2->e[j++];
            else{
                min->e[k] = s1->e[i];
                min->e[k++].val = s1->e[i++].val - s2->e[j++].val; 
            }
        }
    }
    for(;i<s1->size+1;i++)
        min->e[k++] = s1->e[i];
    for(;j<s2->size+1;j++)
        min->e[k++] = s2->e[j];
    
    min->m = s1->m;
    min->n = s1->n;
    min->size = k;

    return min;
} 
struct sparse * SimpleTransose(struct sparse * s){
    struct sparse * Trans;
    Trans = (struct sparse *)malloc(sizeof(struct sparse));
    Trans->e = (struct Element *)malloc(s->size+1*sizeof(struct Element));
    int k = 1;
    for(int i = 0; i < s->e[0].col; i++){
        for(int j = 1; j <= s->e[0].val; j++){
            if(s->e[j].col == i){
                Trans->e[k].row = s->e[j].col;
                Trans->e[k].col = s->e[j].row;
                Trans->e[k].val = s->e[j].val;
                k++;
            }
        }
    }
    Trans->e[0].row = s->e[0].col;
    Trans->e[0].col = s->e[0].row;
    Trans->e[0].val = s->e[0].val;

    Trans->m = s->n;
    Trans->n = s->m;
    Trans->size = s->size+1;

    return Trans;

}
struct sparse * FastTranspose(struct sparse * s){
    struct sparse * Fast;
    Fast = (struct sparse *)malloc(sizeof(struct sparse));
    Fast->e = (struct Element *)malloc((s->size+1)*sizeof(struct Element));
    int size = s->e[0].col;
    int total[size];
    for(int i = 0; i < size; i++)
        total[i] = 0;
    for(int i = 1; i < s->size; i++){
        int p = s->e[i].col;
        total[p]++;
    }
    int index[size+1];
    index[0] = 1;
    
    for(int i = 1; i <= size + 1; i++){
        index[i] = index[i-1] + total[i-1];
    }
    int location;
    
    for(int i = 1; i <= s->size; i++){
        location = index[s->e[i].col];
        Fast->e[location].row = s->e[i].col;
        Fast->e[location].col = s->e[i].row;
        Fast->e[location].val = s->e[i].val;
        index[s->e[i].col]++;
    }

    Fast->e[0].col = s->e[0].row;
    Fast->e[0].row = s->e[0].col;
    Fast->e[0].val = s->e[0].val;

    Fast->m = s->n;
    Fast->n = s->m;
    Fast->size = s->size;

    return Fast;
}
int main(){
    system("clear");
    struct sparse s1,s2,*s3,*s4,*s5,*s6;
    bool flag = true;
    do
    {
        int choice;
        printf("1.Create\n2.Display\n3.Addition\n4.Substraction\n5.Transpose\n6.Fast Transpose\n7.Exit\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
            int ch;
            do
            {
                printf("\n\n1.Matrix A\n2.Matrix B\n3.Exit\n\nEnter your choice : ");
                scanf("%d",&ch);
                switch (ch)
                {
                    case 1:
                        create(&s1);
                        printf("\n");
                        break;
                    case 2:
                        create(&s2);
                        printf("\n");
                        break;
                    case 3:
                        printf("Terminated successfully\n\n");
                        break;
                        
                    default:
                        printf("Invalid Inout\n\n");
                        break;
                    }
            } while (ch!=3);

            break;    
        }
        case 2:{
            int ch;
            do
            {
                printf("\n\n1.Matrix A\n2.Matrix B\n3.Exit\n\nEnter your choice : ");
                scanf("%d",&ch);
                switch (ch)
                {
                    case 1:
                        display(&s1);
                        break;
                    case 2:
                        display(&s2);
                        break;
                    case 3:
                        printf("Terminated successfully\n\n");
                        break;
                        
                    default:
                        printf("Invalid Inout\n\n");
                        break;
                    }
            } while (ch!=3);

            break;    
        }
        case 3:{
            s3 = Add(&s1,&s2);
            printf("\n\n");
            display(s3);
            break;
        }
        case 4:{
            s4 = Sub(&s1,&s2);
            printf("\n\n");
            display(s4);
            break;
        }
        case 5:{
            int ch;
            do
            {
                printf("\n\n1.Matrix A\n2.Matrix 2\n3.Exit\n\nEnter your choice : ");
                scanf("%d",&ch);
                switch (ch)
                {
                    case 1:
                        s5 = SimpleTransose(&s1);
                        display(s5);
                        printf("\n");
                        break;
                    case 2:
                        s5 = SimpleTransose(&s2);
                        display(s5);
                        printf("\n");
                        break;
                    case 3:
                        printf("Terminated Successfully !\n\n");
                        break;
                    default:
                        printf("Invalid Input !\n\n");
                        break;
                    }
            } while (ch!=3);
            
            break;
        }
        case 6:{
            int ch;
            do
            {
                printf("1.Matrix A\n2.Matrix B\n3.Exit\n\nEnter your choice : ");
                scanf("%d",&ch);
                switch (ch)
                {
                case 1:
                    s6 = FastTranspose(&s1);
                    printf("\n");
                    display(s6);
                    break;
                case 2:
                    s6 = FastTranspose(&s2);
                    printf("\n");
                    display(s6);
                    break;
                case 3:
                    printf("Terminated successfully\n\n");
                    break;
                default:
                    printf("Invalid Input\n\n");
                    break;
                }
            } while (ch!=3);
            
            break;
        }
        case 7:{
            flag = false;
            break;
        }
        default:
            printf("Invalid Inputn\n");
            break;
        }

    } while (flag);
    

}