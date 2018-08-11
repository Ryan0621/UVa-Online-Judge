#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> dfs_check;
vector<int> topo;

void dfs(int u) {
  dfs_check[u]=1;
  for (int k=0; k<graph[u].size(); k++){
    int v = graph[u][k];
    if (dfs_check[v] == 0) dfs(v);
  }
  topo.push_back(u);
}

int main() {
  int m, n;
  while (cin>>n>>m && !(m==0 && n==0)) {
    graph.resize(n);
    dfs_check.resize(n, 0);
    for (int x=0; x<m; x++){
      int i, j;
      cin>>i>>j;
      graph[i-1].push_back(j-1);
    }
    for (int y=0; y<n; y++){
      if (dfs_check[y] == 0) dfs(y);
    }
    for (int z = n-1; z>=0; z--) {
      cout<<topo[z]+1;
      if (z) cout<<' ';
    }
    cout<<endl;
    graph.clear();
    dfs_check.clear();
    topo.clear();
  }
}
