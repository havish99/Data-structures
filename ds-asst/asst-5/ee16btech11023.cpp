``# include <bits/stdc++.h>

using namespace std;
// the adjacency list was implemented using an array of pointers each one pointing to the object of class Linked list
// the struct which holds the values of a node in the adjacency list
struct node{
  int val;
  node *next;
};

// class which holds details about the Queue. It was implemented using linked list
class Queue{
public:
  node *head;
  node *tail;
  Queue(){
    head=NULL;
    tail=NULL;
  }
  void enqueue(int val);
  int dequeue();
  bool isEmpty();
};

// the enqueue method which adds new element at the tail
void Queue :: enqueue(int val){
  if(head==NULL){
    head = new node;
    head->val=val;
    tail=head;
    head->next=NULL;
    return;
  }
  node *new_node = new node;
  new_node->val=val;
  new_node->next=NULL;
  tail->next=new_node;
  tail=new_node;
}

// the dequeue method which dequeues the front element of the queue and returns the value of that element
int Queue :: dequeue(){
  if(head==NULL){
    return -1;
  }
  node *tmp=head;
  head=head->next;
  int temp=tmp->val;
  delete tmp;
  tmp=NULL;
  return temp;
}

// the method which checks if Queue is empty. returns 1 if true.
bool Queue :: isEmpty(){
  if(head==NULL){
    return 1;
  }
  else{
    return 0;
  }
}

// the class which holds the details of a Linked list.
class Linked_list{
  public:
  node *head;
  node *tail;
  Linked_list(){
    head=NULL;
    tail=NULL;
  }
  void insert(int val);
  void insert_at_head(int val);
  void delete_Linked_list();
  void print_Linked_list();
};

// method which inserts elements at the head of a linked list
void Linked_list :: insert_at_head(int val){
  if(head==NULL){
    head = new node;
    head->val=val;
    head->next=NULL;
    return ;
  }
  node *new_node = NULL;
  new_node = new node;
  new_node->val=val;
  new_node->next=head;
  head=new_node;
}

//method which inserts elements at the end of a linked list
void Linked_list :: insert(int val){
  if(head==NULL){
    head = new node;
    head->val=val;
    tail=head;
    head->next=NULL;
    return;
  }
  node *new_node = new node;
  new_node->val=val;
  new_node->next=NULL;
  tail->next=new_node;
  tail=new_node;
}

// method which deletes elements of linked list
void Linked_list :: delete_Linked_list(){
  node *temp=head;
  node *next_node;
  while(temp!=NULL){
    next_node=temp->next;
    delete temp;
    temp=next_node;
  }
  head=NULL;
  tail=NULL;
}
// method which prints the nodes of a linked list
void Linked_list :: print_Linked_list(){
  node *temp = head;
  while(temp!=NULL){
    cout << temp->val << " ";
    temp=temp->next;
  }
  cout << endl;
}

// class which holds the details of a graph
class graph{
  public:
  Linked_list *a;
  int *parent;
  int size;
  graph(){
    a=NULL;
    parent=NULL;
    size=0;
  }
  void createGraph();
  void delete_graph();
  void shortest_path(int u, int v);
  void insert(int index,int val);
  void search(int v1,int v2);
  void bfs(int v1,bool flag);
};

// the method which creates a graph by initialising the number of vertices
void graph :: createGraph(){
  a = new Linked_list[size+1];
  for(int i=1;i<size+1;i++){
    a[i].head=NULL;
  }
 }

// the method which inserts new edges into the graph
void graph :: insert(int v1,int v2){
  // connection v1->v2(assuming that both direction edges are given as input)
  a[v1].insert(v2);
  // connection v2->v1
  // a[v2].insert(v1);
}

// the method which searches for a given edge in graph. Does this by searching for v2 in the adjacency list of v1
void graph :: search(int v1,int v2){
  node *temp=a[v1].head;
  while(temp!=NULL){
    if(temp->val == v2){
      cout << "1" << endl;
      return;
    }
    temp=temp->next;
  }
  cout << "0" << endl;
  return;
}

// the method which deletes the edges of the graph
void graph :: delete_graph(){
  for(int i=1;i<=size;i++){
    a[i].delete_Linked_list();
  }
  delete[] a;
  delete[] parent;
  size=0;
  a=NULL;
  parent=NULL;
}


// the method which performs BFS from a given vertex. The bfs is printed depending upon the flag argument(1 means no printing and 0 means printing)
void graph :: bfs(int v,bool flag){
  Queue temp;
  // initialising the status of all vertices. 0 means not visited, 1 means discovered and 2 means visited
  int *status = new int[size+1];
  for(int i=1;i<=size;i++){
    status[i]=0;
  }
  parent =new int[size+1];
  for(int i=1;i<size+1;i++){
    parent[i]=-1;
  }
  // the given vertex is enqueued
  temp.enqueue(v);
  while(!(temp.isEmpty())){
    // dequeued
    int u=temp.dequeue();
    node *tmp=a[u].head;
    while(tmp!=NULL){
      // all the elements in the adjacency list are discovered
      if(status[tmp->val]==0){
      temp.enqueue(tmp->val);
      status[tmp->val]=1;
      // the parent array is updated as per requirement
      parent[tmp->val]=u;
      }
      tmp=tmp->next;
    }
    // the status is changed to black since the element is dequeued(this prevents revisting the same element)
    status[u]=2;
    if(flag==0)
    cout << u << " ";
  }
  if(flag==0){
  cout << endl;
  }
  delete status;
}


// the method which prints the shortest path from source to destination
void graph :: shortest_path(int u,int v){
Linked_list tmp;
int temp=v;
// the below loop does back tracking
while(parent[temp]!=-1){
  // inserts every parent from destination to source into the linked list and pushes them to the end
  tmp.insert_at_head(temp);
  temp=parent[temp];
}
if(tmp.head==NULL){
  cout << "-1" << endl;
  return;
}
else{
  // effectively at the end we have source to destination path
  tmp.insert_at_head(u);
  tmp.print_Linked_list();
  tmp.delete_Linked_list();
}
}


int main(){
	int digit,a=0;
  int flagN=0;
  int temp=0;
  int flagB=0;
  int flagE=0,firstelem=0;
  int flagP=0,flagS=0,flag_bfs=0;
  int u=-1;
  graph G;
  // flagN takes care of creating a new graph
  // flagB takes care of doing BFS
  // flagE takes care of inserting edge into a graph
  // flagP takes care of printing the shortest path from source to destination
  // flagS takes care of checking if a given node is present in the graph
  // flag_bfs takes care of avoiding bfs for consecutive requests starting from same node
  // firstelem takes care of knowing the index to which the adjacency list will be inserted
  while((digit = fgetc(stdin)) != EOF){
  if(digit=='\n'){
    if(flagN==1){
      G.size=a;
      G.createGraph();
      a=0;
      flagN=0;
    }
    else if(flagE==1){
      G.insert(u,a);
      a=0;
      flagE=0;
    }
    else if(flagP==1){
      if(flag_bfs==1){
        // this is if bfs is not performed in the previous query
        G.bfs(u,1);
        flag_bfs=0;
      }
      G.shortest_path(u,a);
      a=0;
      flagP=0;
    }
    else if(flagS==1){
      G.search(u,a);
      a=0;
      flagS=0;
    }
    else if(flagB==1){
      u = a;
      G.bfs(u,0);
      a=0;
      flagB=0;
    }
  }
  else if(digit=='P'){
    flagP=1;
    firstelem=1;
  }
  else if(digit=='B'){
    flagB=1;
  }
  else if(digit=='N'){
    if(G.size!=0){
      // this is for just deleting the graph if it was existing previously
      G.delete_graph();
    }
    temp=0;
    flagN=1;
  }
  else if(digit=='E'){
    flagE=1;
    firstelem=1;
  }
  else if(digit=='?'){
    flagS=1;
    firstelem=1;
  }
  else if(a>0 && flagB==0 && digit==' ' && (flagE==1 || flagS==1 || flagP==1) && temp==0){
    if(firstelem==1){
      if(u!=a && flagP==1){
        flag_bfs = 1;
      }
      u=a;
      a=0;
      firstelem=0;
    }
    else{
    G.insert(u,a);
    a=0;
  }
  }
  else{
    int k=digit-'0';
    if(k<10 && k>=0){
    a=10*a+k;
  }
  }
}
  delete[] G.parent;
	return 0;
}
