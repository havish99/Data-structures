// WORKS FOR ANY LENGTH NUMBER
# include <bits/stdc++.h>
using namespace std;
// struct which holds the details of a node in linked list
struct node {
  int val;
  node *prev;
  node *next;
};

// class which holds the functions on a list
class Linked_list
{
   // attributes of the list
   public:
   node *head;
   // constructor which creates the list(called only once when an object is created)
   Linked_list(){
     head=NULL;
   }
   void insert(int val);
   void print();
   void delete_list();
   Linked_list copy_list();
   Linked_list reverse();
   int length();
   // overloads > to compare two objects of class Linked_list
   bool operator > (Linked_list head_2){
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
       int flag=0;
       while(head1!=NULL && head2!=NULL){
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
       //if(flag==k1)
       return 0;
     }
   }
   // overloads == to compare two objects of class Linked_list
   bool operator == (Linked_list head_2){
     int k1= length();
     int k2= head_2.length();
     node *head1=head;
     node *head2=head_2.head;
     if(k1==k2){
       while(head1!=NULL && head2!=NULL){
         if(head1->val > head2->val){
           return 0;
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
     else
     return 0;
   }

};
// struct which holds the details of a node in binary search tree
struct node_bst{
  Linked_list val;
  node_bst *parent;
  node_bst *left;
  node_bst *right;
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
//method which copies contents of a List and removes any zeros
Linked_list Linked_list :: copy_list(){
  Linked_list b;
  node *temp=head;
  while(temp!=NULL){
    int val=temp->val;
    b.insert(val);
    temp=temp->next;
  }
  while(b.head->next!=NULL && b.head->val==0){
    b.head=b.head->next;
  }
  return b;
}
// method which traverses the list
void Linked_list :: print(){
  node *temp=head;
  while(temp!=NULL){
    cout << temp->val;
    temp=temp->next;
  }
  //cout << endl;
  cout << " ";
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
// method which returns deletes the elements of the list
void Linked_list :: delete_list(){
  node *temp=head;
  node *next_node;
  while(temp!=NULL){
    next_node=temp->next;
    delete temp;
    temp=next_node;
  }
  head=NULL;
  // cout << "List is deleted" << endl;
}
// class which holds the functions of a Binary Search Tree
class BST{
 public:
  node_bst *root;
  BST(){
    root=NULL;
  }
  void insert(Linked_list a);
  void pre_order_traversal(node_bst *temp);
  void delete_tree(node_bst *temp);
  node_bst *search(Linked_list val,int flag);
  node_bst *successor(Linked_list val);
  void splice(node_bst *temp);
  void delete_node(Linked_list val);
};
// method which inserts elements into a bst
void BST :: insert(Linked_list a){
  if(root==NULL){
    root = new node_bst;
    root->val=a;
    root->parent=NULL;
    root->left=NULL;
    root->right=NULL;
  }
  else{
    node_bst *new_node=new node_bst;
    new_node->val=a;
    new_node->left=NULL;
    new_node->right=NULL;
    node_bst *temp=root;
    node_bst *refer=NULL;
    while(temp!=NULL){
      refer=temp;
      if(a==temp->val)
      return;
      else if(a>temp->val){
        temp=temp->right;
      }
      else{
        temp=temp->left;
      }
    }
    new_node->parent=refer;
    if(a>refer->val){
      refer->right=new_node;
    }
    else{
      refer->left=new_node;
    }
  }

}
// method which does pre order traversal
void BST :: pre_order_traversal(node_bst *temp){
 if(temp==NULL)
 return;
 else{
   temp->val.print();
   pre_order_traversal(temp->left);
   pre_order_traversal(temp->right);
 }
}
// method which deletes tree and its elements
void BST :: delete_tree(node_bst *temp){
 if(temp!=NULL){
  delete_tree(temp->left);
  delete_tree(temp->right);
  temp->val.delete_list();
  delete temp;
}
root=NULL;
}
// method which searches for a given node in bst
node_bst *BST :: search(Linked_list val,int flag){
 node_bst *temp=root;
 string path="";
 while(temp!=NULL){
   if(val==temp->val){
     if(flag==1)
     cout << path << endl;
     return temp;
   }
   else{
     if(val>temp->val){
       path=path+'1';
       temp=temp->right;
     }
     else{
       path=path+'0';
       temp=temp->left;
     }
   }
 }
 return temp;
}
// method which returns the succesor of a given node in bst
node_bst *BST :: successor(Linked_list val){
  node_bst *temp=search(val,0);
  if(temp==NULL){
    insert(val);
    node_bst *temp1=search(val,0);
    node_bst *temp=temp1;
    // part which removes the inserted node
    if(val > temp1->parent->val)
    temp1->parent->right=NULL;
    else
    temp1->parent->left=NULL;
    while(temp!=NULL){
      if(temp->val > val){
        return temp;
      }
      temp=temp->parent;
    }
  }
  else{
    if(temp->right!=NULL){
      temp=temp->right;
      while((temp->left)!=NULL){
        temp=temp->left;
      }
      return temp;
    }
    else if(temp->right==NULL){
      while(temp!=NULL){
        if(temp->val > val){
          return temp;
        }
        temp=temp->parent;
      }
    }
  }
  return temp;
}
// method which splices a given node in bst


// method which deletes a node from bst
void BST :: delete_node(Linked_list val){
  node_bst *temp=search(val,0);
  if(temp->parent==NULL){
    temp->val.delete_list();
    delete temp;
    temp=NULL;
    return;
  }
  if(temp->val > temp->parent->val){
    if(temp->left==NULL){
      temp->parent->right=temp->right;
    }
    else if(temp->right==NULL){
      temp->parent->right=temp->left;
    }
  }
  else if(temp->parent->val > temp->val){
    if(temp->left==NULL){
      cout << "Hello" << endl;
      cout << temp->right;
      temp->parent->left=temp->right;
    }
    else if(temp->right==NULL){
      temp->parent->left=temp->left;
    }
  }
  temp->val.delete_list();
  delete temp;
  temp->val.print();
  temp=NULL;
}


int main(){
	int digit, count = 0,flag1=0,flag=0,flag2=0,flag3=0,flag4=0;
	Linked_list a ,temp;
  node_bst *tmp;
  BST bst;
  // flag4 takes care of printing the succesor
  // flag3 takes care of deleting a given element
  // flag2 takes care of inserting new element into the set
  // flag1 takes care of pre-order-traversal
  // flag takes care of search
  while((digit = fgetc(stdin)) != EOF){
	if(digit=='\n'){
    if(a.head!=NULL && flag==0 && flag4==0 && flag3==0){
      temp=a.copy_list();
      bst.insert(temp);
      a.delete_list();
    }
    else if(flag==1){
      a=a.copy_list();
      tmp=bst.search(a,flag);
      a.delete_list();
      if(tmp==NULL){
        cout << -1 << endl;
      }
      flag=0;
    }
    else if(flag4==1){
      a=a.copy_list();
      tmp=bst.successor(a);
      if(tmp!=NULL)
      tmp->val.print();
      else
      cout << -1;
      cout << endl;
      a.delete_list();
      flag4=0;
    }
    else if(flag3==1){
      a=a.copy_list();
      bst.delete_node(a);
      a.delete_list();
      flag3=0;
    }
    else if(flag1==1){
      bst.pre_order_traversal(bst.root);
      cout << endl;
      flag1=0;
    }
  }
  else if(digit=='N'){
    bst.delete_tree(bst.root);
  }
  else if(digit=='S'){
    flag=1;
  }
  else if(digit=='P'){
    flag1=1;
  }
  else if(digit=='+'){
    flag2=1;
  }
  else if(digit=='-'){
    flag3=1;
  }
  else if(digit=='>'){
    flag4=1;
  }
  else if(digit==' ' || flag2==1){
    if(a.head!=NULL){
      temp=a.copy_list();
      bst.insert(temp);
      a.delete_list();
    }
    flag2=0;
  }
  else{
    int k=digit-'0';
    a.insert(k);
    // a.print();
  }
	}
	bst.delete_tree(bst.root);
	temp.delete_list();
	return 0;
}
