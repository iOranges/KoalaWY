#include<cstdio>
#include<cstring>
#define abs(x) ((x)>0?(x):-(x))
#define max(x,y) (x)>(y)?(x):(y)
int q[150005];
long long f[150005][2];

int main()
{
	int n,m,d,head,tail,i,a,b,t1,t2 = 0,j;
	long long sum = 0;
	memset(f,0xcf,sizeof f);
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=n;i++)
		f[i][0] = 0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&t1);
		head = tail = 0;
		sum += b;
		memset(q,0,sizeof q);
		long long t = d * 1ll * (t1 - t2);
		for(j=1;j<=n;j++)
		{
			if(head <= tail&&1ll * j - t > q[head]) head ++;
			while(head <= tail&&f[j][(i-1)%2] >= f[q[tail]][(i-1)%2]) tail--;
			q[++tail] = j;
			f[j][i%2] = f[q[head]][(i-1)%2] - abs(a - j);
		}
		tail = head = 0;
		memset(q,0,sizeof q);
		for(j=n;j>=1;j--)
		{
			if(head <= tail&&1ll * j + t < q[head]) head++;
			while(head <= tail&&f[j][(i-1)%2] >= f[q[tail]][(i-1)%2]) tail--;
			q[++tail] = j;
			f[j][i%2] = max(f[j][i%2],f[q[head]][(i-1)%2] - abs(a - j));
		}
		t2 = t1;
	}
	long long ans = 0xcfcfcfcfcfcfcfcf;
	int o = m%2;
	for(i=1;i<=n;i++)
		ans = max(ans,f[i][o]);
	printf("%lld",sum + ans);
	return 0;
}
