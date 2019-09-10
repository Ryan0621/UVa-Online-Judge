#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int k, previous, track, trapped, visited[26] = {0};
vector<vector<int>> adjList(26);

void dfs(int u) {
	track++;
	for (int i=0; i<adjList[u].size(); i++) {
		int v = adjList[u][i];
		if (v == previous || visited[v]==1 ) continue;
		if (track == k) {
			visited[u] = 1;
			cout << char(u+'A') << ' ' ;
			track = 0;
		}
		trapped = v;
		previous = u;
		dfs(v);
		return;
	}
}

int main() {
	string input;
	while (cin >> input && input != "#") {
		char T, M;
		input = input.substr(0, input.size()-1);
		stringstream ss(input);
		string token;
		while (getline(ss, token, ';')) {
			for (int i=2; i<token.size(); i++) {
				adjList[token[0]-'A'].push_back(token[i]-'A');
			}
		}
		cin >> M >> T >> k;
		track = 0;
		previous = T-'A';
		trapped = M-'A';
		dfs(M-'A');
		cout << '/' << char(trapped+'A') << endl;
		for (int i=0; i<26; i++) {
			visited[i] = 0;
			adjList[i].clear();
		}

	}
	return 0;
}
