#include<cstdio>
#include<cstring>
#define min(x,y) (x)<(y)?(x):(y)
int f[1000005],q[1000005],head,tail;

int main()
{
	int T,n,k,x,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&x);
		memset(f,0x3f,sizeof f);
		memset(q,0,sizeof q);
		head = tail = 1;
		q[1] = 1;
		f[1] = 0;
		for(i=2;i<=n;i++)
		{
			if(head <= tail && q[head] < i - x) head ++;
			if(i % k == 0) f[i] = f[i / k] + 1;
			f[i] = min(f[i],f[q[head]] + 1);
			while(head <= tail&&f[q[tail]] >= f[i]) tail--;
			q[++tail] = i;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
