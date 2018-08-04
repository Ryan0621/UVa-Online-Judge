#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> AdjList_G;
vector<int> dfs_num;

void dfs(int u){
	for(int j = 0 ; j < AdjList_G[u].size(); j++){
		int v = AdjList_G[u][j];
		if(dfs_num[v] == 0){
			dfs_num[v] = 1;
			dfs(v);
		}
	}
}

int main() {
	int n;
	while (cin>>n && n!=0) {
		vector<vector<int>>AdjList(n+1);
		dfs_num.resize(n+1);
		int i;
		while (cin>>i && i!=0) {
			int v;
			while (cin>>v && v!=0) {
				AdjList[i].push_back(v);
			}
		}
		int m;
		cin>>m;
		AdjList_G = AdjList;
		while (m--) {
			int s;
			cin>>s;
			dfs(s);
			vector<int> solution;
			for (int z=1; z<dfs_num.size(); z++){
				if(dfs_num[z] == 0){
					solution.push_back(z);
				}
				dfs_num[z] = 0;
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
