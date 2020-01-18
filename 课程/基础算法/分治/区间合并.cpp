#include<iostream>
using namespace std;
int a[50001][2];
void qsort(int l,int r)
{
	int i=l,j=r,mid=a[(l+r)/2][0];
	do{
		while(a[i][0]<mid)	i++;
		while(a[j][0]>mid)	j--;
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
	int n,i,Begin,End;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> a[i][0] >> a[i][1];
	qsort(1,n);
	Begin = a[1][0];
	End = a[1][1];
	for(i=2;i<=n;i++)
	{
		if(a[i][0]>=Begin&&a[i][0]<=End)
		{
			if(a[i][1]>End)
				End = a[i][1];
		}
		else
		{
			cout << "no";
			return 0; 
		} 
	}
	cout << Begin << " " << End;
	return 0;
}
