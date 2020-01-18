#include <bits/stdc++.h>
using namespace std;
int l,r,temp,ans;
int main()
{
	cin >> l >> r;
	for(int i=l;i<=r;i++)
	{
		int qwq=i; 
		while(qwq)
		{
			temp=qwq%10;
			if(temp==2)
			{
				ans++;	
			}	
			qwq/=10;
		}	
	}	
	cout << ans;
	return 0;	
}
