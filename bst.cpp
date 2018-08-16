#include <iostream>
#include <stdlib.h>

using namespace std;

struct bst{
	int val;
	struct bst *left;
	struct bst *right;
	struct bst *parent;
};

void insert(struct bst **node,struct bst *parent,int val){
if(*node==NULL){
	*node=(struct bst *)malloc(sizeof(struct bst));
	(*node)->parent=parent;
	(*node)->left=NULL;
	(*node)->right=NULL;
	(*node)->val=val;
}
else {
	struct bst *new_node=(struct bst *)malloc(sizeof(struct bst));
	if(val < (*node)->val){
		insert(&((*node)->left),*node,val);
	}
	if(val > (*node)->val){
		insert(&((*node)->right),*node,val);
	}
}
}

void inorder_traversal(struct bst *root){
if(root==NULL){
	return ;
}
else{
	inorder_traversal(root->left);
	cout << root->val << endl;	
	inorder_traversal(root->right);
}
}

void preorder_traversal(struct bst *root){
if(root==NULL){
	return ;
}
else{
	cout << root->val << endl;
	preorder_traversal(root->left);	
	preorder_traversal(root->right);
}	
}

struct bst *search(struct bst *root,int val){
while(root!=NULL){
	if(val==root->val){
		cout << "Found" << endl;
		return root;
	}
	else if(val>root->val){
		root=root->right;
	}
	else if(val<root->val){
		root=root->left;
	}
}
cout << "Not found" << endl;
return root;
}

void successor(struct bst *root, int val){
struct bst *node=search(root,val);
if(node==NULL){
	cout << "Element does not exist" << endl;
	return ;
}
if(node->right!=NULL){
	node=node->right;
	while((node->left)!=NULL){
		node=node->left;
	}
	cout << "successor is : " << node->val << endl;
	return ;
}
else if(node->right==NULL){
	while(node!=NULL){
		if(node->val > val){
			cout << "Successor is : " << node->val << endl;
			return ;
		}
		node=node->parent;
	}
}
cout << "No successor" << endl;
}

int main(){
	struct bst *root=NULL;
	insert(&root,root,6);
	insert(&root,root,4);
	insert(&root,root,9);
	insert(&root,root,10);
	insert(&root,root,5);
	insert(&root,root,1);
	insert(&root,root,2);
	insert(&root,root,-1);
	insert(&root,root,100);
	successor(root,1000);
}