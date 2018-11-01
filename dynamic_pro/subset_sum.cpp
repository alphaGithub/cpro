
#include<iostream>
using namespace std;
#define size 4
int subset_sum(int *set,int sum){
    int matrix[size+1][sum+1];
    for(int i=0;i<size+1;i++)
        for(int j=0;j<sum;j++)
            matrix[i][j]=0;
    
    for(int i=0;i<size+1;i++)
        matrix[i][0]=0;
    for(int j=0;j<sum+1;j++)
        matrix[0][j]=0;

    for(int i=1;i<size+1;i++){
        for(int j=1;j<sum+1;j++){
            if(j>=set[i-1]){
                if(i==3 && j== 3){
                    cout <<matrix[i-1][j-set[i-1]];
                    cout <<matrix[i-1][j];
                }
                matrix[i][j]=matrix[i-1][j-set[i-1]] | matrix[i-1][j];
            }
            else{
                matrix[i][j]=matrix[i-1][j];
            }
        }
    }
    cout <<endl;
    for(int i=0;i<size+1;i++){
        for(int j=0;j<sum+1;j++){
            cout << matrix[i][j]<<"  ";
        }
        cout <<endl;
    }
    return matrix[size][sum];
}
int main(){
    int set[]={6,3,2,1};
    if(subset_sum(set,9)){
        cout<<"\nYes sum is possible"<<endl;
    }
    return 0;
}