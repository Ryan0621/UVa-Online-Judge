#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	int count =1;
	while (cin>>str) {
		int n,i,j,a,b;
		cin>>n;
		cout<<"Case "<<count<<":"<<endl;
		while (n--) {
			cin>>i>>j;
			a = min(i,j);
			b = max(i,j);
			char first = str[a];
			bool check = true;
			for (int x=a; x<b+1; x++) {
				if (str[x] != first) check = false;
			}
			if (check) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		count ++;
	}
	return 0;
}