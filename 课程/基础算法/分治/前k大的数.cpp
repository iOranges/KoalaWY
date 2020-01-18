#include<iostream>
using namespace std;
long long a[1000001];

void qsort(long l,long r)
{
	long long i=l,j=r,mid=a[(l+r)/2];
	do{
		while(a[i]>mid)	i++;
		while(a[j]<mid)	j--;
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
	long long n,k,i;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	cin >> k;
	qsort(0,n-1);
	for(i=0;i<k;i++)
		cout << a[i] << endl;
	return 0;
}

