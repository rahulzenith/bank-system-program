#include <stdio.h>
#include <string.h>
// structure declaration
struct customer{
      int account_no;
      char name[80];
      float balance;

};
 int c;  // global integer declaration
 //functions declaration
 void display(struct customer[]);
 int  search(struct customer[],int);
 int  deposit(struct customer[],int);
 int  withdaw(struct customer[],int);


int main(){
      int i=0,index,choice,account_no,money;
      printf("enter the number of customers whom data you want to enter\n");
      scanf("%d",&c);
      struct customer data[c];
      // entering data of customers
      for(i=0;i<c;i++){
      printf("enter the data of customer %d\n",i+1);
      printf("enter account no.\n");
      fflush(stdin);
      scanf("%d",&data[i].account_no);
      printf("enter name\n");
      scanf("%s",data[i].name);
      data[i].balance=0;
      }

      do{
        // Menu
        printf("press 1 to display all data\n");
        printf("press 2 to search a record\n");
        printf("press 3 to deposit money\n");
        printf("press 4 to withdraw money\n");
        printf("press 0 to exit\n\n");
        printf("make your choice from(0-4)\n");
        scanf("%d",&choice);

        switch (choice){

        case 1:
               display(data);
               break;
        case 2:
               printf("enter the account number:\n");
               scanf("%d",&account_no);
               index=search(data,account_no);
               if(index==-1){
                   printf("no account exist\n");
               }
               else{
                   printf("account no is = %d\n",data[index].account_no);
                   printf("name of customer is =%s\n",data[index].name);
                   printf("balance is = %f\n",data[index].balance);
               }
               break;
        case 3:
               printf("enter the account number\n");
               scanf("%d",&account_no);
               index=deposit(data,account_no);
               printf("enter the money you want to deposit:\n");
               scanf("%d",&money);
               data[index].balance += money;
               break;

        case 4:
               printf("enter the account number\n");
               scanf("%d",&account_no);
               index=withdraw(data,account_no);
               printf("enter the money you want to withdraw\n");
               scanf("%d",&money);
               if(data[index].balance>=money){
                    data[index].balance -= money;
               }
               else{
                    printf("sorry no sufficient balance\n");
               }
        }
      }while(choice!=0);
      return 0;
}
     void display(struct customer list[c]){       // function for displaying all accounts
     int i=0;
     for(i=0;i<c;i++){
        printf("data of customer %d\n",i+1);
        printf("Account no. is = %d\n",list[i].account_no);
        printf("name of customer is = %s\n",list[i].name);
        printf("account balance is = %f\n",list[i].balance);
     }
     }

     int search(struct customer list[c],int ACN){  // function for searching  a account
         int i=0;
         for(i=0;i<c;i++){
            if(ACN==list[i].account_no){
                return i;
            }
         }
         return -1;
     }
     int deposit(struct customer list[c],int ACN){ // function for depositing money
         int i=0,index;
         index=search(list,ACN);
         if(index==-1){
            printf("no such account exist");
         }
         else{
              return index;
         }
     }
     int withdraw(struct customer list[c],int ACN){ // function for withdrawing money
         int i=0,index;
         index=search(list,ACN);
         if(index==-1){
            printf("no such account exist");
         }
         else{
            return index;
         }
     }
























