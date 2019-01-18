#include <stdio.h>
#include <stdlib.h>
struct node{
  int val;
  struct node *next;
  struct node *prev;
};

// function to insert
struct node *insert(struct node *head,int val){
  if(head==NULL){
		head=(struct node *)malloc(sizeof(struct node));
		(head)->val=val;
    (head)->prev=NULL;
    (head)->next=NULL;
	}
	else{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->next=head;
  new_node->prev=NULL;
  new_node->val=val;
  (head)->prev=new_node;
	head=new_node;
}
return head;
}

// function to add
struct node *addition(struct node *head1,struct node *head2){
  int carry=0;
  int val;
  struct node *ans=NULL;
  while(head1!=NULL && head2!=NULL){
      val=carry+head1->val+head2->val;
      ans=insert(ans,val%10);
      carry=val/10;
      head2=head2->next;
      head1=head1->next;

  }
  while(head1!=NULL && head2==NULL){
      val=carry+head1->val;
      ans=insert(ans,val%10);
      carry=val/10;
      head1=head1->next;

  }
  while(head1==NULL && head2!=NULL){
      val=carry+head2->val;
      ans=insert(ans,val%10);
      carry=val/10;
      head2=head2->next;
  }
  if(carry>0){
    ans=insert(ans,carry);
  }
  struct node *tmp=ans;
  while(tmp->val==0 && tmp->next!=NULL){
    tmp=tmp->next;
  }
  ans=tmp;
  return ans;
}

// function to print
void print(struct node *head){
  struct node *temp=head;

  while(temp){
    printf("%d",temp->val);
    temp=temp->next;
  }
  printf("\n");
}

int main(){
  int digit;
  struct node *head1=NULL;
  struct node *head2=NULL;
  struct node *head3=NULL;
  int check=0;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      head3=addition(head1,head2);
      print(head3);
      head1=NULL;
      head2=NULL;
      head3=NULL;
      check=0;
    }
    else if(digit==' '){
      check=check+1;
      // print(head1);
    }
    else{
      digit=digit-'0';
      if(check==1){
        head2=insert(head2,digit);
      }
      else{
        head1=insert(head1,digit);
      }
    }
  }
  return(0);
}
