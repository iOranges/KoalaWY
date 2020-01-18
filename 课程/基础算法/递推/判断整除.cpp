#include<cstdio>
int a[10002];
int main()
{
	int n,k,sum=0,i,j,sum1;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&a[i]);
	    sum+=a[i];
	}
	for(i=0;i<=n;i++)
	{
	    sum1=sum;
	    for(j=n;j>=i;j--)
	        sum1-=2*a[j];
	    if(sum1%k==0&&sum1!=0)
	    {
	        printf("YES");
	        return 0;
	    }
	}
	printf("NO");
	return 0;
}
