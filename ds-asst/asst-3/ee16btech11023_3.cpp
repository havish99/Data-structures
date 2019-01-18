# include <bits/stdc++.h>
using namespace std;
// class which holds the functions of a Binary Search Tree
struct node_bst{
  long long int val;
  node_bst *parent;
  node_bst *left;
  node_bst *right;
};
class BST{
 public:
  node_bst *root;
  BST(){
    root=NULL;
  }
  void insert(long long int a);
  void pre_order_traversal(node_bst *temp);
  void delete_tree(node_bst *temp);
  node_bst *search(long long int val,long long int flag);
  node_bst *successor(long long int val);
  void splice(node_bst *temp);
  void delete_node(long long int val);
};
// method which inserts elements into a bst
void BST :: insert(long long int a){
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
   cout << temp->val << " ";
   pre_order_traversal(temp->left);
   pre_order_traversal(temp->right);
 }
}
// method which deletes tree and its elements
void BST :: delete_tree(node_bst *temp){
 if(temp!=NULL){
  delete_tree(temp->left);
  delete_tree(temp->right);
  delete temp;
}
root=NULL;
}
// method which searches for a given node in bst
node_bst *BST :: search(long long int val,long long int flag){
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
node_bst *BST :: successor(long long int val){
  if(root==NULL){
    return root;
  }
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
void BST :: splice(node_bst *temp){
  if(temp==root){
    if(temp->left==NULL && temp->right==NULL){
      delete temp;
      root=NULL;
      return;
    }
    if(temp->left!=NULL && temp->right==NULL){
      root=temp->left;
      delete temp;
      temp=NULL;
      return;
    }
    if(temp->left==NULL && temp->right!=NULL){
      root=temp->right;
      delete temp;
      temp=NULL;
      return;
    }
  }
  if(temp->left==NULL && temp->right==NULL){
    if(temp->parent->left==temp){
      temp->parent->left=NULL;
    }
    else{
      temp->parent->right=NULL;
    }
    delete temp;
    temp=NULL;
    return;
  }
  if(temp->left!=NULL && temp->right==NULL){
    if(temp->parent->val > temp->val){
    temp->parent->left=temp->left;
    temp->left->parent=temp->parent;
    }
    else{
    temp->parent->right=temp->left;
    temp->left->parent=temp->parent;
  }
    delete temp;
    temp=NULL;
    return;

  }
  if(temp->left==NULL && temp->right!=NULL){
    if(temp->parent->val > temp->val){
    temp->parent->left=temp->right;
    temp->right->parent=temp->parent;
    }
    else{
    temp->parent->right=temp->right;
    temp->right->parent=temp->parent;
    }
    delete temp;
    temp=NULL;
    return;
  }
}

// method which deletes a node from bst
void BST :: delete_node(long long int val){
  node_bst *temp=search(val,0);
  if(temp->left==NULL || temp->right==NULL){
    splice(temp);
    temp=NULL;
  }
  else{
    node_bst *succ=successor(val);
    long long int tmp=succ->val;
    splice(succ);
    succ=NULL;
    temp->val=tmp;
  }

}


int main(){
	long long int digit, count = 0,flag1=0,flag=0,flag2=0,flag3=0,flag4=0;
	long long int a=0;
  node_bst *tmp;
  BST bst;
  // flag4 takes care of prlong long inting the succesor
  // flag3 takes care of deleting a given element
  // flag1 takes care of pre-order-traversal
  // flag takes care of search
  while((digit = fgetc(stdin)) != EOF){
	if(digit=='\n'){
    if(a>0 && flag==0 && flag4==0 && flag3==0){
      bst.insert(a);
      a=0;
    }
    else if(flag==1){
      tmp=bst.search(a,flag);
      a=0;
      if(tmp==NULL){
        cout << -1 << endl;
      }
      flag=0;
    }
    else if(flag4==1){
      tmp=bst.successor(a);
      if(tmp!=NULL)
      cout << tmp->val;
      else
      cout << -1;
      cout << endl;
      a=0;
      flag4=0;
    }
    else if(flag3==1){
      bst.delete_node(a);
      a=0;
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
  else if(digit=='-'){
    flag3=1;
  }
  else if(digit=='>'){
    flag4=1;
  }
  else if(a>0 && digit==' ' && (flag==0 && flag1==0 && flag3==0 && flag4==0)){
    bst.insert(a);
    a=0;
  }
  else{
    long long int k=digit-'0';
    if(k<10 && k>=0){
    a=10*a+k;
  }
  }
	}
	bst.delete_tree(bst.root);
	return 0;
}
