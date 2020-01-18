#include<cstdio>
#include<cstring>
#define max(x,y) (x)>(y)?(x):(y) 
int a[100005],q1[100005],q2[100005];

int main()
{
	int n,m,k,i,l1,r1,l2,r2;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		l1 = l2 = r1 = r2 = 0;
		memset(q1,0,sizeof q1);
		memset(q2,0,sizeof q2);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int pos = 0,len = 0;
		for(i=1;i<=n;i++)
		{
			while(l1<=r1&&a[q1[r1]] <= a[i]) r1 --;
			while(l2<=r2&&a[q2[r2]] >= a[i]) r2 --;
			q1[++r1] = q2[++r2] = i;
			while(a[q1[l1]] - a[q2[l2]] > k)
			{
				if(q1[l1] < q2[l2]) pos = max(pos,q1[l1]),l1++;
				else pos = max(pos,q2[l2]),l2++;
			}
			if(a[q1[l1]] - a[q2[l2]] >= m) 
				len = max(len,i - pos);			
		}
		printf("%d\n",len);
	}
	return 0;
}
