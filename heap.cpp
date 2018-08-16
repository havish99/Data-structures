#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int a[],int n){
	for(int i=0;i<n;i++){
		cout << a[i] << endl;
	}
}

void min_heap(int a[],int i,int n){
//cout << i << endl;
int left=2*i+1;
int right=2*i+2;
int smallest=i;
//cout << n << endl;
if(left<n && a[left]<a[smallest])
	smallest=left;
if(right<n && a[right]<a[smallest])
	smallest=right;
if(smallest != i){
	int temp=a[smallest];
	a[smallest]=a[i];
	a[i]=temp;
}
else{
	return ;
}
min_heap(a,smallest,n);
}

void create_heap(int a[],int n){
int i = (n/2)-1;
while(i>=0){
	min_heap(a,i,n);
	i=i-1;
}
}




int main(){
	int a[7]={100,4,3,5,-1,-9,11};
	create_heap(a,7);
	//print(a,8);
	print(a,7);
}
