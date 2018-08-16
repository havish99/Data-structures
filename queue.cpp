#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
	int val;
	struct node *next;
};

struct queue{
	struct node *front;
	struct node *rear;
};

struct node *Node(int val){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->val=val;
	newnode->next=NULL;
	return newnode;
}

struct queue *createQueue(){
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->front=NULL;
	q->rear=NULL;
	return q;
}

void enqueue(struct queue **queue,int val){
struct queue *q=*queue;
struct node *newnode=Node(val);

if(q->rear==NULL){
	q->front=q->rear=newnode;
}

else{
	q->rear->next=newnode;
	q->rear=newnode;
}
}

void dequeue(struct queue **queue){
	struct queue *q=*queue;
	if(q->front==NULL){
		cout << "queue is empty" << endl;
	}
	else{
	q->front=q->front->next;
}
}

void print(struct queue *q){
	struct node *head=q->front;
	while(head!=NULL){
		cout << head->val << endl;
		head=head->next;
	}
}


int main(){
	struct queue *q=createQueue();
	enqueue(&q,10);
	enqueue(&q,100);
	enqueue(&q,120);
	dequeue(&q);
	print(q);
}