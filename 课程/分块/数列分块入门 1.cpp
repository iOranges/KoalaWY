#include<cmath>
#include<cstdio>
#define N 50005
#define SQRTN 251
#define min(x,y) ((x) < (y) ? (x) : (y))
int l[SQRTN],r[SQRTN],num[N],n;
long long v[N],lzy[SQRTN];

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
	r[i] = n;
	for(i = 1;i <= n;++ i)
		num[i] = (i - 1) / block + 1;
}

void add(int a,int b,long long c)
{
	register int i;
	int edge = min(r[num[a]],b);
	for(i = a;i <= edge;++ i)
		v[i] += c;
	if(num[a] != num[b])
		for(i = l[num[b]];i <= b;++ i)
			v[i] += c;
	for(i = num[a] + 1;i < num[b];++ i)
		lzy[i] += c;
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
			printf("%lld\n",v[b] + lzy[num[b]]);
		else
			add(a,b,1ll * c);
	}
	return 0;
}
