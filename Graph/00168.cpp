#include <iostream>
#include <sstream>
using namespace std;

int k, track, visited, trapped;
int matrix[26][26] = {0};

void disconnect(int u) {
	for (int i=0; i<26; i++) {
		matrix[u][i] = 0;
		matrix[i][u] = 0;
	}
}

int findMinimum(int u) {
	int mini = 999999, v = -1;
	for (int i=0; i<26; i++) {
		if (matrix[u][i] < mini && matrix[u][i] && visited != i) {
			mini = matrix[u][i];
			v = i;
		}
	}
	return v;
}

void dfs(int u) {
	track++;
	int v = findMinimum(u);
	if (v != -1) {
		trapped = v;
		if (track == k) {
			disconnect(u);
			cout << char(u+'A') << ' ' ;
			track = 0;
		}
		visited = u;
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
				matrix[token[0]-'A'][token[i]-'A'] = i-1;
			}
		}
		cin >> M >> T >> k;
		track = 0;
		visited = T-'A';
		trapped = M-'A';
		dfs(M-'A');
		cout << '/' << char(trapped+'A') << endl;
		for (int i=0; i<26; i++) {
			for (int j=0; j<26; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	return 0;
}
