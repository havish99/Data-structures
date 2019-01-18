# include <bits/stdc++.h>

# define INF 0x3F3F3F3F;

using namespace std;

int main(){
  int n,m,u,v;
  cin >> n >> m;

  vector <int> graph[n+1];
  for(int i=0;i<m;i++){
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int src;
  cin >> src;

  queue <int> a;
  bool visited[n+1]={};
  int distance[n+1]={};
  a.push(src);

  while(!a.empty()){
    int tmp = a.front();
    a.pop();
    visited[tmp]=1;
    // for(int child : graph[tmp])
    for(vector<int>::iterator it =graph[tmp].begin() ; it!=graph[tmp].end() ; it++){
      if(!visited[*it]){
      a.push(*it);
      distance[*it]=distance[tmp]+1;
      }
    }
  }
  for(int i=1;i<=n;i++){
    cout << "destination: " << i << "distance: " << distance[i] << endl;
  }
}
