#include<cstdio>
#include<iostream>
using std::swap;
int a[200002];

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
	int n,same,cnt = 1,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1] = -1;
	qsort(1,n);
	same = a[1];
	for(i=2;i<=n+1;i++)
	{
		if(a[i]==same)
			cnt ++;
		else
		{
			printf("%d %d\n",same,cnt);
			same = a[i];
			cnt = 1; 
		}
	}
	return 0;
}

