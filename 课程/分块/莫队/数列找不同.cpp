#include<cmath>
#include<cstdio>
#include<algorithm>
using std::sort;
bool res[100005];
int a[100005],cnt[100005],n,block,ans;
struct question{
	int l,r,id;
	bool operator < (question a) const{
		return (l/block) == (a.l/block) ? r < a.r : l < a.l;
	}
}q[100005];

template <typename e> inline void read(e &x)
{
	x = 0;char ch;
	ch = getc(stdin);
	while(ch > '9'||ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0')	{x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

template <typename e,typename ...h> inline void read(e &x,h &...y)
{
	read(x),read(y...);
}

inline void del(int x)
{
	if(--cnt[x] == 0) 
		-- ans;
}

inline void add(int x)
{
	if(++cnt[x] == 1)
		++ ans;
}

int main()
{
	int m;
	register int i,l = 1,r = 0;
	read(n,m);
	block = n / sqrt(m); 
	for(i = 1;i <= n;++ i)
		read(a[i]);
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
			add(a[--l]);
		while(r < qr)
			add(a[++r]);
		while(l < ql)
			del(a[l++]);
		while(r > qr)
			del(a[r--]);
		if(ans == qr - ql + 1)
			res[q[i].id] = 1;
	}
	for(i = 1;i <= m;++ i)
		if(res[i])
			printf("Yes\n");
		else
			printf("No\n");
	return 0;
}
