#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main() {
  int N, count=1;
  while (cin>>N) {
    map<string, int> mp;
    vector<string> name;
    vector<vector<int>> graph(N);
    vector<int> in_deg(N, 0);
    for (int i=0; i<N; i++){
      string bev;
      cin>>bev;
      //cout<<bev<<endl;
      mp[bev] = i;
      name.push_back(bev);
    }
    int M;
    cin>>M;
    while (M--){
      string B1, B2;
      cin>>B1>>B2;
      graph[mp[B1]].push_back(mp[B2]);
      in_deg[mp[B2]]++;
    }
    priority_queue <int, vector<int>, greater<int> > que;
    for (int j=0; j<N; j++) {
      if (in_deg[j]==0) que.push(j);
    }
    cout<<"Case #"<<count<<": Dilbert should drink beverages in this order:";
    while (!que.empty()) {
      int u = que.top();
      que.pop();
      cout<<" "<<name[u];
      for (int k=0; k<graph[u].size(); k++) {
        in_deg[graph[u][k]]--;
        if (in_deg[graph[u][k]]==0) que.push(graph[u][k]);
      }
    }
    cout<<"."<<endl<<endl;
    count++;
  }
}
