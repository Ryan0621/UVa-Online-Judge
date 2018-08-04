#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		int arr[100];
		int p = 0;
		for (int i=0; i<n; i++) {
			string ins;
			cin>>ins;
			if (ins=="RIGHT") {
				arr[i]=1;
				p+=arr[i];
			}
			else if (ins=="LEFT") {
				arr[i]=-1;
				p+=arr[i];
			}
			else {
				cin>>ins;
				int k;
				cin>>k;
				arr[i]=arr[k-1];
				p+=arr[i];
			}
		}
		cout<<p<<endl; 
	}
	return 0;
}