#include<cstdio>
const int max=101;
int a[max];   
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		a[m]++;
	}
	for(int i=0;i<=max;i++)
	{
		while(a[i]>0)
		{
			printf("%d ",i);
			a[i]--;
		}
	}
	return 0;
}

