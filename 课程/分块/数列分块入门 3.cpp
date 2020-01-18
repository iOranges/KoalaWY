#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
#define SQRTN 1001
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))
using std::sort;
using std::lower_bound;
int l[SQRTN],r[SQRTN],num[N],n,v[N],lzy[SQRTN],w[N];

void reset(int x)
{
	memcpy(w + l[x],v + l[x],sizeof(int) * (r[x] - l[x] + 1));
	sort(w + l[x],w + r[x] + 1);
} 

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
		sort(w + l[i],w + r[i] + 1);
	}
	r[cnt] = n;
	for(i = 1;i <= n;++ i)
		num[i] = (i - 1) / block + 1;	
}

void add(int a,int b,int c)
{
	register int i;
	int edge = min(r[num[a]],b);
	for(i = a;i <= edge;++ i)
		v[i] += c;
	reset(num[a]);
	if(num[a] != num[b])
	{
		for(i = l[num[b]];i <= b;++ i)
			v[i] += c;	
		reset(num[b]);	
	}
	for(i = num[a] + 1;i < num[b];++ i)
		lzy[i] += c;
}

int query(int a,int b,int c)
{
	register int i;
	int edge = min(r[num[a]],b),ans = -1;
	for(i = a;i <= edge;++ i)
		if(v[i] + lzy[num[a]] < c)
			ans = max(ans,v[i] + lzy[num[a]]);
	if(num[a] != num[b])
		for(i = l[num[b]];i <= b;++ i)
			if(v[i] + lzy[num[b]] < c)
				ans = max(ans,v[i] + lzy[num[b]]);
	for(i = num[a] + 1;i < num[b];++ i)
	{
		int mid = lower_bound(w + l[i],w + r[i] + 1,c - lzy[i]) - w;
		if(mid - 1 >= l[i])
			ans = max(ans,w[mid - 1] + lzy[i]);	
	}
	return ans;
}

int main()
{
	register int i;
	int opt,a,b,c;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		scanf("%d",&v[i]);
	memcpy(w + 1,v + 1,sizeof(int) * n);
	build();
	for(i = 1;i <= n;++ i)
	{
		scanf("%d%d%d%d",&opt,&a,&b,&c);
		if(opt)
			printf("%d\n",query(a,b,c));
		else
			add(a,b,c);
	}
	return 0;
}
