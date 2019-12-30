#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

class UnionFind {
	private:
		vector<int> p, rank;
	public:
		UnionFind(int N) {
			rank.assign(N, 0);
			p.assign(N, 0);
			for(int i=0; i<N; i++) p[i] = i;
		}
		int findSet(int i) {
			if(p[i] == i) {
				return p[i];
			}
			else {
				p[i] = findSet(p[i]);
				return p[i];
			}
		}
		// int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

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
	int tc, counter=1;
	cin >> tc;
	while (tc--) {
		cout << "Case " << counter++ << ':' << endl;
		int cities;
		string input;
		cin >> cities;
		vector< pair<int, ii> > EdgeList;
		getline(cin, input);
		for (int i=0; i<cities; i++) {
			getline(cin, input);
			stringstream ss(input);

			vector<int> temp;
		    for (int j; ss >> j;) {
				temp.push_back(j);
		        if (ss.peek() == ',' || ss.peek() == ' ') {
		        	ss.ignore();
		        }
		    }
		    for (int j=0; j<temp.size(); j++) {
		    	if (temp[j] != 0)
		    		EdgeList.push_back( make_pair(temp[j], ii(i, j)) );
		    }
		}

		sort(EdgeList.begin(), EdgeList.end());
		int mst_cost = 0;
		UnionFind UF(cities);
		for (int i = 0; i < EdgeList.size(); i++) {
			pair<int, ii> front = EdgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)) {
				cout << char(front.second.first+'A') << '-' << char(front.second.second+'A') << ' ' << front.first << endl;
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);

			}
		}
	}
	return 0;
}
