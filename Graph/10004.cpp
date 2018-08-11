#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n;
  while (cin>>n && n!=0) {
    int l;
    cin>>l;
    vector<vector<int>> graph (n);
    vector<int> color (n, -1);
    for (int i=0; i<l; i++) {
      int a,b;
      cin>>a>>b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    color[0]=0;
    bool isBip = true;
    while (!q.empty() && isBip) {
      int u = q.front();
      q.pop();
      for (int j=0; j<graph[u].size(); j++) {
        int v = graph[u][j];
        if (color[v] == -1) {
          color[v] = 1 - color[u];
          q.push(v);
        }
        else {
          if (color[v] == color[u]) {
            isBip = false;
            break;
          }
        }
      }
    }
    if (isBip == true) cout<<"BICOLORABLE.";
    else cout<<"NOT BICOLORABLE.";
    cout<<endl;
  }
}
