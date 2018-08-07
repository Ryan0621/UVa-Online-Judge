#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
vector<string> grid;
int R, C;

int floodfill (int r, int c) {
  if (r<0 || r>=R || c<0 || c>=C) return 0;
  if (grid[r][c] != '1') return 0;
  int size = 1;
  grid[r][c] = '0';
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

  while (tc--){
    string row;
    while (getline(cin, row) && row.size()) {
      grid.push_back(row);
      //cout<<"row: "<<row<<endl;
    }
    //for (int x=0; x<grid.size(); x++) cout<<grid[x]<<endl;
    R=grid.size();
    C=grid[1].length();
    //cout<<R<<'a'<<endl;
    int largest_size=0;
    for (int a=0; a<R; a++){
      for (int b=0; b<C; b++){
        int current_size = floodfill(a,b);
        //cout<<current_size;
        if (current_size>largest_size) largest_size = current_size;
      }
    }
    cout<<largest_size<<endl;
    if (tc) cout<<endl;
    grid.clear();
  }
}
