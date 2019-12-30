#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};


// bool move(int r, int c) {
// 	if (r>=0 && r<=R && c>=0 && c<=C && mineMap[r][c]!=-1 && mineMap[r][c]!=INF) {
// 		return true;
// 	}
// 	return false;
// }

int main() {
	int R, C;
	while (cin >> R >> C) {
		if (R==0 && C==0) {
			return 0;
		}
		int mineMap [1001][1001];
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				mineMap[i][j] = 999999999;
			}
		}
		int mineRowCount;
		cin >> mineRowCount;
		for (int i=0; i<mineRowCount; i++) {
			int rowNumber, bombCount;
			cin >> rowNumber >> bombCount;
			for (int j=0; j<bombCount; j++) {
				int colNumber;
				cin >> colNumber;
				mineMap[rowNumber][colNumber] = -1;
			}
		}
		int startRow, startCol, endRow, endCol;
		cin >> startRow >> startCol >> endRow >> endCol;

		queue<ii> q;
		q.push(ii(startRow, startCol));
		mineMap[startRow][startCol] = 0;
		while(!q.empty()) {
			ii u = q.front();
			q.pop();
			for (int i=0; i<4; i++) {
				int tr = u.first + dr[i];
				int tc = u.second + dc[i];
				if (tr>=0 && tr<R && tc>=0 && tc<C && mineMap[tr][tc]!=-1 && mineMap[tr][tc]==999999999) {
					mineMap[tr][tc] = mineMap[u.first][u.second] + 1;
					q.push(ii(tr, tc));
				}
			}
		}
		cout << mineMap[endRow][endCol] << endl;
	}
	return 0;
}
