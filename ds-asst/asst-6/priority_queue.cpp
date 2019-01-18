# include <bits/stdc++.h>

using namespace std;


struct node{
  int val;
  int weight;
};



class Priority_Queue{
public:
  node *a;
  int *pos;
  int size;
  int max_size;
  Priority_Queue(int k){
    size=0;
    max_size=k;
    a = new node[max_size];
    pos = new int[max_size+1];
  }
  int parent(int i){
    return (i-1)/2;
  }
  int left(int i){
    return 2*i+1;
  }
  int right(int i){
    return 2*i+2;
  }
  void createHeap();
  void swap(node *x,node *y);
  void deleteHeap();
  void heapify(int i);
  void insert(node val);
  node extractMin();
  void decreaseKey(int val,int weight);
  void print();
  bool isEmpty();
};

void Priority_Queue :: swap(node *x,node *y){
  node temp = *x;
  *x = *y;
  *y = temp;
}

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

void Priority_Queue :: deleteHeap(){
  delete[] a;
  delete[] pos;
  max_size=0;
  size=0;
  a = NULL;
  pos=NULL;
}

void Priority_Queue :: insert(node val){
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

bool Priority_Queue :: isEmpty(){
  if(size==0)
  return 1;
  else
  return 0;
}


void Priority_Queue :: decreaseKey(int vertex,int weight){
  int i = pos[vertex];
  a[i].weight=weight;
// cout << a[i].weight << " " << a[parent(i)].weight << endl;
  while(i!=0 && (a[i].weight<a[parent(i)].weight)){
    int temp = pos[a[i].val];
    pos[a[i].val]=pos[a[parent(i)].val];
    pos[a[parent(i)].val]=temp;
    swap(&a[i],&a[parent(i)]);
    i=parent(i);
}
}

node Priority_Queue :: extractMin(){
  if(size==1){
    size = size-1;
    return a[0];
  }
  node root = a[0];
  a[0]=a[size-1];
  pos[a[size-1].val]=0;
  size=size-1;
  heapify(0);
  return root;
}

void Priority_Queue :: print(){
  for(int i=0;i<size;i++){
    cout << "Value: " << a[i].val << " " << "Weight: " << a[i].weight << " " << "Position: " << pos[a[i].val] << endl;
  }
}

int main(){
  Priority_Queue p(10);
  node a[5]={{1,INT_MAX},{2,INT_MAX},{3,INT_MAX},{4,INT_MAX},{5,INT_MAX}};
  p.insert(a[0]);
  p.insert(a[1]);
  p.insert(a[2]);
  p.insert(a[3]);
  p.insert(a[4]);
  p.print();
  cout << endl;
  p.decreaseKey(2,0);
  p.print();
  // node temp=p.extractMin();
  p.deleteHeap();
  // cout << temp.val << endl;
  // p.print();
}
