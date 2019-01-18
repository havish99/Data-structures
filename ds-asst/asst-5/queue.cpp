# include <bits/stdc++.h>

using namespace std;

struct node{
  int val;
  node *next;
};

class Queue{
public:
  node *head;
  node *tail;
  Queue(){
    head=NULL;
    tail=NULL;
  }
  void enqueue(int val);
  node *dequeue();
  void print();
};

void Queue :: enqueue(int val){
  if(head==NULL){
    head = new node;
    head->val=val;
    tail=head;
    head->next=NULL;
    return;
  }
  node *new_node = new node();
  new_node->val=val;
  new_node->next=NULL;
  tail->next=new_node;
  tail=new_node;
}

node * Queue :: dequeue(){
  if(head==NULL){
    return head;
  }
  node *tmp=head;
  head=head->next;
  return tmp;
}

void Queue :: print(){
  node *tmp=head;
  while(tmp!=NULL){
    cout << tmp->val << " ";
    tmp=tmp->next;
  }
  cout << endl;
}


int main(){
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.print();
  node *tmp=q.dequeue();
  tmp=q.dequeue();
  tmp=q.dequeue();
  q.enqueue(1);
  q.enqueue(2);
  tmp=q.dequeue();
  q.print();
  cout << tmp->val << endl;
  return 0;
}
