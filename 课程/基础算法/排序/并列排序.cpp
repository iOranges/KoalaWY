#include<cstdio>
int a[10001],b[10001];

int msort(int l,int r)
{
	if(l!=r)
	{
		int mid=(l+r)/2;
		msort(l,mid);		//·ÖÁÑ×óÏî 
		msort(mid+1,r);		//·ÖÁÑÓÒÏî
		int i=l,j=mid+1,k=l;
		while(i<=mid && j<=r)
		{
			if(a[i]<=a[j])  //ÉıĞò 
			{
				b[k]=a[i];
				k++,i++;
			}
			else
			{
				b[k]=a[j];
				k++,j++;
			}
		}
		while(i<=mid)       //·ÀÖ¹Â©ÍøÖ®fish
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

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	msort(0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);	
	return 0;
}
