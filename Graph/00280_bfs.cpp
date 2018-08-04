#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs_num;

int main() {
	int n;
	while (cin>>n && n!=0) {
		vector<vector<int>>AdjList(n+1);
		bfs_num.resize(n+1);
		int i;
		while (cin>>i && i!=0) {
			int v;
			while (cin>>v && v!=0) {
				AdjList[i].push_back(v);
			}
		}
		int m;
		cin>>m;

		while (m--) {
			int s;
			cin>>s;
			queue<int> q;
			q.push(s);
			while(!q.empty()){
				int u = q.front();
				q.pop();

				for(int j = 0 ; j < AdjList[u].size(); j++){
					int v = AdjList[u][j];
					if( bfs_num[v] == 0){
						bfs_num[v] = 1;
						q.push(v);
					}
				}
			}


			vector<int> solution;
			for (int z=1; z<bfs_num.size(); z++){
				if(bfs_num[z] == 0){
					solution.push_back(z);
				}
				bfs_num[z] = 0;
			}
			cout<<solution.size();
			for(int z=0;z<solution.size();z++){
				cout<<" "<<solution[z];
			}
			cout<<endl;

		}


	}
	return 0;
}
