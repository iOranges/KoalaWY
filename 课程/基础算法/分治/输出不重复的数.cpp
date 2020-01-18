#include<cstdio>
#include<iostream>
using std::swap;
int a[100001],temp;
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
	int n,num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	qsort(1,n);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1])
			printf("%d ",a[i]);
	return 0;
}
