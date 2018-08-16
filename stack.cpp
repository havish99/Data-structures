#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
	int val;
	struct node *next;
};

void insert_at_end(struct node **head,int val){
	if(*head==NULL){
		*head=(struct node *)malloc(sizeof(node));
		(*head)->val=val;
	}
	else{
	struct node *new_node=(struct node*)malloc(sizeof(node));
	struct node *temp=*head;
	new_node->val=val;
	new_node->next=NULL;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
}
}

void push(struct node **head,int val){
	if(*head==NULL){
		*head=(struct node *)malloc(sizeof(node));
		(*head)->val=val;
	}
	else{
	struct node *new_node=(struct node*)malloc(sizeof(node));
	new_node->next=*head;
	new_node->val=val;
	*head=new_node;
}
}

void remove_last_elem(struct node **head){
	struct node *temp=*head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	temp->next=NULL;
}

void pop(struct node **head){
	if(*head==NULL){
		cout << "Stack is empty" << endl;
	}
	else{
		(*head)=(*head)->next;
	}
}

void peek(struct node **head){
	if(*head==NULL){
		cout << "Stack is empty" << endl;
	}
	else{
		cout << (*head)->val << endl;
	}
}

void print(struct node *head){
	if(head==NULL){
		cout << "Stack is empty" << endl;
	}
	while(head!=NULL){
		cout << head->val << endl;
		head=head->next;
	}
}


int main(){
	int valu=4;
	struct node *head=NULL;
	insert_at_end(&head,4);
	push(&head,6);
	push(&head,10);
	//push(&head,20);
	//push(&head,20);
	pop(&head);
	peek(&head);
	print(head);
}