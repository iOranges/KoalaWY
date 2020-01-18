#include<cstdio>
#define N 100005
#define SIZE 1<<20
#define lson rt<<1
#define rson rt<<1|1
#define tol l,mid,lson
#define tor mid+1,r,rson
#define pushup(rt) t[rt] = (t[lson] + t[rson]) % p
int a[N];
long long t[N << 2],lzy[N << 2],tag[N << 2],p;
char buf[SIZE],*S = buf,*T = buf;
inline char gc() {return S == T && (T = (S = buf) + fread(buf,1,SIZE,stdin),S == T) ? -1 : *S++;}
#define getc(stdin) gc()
template <typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

void build(int l,int r,int rt)
{
	tag[rt] = 1;
	if(l == r)
	{
		t[rt] = a[l];
		return;
	} 
	int mid = (l + r) >> 1;
	build(tol),build(tor);
	pushup(rt);
}

inline void pushdown(int l,int r,int rt)
{
	if(tag[rt] != 1)
	{
		t[lson] = t[lson] * tag[rt] % p;
		t[rson] = t[rson] * tag[rt] % p;
		tag[lson] = tag[lson] * tag[rt] % p;
		lzy[lson] = lzy[lson] * tag[rt] % p;
		tag[rson] = tag[rson] * tag[rt] % p;
		lzy[rson] = lzy[rson] * tag[rt] % p;
		tag[rt] = 1;
	}
	if(lzy[rt])
	{
		int len = (r - l + 1) >> 1;
		t[lson] = (t[lson] + lzy[rt] * (r - l + 1 - len)) % p;
		t[rson] = (t[rson] + lzy[rt] * len) % p;
		lzy[lson] = (lzy[lson] + lzy[rt]) % p;
		lzy[rson] = (lzy[rson] + lzy[rt]) % p;
		lzy[rt] = 0;
	}
}

void update(int l,int r,int rt,int x,int y,int v,int k)
{
	if(x <= l&&r <= y)
	{
		if(k) t[rt] = (t[rt] + v * (r - l + 1)) % p,lzy[rt] = (lzy[rt] + v) % p;
		else 
			t[rt] = (t[rt] * v) % p,lzy[rt] = lzy[rt] * v % p,tag[rt] = tag[rt] * v % p;
		return ;
	} 
	pushdown(l,r,rt);
	int mid = (l + r) >> 1;
	if(y <= mid) update(tol,x,y,v,k);
	else if(x > mid) update(tor,x,y,v,k);
	else update(tol,x,mid,v,k),update(tor,mid+1,y,v,k);
	pushup(rt);
}

long long query(int l,int r,int rt,int x,int y)
{
	if(x <= l&&r <= y)
		return t[rt];
	pushdown(l,r,rt);
	int mid = (l + r) >> 1;
	if(y <= mid) return query(tol,x,y);
	else if(x > mid) return query(tor,x,y);
	else return (query(tol,x,mid) + query(tor,mid+1,y)) % p;
}

int main()
{
	int n,m,opt,x,y,z;
	register int i;
	read(n),read(m),read(p);
	for(i = 1;i <= n;++ i)
		read(a[i]);
	build(1,n,1);
	for(i = 1;i <= m;++ i)
	{
		read(opt),read(x),read(y);
		if(opt != 3)
		{
			read(z);
			update(1,n,1,x,y,z,opt - 1);
		}
		else
			printf("%lld\n",query(1,n,1,x,y));
	}
	return 0;
}
