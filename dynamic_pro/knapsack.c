#include<stdio.h>
#define MAX 5
int max(int a,int b){
    return a>b?a:b;
}
int knapsack(int n,int *weight,int *profit,int capacity){
    int matrix[n+1][capacity+1];
    int i,j;
    for(i=0;i<n+1;i++)
        for(j=0;j<capacity+1;j++)
            matrix[i][j]=0;
    
    for(i=1;i<n+1;i++){
        for(j=1;j<capacity+1;j++){
            if(weight[i-1]<=j){
                matrix[i][j]=max(profit[i-1]+matrix[i-1][j-weight[i-1]],matrix[i-1][j]);
            }
            else{
                matrix[i][j]=matrix[i-1][j];
            }
        
            
        }
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<capacity+1;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    return matrix[n][capacity];
}
int main(){
    int weight[MAX]={1,2,4,2,3};
    int profit[MAX]={10,12,28,20,18};
    printf("maximum profit :%d\n",knapsack(5,weight,profit,7));
    return 0;
}