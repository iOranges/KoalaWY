#include<iostream>
using namespace std;
int a[1005][2];
void qsort(int l,int r)
{
	int i=l,j=r,mid=a[(l+r)/2][1];
	do{
		while(a[i][1]<mid)	i++;
		while(a[j][1]>mid)	j--; 
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++,j--; 
		}
	}while(i<=j);
	if(l<j)	qsort(l,j);
	if(r>i)	qsort(i,r);
}

int main()
{
	int n,cnt=0,i,time=0;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> a[i][0] >> a[i][1];
	qsort(1,n);
	for(i=1;i<=n;i++)
	{
		if(a[i][0]>=time)
		{
			cnt++;
			time=a[i][1];
		}
	}
	cout << cnt;
	return 0;
 } 
