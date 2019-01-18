#include <stdio.h>
#include <stdlib.h>
struct node{
  int val;
  struct node *next;
  struct node *prev;
};

void **insert(struct node **head,int val){
  if(*head==NULL){
		*head=(struct node *)malloc(sizeof(struct node));
		(*head)->val=val;
    (*head)->prev=NULL;
    (*head)->next=NULL;
	}
	else{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->next=*head;
  new_node->prev=NULL;
  new_node->val=val;
  (*head)->prev=new_node;
	*head=new_node;
}
}

struct node *addition(struct node *head1,struct node *head2){
  int carry=0;
  int val;
  struct node *ans=NULL;
  while(head1!=NULL && head2!=NULL){
      val=carry+head1->val+head2->val;
      insert(&ans,val%10);
      carry=val/10;
      head2=head2->next;
      head1=head1->next;

  }
  while(head1!=NULL && head2==NULL){
      val=carry+head1->val;
      insert(&ans,val%10);
      carry=val/10;
      head1=head1->next;

  }
  while(head1==NULL && head2!=NULL){
      val=carry+head2->val;
      insert(&ans,val%10);
      carry=val/10;
      head2=head2->next;
  }
  if(carry>0){
    insert(&ans,carry);
  }
  struct node *tmp=ans;
  while(tmp->val==0 && tmp->next!=NULL){
    tmp=tmp->next;
  }
  ans=tmp;
  return ans;
}

void print(struct node *head){
  struct node *temp=head;

  while(temp){
    printf("%d",temp->val);
    temp=temp->next;
  }
  printf("\n");
}
int main(){
  struct node *head2=NULL;
  struct node *head1=NULL;
  struct node *head3=NULL;
  int a[14]={0,0,0,0,0,0,1,0,0,0,0,0,0,1};
  int b[7]={0,0,0,0,0,0,1};
  for(int i=0;i<14;i++){
    insert(&head1,a[i]);
  }
  for(int i=0;i<7;i++){
    insert(&head2,b[i]);
  }
  head2=addition(head1,head2);

  print(head2);
  //printf("\n");
}
