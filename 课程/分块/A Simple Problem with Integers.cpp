#include<cmath>
#include<cstdio>
#define N 100005
#define min(x,y) ((x) < (y) ? (x) : (y))
int l[505],r[505],num[N],n;
long long sum[505],lzy[505],v[N];

void build()
{
	register int i;
	int block = sqrt(n);
	int cnt = n / block;
	if(n % block) ++cnt;
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

void add(int a,int b,long long k)
{
	register int i;
	for(i = a;i <= min(r[num[a]],b);++ i)
		v[i] += k,sum[num[a]] += k;
	if(num[a] != num[b])
		for(i = l[num[b]];i <= b;++ i)
			v[i] += k,sum[num[b]] += k;
	for(i = num[a] + 1;i < num[b];++ i)
		lzy[i] += k;
}

long long query(int a,int b)
{
	register int i;
	long long ans = 0;
	for(i = a;i <= min(r[num[a]],b);++ i)
		ans += (v[i] + lzy[num[a]]);
	if(num[a] != num[b])
		for(i = l[num[b]];i <= b;++ i)
			ans += (v[i] + lzy[num[b]]);
	for(i = num[a] + 1;i < num[b];++ i)
		ans += (sum[i] + lzy[i] * (r[i] - l[i] + 1));
	return ans;
}

int main()
{
	char ch[10];
	register int i;
	int m,a,b;
	long long k;
	scanf("%d%d",&n,&m);
	for(i = 1;i <= n;++ i)
		scanf("%lld",&v[i]);
	build();
	for(i = 1;i <= m;++ i)
	{
		scanf("%s%d%d",ch,&a,&b);
		if(ch[0] == 'C')
		{
			scanf("%lld",&k);
			add(a,b,k);
		}
		else
			printf("%lld\n",query(a,b));
	}
	return 0;
}
