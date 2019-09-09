#include <iostream>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	int tc;
	cin >> tc;
	while (tc--) {
		int d, n;
		cin >> d >> n;
		int ratCount[1025][1025];
		memset(ratCount, 0, sizeof(ratCount));
		while (n--) {
			int x, y, z, x_start, y_start, x_end, y_end;
			cin >> x >> y >> z;
			x_start = max(x-d, 0);
			y_start = max(y-d, 0);
			x_end = min(x+d, 1024);
			y_end = min(y+d, 1024);
			for (int i = x_start; i <= x_end; i++) {
				for (int j = y_start; j <= y_end; j++) {
					ratCount[i][j] += z;
				}
			}
		}
		int x, y, temp_max=0;
		for (int i=0; i<1025; i++) {
			for (int j=0; j<1025; j++) {
				if (temp_max < ratCount[i][j]) {
					temp_max = ratCount[i][j];
					x = i;
					y = j;
				}
			}
		}
		cout << x << ' ' << y << ' ' << temp_max << endl;
	}
	return 0;
}
