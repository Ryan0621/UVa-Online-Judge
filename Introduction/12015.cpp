#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	for (int n=1; n<T+1; n++) {
		string web[100];
		int rel[100];
		int max=0;
		
		for (int i=0; i<10; i++) {
			string site;
			cin>>site;
			web[i]=site;
			
			int x;
			cin>>x;
			rel[i]=x;
			
			if (x>max) max=x;	
		}
		cout<<"Case #"<<n<<":"<<endl;
		
		for (int i=0; i<10; i++) {
			if (rel[i]==max) {
				cout<<web[i]<<endl;
			}
		}
	}
	return 0;
}