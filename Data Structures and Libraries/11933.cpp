#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	while(cin>>n && n)
	{
		int a=0, b=0;
		bool isEven = false;
		while(n & (-n))
		{
			int add = (n & (-n));
			if(!isEven)
				a+=add;
			else
				b+=add;
			isEven = (!isEven);
			n -= add;
		}
		cout << a << " " << b << endl;
	}
	return 0;
}
