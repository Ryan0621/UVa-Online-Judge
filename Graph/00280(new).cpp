#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjList;
vector<int> visited;

void dfs(int u) {
	visited[u] = 1;
	for (int i=0; i<adjList[u].size(); i++) {
		int v = adjList[u][i];
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main() {
	int vertexSize;
	while (cin >> vertexSize && vertexSize) {
		adjList.resize(vertexSize);
		visited.resize(vertexSize);
		int u;
		while (cin >> u && u) {
			int v;
			cout << "u: " << u << endl;
			while (cin >> v && v) {
				cout << "vertex " << v << endl;
				adjList[--u].push_back(--v);
			}
		}
	}
	int numStarting;
	cin >> numStarting;
	for (int i=0; i<numStarting; i++) {
		int start;
		cin >> start;
		dfs(--start);
		for (int j=0; j<visited.size(); j++) {
			cout << visited[j];
		}
	}
	return 0;
}
