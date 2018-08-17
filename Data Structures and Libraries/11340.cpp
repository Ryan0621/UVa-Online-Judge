#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, K;
  cin>>N;
  while (N--) {
    cin>>K;
    int value [255] = {0};
    double price = 0;
    while (K--){
      char ch;
      int num;
      cin>>ch>>num;
      value[ch +128]=num;
    }
    int M;
    cin>>M;
    cin.ignore();
    while (M--) {
      string sentence;
      getline(cin, sentence);
      for (int i=0; i<sentence.size(); i++) {
        price += value[sentence[i]+128];
      }
    }
    printf("%.2f$\n", price/100);
  }
}
