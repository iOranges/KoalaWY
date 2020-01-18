#include<iostream>
#include<cstdio>
using namespace std;
double sum=0;
struct what
{
	long long t;
	int num;
}a[1005];
void qsort(int l,int r)
{
	int i=l,j=r,mid=a[(l+r)/2].t;
	do{
		while(a[i].t<mid)	i++;
		while(a[j].t>mid)	j--; 
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
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].t;
		a[i].num = i;
	}
	qsort(1,n);
	for(int i=1;i<=n;i++)
	{
		cout << a[i].num << " ";
		sum+=a[i].t*(n-i);
	}
	cout << endl; 
	double b = 1.0*sum/n;
	printf("%.2lf",b);
 } 
