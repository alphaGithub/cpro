#include<stdio.h>
#include<stdlib.h>
struct account{
    int acc_no;
    char acc_name[100];
    float acc_balance;
};
void display_account(struct account * acc){
    printf("%-10d%-20s%10.3f\n",acc->acc_no,acc->acc_name,acc->acc_balance);
}
void input_data(struct account *acc){
    printf("\nEnter Account Number,Account name,Account balance\n");
    scanf("%d%s%f",&acc->acc_no,acc->acc_name,&acc->acc_balance);
}
void add_data_file(char *fname){
    FILE *fp;
    struct account new_data;
    input_data(&new_data);
    fp=fopen(fname,"ab");
    if(fp==NULL){
        printf("Error in opening file\n");
        return;
    }
    fwrite(&new_data,sizeof(struct account),1,fp);
    printf("Data added to file\n");
    fclose(fp);
}
void read_file(char *fname){
    FILE *fp;
    struct account new_data;
    fp=fopen(fname,"rb");
    if(fp==NULL){
        printf("Error in opening file\n");
        return;
    }
    int c=0;
    while(fread(&new_data,sizeof(struct account),1,fp)==1){
        display_account(&new_data);
        c++;
    }
    if(c==0){
        printf("No data to read\n");
    }
    else{
        printf("Read %d data\n",c);
    }
    fclose(fp);
}
void update_data(char *fname,int n){
    FILE *fp;
    struct account udata;
    fp=fopen(fname,"rb+");
    if(fp==NULL){
        printf("Error in opening file\n");
        return;
    }
    printf("Enter new Data:");
    input_data(&udata);
    fseek(fp,(n-1)*sizeof(udata),0);
    fwrite(&udata,sizeof(struct account),1,fp);
    fclose(fp);
}
void delete_data(char *fname,int n){
    FILE *fp,*tmp;
    int c=0;
    struct account udata;
    fp=fopen(fname,"rb");
    tmp=fopen("tmpfile","wb");
    if(fp==NULL){
        printf("Error in opening file\n");
        return;
    }
    while(fread(&udata,sizeof(struct account),1,fp)==1){
        c++;
        if(c!=n){
            fwrite(&udata,sizeof(struct account),1,tmp);
        }
    }
    fclose(fp);
    fclose(tmp);
    remove(fname);
    rename("tmpfile",fname);
}   

int main(int argc, char const *argv[])
{
    char *fname="input";
    int choice=0;
    int pos;
    while(1){
    printf("Enter choice :\n1.Add data\n2.Read file\n3.Update file\n4.Delete data\n5.EXIT\n:");
    scanf("%d",&choice);
        switch(choice){
            case 1:
                add_data_file(fname);
                break;
            case 2:
                read_file(fname);
                break;
            case 3:
                printf("Enter Position to be modified :");
                scanf("%d",&pos);
                update_data(fname,pos);
                break;
            case 4:
                printf("Enter Position to be deleted :\n");
                scanf("%d",&pos);
                delete_data(fname,pos);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Wrong Entry");
        }
    }
    return 0;
}
