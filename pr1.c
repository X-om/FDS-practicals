#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void initialize(int arr[5][5],int row , int col)
{
    for(int i = 0; i<row; i++)
    {
        printf("Enter the values for row %d : ",i+1);
        for(int j = 0; j<col; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
void display(int arr[5][5],int row, int col)
{
    for(int i = 0; i<row; i++)
    {
        printf("[ ");
        for(int j = 0; j<col; j++)
        {
            printf("%d",arr[i][j]);
            printf(" ");
        }
        printf("]\n");
    }

}
void add(int arr1[5][5],int arr2[5][5], int result[5][5],int row1,int col1,int row2,int col2)
{
    if(row1 == row2 && col1 == col2)
    {  
        for(int i = 0; i<row1; i++)
        {
            for(int j = 0; j<col1; j++)
            {
                result[i][j] = arr1[i][j] + arr2[i][j];
            }
        }

    }
    else
        printf("ERROR ! , To Add Matrix The dimension of both matrix must be same !\n");

}
void substract(int arr1[5][5],int arr2[5][5], int result[5][5],int row1,int col1,int row2,int col2)
{
    if(row1 == row2 && col1 == col2)
    {  
        for(int i = 0; i<row1; i++)
        {
            for(int j = 0; j<col1; j++)
            {
                result[i][j] = arr1[i][j] - arr2[i][j];
            }
        }

    }
    else
        printf("ERROR ! , To substract Matrix The dimension of both matrix must be same !\n");
}
void multiplication(int arr1[5][5], int arr2[5][5],int result[5][5],int row1,int col1, int row2 , int col2)
{
    if(row1 == col2)
    {
        int temp;

           for(int i = 0; i<row1; i++)
           {
                
                for(int j = 0; j<col2; j++)
                {
                    temp = 0;
                    for(int k = 0; k < col1 ; k++)
                    {
                        temp+=arr1[i][k]*arr2[k][j];
                    }
                    result[i][j]=temp;
                }
           }


          
}
    else
    {
        printf("**************************************************************************************\n");
        printf("ERROR ! \nTo multiply METRIX the COLUMN of METRIX 1 must be equal to ROWS of METRIX 2\n");
        printf("***************************************************************************************\n");
    }
        
}
void Transpose(int arr[5][5],int result[5][5],int row,int col)
{
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            result[i][j] = arr[j][i];
        }
    }
}
int main(){
    system("clear");
    int r1,c1,r2,c2;
    int arr1[5][5],arr2[5][5],result[5][5];
    
    bool flag = true;
    while (flag)
    {
        printf("Enter the dimensions of MATRIX 1 : ");
        scanf("%d%d",&r1,&c1);
        if(r1 < 5 && c1 <5)
        {
            initialize(arr1,r1,c1);
            printf("\nMatrix 1 : \n");
            display(arr1,r1,c1);
            printf("\n");
        }
        else
        {
            printf("The rows and cols of MATRIX must be less that 5 !\n\n");
            break;
        }

        printf("Enter the dimensions of MATRIX 2 : ");
        scanf("%d%d",&r2,&c2);
        if(r1 < 5 && c1 <5)
        {
            initialize(arr2,r2,c2);
            printf("\nMatrix 2 : \n");
            display(arr2,r2,c2);
            printf("\n");
        }
        else
        {
            printf("The rows and cols of MATRIX must be less that 5 !\n\n");
            break;
        }
    
    bool flag2 = true;
    while(flag2)
    {
        printf("\t\t\tSelect the choice !\n");
        printf("1.Addition\n2.Substraction\n3.Multiplication\n4.Transpose\n5.Exit\n");

        int choice = 0;
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            
            add(arr1,arr2,result,r1,c1,r2,c2);
            printf("\n\n");
            if(r1==r2 && c1 == c2)
                display(result,r1,c1);
            break;
        case 2:
            substract(arr1,arr2,result,r1,c1,r2,c2);
            printf("\n\n");
            if(r1==r2 && c1 == c2)
                display(result,r2,c2);
            break;
        case 3:
            multiplication(arr1,arr2,result,r1,c1,r2,c2);
            if(c1 == r2){
                printf("\n\n");
                display(result,r1,c2);
            }
            break;
        case 4:
        {
            int choice2 = 0;
            printf("\n");
            printf("\t\tSELECT MATRIX\n");
            printf("1).Matrix 1\n2).Matrix 2\n\n");
            printf("Enter your choice : ");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                    Transpose(arr1,result,r1,c1);
                    display(result,r1,c1);
                    break;
                case 2:
                    Transpose(arr2,result,r2,c2);
                    display(result,r2,c2);
                    break;
            }

            break;
        }
        case 5:
            printf("\n\n\t\tPROGRAM TERMINATED SUCCESSFULLY !\n");
            flag2 = false;
            break;
        }
    }
    flag = false;
    }
}

