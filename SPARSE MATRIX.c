#include <stdio.h>

void acceptMat(int mat[20][20],int r,int c){
    int i,j;
    printf("Enter the matrix row wise");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void displayMat(int mat[20][20],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}

void compactMat(int mat1[20][20],int comp[20][20],int r1,int c1){
    int i,j,k=1;
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            if (mat1[i][j]!=0){
                comp[k][0]=i;
                comp[k][1]=j;
                comp[k][2]=mat1[i][j];
                k++;
            }
        }
    }
    comp[0][0]=r1;
    comp[0][1]=c1;
    comp[0][2]=k-1;
    printf("COMPACT MATRIX: \n");
    displayMat(comp,k,3);

}

void simpleTranspose(int com[20][20],int trans[20][20]){
    int k=1,i,j;
    for(i=0;i<4;i++){
        for(j=1;j<=com[0][2];j++){
            if (com[j][1]==i){
                trans[k][0]=com[j][1];
                trans[k][1]=com[j][0];
                trans[k][2]=com[j][2];
                
                k++;
            }
        }
        
    }
    trans[0][0]=com[0][1];
    trans[0][1]=com[0][0];
    trans[0][2]=com[0][2];
    printf("SIMPLE TRANSPOSE\n");
    displayMat(trans,k,3);
}

void fastTranspose(int com[20][20],int trans[20][20]){
    int i,j,total[20]={0},index[20],z,k,m;
    for(i=0;i<com[0][1];i++){
        for(j=1;j<=com[0][2];j++){
            if (com[j][1]==i){
                total[i]=total[i]+1;
            }
        }
    }
    index[0]=1;
    for(k=1;k<=com[0][1]+1;k++){
        index[k]=index[k-1]+total[k-1];
    }
    for(m=1;m<=com[0][2];m++){
        z=index[com[m][1]];
        trans[z][0]=com[m][1];
        trans[z][1]=com[m][0];
        trans[z][2]=com[m][2];
        index[com[m][1]]++;
    }
    trans[0][0]=com[0][1];
    trans[0][1]=com[0][0];
    trans[0][2]=com[0][2];
    printf("FAST TRANSPOSE:\n");
    displayMat(trans,m,3);

}

int main(){
    int r,c;
    int mat[20][20],compact[20][20],transpose1[20][20],transpose2[20][20];
    printf("Enter number of rows in sparse matrix");
    scanf("%d",&r);
    printf("Enter number of columns in sparse matrix");
    scanf("%d",&c);
    acceptMat(mat,r,c);
    printf("SPARSE MATRIX: \n");
    displayMat(mat,r,c);
    compactMat(mat,compact,r,c);
    simpleTranspose(compact,transpose1);
    fastTranspose(compact,transpose2);
    return 0;
}
