#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10
void initialize(int Matrix[max][max], int row, int col)
{
    printf("Enter the values of Matrix !\n\n");
    for (int i = 0; i < row; i++)
    {
        printf("Row %d : ", i + 1);
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &Matrix[i][j]);
        }
    }
}
void display(int Matrix[max][max], int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        printf("[ ");
        for (size_t j = 0; j < col; j++)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("]\n");
    }
}
void Add(int Matrix_A[max][max],int r1,int c1,int Matrix_B[max][max],int r2,int c2,int Result[max][max]){
    if(r1 == r2 && c1 == c2){
        for(size_t i = 0; i < r1; i++){
            for(size_t j = 0; j < c1; j++){
                Result[i][j] = Matrix_A[i][j] + Matrix_B[i][j];
            }
        }
        // display

        for(size_t i = 0; i < r1; i++){
            printf("[ ");
            for(size_t j = 0; j < c1; j++){
                printf("%d ",Result[i][j]);
            }
            printf("]\n");
        }
        printf("\n\n");
    }
    else{
        printf("To Add to Matrices Dimension Must be Same \n\n");
    }
}
void Sub(int Matrix_A[max][max],int r1,int c1,int Matrix_B[max][max],int r2,int c2,int Result[max][max]){
    if(r1 == r2 && c1 == c2){
        for(size_t i = 0; i < r1; i++){
            for(size_t j = 0; j < c1; j++){
                Result[i][j] = Matrix_A[i][j] - Matrix_B[i][j];
            }
        }
        // display

        for(size_t i = 0; i < r1; i++){
            printf("[ ");
            for(size_t j = 0; j < c1; j++){
                printf("%d ",Result[i][j]);
            }
            printf("]\n");
        }
        printf("\n\n");
    }
    else{
        printf("To Substrct to Matrices Dimension Must be Same \n\n");
    }
}
void Multiply(int Matrix_A[max][max],int r1,int c1,int Matrix_B[max][max],int r2, int c2,int result[max][max]){
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            result[i][j] = 0;
        }
    }
    
    if(c1 == r2){
        for(size_t i = 0; i < r1; i++){
            for(size_t j = 0; j < c2; j++){
                for(size_t k = 0; k < r2; k++){
                    result[i][j] += Matrix_A[i][k] * Matrix_B[k][j];
                }
            }
        }
        for(size_t i = 0; i < r1; i++){
            printf("[ ");
            for(size_t j = 0; j < c2; j++){
                printf("%d ",result[i][j]);
            }
            printf("]\n");
        }
    }
    else{
        printf("To Multiply Matrices Columns of M1 must be Equal to Rows of M2\n\n");
    }
}
void Transpose(int Matrix[max][max],int row,int col,int Result[max][max]){
    
    for(size_t i = 0; i < row; i++){
        for(size_t j = 0; j < col; j++){
            Result[j][i] = Matrix[i][j];
        }
    }

    display(Result,col,row);
}
int main()
{
    system("clear");
 
    int r1, r2, c1, c2;
    int Matrix_A[max][max];
    int Matrix_B[max][max];
    int Result[max][max];
    bool flag = true;
    do
    {
        int choice;
        printf("\n\n");
        printf("1.Initialize\n2.Display\n3.Addition\n4.Substact\n5.Multiply\n6.Transpose\n7.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("Enter the dimension of M 1 : ");
                scanf("%d%d", &r1, &c1);

                if (r1 > max && c1 > max)
                {
                    printf("The dimension of Matrix can not be greater than %d\n\n", max);
                }
                else
                {
                    initialize(Matrix_A, r1, c1);
                }

                printf("\n\n");

                printf("Enter the dimension of M 2 : ");
                scanf("%d%d", &r2, &c2);
                if (r2 > max && c2 > max)
                {
                    printf("The dimension of Matrix can not be greater than %d\n\n", max);
                }
                else
                {
                    initialize(Matrix_B, r2, c2);
                }
                break;
            }

            case 2:{
                int ch;
                do
                {                    
                    printf("1.Matrix_A\n2.Matrix_B\n3.Exit\n\n");
                    printf("Enter your choice : ");
                    scanf("%d",&ch);
                    switch (ch)
                    {
                        case 1:
                            display(Matrix_A,r1,c1);
                            printf("\n\n");
                            break;
                        
                        case 2:
                            display(Matrix_B,r2,c2);
                            printf("\n\n");
                            break;

                        case 3:
                            printf("Exit From Display !\n\n");
                            break;
                        default:
                            printf("Invalid Choice !\n\n");
                            break;
                        }
                    } while (ch!=3);
            }
            case 3:{
                Add(Matrix_A,r1,c1,Matrix_B,r2,c2,Result);
                break;
            }
            case 4:{
                Sub(Matrix_A,r1,c1,Matrix_B,r2,c2,Result);
                break;
            }
            case 5:{
                Multiply(Matrix_A,r1,c1,Matrix_B,r2,c2,Result);
                break;
            }
            case 6:{
                int ch;
                do
                {
                    printf("1.Matrix_A\n2.Matrix_B\n3.Exit\n\nEnter your choice : ");
                    scanf("%d",&ch);
                    switch (ch)
                    {
                        case 1:
                            Transpose(Matrix_A,r1,c1,Result);
                            break;
                        case 2:
                            Transpose(Matrix_B,r2,c2,Result);
                            break;
                        case 3:
                            printf("Exit Transpose\n\n");
                            break;
                        default:
                            printf("Invalid Choice ! \n");
                            break;
                        }
                } while (ch!=3);
                
                break;
            }
                
            case 7:
                printf("Terminated Successfully !\n\n");
                flag = false;
                break;
        
            default:
                printf("Invalid Choice\n\n");
                break;
            }

    } while (flag);

    return 0;
}