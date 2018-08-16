#include <iostream>
#include <bitset>
using namespace std;

int main() {
  int n;
  while (cin>>n) {
    int arr [n];
    for (int i=0; i<n; i++) cin>>arr[i];
    bitset<3000> jolly;
    for (int j=0; j<n-1; j++) {
      int diff = abs(arr[j] - arr[j+1]);
      jolly[diff] = true;
    }
    bool check = true;
    for (int k=1; k<n; k++) {
      if (jolly[k] == false) {
        check = false;
        break;
      }
    }
    check ? cout<<"Jolly"<<endl : cout<<"Not jolly"<<endl;
  }
}
