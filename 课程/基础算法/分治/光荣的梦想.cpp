#include<cstdio>
int a[10001],b[10001],cnt = 0;

int msort(int l,int r)
{
	if(l!=r)
	{
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
				cnt += (mid-i+1); 
				b[k]=a[j];
				k++,j++;
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
	}
}

int  main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	msort(1,n);
	printf("%d",cnt);
	return 0;
}
