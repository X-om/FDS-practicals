#include<stdio.h>
#include<stdlib.h>
struct Element{
    int row;
    int col;
    int val;
};
struct sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};
void create(struct sparse *s){
    printf("Enter the Dimenssions of MATRIX : ");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter the total number of NON-ZERO elements : ");
    scanf("%d",&s->num);
    s->e = (struct Element*)malloc((s->num+1)*sizeof(struct Element));
    printf("Enter the total number of rows : ");
    scanf("%d",&s->e[0].row);
    printf("Enter the total number of cols : ");
    scanf("%d",&s->e[0].col);
    s->e[0].val = s->num;
    for(int i = 1;i < s->num+1;i++)
    {
            printf("Enter Row Value %d : ",i);
            scanf("%d",&s->e[i].row);
            printf("Enter Col Value %d : ",i);
            scanf("%d",&s->e[i].col);
            printf("Enter the Value : ");
            scanf("%d",&s->e[i].val);
            printf("\n");
    }
}
void displaySparse(struct sparse *s){
    printf("\nSPARSE REPRESENTATION : \n\n");
    printf("ROW COL VAL\n");
    printf("-------------\n");
    printf("%d    %d    %d\n",s->e[0].row,s->e[0].col,s->e[0].val);
    printf("-------------\n");
    for(int i = 1; i<s->num+1; i++)
    {
        printf("%d    %d    %d\n",s->e[i].row,s->e[i].col,s->e[i].val);
    }
}
void displayMatrix(struct sparse *s){
    printf("\nMATRIX REPRESENTATION : \n\n");
    int k = 1;
    for(int i = 0; i<s->m; i++)
    {
        for(int j = 0; j<s->n; j++)
        {
            if(i == s->e[k].row && j == s->e[k].col)
                printf("%d ",s->e[k++].val);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
struct sparse *add(struct sparse *s1,struct sparse *s2)
{
    struct sparse *sum;
    sum=(struct sparse*)malloc(sizeof(struct sparse));
    sum->e= (struct Element*)malloc(((s1->num+s2->num)+1)*sizeof(struct Element));
    sum->e[0].row = s1->e[0].row;
    sum->e[0].col = s2->e[0].col;
    int i,j,k;
    i=j=k=1;
    while(i < s1->num+1 && j < s2->num+1)
    {
        if(s1->e[i].row < s2->e[j].row)
            sum->e[k++] = s1->e[i++];
        else if(s1->e[i].row > s2->e[j].row)
            sum->e[k++] = s2->e[j++];
        else
        {
            if(s1->e[i].col < s2->e[j].col)
                sum->e[k++] = s1->e[i++];
            else if(s1->e[i].col > s2->e[j].col)
                sum->e[k++] = s2->e[j++];
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].val = s1->e[i++].val + s2->e[j++].val;
            }
        }
    }
    for(;i<s1->num+1;i++)
        sum->e[k++] = s1->e[i];
    for(;j<s2->num+1;j++)
        sum->e[k++] = s2->e[j];
    sum->e[0].val = k;
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
   
}
struct sparse *substract(struct sparse *s1,struct sparse *s2)
{
    struct sparse *sub;
    sub=(struct sparse*)malloc(sizeof(struct sparse));
    sub->e= (struct Element*)malloc(((s1->num+s2->num)+1)*sizeof(struct Element));
    sub->e[0].row = s1->e[0].row;
    sub->e[0].col = s2->e[0].col;
    int i,j,k;
    i=j=k=1;
    while(i < s1->num+1 && j < s2->num+1)
    {
        if(s1->e[i].row < s2->e[j].row)
            sub->e[k++] = s1->e[i++];
        else if(s1->e[i].row > s2->e[j].row)
            sub->e[k++] = s2->e[j++];
        else
        {
            if(s1->e[i].col < s2->e[j].col)
                sub->e[k++] = s1->e[i++];
            else if(s1->e[i].col > s2->e[j].col)
                sub->e[k++] = s2->e[j++];
            else
            {
                sub->e[k] = s1->e[i];
                sub->e[k++].val = s1->e[i++].val - s2->e[j++].val;
            }
        }
    }
    for(;i<s1->num+1;i++)
        sub->e[k++] = s1->e[i];
    for(;j<s2->num+1;j++)
        sub->e[k++] = s2->e[j];
    sub->e[0].val = k;
    sub->m = s1->m;
    sub->n = s1->n;
    sub->num = k;

    return sub;
};
struct sparse *Transpose(struct sparse *s){
    struct sparse *Trans;
    Trans = (struct sparse *)malloc(sizeof(struct sparse));
    Trans->e = (struct Element *)malloc((s->num+1)*sizeof(struct Element));
    Trans->e[0].row = s->e[0].col;
    Trans->e[0].col = s->e[0].row;
    Trans->e[0].val = s->e[0].val;
    for(int i = 1; i<=s->num; i++)
    {   
        Trans->e[i].row = s->e[i].col;
        Trans->e[i].col = s->e[i].row;
        Trans->e[i].val = s->e[i].val;
    } 
    Trans->m = s->m;
    Trans->n = s->n;
    Trans->num = s->num;
    return Trans;
}
struct sparse *fastTranspose(struct sparse *s){
    struct sparse *Ftrans;
    Ftrans = (struct sparse *)malloc(sizeof(struct sparse));
    Ftrans->e = (struct Element *)malloc((s->num)*sizeof(struct Element));
    Ftrans->e[0].row = s->e[0].col;
    Ftrans->e[0].col = s->e[0].row;
    Ftrans->e[0].val = s->e[0].val;
    int size = s->e[0].col;
    int total[size];

    for(int i = 0; i<size; i++)
        total[i] = 0;
    for(int i = 1; i<=s->num;i++)
    {
        int p = s->e[i].col;
        total[p]++;    
    }
    int index[size+1];
    index[0] = 1;
    for(int i = 1; i<=size+1; i++)
        index[i] = index[i-1] + total[i-1];
        
    int location;
    for(int i = 1; i<=s->num; i++)
    {

        location = index[s->e[i].col];
        Ftrans->e[location].row = s->e[i].col;
        Ftrans->e[location].col = s->e[i].row;
        Ftrans->e[location].val = s->e[i].val;
        index[s->e[i].col]++;
    }
    Ftrans->m = s->m;
    Ftrans->n = s->n;
    Ftrans->num = s->num;

    return Ftrans;    
}
int main(){
    struct sparse s,*s1;
    create(&s);
    displaySparse(&s);
    printf("\n");
    s1 = fastTranspose(&s);
    printf("\n");
    displaySparse(s1);

}