#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>> n;
	while (n--) {
		string S;
		cin>> S;
		if (S == "1" || S == "4" || S == "78") {
			cout<< "+"<< endl;
		}
		else if (S[S.length()-1] == '5' && S[S.length()-2] == '3') {
			cout<< "-"<< endl;
		}
		else if (S[0] == '9' && S[S.length()-1] == '4') {
			cout<< "*"<< endl;
		}
		else if (S.substr(0,3) == "190") {
			cout<< "?"<< endl;
		}
	}
	return 0;
}