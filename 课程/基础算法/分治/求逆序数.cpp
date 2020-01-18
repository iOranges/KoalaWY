#include<cstdio>
int a[100100],b[100100];
long long ans=0;

void msort(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	msort(l,mid);
	msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=r)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			k++,i++;
		}
		else
		{
			b[k]=a[j];
			k++,j++;
			ans+=(long long)(mid-i+1);
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		k++,i++;
	}
	while(j<=r)
	{
		b[k]=a[j]; 
		k++,j++;
	}
	for(i=l;i<=r;i++)	a[i]=b[i];
	return;
}

int  main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	msort(0,n-1);
	printf("%lld",ans);	
	return 0;
}
