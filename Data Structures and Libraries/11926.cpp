#include <iostream>
#include <bitset>
using namespace std;

int main() {
	// your code goes here
	int n, m;
	while (cin>>n>>m && !(n==0 && m==0))
	{
		bool check_m = 1, check_n = 1;
		bitset<1000001> calendar;
		while(n--)
		{
			int start, end;
			cin>>start>>end;
			for (int i=start; i<end; i++)
			{
				if(!calendar[i])
					calendar.set(i);
				else
				{
					check_n = 0;
					i=end;
				}
			}
		}
		while(m--)
		{
			int start, end, inter;
			cin>>start>>end>>inter;
			bool stop=0;
			while(check_m && !stop)
			{
				for (int i =start; i<end; i++)
				{
					if(i>1000000)
					{
						stop =1;
						continue;
					}
					if(!calendar[i])
						calendar.set(i);
					else
					{
						check_m = 0;
						i=end;
					}
				}
				start+=inter;
				end+=inter;
			}
		}
		if (check_m && check_n)
			cout << "NO CONFLICT\n";
		else
			cout << "CONFLICT\n";
	}
	return 0;
}
