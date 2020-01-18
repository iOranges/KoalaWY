#include<cmath>
#include<cstdio>
long long sum[505],lazy[505],a[100005];
int n,m,l[505],r[505],num[100005],block,cnt;

void build()
{
	register int i,j;
	block = sqrt(n);
	cnt = n / block;
	if(n%block!=0) ++cnt;
	for(i=1;i<=cnt;++i)
	{
		l[i] = (i - 1) * block + 1;
		r[i] = i * block;
		for(j = l[i];j <= r[i];++ j)
			sum[i] += a[j];
	}
	r[cnt] = n;
	for(i=1;i<=n;++i)
		num[i] = (i - 1) / block + 1;
}

void add(int x,int y,long long k)
{
	register int i;
	if(num[x] == num[y])
	{
		for(i=x;i<=y;++i)
			a[i] += k;
		sum[num[x]] += k * (x - y + 1);
		return;
	}
	for(i = x;i <= r[num[x]];++ i)
		a[i] += k;
	sum[num[x]] += k * (r[num[x]] - x + 1);
	for(i = l[num[y]];i <= y;++ i)
		a[i] += k;
	sum[num[y]] += k * (y - l[num[y]] + 1);
	for(i = num[x] + 1;i < num[y];++ i)
		lazy[i] += k; 
}

long long query(int x,int y)
{
	long long ans = 0;
	register int i;
	if(num[x] == num[y])
	{
		for(i = x;i <= y;++ i)
			ans += a[i];
		ans += lazy[num[x]] * (x - y + 1);
		return ans;
	}
	for(i = x;i <= r[num[x]];++ i)
		ans += a[i];
	ans += lazy[num[x]] * (r[num[x]] - x + 1);
	for(i = l[num[y]];i <= y;++ i)
		ans += a[i];
	ans += lazy[num[y]] * (y - l[num[y]] + 1);
	for(i = num[x] + 1;i < num[y];++ i)
		ans += lazy[i] * (r[i] - l[i] + 1) + sum[i]; 	
	return ans;
}

int main()
{
	int i,opt,x,y;
	long long k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build();
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&opt,&x,&y);
		if(opt == 1)
		{
			scanf("%lld",&k);
			add(x,y,k); 
		}
		else
			printf("%lld\n",query(x,y));
	}
	return 0;
}
