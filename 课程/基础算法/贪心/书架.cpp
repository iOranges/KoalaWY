#include<iostream>
using namespace std;
int h[20001];
int main()
{
	int n,high,i,h2=0,k=0;
	cin >> n >> high;
	for(i=1;i<=n;i++)
		cin >> h[i];
	for(i=n;i>1;i--)
	{
		bool ok=true;
		for(int j=1;j<i;j++)
			if(h[j]<h[j+1])
			{
				swap(h[j],h[j+1]);
				ok=false;
			}
		if(ok==true) break;
	}
	for(i=1;i<=n;i++)
	{
		if(h2<high)
		{
			h2+=h[i];
			k++;
		}
	}	
	cout << k;
	return 0;
 } 
