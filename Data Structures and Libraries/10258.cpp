#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct team {
  int contestant, problem=0, time=0, isSubmit=0;
} ;

bool compare (const team &a, const team &b) {
  if (a.problem != b.problem) return (a.problem > b.problem);
  if (a.time != b.time) return (a.time < b.time);
  return (a.contestant < b.contestant);
}

int main() {
  int T;
  cin>>T;
  cin.ignore();
  cin.ignore();
  while (T--) {
    int check [100][9] = {0};
    int isSolved[100][9] = {0};
    int finalScore[100][9] = {0};
    vector<team> teams (100);
    for (int j=0; j<100; j++) {
      teams[j].contestant = j+1;
    }
    string in;
    while (getline(cin, in) && in != "") {
      istringstream is(in);
      int contestant, problem, time;
      char L;
      is>>contestant>>problem>>time>>L;
      teams[contestant-1].isSubmit =1;
      if (check[contestant-1][problem-1] == 1) continue;
      if (L == 'C') {
        teams[contestant-1].problem +=1;
        finalScore[contestant-1][problem-1] += time;
        check[contestant-1][problem-1] = 1;
        isSolved[contestant-1][problem-1] = 1;
      }
      else if (L == 'I') {
        finalScore[contestant-1][problem-1] += 20;
      }
    }
    for(int i = 0; i<100;i++){
      for(int j = 0;j<9;j++){
        if(isSolved[i][j] == 1){
       		teams[i].time += finalScore[i][j];
       	}
       }
    }
    sort (teams.begin(), teams.end(), compare);
    for (int i=0; i<100; i++) {
      if (teams[i].isSubmit == 1) cout<<teams[i].contestant<<' '<<teams[i].problem<<' '<<teams[i].time<<endl;
    }
    if(T) cout<<endl;
  }
  return 0;
}
