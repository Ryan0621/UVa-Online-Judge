#include <iostream>
#include <vector>
using namespace std;

vector<int> cd, ans, temp_ans;
int num_track, N, temp_max;

void bt(int index, int current) {
	if (current > temp_max) {
		temp_max = current;
		temp_ans = ans;
	}
	for (int i=index; i<num_track; i++) {
		if (current+cd[i] <= N) {
			ans.push_back(cd[i]);
			bt(i+1, current+cd[i]);
			ans.pop_back();
		}
	}
	return;
}

int main() {
	// your code goes here
	while (cin >> N) {
		cin >> num_track;
		for (int i=0; i<num_track; i++) {
			int track;
			cin >> track;
			cd.push_back(track);
		}

		ans.clear();
		temp_ans.clear();
		temp_max=0;
		bt(0, 0);
		for (int i=0; i < temp_ans.size(); i++) {
			cout << temp_ans[i] << ' ';
		}
		cout << "sum:" << temp_max << endl;

		cd.clear();
	}
	return 0;
}
