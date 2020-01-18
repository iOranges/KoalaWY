#include<cstdio>
#define N 100010
#define swap(x,y) (x ^= y ^= x ^= y)
int org[N],son[N][2],w[N],siz[N],fa[N],tag[N],n,cnt;
template <typename e> inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

#define root son[0][1]
inline void pushup(int rt)
{
	siz[rt] = siz[son[rt][0]] + siz[son[rt][1]] + 1;
}

inline int get_id(int rt)
{
	return son[fa[rt]][0] == rt ? 0 : 1;
}

inline void connect(int rt,int f,int id)
{
	fa[rt] = f;
	son[f][id] = rt;
}

int build(int l,int r,int f)
{
	if(l > r) return 0;
	int mid = (l + r) >> 1;
	int rt = ++ cnt;
	siz[rt] = 1;
	w[rt] = org[mid],fa[rt] = f;
	son[rt][0] = build(l,mid - 1,rt);
	son[rt][1] = build(mid + 1,r,rt);
	pushup(rt);
	return rt;
}

inline void pushdown(int rt)
{
	if(!tag[rt]) return;
	tag[son[rt][0]] ^= 1;
	tag[son[rt][1]] ^= 1;
	swap(son[rt][0],son[rt][1]);
	tag[rt] = 0;
}

void rotate(int rt)
{
	int f = fa[rt];
	pushdown(rt),pushdown(f);
	int id = get_id(rt),fid = get_id(f),gf = fa[f];
	connect(son[rt][id ^ 1],f,id);
	connect(f,rt,id ^ 1),connect(rt,gf,fid);
	pushup(f),pushup(rt);
}

void splay(int at,int to)
{
	to = fa[to];
	while(fa[at] ^ to)
	{
		int up = fa[at];
		if(fa[up] == to) rotate(at);
		else if(get_id(at) ^ get_id(up))
			rotate(at),rotate(at);
		else
			rotate(up),rotate(at);
	}
}

int find(int k)
{
	int rt = root;
	while(true)
	{
		pushdown(rt);
		if(k <= siz[son[rt][0]]) rt = son[rt][0];
		else 
		{
			k -= siz[son[rt][0]] + 1;
			if(!k) return rt;
			rt = son[rt][1];
		}
	}
}

void reserve(int l,int r)
{
	l = l - 1,r = r + 1;
	l = find(l),r = find(r);
	splay(l,root);
	splay(r,son[l][1]);
	tag[son[r][0]] ^= 1;
}

void print(int rt)
{
	pushdown(rt);
	if(son[rt][0]) print(son[rt][0]);
	if(w[rt]) printf("%d ",w[rt]);
	if(son[rt][1]) print(son[rt][1]);
}

int main()
{
	int m,a,b;
	register int i;
	read(n),read(m);
//	org[1] = -1,org[n + 2] = n + 1;
	for(i = 1;i <= n;++ i)
		org[i + 1] = i;
	root = build(1,n + 2,0);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b);
		reserve(a + 1,b + 1);
	}
	print(root);
	return 0;
 } 
