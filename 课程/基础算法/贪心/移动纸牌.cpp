#include<iostream>
using namespace std;
int a[102],n,sum=0,i,j,cnt=0;
int main()
{
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	sum/=n;
	for(i=1;i<=n;i++) a[i]-=sum;
	i=1,j=n;
	while(a[i]==0&&i<n) i++;
	while(a[j]==0&&j>1) j--;
	while(i<j)
	{
		a[i+1]+=a[i];
		a[i]=0;
		cnt++;
		i++;
		while(a[i]==0&&i<n) i++;
	}
	cout << cnt << endl;
	return 0;
} 
