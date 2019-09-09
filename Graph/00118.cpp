#include <iostream>
#include <map>
using namespace std;

int main() {
	int X_MAX, Y_MAX, x, y;
	char current_dir;
	char arr[4] = {'N', 'E', 'S', 'W'};
	int coord[51][51] = {0};
	map<char, int> dir = {
		{'N', 0},
		{'E', 1},
		{'S', 2},
		{'W', 3}
	};
	cin >> X_MAX >> Y_MAX;
	while (cin >> x >> y >> current_dir) {
		string instructions;
		cin >> instructions;
		bool isOff = 0;
		for (int i=0; i < instructions.length(); i++) {
			if (instructions[i] == 'F' && coord[x][y] == 1) {
				if (current_dir == 'N' && y+1 <= Y_MAX) {
					y++;
				}
				else if (current_dir == 'S' && y-1 >= 0) {
					y--;
				}
				else if (current_dir == 'E' && x+1 <= X_MAX) {
					x++;
				}
				else if (current_dir == 'W' && x-1 >= 0) {
					x--;
				}
			}
			else if (instructions[i] == 'F' && coord[x][y] == 0) {
				if (current_dir == 'N' && y+1 <= Y_MAX) {
					y++;
				}
				else if (current_dir == 'S' && y-1 >= 0) {
					y--;
				}
				else if (current_dir == 'E' && x+1 <= X_MAX) {
					x++;
				}
				else if (current_dir == 'W' && x-1 >= 0) {
					x--;
				}
				else {
					i = instructions.length();
					isOff = 1;
					coord[x][y] = 1;
				}
			}
			else if (instructions[i] == 'R') {
				current_dir = arr[(dir[current_dir] +1) %4];
			}
			else if (instructions[i] == 'L') {
				current_dir = arr[(dir[current_dir] -1+4) %4];
			}
		}
		cout << x << ' ' << y << ' ' << current_dir;
		if (isOff)
			cout << " LOST";
		cout << endl;
	}
	return 0;
}
