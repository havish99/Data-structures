# include <bits/stdc++.h>
using namespace std;

// the struct which holds the details of a node in the set
struct node{
  int val;
  int rank;
  node *parent;
};

// the class which holds the details of a Disjoint set 
class Disjoint_set{
public:
  node *p;
  int size;
  Disjoint_set(){
    p=NULL;
  }
  void createSet();
  void Union(int a,int b);
  void search(int a,int b);
  void rank(int a);
  int findset(int a);
  void delete_set();
};

// the method used to create n disjoint sets.
void Disjoint_set :: createSet(){
  int n = size;
  p = new node[n];
  for(int i=0;i<n;i++){
    p[i].parent=p+i;
    p[i].val=i+1;
    p[i].rank=1;
  }
}

// the method which deletes the set
void Disjoint_set :: delete_set(){
  delete[] p;
  p=NULL;
}

// the method which finds the representative element of a set.
int Disjoint_set :: findset(int a){
  node *tmp = p+a-1;
  // while loop breaks once we reach the representative element
  while(tmp->parent!=tmp){
    tmp=tmp->parent;
  }
  return tmp->val;
}

// the method which does union by rank heuristic
void Disjoint_set :: Union(int a,int b){
  int ra,rb;
  ra = findset(a)-1;
  rb = findset(b)-1;
  // ra and rb are the indices of representative elements of two sets
  // to make sure that union is not performed on two sets if they are not disjoint 
  if(ra==rb){
  	return;
  }
  // union by rank heuristic
  if(p[ra].rank > p[rb].rank){
    p[rb].parent = p+ra;
  }
  else if(p[ra].rank < p[rb].rank){
    p[ra].parent = p+rb;
  }
  // if both ranks are equal increment the rank of first one and attach the second one to the first one
  else if(p[ra].rank==p[rb].rank){
    p[ra].rank++;
    p[rb].parent = p+ra;
  }
}

// the method which checks if two elements are in same set
void Disjoint_set :: search(int a,int b){
  int val1 = findset(a);
  int val2 = findset(b);
  if(val1==val2){
    cout << 1 << endl;
  }
  else{
    cout << 0 << endl;
  }
}

// the method which prints the rank of an element
void Disjoint_set :: rank(int a){
  cout << p[a-1].rank << endl;
}

int main(){
	int digit,a=0;
  int flagN=0;
  int temp=0;
  int flagU=0;
  int flagR=0,tmp,firstelem=0;
  int flagP=0,flagS=0;
  int u,check=0;
  // flagN for creating new set
  // flagR for finding the rank of a node
  // flagU for performing union
  // flagP for checking if a pair belongs to same set
  // flagS for returning the representative element of a set
  // check for checking if the given input is a valid one(1 <= input <= n)
  // firstelem for storing the first number given two numbers as input
  Disjoint_set D;
  while((digit = fgetc(stdin)) != EOF){
  if(digit=='\n'){
    if(flagN==1){
      D.size=a;
      D.createSet();
      a=0;
      flagN=0;
    }
    else if(flagU==1){
      if(check==0){
      D.Union(u,a);
    }
      if(check==1){
        check=0;
      }
      a=0;
      flagU=0;
    }
    else if(flagP==1){
      if(check==0){
      D.search(u,a);
    }
      if(check==1){
        cout << -1 << endl;
        check=0;
      }
      a=0;
      flagP=0;
    }
    else if(flagR==1){
      if(check==0){
      D.rank(a);
    }
      if(check==1){
        cout << -1 << endl;
        check=0;
      }
      a=0;
      flagR=0;
    }
    else if(flagS==1){
      if(check==0){
      int ans = D.findset(a);
      cout << ans << endl;
    }
      if(check==1){
        cout << -1 << endl;
        check=0;
      }
      a=0;
      flagS=0;
    }
  }
  // if statements for various types of input.
  // for creating a new set 
  else if(digit=='N'){
    if(D.size!=0){
      // this is for just deleting the set if it was existing previously
      D.delete_set();
    }
    temp=0;
    flagN=1;
  }
  // for checking if two elements belong to the same set given they are valid
  else if(digit=='?'){
    flagP=1;
    firstelem=1;
  }
  // performs union if the two elements are valid elements
  else if(digit=='U'){
    flagU=1;
    firstelem=1;
  }
  // returns the representative element of a set given a valid number
  else if(digit=='S'){
    flagS=1;
  }
  // prints the rank of an element in the set
  else if(digit=='R'){
    flagR=1;
  }
  else if(a>0 && digit==' ' && (flagU!=0 || flagP!=0)){
    if(firstelem==1){
      u=a;
      a=0;
      firstelem=0;
    }
  }
  else{
    int k=digit-'0';
    if(k<10 && k>=0){
    a=10*a+k;
    if(a>D.size || a<1){
      check=1;
      a=0;
    }
  }
  }
}
	return 0;
}
