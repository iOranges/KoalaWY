#include<cmath>
#include<cstdio>
#include<algorithm>
#define N 50005
#define SQRTN 501
#define min(x,y) ((x) < (y) ? (x) : (y))
using std::sort;
int l[SQRTN],r[SQRTN],num[N],n;
long long v[N],lzy[SQRTN],w[N];

template <typename e> void read(e &x)
{
	x = 0;char ch;int f = 1;
	ch = getchar();
	while(ch > '9'||ch < '0') {if(ch=='-') f = -1;ch = getchar();}
	while(ch >= '0'&&ch <= '9') {x = (x * 10) + (ch ^ 48);ch = getchar();}
	x  *= f;
}

template <typename e,typename ...h> void read(e& x,h& ...y)
{
	read(x),read(y...);
}

inline void memcpy(register int i,register int k)
{
	while(k)
	{
		w[i] = v[i];
		--k,++i;
	}
}

void build()
{
	register int i;
	int block = sqrt(n) / 2;
	int cnt = n / block;
	if(n % block) cnt ++;
	for(i = 1;i <= cnt;++ i)
	{
		l[i] = (i - 1) * block + 1;
		r[i] = i * block;
		sort(w + l[i],w + r[i] + 1);
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
	memcpy(l[num[a]],r[num[a]] - l[num[a]] + 1);
	sort(w + l[num[a]],w + r[num[a]] + 1);
	if(num[a] != num[b])
	{
		for(i = l[num[b]];i <= b;++ i)
			v[i] += c;	
		memcpy(l[num[b]],r[num[b]] - l[num[b]] + 1);
		sort(w + l[num[b]],w + r[num[b]] + 1);		
	}
	for(i = num[a] + 1;i < num[b];++ i)
		lzy[i] += c;
}

int query(int a,int b,long long c)
{
	register int i;
	int edge = min(r[num[a]],b),cnt = 0;
	for(i = a;i <= edge;++ i)
		if(v[i] + lzy[num[a]] < c)
			++ cnt;
	if(num[a] != num[b])
		for(i = l[num[b]];i <= b;++ i)
			if(v[i] + lzy[num[b]] < c)
				++cnt;
	for(i = num[a] + 1;i < num[b];++ i)
	{
		int L = l[i],R = r[i],mid,t = c - lzy[i];
		while(L <= R)
		{
			mid = (L + R) >> 1;
			if(t > w[mid])
				L = mid + 1;
			else
				R = mid - 1;
		}
		cnt += (r[i] - L + 1);
	}
	return cnt;
}

int main()
{
	register int i;
	int opt,a,b,c;
	read(n);
	for(i = 1;i <= n;++ i)
		read(v[i]);
	memcpy(1,n);
	build();
	for(i = 1;i <= n;++ i)
	{
		read(opt,a,b,c);
		if(opt)
			printf("%d\n",query(a,b,1ll * c * c));
		else
			add(a,b,1ll * c);
	}
	return 0;
}
