#include<cstdio>
#include<iostream>
using std::swap;
int a[10001];
int main()
{
	int n;bool ok;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=n-1;i>0;i--)
	{
		ok=false;
		for(int j=0;j<i;j++)
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				ok=true;
			}
		if(ok==false)	break;
	}
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
