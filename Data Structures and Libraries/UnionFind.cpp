#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

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
	int TC;
	cin >> TC;
	string tmp;
	getline(cin, tmp);
	while (TC--) {
		int N;
		cin >> N;
		// cout<< "N: "<< N<<endl;
		UnionFind uf(N+1);
		cin.ignore();
		int correct=0, wrong=0;
		while (getline(cin, tmp)&& !tmp.empty()) {

			string buf;                 // Have a buffer string
		    stringstream ss(tmp);       // Insert the string into a stream

		    vector<string> tokens; // Create vector to hold our words

		    while (ss >> buf)
		        tokens.push_back(buf);

			int c1 = stoi(tokens[1]), c2= stoi(tokens[2]);
			string q = tokens[0];
			// cout << q << " " << c1 << " " << c2 << endl;

			if (q == "c") {
				uf.unionSet(c1, c2);
			}
			else {
				bool sameSet = uf.isSameSet(c1, c2);
				if (sameSet)
					correct++;
				else
					wrong++;
			}
		}
		cout << correct << "," << wrong << endl;
		if (TC) cout << endl;
	}
	return 0;
}
