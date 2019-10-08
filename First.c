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
    int friends[20];
    struct users * next;
};

struct users * create_node(){
    struct users * newusers;
    newusers=(struct users *)malloc(sizeof(struct users));
    newusers->next=NULL;
    return newusers;
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
      int i;
      for(i=0;i<=19;i++){                     //init friends array to 0
          head->friends[i]=0;
      }
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
      int i;
      for(i=0;i<=19;i++){
          tmp->friends[i]=0;            //init friends array to 0
      }
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
        }else{
          puts("Invalid admin password. better luck next time ");
        }
  return head;
}

int noOfUsers(struct users * head){
    int no = 1;
    struct users * tmp;
    tmp=head;
    if(head==NULL)
        return 0;
    else{
        while(tmp->next!=NULL){
            no++;
            tmp=tmp->next;
        }
      return no;
    }

}

struct users * addFriend(struct users * head,struct users * tmp){
  struct users * tmp1;
  char uname[20];
  tmp1=head;
    puts("These are the current users.");
    puts("FirstName\t\t\tLastname\t\t\tUsername\n___________________________________________________________________________");
      while(tmp1!=NULL){
        printf("%s\t\t\t\t%s\t\t\t\t%s",tmp1->fName,tmp1->lName,tmp1->username);
        puts("\n");
        tmp1=tmp1->next;
      }
    puts("Enter username of the person who you want to add.");
    scanf("%s",uname);

  tmp1=head;
  int counter=0;
  int i;
    while(tmp1!=NULL){

        if(strcmp(uname,tmp1->username)==0){
            puts("Found user to be added");
              i=0;
                while(tmp->friends[i]!=0){
                  i++;
                }
                tmp->friends[i]=counter;
              break;
        }
        counter++;
        tmp1=tmp1->next;

    }

    int size=0;
    struct users * tmp2;
    tmp2=head;
      while(tmp2!=tmp){
        tmp2=tmp2->next;
        size++;
      }


  //add the current user to friend list of the one he just added.
    i=0;
    tmp2=head;
      while(i<counter){
          tmp2=tmp2->next;
          i++;
      }
    int j=0;
      while(tmp2->friends[j]!=0){
          j++;
      }
      tmp2->friends[j]=size;

  return head;
}

void findFriend(struct users * head, int posi){      //traverse to posi and print user

    struct users * tmp;
    tmp=head;
    int i=0;
    while(i<posi)
      {
        tmp=tmp->next;
        i++;
      }

    printf("%s \n",tmp->username);
}

void checkFriends(struct users * head,struct users * tmp){
    struct users * tmp1;
    tmp1=head;
    int i;
    int counter = 0;
    for(i=0;i<20;i++){
      if(tmp->friends[i]!=0){
        counter = 1;                                  // user has friends
        break;
      }
    }
    if(counter == 0)
      puts("You dont have any friends.");

    if(counter == 1){                                         // display all friends
        puts("Your friends are");
        for(i=0; i<20; i++){
              if(tmp->friends[i]!=0){
                  findFriend(head,tmp->friends[i]);        //print who the user is .
              }
        }
    }
}


struct users * login_user(struct users * head){
    struct users * tmp;
    char user[20];
    char pass[20];
    tmp=head;
    puts("Enter Username");
    scanf("%s",&user);
    puts("Enter password");
    scanf("%s",&pass);
    int choice;
    int userflag = 0;
       while(tmp!=NULL){
            if(strcmp(user,tmp->username)==0  )
            {    if(strcmp(pass,tmp->password)==0)   //found user in LL
              {
                puts("found user");
                userflag = 1;
                  do{
                      puts("\n Enter 1 to check your current friends \n Enter 2 to add a new friend \n Enter 3 to logout. ");
                      scanf("%d",&choice);
                      switch (choice) {
                        case 1:     //check current friends
                                checkFriends(head,tmp);
                                break;
                        case 2:     //add a new friend
                                head=addFriend(head,tmp);
                                break;
                        case 3:
                                puts("Logging outt.....");
                                break;
                        default: puts("Invalid choice??");
                      }
                  }while(choice!=3);
              }}
            tmp=tmp->next;
     }
    if(userflag == 0){
        puts("Invalid Username Or Password");
    }
 return head;
}


void main(){
    struct users * head;
    head=NULL;
    int choice;
    do{
        puts("\n Welcome to HV's Social Media App");
        puts("\n Enter 1 to Register \n Enter 2 to Login \n Enter 3 for Admin Login \n Enter 4 to Exit\n");
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
          default:
                  puts("Invalid Choice.");
        }
    }while(choice!=4);
}
