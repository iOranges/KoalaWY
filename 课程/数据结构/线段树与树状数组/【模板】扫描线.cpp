#include<cstdio>
#include<algorithm>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define N 100005
using namespace std;
int n,x[N << 1],tot;
struct ScanLine{
	int l,r,h,w;
	bool operator < (const ScanLine b) const{
		return h < b.h;
	}
}s[N << 1];
struct node{
	int l,r,len,cnt;
}t[N << 4];
template <typename e>inline void read(e &x)
{
	char ch;x=0;
	ch = getc(stdin);
	while(ch>'9'||ch<'0') ch = getc(stdin);
	while(ch<='9'&&ch>='0') {x = (x<<1) + (x<<3) + (ch^48);ch = getc(stdin);}
}

void build(int rt,int l,int r)
{
	t[rt].l = l,t[rt].r = r;
	t[rt].len = t[rt].cnt = 0;
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	build(lson,l,mid);
	build(rson,mid + 1,r);
}

inline void pushup(int rt)
{
	int l = t[rt].l,r = t[rt].r;
	if(t[rt].cnt)
		t[rt].len = x[r + 1] - x[l];
	else
		t[rt].len = t[lson].len + t[rson].len; 
}

void update(int rt,int L,int R,int v)
{
	int l = t[rt].l,r = t[rt].r;
	if(L >= x[r + 1]||R <= x[l])
		return;
	if(L <= x[l]&&R >= x[r + 1])
	{
		t[rt].cnt += v; 
		pushup(rt);
		return;
	}
	update(lson,L,R,v); 
	update(rson,L,R,v); 
	pushup(rt);
}

int main()
{
	long long ans = 0;
	register int i;
	int x1,x2,y1,y2;
	read(n);
	for(i = 1;i <= n;++ i)
	{
		read(x1),read(y1),read(x2),read(y2);
		s[i * 2 - 1].l = s[i * 2].l = x1;
		s[i * 2 - 1].r = s[i * 2].r = x2;
		s[i * 2 - 1].h = y1,s[i * 2].h = y2;
		s[i * 2 - 1].w = 1,s[i * 2].w = -1;
		x[i * 2 - 1] = x1,x[i * 2] = x2; 
	}
	n <<= 1;
	sort(x + 1,x + n + 1);
	sort(s + 1,s + n + 1);
	tot = unique(x + 1,x + n + 1) - x - 1;
	build(1,1,tot - 1);
	for(i = 1;i < n;++ i)
	{
		update(1,s[i].l,s[i].r,s[i].w);
		ans = ans + (s[i + 1].h - s[i].h) * 1ll * t[1].len;
	}
	printf("%lld",ans);
	return 0;
}
