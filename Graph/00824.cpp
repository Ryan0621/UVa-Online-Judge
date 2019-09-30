#include <iostream>
using namespace std;

int map[3][3];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int nextStep(int dir) {
	for (int i=0; i<8; i++) {
		int next_x = 1 + dx[(i + dir +5)%8];
		int next_y = 1 + dy[(i + dir +5)%8];
		if (map[next_x][next_y]) {
			return (i + dir +5) %8;
		}
	}
	return 0;
}

int main() {
	int x,y,d;
	while (cin >> x >> y >> d && x>=0) {
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				map[i][j] = 0;
			}
		}
		for (int i=0; i<8; i++) {
			int xi, yi, is_land;
			cin >> xi >> yi >> is_land;
			xi -= x-1;
			yi -= y-1;
			map[xi][yi] = is_land;
		}
		cout << nextStep(d) << endl;
	}
	return 0;
}


