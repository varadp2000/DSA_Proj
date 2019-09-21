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
    char uname[10];
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
char *passSet(){
    char pass[50],*e;
    printf("Enter Password\nAtLeast 8char,1Uppercase,Digit and Lowercase\n");
    scanf("%s",&pass);
    printf("%s\n",pass);
    printf("%d",strlen(pass));
    int a=0,b=0,c=0,i;
    for(i=0;i<strlen(pass);i++){
        printf("%c\t",pass[i]);
        if(isdigit(pass[i]))
            a++;
        if(isupper(pass[i]))
            b++;
        if(islower(pass[i]))
            c++;
    }
    printf("%d  %d  %d  %d\n",a,b,c,a+b+c);
    if(a+b+c > 8 && (a>0 && (b>0||c>0) )){
        *e=&pass;
        return a;
    }
    else{
        printf("Invalid Pass\n");
        return passSet();
    }
}

struct data *new_user(struct data *newnode){
    char *pass;
    printf("Welcome to ______________\nPlease Enter Your Data\n");
    printf("Enter First and Last Name\n");
    scanf("%s%s",newnode->fullname.fname,newnode->fullname.lname);
    printf("Enter birthdate DD MM YYYY\n");
    scanf("%d%d%d",&newnode->bdate.DD,&newnode->bdate.MM,&newnode->bdate.YYYY);
//    printf("Enter Password\n");
//    scanf("%s",newnode->password);
    pass=passSet();
    newnode->password=pass;
    printf("Enter Gender[M/F]\n");
    scanf("%s",newnode->gender);
    printf("Enter Username\n");
    scanf("%s",newnode->uname);

    return newnode;
}

struct data *insert(struct data *head){
    struct data *newnode,*temp;
    newnode=create();
    temp=head;
    if(head==NULL){
        head=create();
        head=new_user(head);
        head->next=NULL;
        return head;
        }
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        newnode=new_user(newnode);
        temp->next=newnode;
        newnode->next=NULL;

        return head;
    }
}




/*
char *uname(){
    struct data *temp;
    char uname[10];
    temp=head;
    printf("Select Uname");
    scanf("%s",un);
    while(temp!=NULL){
    if(temp->uname==un){
        printf("Invalid uname");
        return uname();
    }
    else
        return un;
        temp=temp->next;
    }
}
*/
void adminDisplay(struct data *head){
    int pass;
    struct data *temp;
    printf("Enter Admin Password:\n");
    scanf("%d",&pass);
    temp=head;
    if(pass==12345 || pass ==67890){
        printf("Password Accepted\n");
        printf("FName\tLname\tBDate\t\tUname\t\tPass\t\tGender\n_________________________________________________________________\n");
        while(temp!=NULL){
            printf("%s\t%s\t%d-%d-%d\t%s\t\t%s\t\t%s\n",temp->fullname.fname,temp->fullname.lname,temp->bdate.DD,temp->bdate.MM,temp->bdate.YYYY,temp->uname,temp->password,temp->gender);
            temp=temp->next;
        }
    }
}

void main(){
    int ch;
    struct data *head=NULL;
    printf("Before Loop\n");
    while(ch != 5){
        printf("Loop Started\n");
    scanf("%d",&ch);
        switch (ch){
        case 1:
            head=insert(head);
            break;
        case 2:
            adminDisplay(head);
            break;
        case 5:
            exit(0);
        }
    }
}






