#include<cstdio>
#include<iostream>
using std::swap;
int a[10001];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
