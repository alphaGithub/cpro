//longest common subsequence
#include<stdio.h>
#include<string.h>
int max(int a,int b){
    return (a>=b)?a:b;
}
int lcs(char *a,char *b){
    int l1=strlen(a);
    int l2=strlen(b);
    int arr[l1+1][l2+1];
    int i,j;
    for(i=0;i<=l1;i++){
        arr[i][0]=0;
    }
    for(i=0;i<=l2;i++){
        arr[0][i]=0;
    }
for(i=1;i<=l1;i++){
    for(j=1;j<=l2;j++){
        arr[i][j]=0;
            if(a[i]==b[j]){
                
                arr[i][j]= (1+max(arr[i-1][j-1],arr[i-1][j]));
            }
            else{
                arr[i][j]=arr[i-1][j-1];
            }
        }
    }
    printf("Table :\n");
    for(i=0;i<=l1;i++){
        for(j=0;j<=l2;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return arr[l1][l2];
}
int main(){
    char a[100],b[100];
    printf("Enter two sequence of string :\n");
    scanf("%s%s",a,b);
    printf("\nLCS :%d",lcs(a,b));
    return 0;
}