#include <iostream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<int> group;

class UnionFind {
	private:
		vector<int> p, rank;
	public:
		UnionFind(int N) {
			rank.assign(N, 0);
			p.assign(N, 0);
			for(int i=0; i<N; i++) p[i] = i;
		}
		// int findSet(int i) {
		// 	if(p[i] == i) {
		// 		return p[i];
		// 	}
		// 	else {
		// 		p[i] = findSet(p[i]);
		// 		return p[i];
		// 	}
		// }

		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

		bool isSameSet(int i, int j) {
			return (findSet(i) == findSet(j));
		}
		void unionSet(int i, int j) {
			int x=findSet(i), y=findSet(j);
			if(!isSameSet(i, j)) {
				if(rank[x] > rank[y]) {
					p[y] = x;
					group[y] += group[x];
					group[x] = group[y];
 				}
				else {
					p[x] = y;
					group[x] += group[y];
					group[y] = group[x];
				}
				if(rank[x] == rank[y])
					rank[y]++;
			}
			cout << group[x] << endl;
		}
};

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		group.resize(n, 0);
		UnionFind uf(100000);
		map<string, int> mp;
		int counter = 0;
		while (n--) {
			string f1, f2;
			cin >> f1 >> f2;
			if (mp.find(f1) == mp.end()) {
				mp[f1] = counter++;
				group[mp[f1]] = 1;
			}
			if (mp.find(f2) == mp.end()) {
				mp[f2] = counter++;
				group[mp[f2]] = 1;
			}
			uf.unionSet(mp[f1], mp[f2]);
		}
	}
	return 0;
}
