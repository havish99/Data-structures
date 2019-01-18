# include <bits/stdc++.h>

using namespace std;
// the adjacency list was implemented using an array of pointers each one pointing to the object of class Linked list
// the struct which holds the values of a node in the adjacency list
struct node{
  int val;
  int weight;
  node *next;
};
// the struct which holds the details of a node in Min Heap. Stores the vertex value and the cost to go to that vertex
struct node_minheap{
  int val;
  int weight;
};

// the class which holds the details of a Linked list.
class Linked_list{
  public:
  node *head;
  node *tail;
  Linked_list(){
    head=NULL;
    tail=NULL;
  }
  void insert(int val,int weight);
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
void Linked_list :: insert(int val,int weight){
  if(head==NULL){
    head = new node;
    head->val=val;
    head->weight = weight;
    tail=head;
    head->next=NULL;
    return;
  }
  node *new_node = new node;
  new_node->val=val;
  new_node->weight = weight;
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

// class which holds the details of a Priority Queue
class Priority_Queue{
public:
  // the minheap is a fixed array of size=max_size(the number of vertices in this case)
  node_minheap *a;
  // pos is the array which stores the position of a vertex in the min heap.
  int *pos;
  // the current size of minheap. This is changed whenever new node is inserted or the minimum is extracted.
  int size;
  // the maximum size of minheap. This is equal to number of vertices.
  int max_size;
  // the constructor which is called when heap is initialised. It sets max size to number of vertices and size to 0
  Priority_Queue(int k){
    size=0;
    max_size=k;
    a = new node_minheap[max_size];
    pos = new int[max_size+1];
  }
  // method which returns the index of parent of a node in min heap
  int parent(int i){
    return (i-1)/2;
  }
  // method which returns the index of left child of a node in min heap
  int left(int i){
    return 2*i+1;
  }
  // method which returns the index of right child of a node in min heap
  int right(int i){
    return 2*i+2;
  }
  void swap(node_minheap *x,node_minheap *y);
  void deleteHeap();
  void heapify(int i);
  void insert(node_minheap val);
  node_minheap extractMin();
  void decreaseKey(int val,int weight);
  void print();
  bool isEmpty();
};

// method used to swap the nodes in min heap
void Priority_Queue :: swap(node_minheap *x,node_minheap *y){
  node_minheap temp = *x;
  *x = *y;
  *y = temp;
}
// method used to check if the heap condition is satisfied. It assumes that the sub tree is heapified(called recursively to heapify the full heap)
void Priority_Queue :: heapify(int i){
  int l = left(i);
  int r = right(i);
  int small = i;
  if(l < size && a[l].weight<a[small].weight){
    small = l;
  }
  if(r < size && a[r].weight<a[small].weight){
    small = r;
  }
  if(small != i){
    int temp = pos[a[i].val];
    pos[a[i].val]=pos[a[small].val];
    pos[a[small].val]=temp;
    swap(&a[small],&a[i]);
    heapify(small);
  }
}
// method used to delete the min heap
void Priority_Queue :: deleteHeap(){
  delete[] a;
  delete[] pos;
  max_size=0;
  size=0;
  a = NULL;
  pos=NULL;
}
// method used to insert a new node into minheap. It checks only with the parents if the heap condition is satisfied.  If not swap is called iteratively
void Priority_Queue :: insert(node_minheap val){
  if(size == max_size){
    return;
  }
  size = size+1;
  int i=size-1;
  pos[val.val]=i;
  a[i]=val;
  while(i!=0 && (a[i].weight<a[parent(i)].weight)){
    int temp = pos[a[i].val];
    pos[a[i].val]=pos[a[parent(i)].val];
    pos[a[parent(i)].val]=temp;
    swap(&a[i],&a[parent(i)]);
    i=parent(i);
  }
}
// method used to check if the Priority Queue is empty.
bool Priority_Queue :: isEmpty(){
  if(size==0)
  return 1;
  else
  return 0;
}
// method used to change the value of a node in the minheap
void Priority_Queue :: decreaseKey(int vertex,int weight){
  int i = pos[vertex];
  a[i].weight=weight;
  while(i!=0 && (a[i].weight<a[parent(i)].weight)){
  int temp = pos[a[i].val];
  pos[a[i].val]=pos[a[parent(i)].val];
  pos[a[parent(i)].val]=temp;
  swap(&a[i],&a[parent(i)]);
  i=parent(i);
  }
}
// method used to extract the minimum element in heap. Heapify is called at the root to make sure that the heap condition is satisfied.
node_minheap Priority_Queue :: extractMin(){
  if(size==1){
    size = size-1;
    return a[0];
  }
  node_minheap root = a[0];
  a[0]=a[size-1];
  pos[a[size-1].val]=0;
  size=size-1;
  heapify(0);
  return root;
}
// method used to print the contents of min heap
void Priority_Queue :: print(){
  for(int i=0;i<size;i++){
    cout << "Value: " << a[i].val << " " << "Weight: " << a[i].weight << " " << "Position: " << pos[a[i].val] << endl;
  }
}

// class which holds the details of a graph
class graph{
  public:
  Linked_list *G;
  int *parent;
  int *distance;
  int size;
  graph(){
    G=NULL;
    parent=NULL;
    size=0;
  }
  void createGraph();
  void delete_graph();
  void insert(int index,int val,int weight);
  void search(int v1,int v2);
  void Dijkstra(int u,int flag);
  void shortest_path(int u,int v);
};

// the method which creates a graph by initialising the number of vertices
void graph :: createGraph(){
  G = new Linked_list[size+1];
  distance = new int[size+1];
  parent = new int[size+1];
  for(int i=1;i<size+1;i++){
    G[i].head=NULL;
    // all parents are initialised to -1
    parent[i]=-1;
    // distance initialisation
    distance[i]=INT_MAX;
  }
 }

// the method which inserts new edges into the graph
void graph :: insert(int v1,int v2,int weight){
  G[v1].insert(v2,weight);
}

// the method which searches for a given edge in graph. Does this by searching for v2 in the adjacency list of v1
void graph :: search(int v1,int v2){
  node *temp=G[v1].head;
  while(temp!=NULL){
    if(temp->val == v2){
      cout << temp->weight << endl;
      return;
    }
    temp=temp->next;
  }
  cout << "-1" << endl;
  return;
}

// the method which deletes the edges of the graph
void graph :: delete_graph(){
  for(int i=1;i<=size;i++){
    G[i].delete_Linked_list();
  }
  delete[] G;
  delete[] parent;
  size=0;
  G=NULL;
  parent=NULL;
}


// the method which computes all shortest paths using Dijkstra algorithm. Uses a Priority Queue(implemented using a min heap). Iteratively extracts min
// until the heap is empty. Initialises all the distances to INT_MAX and updates them as per the traversal. the condition d(v) > d(u)+weight(u,v) is used for this purpose.
void graph :: Dijkstra(int u,int flag){
  // flag is to check the condition for printing the dijkstra traversal.
  node_minheap temp;
  Priority_Queue p(size);
  for(int i=1;i<=size;i++){
    // all parents are initialised to -1
    parent[i]=-1;
    // distance initialisation
    distance[i]=INT_MAX;
    temp.val = i;
    temp.weight = distance[i];
    p.insert(temp);
  }
  distance[u]=0;
  p.decreaseKey(u,distance[u]);
  while(!(p.isEmpty())){
    temp = p.extractMin();
    int val = temp.val;
    node *tmp = G[val].head;
    while(tmp!=NULL){
      // the condition to check for decreasing the distance of a node
      if(distance[tmp->val] > distance[val]+tmp->weight){
        distance[tmp->val] = distance[val] + tmp->weight;
        p.decreaseKey(tmp->val,distance[tmp->val]);
        parent[tmp->val]=val;
      }
      tmp=tmp->next;
    }
    if(flag!=1){
    if(distance[val] == INT_MAX)
    cout << val << " " << -1 << endl;
    else
    cout << val << " " << distance[val] << endl;
    }
  }
}


// the method which prints the shortest path from source to destination
void graph :: shortest_path(int u,int v){
Linked_list tmp;
int temp=v;
// if the distance of source is not zero means dijksta algorithm was not performed on source vertex.
if(distance[u]!=0){
  Dijkstra(u,1);
}
if(distance[v]==INT_MAX){
  cout << "-1" << endl;
  return;
}
// the below loop does back tracking
while(parent[temp]!=-1){
  // inserts every parent from destination to source into the linked list and pushes them to the end
  tmp.insert_at_head(temp);
  temp=parent[temp];
}
  // effectively at the end we have source to destination path
  cout << distance[v] << " ";
  tmp.insert_at_head(u);
  tmp.print_Linked_list();
  tmp.delete_Linked_list();
}

int main(){
	int digit,a=0;
  int flagN=0;
  int temp=0;
  int flagB=0,flagD=0;
  int flagE=0,tmp,firstelem=0;
  int flagP=0,flagS=0;
  int u=-1;
  graph G;
  // flagD takes care of running Dijkstra algorithm
  // flagN takes care of creating a new graph
  // flagE takes care of inserting edge into a graph
  // flagP takes care of printing the shortest path from source to destination
  // flagE takes 0,1,2 values. 0 means it is not an edge. 1 means it is the vertex and 2 means it is a weight
  // flagS takes care of checking if a given node is present in the graph
  // firstelem takes care of knowing the index to which the adjacency list will be inserted
  while((digit = fgetc(stdin)) != EOF){
  if(digit=='\n'){
    if(flagN==1){
      G.size=a;
      G.createGraph();
      a=0;
      flagN=0;
    }
    else if(flagE==2){
      G.insert(u,tmp,a);
      a=0;
      flagE=0;
    }
    else if(flagS==1){
      G.search(u,a);
      a=0;
      flagS=0;
    }
    else if(flagP==1){
      G.shortest_path(u,a);
      a=0;
      flagP=0;
    }
    else if(flagD==1){
      G.Dijkstra(a,0);
      a=0;
      flagD=0;
    }
  }
  else if(digit=='P'){
    flagP=1;
    firstelem=1;
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
  else if(digit=='D'){
    flagD=1;
  }
  else if(a>0 && digit==' ' && (flagE!=0 || flagS==1 || flagP==1) && temp==0 && flagD==0){
    if(firstelem==1){
      u=a;
      a=0;
      firstelem=0;
    }
    else{
    if(flagE==1){
    tmp = a;
    flagE=2;
    a=0;
  }
    else if(flagE=2){
      G.insert(u,tmp,a);
      flagE=1;
      a=0;
    }
  }
  }
  else{
    int k=digit-'0';
    if(k<10 && k>=0){
    a=10*a+k;
  }
  }
}
	return 0;
}