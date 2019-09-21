#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

struct name{
    char fname[10];
    char lname[10];
};

struct date{
    int DD;
    int MM;
    int YYYY;
};

struct messages{
    char username[10];
    char message[100];
};

struct data{
    struct name fullname;
    struct date bdate;
    char *uname;
    char gender[1];
    struct messages gotmessage[100];
    char *password;
    struct data *next;
};


struct data *create(){
    struct data *newnode;
    newnode=(struct data *)malloc(sizeof(struct data));
//    newnode=NULL;
//    newnode->next=NULL;
    return newnode;
}

//char pass1[50];

char *passSet(){
    char pass[50]="\0";
    char *e=NULL;
    printf("Enter Password\nPassword Should Be AtLeast 8 charecter long and must contain 1 Uppercase,Digit and Special Char\n");
    scanf("%s",pass);
    e=(char *)malloc(sizeof(strlen(pass)+1));
    int a=0,b=0,c=0,d=0,i;
    for(i=0;i<strlen(pass);i++){
        if(isdigit(pass[i]))
            a++;
        else if(isupper(pass[i]))
            b++;
        else if(islower(pass[i]))
            c++;
        else
            d++;
    }
    if(a+b+c+d >= 8 && (a>0 && b>0 && c>0 && d>0 )){
      strcpy(e,pass);
      return e;
    }
    else{
        printf("Invalid Pass\n");
        return passSet();
    }
}

char *usname(struct data *head){
    struct data *temp;
    char unn[10]="\0";
    char *un=NULL;
    un=(char *)malloc(sizeof(char)*10);
    int flag=0;
    temp=head;
    printf("Select Uname\n");
    scanf("%s",unn);
    while(temp!=NULL){
    if(strcmp(temp->uname,unn)==0)
        flag=1;
        temp=temp->next;
    }
    if(flag==1){
        printf("Username Already taken\n");
        return usname(head);
    }
    else if(flag==0){
        strcpy(un,unn);
        return un;
    }
}

struct data *new_user(struct data *newnode,struct data *head){
    char *pass;
    printf("Please Enter Your Data\n");
    printf("Enter First and Last Name\n");
    scanf("%s%s",newnode->fullname.fname,newnode->fullname.lname);
    printf("Enter birthdate DD MM YYYY\n");
    scanf("%d%d%d",&newnode->bdate.DD,&newnode->bdate.MM,&newnode->bdate.YYYY);
    newnode->password=passSet();
    printf("Enter Gender[M/F]\n");
    scanf("%s",newnode->gender);
    newnode->uname="\0";
    newnode->uname=usname(head);
    return newnode;
}

struct data *insert(struct data *head){
    struct data *newnode,*temp;
    newnode=create();
    temp=head;
    if(head==NULL){
        head=create();
        head=new_user(head,head);
        head->next=NULL;
        return head;
        }
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        newnode=new_user(newnode,head);
        temp->next=newnode;
        newnode->next=NULL;

        return head;
    }
}




void adminDisplay(struct data *head){
    int pass;
    struct data *temp;
    printf("Enter Admin Password:\n");
    scanf("%d",&pass);
    temp=head;
    if(pass==12345 || pass ==67890){
        printf("Password Accepted\n");
        printf("FName\tLname\tBDate\t\tUname\t\tPassword   \t\tGender\n______________________________________________________________________________________________\n");
        while(temp!=NULL){
            printf("%s\t%s\t%d-%d-%d\t%s\t\t%s\t\t%s\n",temp->fullname.fname,temp->fullname.lname,temp->bdate.DD,temp->bdate.MM,temp->bdate.YYYY,temp->uname,temp->password,temp->gender);
            temp=temp->next;
        }
    }
}

void main(){
    int ch;
    struct data *head=NULL;
    printf("Welcome to SocialNetwork\n");
    while(ch != 5){
        printf("Enter Your Choice\n1:Enter Data\n2:AdminPanel\n5:Exit\n");
    scanf("%d",&ch);
        switch (ch){
        case 1:
            head=insert(head);
            break;
        case 2:
            adminDisplay(head);
            break;
        case 5:
            printf("Thank you for Using Us.....Have a Nice Day;-)\n");
            exit(0);
            break;
        default:
            printf("Select Proper Choice");
        }
    }
}
