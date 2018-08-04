#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	while(n--) {
		int f;
		cin>>f;
		int premium = 0;
		while(f--) {
			int size, num, env;
			cin>>size>>num>>env;
			premium += size*env;
		}
		cout<<premium<<endl;
	}
	return 0;
}