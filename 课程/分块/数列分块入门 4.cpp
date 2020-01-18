#include<cmath>
#include<cstdio>
#define N 50005
#define SQRTN 251
#define min(x,y) ((x) < (y) ? (x) : (y))
int l[SQRTN],r[SQRTN],num[N],n;
long long v[N],lzy[SQRTN],sum[N];

void build()
{
	register int i;
	int block = sqrt(n);
	int cnt = n / block;
	if(n % block) cnt ++;
	for(i = 1;i <= cnt;++ i)
	{
		l[i] = (i - 1) * block + 1;
		r[i] = i * block;
	}
	r[cnt] = n;
	for(i = 1;i <= n;++ i)
	{
		num[i] = (i - 1) / block + 1;		
		sum[num[i]] += v[i];
	}
}

void add(int a,int b,long long c)
{
	register int i;
	int edge = min(r[num[a]],b);
	for(i = a;i <= edge;++ i)
		v[i] += c,sum[num[a]] += c;
	if(num[a] != num[b])
		for(i = l[num[b]];i <= b;++ i)
			v[i] += c,sum[num[b]] += c;
	for(i = num[a] + 1;i < num[b];++ i)
		lzy[i] += c;
}

long long query(int a,int b,long long mod)
{
	register int i;
	long long ans = 0;
	int edge = min(r[num[a]],b);
	for(i = a;i <= edge;++ i)
		ans = (ans + v[i] + lzy[num[a]]) % mod;
	if(num[a] != num[b])
		for(i = l[num[b]];i <= b;++ i)
			ans = (ans + v[i] + lzy[num[b]]) % mod;
	for(i = num[a] + 1;i < num[b];++ i)
		ans = (ans + (sum[i] % mod + lzy[i] * (r[i] - l[i] + 1) % mod) % mod) % mod;
	return ans;
}

int main()
{
	register int i;
	int opt,a,b,c;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		scanf("%lld",&v[i]);
	build();
	for(i = 1;i <= n;++ i)
	{
		scanf("%d%d%d%d",&opt,&a,&b,&c);
		if(opt)
			printf("%lld\n",query(a,b,c + 1ll));
		else
			add(a,b,1ll * c);
	}
	return 0;
}
