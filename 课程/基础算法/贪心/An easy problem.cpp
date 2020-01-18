#include <iostream>
using namespace std;
int change(int n)
{
	int a[35],t=0,one = 0;
	while(n!=0)
	{
		a[t++]=n%2;
		n=n/2;
	}
	for(int i=0;i<t;i++)
		if(a[i]==1)	one++;
	return one;
}

int main()
{
	int n,n2;
	while(true)
	{
		cin >> n;
		if(n==0) break;
		n2 = change(n);
		for(int i=n+1;;i++)
			if(change(i)==n2)
			{
				cout << i << endl;
				break;
			}
	}
	return 0;
}
