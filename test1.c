#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    };

struct node *create(){
    struct node *newnode=NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data\n");
    scanf("%d",&newnode->data);
    return newnode;
    }

struct node *create_list(struct node *head){
    head=create();
    head->next=NULL;
    head->next=NULL;
    return head;
    }

struct node *insert_begin(struct node *head){
    struct node *newnode;
    newnode=create();
    newnode->next=head;
    head=newnode;
    return head;
}

struct node *insert_rear(struct node *head){
    struct node *newnode,*temp;
    temp = head;
    newnode = create();
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    newnode->next=NULL;
    return head;
}

void display(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void main(){
    struct node *head=NULL;
    int ch;
    printf("Creating Linked List\n");
    head = create_list(head);
    system("cls");
    while(ch != 4){
        printf("Enter Choice\n1:Insert Front\n2:Insert Rear\n3:Display\n");
        scanf("%d",&ch);
        system("cls");
        switch(ch){
        case 1:
           head =  insert_begin(head);
           system("cls");
           break;
        case 2:
            head=insert_rear(head);
            system("cls");
            break;
        case 3:
            display(head);
            getch();d
            system("cls");
            break;
        case 4:
            printf("Exiting...");
            system("cls");
            exit(0);
        default:
            printf("Enter proper Choice");
        }
    }
    getch();
    exit(0);
}
