#include<cstdio>
#include<cstring>
int a[1000005],q[1000005],head,tail,ans[1000005];

int main()
{
	int n,k,i;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(q,0,sizeof q);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		head = tail = 0;
		for(i=1;i<=n;i++)
		{
			if(head <= tail && q[head] <= i - k) head++;
			while(head <= tail&&a[q[tail]] >= a[i]) tail--;
			q[++tail] = i;
			ans[i] = a[q[head]];
		}
		for(i=k;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
		memset(q,0,sizeof q);
		head = tail = 0;
		for(i=1;i<=n;i++)
		{
			if(head <= tail && q[head] <= i - k) head++;
			while(head <= tail&&a[q[tail]] <= a[i]) tail--;
			q[++tail] = i;
			ans[i] = a[q[head]];
		}
		for(i=k;i<=n;i++)
			printf("%d ",ans[i]);			
	}
	return 0;
}
