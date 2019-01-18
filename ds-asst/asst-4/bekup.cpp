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
  void children(long long int val);
  void left(long long int val);
  node_bst *search(long long int val,int flag);
  node_bst *successor(long long int val);
  void uncle(long long int val);
  void right(long long int val);
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
node_bst *BST :: search(long long int val, int flag){
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

// method which prints the uncle of a given value
void BST :: uncle(long long int val){
  node_bst *node=search(val,0);
  if(node==NULL){
    cout << "-1" << endl;
    return;
  }
  node_bst *parent=node->parent;
  if(parent==NULL){
    cout << "-1" << endl;
    return;
  }
  node_bst *grand_parent=parent->parent;
  if(grand_parent==NULL){
    cout << "-1" << endl;
    return;
  }
  if(grand_parent->val > parent->val){
    if(grand_parent->right==NULL){
      cout << "-1" << endl;
      return;
    }
    cout << grand_parent->right->val << endl;
    return;
  }
  if(grand_parent->val < parent->val){
    if(grand_parent->left==NULL){
      cout << "-1" << endl;
      return;
    }
    cout << grand_parent->left->val << endl;
    return;
  }

}

// method which prints the children of a given value
void BST :: children(long long int val){
  node_bst *node=search(val,0);
  if(node==NULL){
    cout << "-1" << endl;
    return;
  }
  if(node->left==NULL){
    cout << "Nil" << " ";
  }
  else if(node->left!=NULL){
    cout << node->left->val << " ";
  }
  if(node->right==NULL){
    cout << "Nil" << endl;
  }
  else if(node->right!=NULL){
    cout << node->right->val << endl;
  }
}

// method which left rotates the tree about a value
void BST :: left(long long int val){
  node_bst *node=search(val,0);
  if(node==NULL){
    return;
  }
  node_bst *parent=node->parent;
  if(node->right==NULL){
    return;
  }
  node_bst *y=node->right;
  node_bst *tmp=y->left;
  y->left=node;
  y->parent=parent;
  node->parent=y;
  node->right=tmp;
  if(tmp!=NULL)
  tmp->parent=node;
  if(parent!=NULL){
  if(parent->val > y->val)
  parent->left=y;
  else if(parent->val < y->val)
  parent->right=y;
  }
    else if(parent==NULL){
      root=y;
    }
}

void BST :: right(long long int val){
  node_bst *node=search(val,0);
  if(node==NULL){
    return;
  }
  node_bst *parent=node->parent;
  if(node->left==NULL){
    return;
  }
  node_bst *y=node->left;
  node_bst *tmp=y->right;
  y->right=node;
  y->parent=parent;
  node->parent=y;
  node->left=tmp;
  if(tmp!=NULL)
  tmp->parent=node;
  if(parent!=NULL){
  if(parent->val > y->val)
  parent->left=y;
  else if(parent->val < y->val)
  parent->right=y;
  }
    else if(parent==NULL){
      root=y;
    }
}

int main(){
	long long int digit, count = 0,flag1=0,flag=0,flag2=0,flag3=0,flag4=0;
  int flag5=0,flag6=0,flag7=0,flag8=0;
  long long int a=0;
  node_bst *tmp;
  BST bst;
  // flag8 takes care of right rotate
  // flag7 takes care of left rotate
  // flag6 takes care of printing children
  // flag5 takes care of printing the uncle
  // flag4 takes care of printing the succesor
  // flag3 takes care of deleting a given element
  // flag1 takes care of pre-order-traversal
  // flag takes care of search
  while((digit = fgetc(stdin)) != EOF){
	if(digit=='\n'){
    if(a>0 && flag==0 && flag4==0 && flag3==0 && flag5==0 && flag6==0 && flag7==0 && flag8==0){
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
    else if(flag5==1){
      bst.uncle(a);
      a=0;
      flag5=0;
    }
    else if(flag6==1){
      bst.children(a);
      a=0;
      flag6=0;
    }
    else if(flag7==1){
      bst.left(a);
      a=0;
      flag7=0;
    }
    else if(flag8==1){
      bst.right(a);
      a=0;
      flag8=0;
    }
  }
  else if(digit=='N' || digit=='B'){
    bst.delete_tree(bst.root);
  }
  else if(digit=='S'){
    flag=1;
  }
  else if(digit=='P'){
    flag1=1;
  }
  else if(digit=='U'){
    flag5=1;
  }
  else if(digit=='-'){
    flag3=1;
  }
  else if(digit=='C'){
    flag6=1;
  }
  else if(digit=='L'){
    flag7=1;
  }
  else if(digit=='R'){
    flag8=1;
  }
  else if(digit=='>'){
    flag4=1;
  }
  else if(a>0 && digit==' ' && (flag==0 && flag1==0 && flag3==0 && flag4==0 && flag5==0 && flag6==0 && flag7==0 && flag8==0)){
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
