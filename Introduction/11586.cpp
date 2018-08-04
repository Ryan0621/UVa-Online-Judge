#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin>>n;
	getchar();
	while (n--) {
		int M=0, F=0;
		string str;
		getline(cin, str);
		for (int i=0; i<str.length(); i++) {
			if (str[i] == 'M') M++;
			else if (str[i] == 'F') F++;
		}
		if (M==1 && F==1) cout<<"NO LOOP"<<endl;
		else if (M==F) cout<<"LOOP"<<endl;
		else cout<<"NO LOOP"<<endl;
	}
	return 0;
}