#include<iostream>
using namespace std;
int a[100001],n,m;
int merge(int mid)
{
	int sum = 0,k = 1;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>mid)
		{
			sum = a[i];
			k++;
		}
	}
	if(k<=m) return 1;
	return -1;
}

int main()
{
	int i,k=1,Max=-1,sum=0,mid,j,num;
	cin >> n >> m;
	for(i=1;i<=n;i++) 
	{
		cin >> a[i];	
		sum+=a[i];
		if(a[i]>Max) Max = a[i];
	}
	i = Max,j = sum;
	while(i<=j)
	{
		mid = (i+j)/2;
		if(merge(mid) == 1) 
		{
			num = mid;
			j = num - 1;			
		}
		else i = mid + 1;
	}
	cout << num << endl;
	return 0;
}
