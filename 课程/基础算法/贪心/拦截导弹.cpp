#include<iostream>
using namespace std;
int a[1005];
int main()
{
	int i=2,k=1,q,j,m;
	cin >> a[1];
	while(cin >> m) 
	{
		q=0;
		for(j=1;j<=k;j++)
			if(a[j]>=m)
				if(q == 0||a[j] < a[q])	q=j;
		if(q == 0)
		{
			++k;
			a[k] = m;
		}
		else a[q] = m;
		i++;
	}
	cout << k;
	return 0;
}
