#include<ctime>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define number(ch) (ch >= '0'&&ch <= '9') 
using std::sort;
using std::__gcd;
int col[50005],cnt[50005],n,m,block;
long long ans[50005][2],res;
struct query{
	int id,l,r;
	bool operator < (const query b) const{
		return (l / block) == (b.l / block) ? r < b.r : l < b.l;
	}
}q[50005];
template <typename e> inline void read(e &x)
{
	x = 0;char ch;
	ch = getc(stdin);
	while(!number(ch)) ch = getc(stdin);
	while(number(ch)) {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

template <typename e,typename ...h> inline void read(e &x,h &...y)
{
	read(x),read(y...);
 } 

int main()
{
	register int i,l = 1,r = 0;
	read(n,m);
	block = n / sqrt(m * 2 / 3);
	for(i = 1;i <= n;++ i)
		read(col[i]);
	for(i = 1;i <= m;++ i)
		read(q[i].l,q[i].r),q[i].id = i;
	sort(q + 1,q + m + 1);
	for(i = 1;i <= m;++ i)
	{
		int ql = q[i].l,qr = q[i].r;
		if(ql == qr)
		{
			ans[q[i].id][0] = 0,ans[q[i].id][1] = 1;
			continue;			
		} 
		while(l < ql)	res = res + 1ll - 2 * cnt[col[l]],cnt[col[l ++]] --;
		while(r > qr) 	res = res + 1ll - 2 * cnt[col[r]],cnt[col[r --]] --;
		while(l > ql)	res = res + 1ll + 2 * cnt[col[-- l]],cnt[col[l]] ++;
		while(r < qr)	res = res + 1ll + 2 * cnt[col[++ r]],cnt[col[r]] ++;
		long long all = (qr - ql) * 1ll * (qr - ql + 1);
		long long t = __gcd(res - (qr - ql + 1),all);
		ans[q[i].id][0] = (res - (qr - ql + 1)) / t,ans[q[i].id][1] = all / t;
	}
	for(i = 1;i <= m;++ i)
		printf("%lld/%lld\n",ans[i][0],ans[i][1]);
	return 0;
}
