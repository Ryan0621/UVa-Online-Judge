#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, pr;
	int count=1;
	while (cin>>n>>pr) 
	{
		if (n==0 && pr==0) break;
		if (count !=1) cout<<endl; 
		string req;
		getchar();
		while (n--)
		{
			getline(cin, req);
		}
		
		string chosen_company;
		int chosen_nreq = 0;
		double chosen_price = 0.0;
		while (pr--) 
		{
			string c;
			int nr;
			double p;
			getline(cin, c);
			cin>>p>>nr;
			string dummy;
			getchar();
			for (int i=0; i<nr; i++)  
			{
				getline(cin, dummy);
			}
			if (nr > chosen_nreq) 
			{
				chosen_nreq = nr;
				chosen_price = p;
				chosen_company = c;
			}
			else if (nr == chosen_nreq)
			{
				if (p<chosen_price) 
				{
					chosen_price = p;
					chosen_company = c;
				}
			}
		}
		cout<<"RFP #"<<count<<endl<<chosen_company<<endl;
		
		count++;
	}
	return 0;
}