#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
vector<string> global;
int R, C;

int floodfill (int r, int c) {
  if (r<0 || r>=R || c<0 || c>=C) return 0;
  if (global[r][c] != 'W') return 0;
  int size = 1;
  global[r][c] = 'L';
  for (int x=0; x<8; x++) {
    size += floodfill(r+dr[x], c+dc[x]);
  }
  return size;
}

int main() {
  int tc;
  string tc_s;
  getline(cin, tc_s);
  tc = stoi(tc_s);
  cin.ignore();

  while(tc--) {
    vector<string> grid;
    string row;

    while (getline(cin, row, '\n') && row.size() != 0){
      if (row[0]=='L' || row[0]=='W'){
        grid.push_back(row);
      }
      else {
        global = grid;
        R = global.size();
        C = global[0].length();
        istringstream is(row);
        int i, j; is>>i>>j;
        cout<<floodfill(i-1,j-1)<<endl;
      }
    }
    if (tc) cout<<endl;
  }
}
