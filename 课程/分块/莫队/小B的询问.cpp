#include<cmath>
#include<cstdio>
#include<algorithm>
using std::sort;
int n,col[50005],block,cnt[50005];
long long res[50005],ans;
template <typename e> inline void read(e &x)
{
	x = 0;int f = 1;char ch;
	ch = getchar();
	while(ch > '9'||ch < '0') {if(ch == '-') f = -1;ch = getchar();}
	while(ch <= '9'&&ch >= '0') {x = (x * 10) + (ch ^ 48);ch = getchar();}
	x *= f;
}

template <typename e,typename ...h> void read(e &x,h &...y)
{
	read(x),read(y...);
}

struct query{
	int l,r,id;
	bool operator < (const query a) const{
		return (l/block) == (a.l/block) ? r < a.r : l < a.l;
	}
}q[50005];

inline void del(int x)
{
	ans -= cnt[x] * 2 - 1ll;
	-- cnt[x];
}

inline void add(int x)
{
	ans += cnt[x] * 2 + 1ll;
	++ cnt[x];
}

int main()
{
	int m,k,l = 1,r = 0;
	read(n,m,k);
	block = n / sqrt(m);
	register int i;
	for(i = 1;i <= n;++ i)
		read(col[i]);
	for(i = 1;i <= m;++ i)
	{
		read(q[i].l,q[i].r);
		q[i].id = i;
	}
	sort(q+1,q+m+1);
	for(i = 1;i <= m;++ i)
	{
		int ql = q[i].l,qr = q[i].r;
		while(l > ql)
			add(col[--l]);
		while(r < qr)
			add(col[++r]);
		while(l < ql)
			del(col[l++]);
		while(r > qr)
			del(col[r--]);
		res[q[i].id] = ans;
	}
	for(i = 1;i <= m;++ i)
		printf("%lld\n",res[i]);
	return 0;
}
