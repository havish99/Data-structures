# include <iostream>
# include <bits/stdc++.h>

using namespace std;
// struct which holds the details of a node
struct node {
  int val;
  node *prev;
  node *next;
};

// class which holds the functions on a list
class Linked_list
{
   // attributes of the list
   node *head;
   // constructor which creates the list(called only once when an object is created)
 public:
   Linked_list(){
     head=NULL;
   }
   void insert(int val);
   void print();
   void sanitize();
   void delete_list();
   int length();
   Linked_list operator + (Linked_list head_2){
     node *head1=head;
     node *head2=head_2.head;
     int carry=0;
     int val;
     Linked_list ans;
     while(head1!=NULL && head2!=NULL){
         val=carry+head1->val+head2->val;
         ans.insert(val%10);
         carry=val/10;
         head2=head2->next;
         head1=head1->next;

     }
     while(head1!=NULL && head2==NULL){
         val=carry+head1->val;
         ans.insert(val%10);
         carry=val/10;
         head1=head1->next;

     }
     while(head1==NULL && head2!=NULL){
         val=carry+head2->val;
         ans.insert(val%10);
         carry=val/10;
         head2=head2->next;
     }
     if(carry>0){
       ans.insert(carry);
     }
     return ans;
   }
   int operator >= (Linked_list head_2){
     int k1= length();
     int k2= head_2.length();
     node *head1=head;
     node *head2=head_2.head;
     if(k1<k2){
       return 0;
     }
     else if(k1>k2){
       return 1;
     }
     else{
       while(head1!=NULL){
         if(head1->val > head2->val){
           return 1;
         }
         else if(head1->val < head2->val){
           return 0;
         }
         else{
           head1=head1->next;
           head2=head2->next;
         }
       }
       return 1;
     }
   }
};

// method which inserts elements into the list (MSB at the tail and LSB at the head)
void Linked_list :: insert(int val){
  if(head==NULL){
    head = new node;
    head->val=val;
    head->next=NULL;
    head->prev=NULL;
  }
  else{
    node *new_node = new node;
    new_node->val=val;
    new_node->next=head;
    new_node->prev=NULL;
    head->prev=new_node;
    head=new_node;
  }
}

// method which traverses the list
void Linked_list :: print(){
  node *temp=head;
  while(temp!=NULL){
    cout << temp->val;
    temp=temp->next;
  }
  cout << endl;
}

// method which reverses the list and removes any leading zeros (MSB at the head and LSB at the tail)
void Linked_list :: sanitize(){
  node *current=head;
  node *temp;
  while(current!=NULL){
    temp=current->prev;
    current->prev=current->next;
    current->next=temp;
    current=current->prev;
  }
  if(temp!=NULL){
  head=temp->prev;
  }
  while(head->val==0 && head->next!=NULL){
    head=head->next;
  }

}

// method which returns the length of Linked_list
int Linked_list :: length(){
  int length=0;
  node *temp=head;
  while(temp!=NULL){
    length=length+1;
    temp=temp->next;
  }
  return length;
}

void Linked_list :: delete_list(){
  node *temp=head;
  node *next_node;
  while(temp!=NULL){
    next_node=temp->next;
    free(temp);
    temp=next_node;
  }
  head=NULL;
}

int main(){
  int digit;
  Linked_list list_1;
  Linked_list list_2;
  int check=0;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      // sanitize the two lists before comparing
      list_1.sanitize();
      list_2.sanitize();
      if(list_1>=list_2){
        cout << "1" << endl;
      }
      else{
        cout << "0" << endl;
      }
      list_1.delete_list();
      list_2.delete_list();
      check=0;
    }
    else if(digit==' '){
      check=check+1;
    }
    else{
      digit=digit-'0';
      if(check==1){
        list_2.insert(digit);
      }
      else{
        list_1.insert(digit);
      }
    }
  }
  return(0);
}
