#include<cstdio>
#include<iostream>
using std::swap;
int a[10001];
int main()
{
	int n,j,k,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		for(j=i-1;j>=0;j--)
			if(a[i]>a[j])	break;
		if(j!=i-1)
		{
			int temp=a[i];
			for(k=i-1;k>j;k--)
				a[k+1]=a[k];
			a[k+1]=temp;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
