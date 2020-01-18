#include<iostream>
using namespace std;
int a[100001];
void qsort(int l,int r)
{
	int i=l,j=r,mid=a[(l+r)/2];
	do{
		while(a[i]<mid)	i++;
		while(a[j]>mid)	j--;
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
	int n,i,j,m,k;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> a[i];
	cin >> m;
	qsort(1,n);
	for(i=1;i<=n;i++)
		for(j=n;j>i;j--)
		{
			k = a[i]+a[j];
			if(k<m) break;			
			else if(k==m)
			{
				cout << a[i] << " " << a[j]; 
				return 0;
			}			
		}
	cout << "No";
	return 0;
}
