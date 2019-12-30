#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;

vector<vii> AdjList;
vector<int> taken;
priority_queue< pair<int, ii> > pq;

void process(int vtx) {
	taken[vtx] = 1;
	for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
		ii v = AdjList[vtx][j];
		if (!taken[v.first])
			pq.push(iii(-v.second, ii(-vtx, -v.first)));
	}
}

int main() {
	int tc, counter=1;
	cin >> tc;
	while (tc--) {
		cout << "Case " << counter++ << ':' << endl;
		int cities;
		string input;
		cin >> cities;
		AdjList.resize(cities);
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
		    	if (temp[j] != 0) {
		    		AdjList[i].push_back(make_pair(j, temp[j]));
		    	}
		    }
		}

		taken.assign(cities, 0);
		process(0);
		int mst = 0;
		while (!pq.empty()) {
			iii front = pq.top();
			pq.pop();
			int w = -front.first, u = -front.second.first, v = -front.second.second;
			if (!taken[v]) {
				cout << char(u+'A') << '-' << char(v+'A') << ' ' << w << endl;
				mst += w;
				process(v);
			}
		}
	}
	return 0;
}
