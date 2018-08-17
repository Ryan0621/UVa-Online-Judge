#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<long long> num;
  int x;
  while (cin>>x) {
    num.push_back(x);
    sort(num.begin(), num.end());
    if (num.size()%2 != 0) {
      cout<<num[num.size()/2]<<endl;
    }
    else {
      cout<<(num[num.size()/2 -1] + num[num.size()/2])/2<<endl;
    }
  }
  return 0;
}
