#include<stdio.h>

void acceptMatrix(int mat[20][20],int r,int c){
    int i,j;
    printf("Enter the elements row wise:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void displayMatrix(int mat[20][20],int r,int c){
    int i,j;
    printf("Matrix\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int Mat1[20][20],int Mat2[20][20],int R1,int R2,int C1,int C2){
    int s[20][20];
    int i,j;
    if ((R1==R2)&&(C1==C2)){
        printf("Addition:\n");
        for(i=0;i<R1;i++){
            for(j=0;j<C1;j++){
                s[i][j]=Mat1[i][j]+Mat2[i][j];
            }
        }
        displayMatrix(s,R1,C1);
    }
    else{
        printf("Matrices cannot be added\n");
    }

}

void subMatrix(int Mat1[20][20],int Mat2[20][20],int R1,int R2,int C1,int C2){
    int m[20][20];
    int i,j;
    if ((R1==R2)&&(C1==C2)){
        printf("Subtraction:\n");
        for(i=0;i<R1;i++){
            for(j=0;j<C1;j++){
                m[i][j]=Mat1[i][j]-Mat2[i][j];
            }
        }
        displayMatrix(m,R1,C1);
    }
    else{
        printf("Matrices cannot be subtracted\n");
    }

}

void transpose(int mat[20][20],int r,int c){
    int i,j;
    printf("Transpose:\n");
    int t[20][20];
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            t[i][j]=mat[j][i];
        }
    }
    displayMatrix(t,c,r);
}

void multiMatrix(int Mat1[20][20],int Mat2[20][20],int R1,int R2,int C1,int C2){
    if (C1==R2){
        int sum;
        int mul[20][20];
        printf("Multiplication:\n");
        int i,j,k;
        for(i=0;i<R1;i++){
            for(j=0;j<C2;j++){
                sum=0;
                for(k=0;k<R2;k++){
                    sum=sum+Mat1[i][k]*Mat2[k][j];
                }
                mul[i][j]=sum;
            }
        }
        displayMatrix(mul,R1,C2);
    }
    else{
        printf("Matrices cannot be multiplied\n");
    }
}

int main(){
    int mat1[20][20],mat2[20][20],r1,c1,r2,c2,ch;
    printf("Enter the number of rows in first matrix:\n");
    scanf("%d",&r1);
    printf("Enter the number of columns in first matrix:\n");
    scanf("%d",&c1);
    acceptMatrix(mat1,r1,c1);
    displayMatrix(mat1,r1,c1);
    printf("Enter the number of rows in second matrix:\n");
    scanf("%d",&r2);
    printf("Enter the number of columns in second matrix:\n");
    scanf("%d",&c2);
    acceptMatrix(mat2,r2,c2);
    displayMatrix(mat2,r2,c2);
    while(1){
        printf("1.Addition\n 2.Subtraction\n 3.Transpose\n 4.Multiplication\n 5.Exit\n Enter your choice:\n");
        scanf("%d",&ch);
        if (ch==1){
            addMatrix(mat1,mat2,r1,r2,c1,c2);
            
        }
        else if (ch==2){
            subMatrix(mat1,mat2,r1,r2,c1,c2);
        }
        else if (ch==3){
            transpose(mat1,r1,c1);
            transpose(mat2,r2,c2);
        }
        else if (ch==4){
            multiMatrix(mat1,mat2,r1,r2,c1,c2);
        }
        else if (ch==5){
            break;
        }
        else{
            printf("Invalid input!!");
        }
    }
    return 0;
}