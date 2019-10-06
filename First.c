//DSA Project - HV's Social Media App.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>


struct users{
  char fName[20];
  char lName[20];
  char username[20];
  char bdate[10];
  char password[20];
  struct users * next;
};

struct posts{
  char post[100];
  char userName[20];
  struct posts * next;
};

struct users * create_node(){
    struct users * newusers;
    newusers=(struct users *)malloc(sizeof(struct users));
    newusers->next=NULL;
    return newusers;
}

struct posts * create_post(){
    struct posts * newpost;
    newpost=(struct posts *)malloc(sizeof(struct posts));
    newpost->next=NULL;
    return newpost;
}


struct users * register_user(struct users * head){
  struct users * tmp;
  tmp=head;
  if(head==NULL){
    head=create_node();
    puts("Enter Firstname");
    scanf("%s",&head->fName);
    puts("Enter Lastname");
    scanf("%s",&head->lName);             //register user when head null
    puts("Enter username");
    scanf("%s",&head->username);
    puts("Enter password");
    scanf("%s",&head->password);
    return head;
  }
  else{
  while(tmp->next!=NULL)
    tmp=tmp->next;
    tmp->next=create_node();
    tmp=tmp->next;                          //register user when one or more users exists.
    puts("Enter Firstname");
    scanf("%s",&tmp->fName);
    puts("Enter Lastname");
    scanf("%s",&tmp->lName);
    puts("Enter username (Make Sure it does not already exist.)");
    scanf("%s",&tmp->username);
    puts("Enter a strong password.");
    scanf("%s",&tmp->password);
      return head;
 }
}


struct users * admin_login(struct users * head){          //admin login
    char pass[20];
    char actual[]="12345";
    struct users * tmp,*tmp2;
    struct users * tmp1=head;
    struct users * tmp3=head;
    tmp=head;
    puts("Enter Password");
    scanf("%s",&pass);
    if(strcmp(pass,actual)==0){
      puts("Reached");
        puts("FirstName\t\t\tLastname\t\t\tUsername\n___________________________________________________________________________");
        while(tmp!=NULL){
          printf("%s\t\t\t\t%s\t\t\t\t%s",tmp->fName,tmp->lName,tmp->username);
          puts("\n");
          tmp=tmp->next;
        }
        puts("Press 1 to remove a user / 0 to cancel menu");
        int i;
        scanf("%d",&i);
        if(i==1){
          puts("Enter username to remove their account.");
          char user[20];
          scanf("%s",&user);
          int flag=0;
              if(head==NULL){
                puts("No users exist.");
              }else if(head->next==NULL){
                if(strcmp(user,head->username)==0){           //found user to remove
                  printf("Removed user: %s",head->username); //user at head and ll has only one node
                  free(head);
                  flag=1;
                  head=create_node();
                   puts(" \n Need atleast one user. Enter default fname , lname , username and password");
                   scanf("%s %s %s %s",head->fName,head->lName,head->username,head->password);
                }
              }else if(head->next!=NULL && strcmp(user,head->username)==0 ){
                printf("Removed user: %s",head->username);       //user at head but ll has more than one nodes
                struct users * tmp2;
                tmp2=head;
                head=head->next;
                tmp2->next=NULL;
                flag=1;
                free(tmp2);
              }else{
               while(tmp3->next!=NULL){     //found user to remove in ll
                 tmp3=tmp3->next;
                 if(strcmp(user,tmp3->username)==0){
                     puts("found user");
                     printf("Removed user: %s",tmp3->username);    //remove user at tmp
                     while(tmp1->next!=tmp3)
                        tmp1=tmp1->next;
                     tmp1->next=tmp3->next;
                     tmp3->next=NULL;
                     flag=1;
                     free(tmp3);
                     break;
                   }
                 }
            }if(flag==0){
              puts("User not Found");
            }
          }
        }
  return head;
}


struct users * login_user(struct users * head){
    struct users * tmp;
    struct posts * p; // head of posts
    p=NULL;
    struct posts * ptemp,*ptemp1;  // temporary of posts struct
    ptemp=p;
    ptemp1=p;
    char user[20];
    char pass[20];
    tmp=head;
    puts("Enter Username");
    scanf("%s",&user);
    puts("Enter password");
    scanf("%s",&pass);
    int choice;
       while(tmp!=NULL){
            if(strcmp(user,tmp->username)==0  )
            {    if(strcmp(pass,tmp->password)==0)   //found user in LL
              {
                puts("found user");
                  do{
                      puts("\n Enter 1 to check all posts \n Enter 2 to add a post \n Enter 3 to logout. ");
                      scanf("%d",&choice);
                      switch (choice) {
                        case 1: if(p!=NULL){
                                    while(ptemp!=NULL){
                                        printf("%s : \n ",ptemp->userName);
                                        printf("%s",ptemp->post);
                                        ptemp=ptemp->next;
                                    }
                                 }
                                break;
                        case 2: if(p==NULL)
                                    {
                                      p=create_post();
                                      puts("Enter Your Post..");
                                      scanf("%s",p->post);
                                    }
                                    else{
                                      while(ptemp1->next!=NULL)
                                          ptemp1=ptemp1->next;
                                      puts("Enter Your Post..");
                                      scanf("%s",ptemp1->post);
                                    }
                                break;
                        case 3:
                                puts("Logging outt.....");
                                break;
                        default: puts("Invalid choice??");
                      }
                  }while(choice!=3);
              }}else{
                puts("Invalid Username Or Password");
              }
            tmp=tmp->next;
     }
 return head;
}

void print(struct users * head)                          //print entire linkedlist:temporaray for debugging
{
struct users *tmp;
tmp=head;
while(tmp->next!=NULL)
{
printf("%s \t",tmp->username);
tmp=tmp->next;
}
printf("%s \t",tmp->username);
}

void main(){
    struct users * head;
    head=NULL;
    int choice;
    do{ puts("\n HV's Social Media App");
        puts("\n Enter 1 to Register \n Enter 2 to Login \n Enter 3 for Admin Login \n Enter 4 to Exit \n enter 5 t print");
        scanf("%d",&choice);

        switch (choice){
          case 1:head=register_user(head);
                  break;
          case 2:head=login_user(head);
                  break;
          case 3:head=admin_login(head);
                  break;
          case 4:
                  puts("Goodbye.");
                  break;
          case 5:print(head);               //temporary case for debugging.
                  break;
          default:
                  puts("Invalid Choice.");
        }
    }while(choice!=4);
}
