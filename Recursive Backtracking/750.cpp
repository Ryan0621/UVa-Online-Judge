#include <iostream>
#include <vector>
using namespace std;

vector<int> placement(8);
int row, col, counter;

bool place(int r, int c) {
	for (int prev=0; prev<c; prev++) {
		if (placement[prev]==r || abs(placement[prev]-r) == abs(prev-c)) {
			return false;
		}
	}
	return true;
}

void backtrack(int c) {
	if (c==8 && placement[col]==row) {
		printf("%2d     ", counter++);
		for (int i=0; i<placement.size(); i++) {
			cout << ' ' << placement[i]+1;
		}
		cout << endl;
	}
	for (int r=0; r<8; r++) {
		if (place(r, c)) {
			placement[c] = r;
			backtrack(c+1);
		}
	}
}

int main() {
	// your code goes here
	int tc;
	cin >> tc;
	while (tc--) {
		counter = 1;
		cin >> row >> col;
		row--; col--;
		for (int i=0; i<8; i++) {
			placement[i] = -1;
		}
		cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
		backtrack(0);
		if (tc) cout << endl;
	}
	return 0;
}
