#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n,i,sum,max,a;
	while(cin >> n)
	{
		sum = 0,max = -1;
		for(i=1;i<=n;i++)
		{
			cin >> a;
			sum += a;
			if(a>max) max = a;
		}
		if(sum < 2*max) cout << setiosflags(ios::fixed) << setprecision(1) << 1.0*(sum-max);
		else cout << setiosflags(ios::fixed) << setprecision(1) << sum/2.0;
		cout << endl;
	
	}
	return 0;
 } 
