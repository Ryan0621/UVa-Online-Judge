#include <iostream>
#include <vector>
#include <algorithm>
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
			if(!isSameSet(i, j)) {
				int x=findSet(i), y=findSet(j);
				if(rank[x] > rank[y])
					p[y] = x;
				else
					p[x] = y;
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
};

int main() {
	// your code goes here
	int N, total_W;
	bool first = true;
	while (cin >> N) {
		if (!first) {
			cout << endl;
		}
		first = false;
		total_W = 0;
		UnionFind uf(N);
		vector<pair <int, ii>> EdgeList;
		for(int i=0; i<N-1; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			total_W += w;
		}
		cout << total_W << endl;
		total_W = 0;

		int K;
		cin >> K;
		for (int i=0; i<K; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			EdgeList.push_back(make_pair(w, ii(x, y)));
		}

		int M;
		cin >> M;
		for (int i=0; i<M; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			EdgeList.push_back(make_pair(w, ii(x, y)));
		}

		sort(EdgeList.begin(), EdgeList.end());
		for (int i=0; i<EdgeList.size(); i++) {
			pair<int, ii> front = EdgeList[i];
			if (!uf.isSameSet(front.second.first, front.second.second)) {
				total_W += front.first;
				uf.unionSet(front.second.first, front.second.second);
			}
		}
		cout << total_W << endl;
	}
	return 0;
}
