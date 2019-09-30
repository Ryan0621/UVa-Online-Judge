#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> ii;

class UnionFind {
	private:
		vector<int> p, rank;
	public:
		UnionFind(int N) {
			rank.assign(N, 0);
			p.assign(N, 0);
			for(int i=0; i<N; i++) p[i] = i;
		}

		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

		bool isSameSet(int i, int j) {
			return (findSet(i) == findSet(j));
		}
		void unionSet(int i, int j) {
			int x=findSet(i), y=findSet(j);
			if(!isSameSet(i, j)) {
				if(rank[x] > rank[y]) {
					p[y] = x;
 				}
				else {
					p[x] = y;
				}
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
};

int main() {
	// your code goes here
	int TC;
	cin >> TC;
	bool first = true;
	while (TC--) {
		if(!first) cout<<endl;
		first = false;
		int M, N, total_w=0, counter=0;
		cin >> M >> N;
		UnionFind uf(M);
		vector<pair <int, ii>> EdgeList;
		map<string, int> mp;
		for (int i=0; i<N; i++){
			string c1, c2;
			int w;
			cin >> c1 >> c2 >> w;
			if (mp.find(c1) == mp.end()) {
				mp[c1] = counter++;
			}
			if (mp.find(c2) == mp.end()) {
				mp[c2] = counter++;
			}
			EdgeList.push_back(make_pair(w, ii(mp[c1], mp[c2])));
		}
		sort(EdgeList.begin(), EdgeList.end());

		int edgeCounter=0;
		for (int i=0; i<EdgeList.size(), edgeCounter < M-1; i++) {
			pair<int, ii> front = EdgeList[i];
			if (!uf.isSameSet(front.second.first, front.second.second)) {
				total_w += front.first;
				edgeCounter++;
				uf.unionSet(front.second.first, front.second.second);
			}
		}
		cout << total_w << endl;
	}
	return 0;
}
