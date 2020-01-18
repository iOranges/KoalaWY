#include<cstdio>
#include<iostream>
using std::swap;
int a[10001];

void qsort(int l,int r)    //r==right l==lift
{
	int i=l,j=r,mid=a[(l+r)/2];
	do{
		while(a[i]<mid)	i++; //在左边向右找比mid大的数 
		while(a[j]>mid)	j--; //在右边向左找比mid小的数 
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++,j--;  //从下一位找起 
		}
	}while(i<=j);
	if(l<j)	qsort(l,j);
	if(r>i)	qsort(i,r);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);	
	return 0;
}

