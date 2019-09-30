#include <iostream>
#include <iomanip>
using namespace std;

double maps[502][502];
double dist[502];
int visited[502];
int cases = 1;

int main() {
  // your code goes here
  int n,m;
  while(cin>>n>>m && n){
    for(int i = 1; i <= n ; i++){
      for(int j = 1; j <= n; j++){
        maps[i][j] = 0;
      }
    }
    int a, b, l;
    while(m--){
      cin>>a>>b>>l;
      maps[a][b] = maps[b][a] = l;
    }

    for(int i = 1 ; i <= n; i++){
      dist[i] = 999999999;
      visited[i] = 0;
    }

    dist[1] = 0;
    int now = 1;
    visited[1] = 1;
    for(int i = 2; i <= n; i++){
      for(int j = 2; j <= n ; j++){
        if( maps[now][j] && dist[j] > dist[now] + maps[now][j] ){
          dist[j] = dist[now] + maps[now][j];
        }
      }

      double min = 999999999;
      for(int j = 1; j <=n ; j++){
        if(!visited[j] && dist[j] < min){
          min = dist[j];
          now = j;

        }
      }
      visited[now] = 1;

    }

    //
    double ans = dist[now];
    int domino2, flag = 0;
    for(int i = 1; i <=n; i++){
      for(int j = i+1; j <=n; j++){
        double timefraction = (maps[i][j] - dist[i] + dist[j] )/ 2.0;
        double meettime = dist[i] + timefraction;
        if(timefraction > 0 && timefraction < maps[i][j] && meettime > ans){
          ans = meettime;
          now = i;
          domino2 = j;
          flag = 1;
        }
      }
    }
    cout << fixed<< setprecision(1);
    cout<<"System #" << cases++<<endl;
    if(flag)
      cout<< "The last domino falls after " <<ans <<" seconds, between key dominoes "<<now<<" and "<<domino2<<"."<<endl;
    else{
      cout<< "The last domino falls after " <<ans <<" seconds, at key domino "<<now<<"."<<endl;
    }
    cout<<endl;
  }

  return 0;
}
