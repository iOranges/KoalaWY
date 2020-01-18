#include<cstdio>
#include<iostream>
using std::min;
struct node{
	int e,next;
}tree[100005];
int h[100005],cnt,n,m,bin[20],tot,p[100005][20]; //tot为dfs序的序数,cnt为tree的序数 

struct node2{
	int l,r,mn;
}t[400005]; //注意为4倍！ 
int val[100005],out[100005],in[100005],d[100005],q[100005];
inline void read(int&x)
{
	int f = 1; x = 0;
	char ch = getchar();
	while(ch > '9' || ch < '0')  {if (ch == '-') f = -1 ; ch = getchar();};
	while(ch <= '9'&& ch >= '0') {x = x * 10 + ch - '0' ; ch = getchar();};
	x *= f;
}

void add(int a,int b)
{
	tree[++cnt].e = b;
	tree[cnt].next = h[a];
	h[a] = cnt;
}

void pushup(int rt)
{
	t[rt].mn = min(t[rt<<1].mn,t[rt<<1|1].mn);
}

void build(int l,int r,int rt)
{
	t[rt].l = l,t[rt].r = r;
	if(l == r)
	{
		t[rt].mn = val[q[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}

void update(int p,int v,int rt)
{
	int l = t[rt].l,r = t[rt].r;
	if(l == r)
	{
		t[rt].mn = v;
		return;
	}
	int mid = (l+r)>>1;
	if(p<=mid) update(p,v,rt<<1);
	else update(p,v,rt<<1|1);
	pushup(rt);
}

int query(int x,int y,int rt)
{
	int l = t[rt].l,r = t[rt].r;
	if(l == x&&r == y)
		return t[rt].mn;
	int mid = (l+r) >> 1;
	if(y<=mid) return query(x,y,rt<<1);
	else if(x>mid) return query(x,y,rt<<1|1);
	return min(query(x,mid,rt<<1),query(mid+1,y,rt<<1|1));
}

void dfs(int u)
{
	in[u] = ++tot; //第一个子树（即为本身） 
	q[tot] = u;
	for(int i=1;bin[i] <= d[u],i<=16;i++)
		p[u][i] = p[p[u][i-1]][i-1];
	for(int i=h[u];i;i=tree[i].next)
	{
		d[tree[i].e] = d[u] + 1;
		p[tree[i].e][0] = u;
		dfs(tree[i].e); 
	}
	out[u] = tot; //最后一个子树 
}

int main()
{
	char ch[5];
	int i,f,k,v,root=1,j;
	bin[0] = 1;
	for(i=1;i<20;i++) bin[i]=bin[i-1]<<1; //预处理2^n 
	read(n),read(m);
	for(i=1;i<=n;i++)
	{
		read(f),read(val[i]);
		if(f) add(f,i);
	}
	dfs(1);
	build(1,n,1);
	for(i=1;i<=m;i++)
	{
		scanf("%s",ch);  //没有& 
		read(k);
		if(ch[0] == 'E') root = k;
		else if(ch[0] == 'V') 
		{
			read(v);
			update(in[k],v,1); //in[k]为k子树dfs序最左之数,即为其本身 
		 }
		else
		{
			if(k == root) printf("%d\n",t[1].mn);
			else if(in[k] <= in[root] && out[k] >= out[root])
			{
				int x = root,deep = d[x] - d[k] - 1;
				for(j=0;j<=16;j++)
					if(bin[j]&deep) x = p[x][j]; //b[j]&d结果为d二进制的j位是否为1
				printf("%d\n",min(query(1,in[x]-1,1),query(out[x]+1,n,1))); 
			}
			else
				printf("%d\n",query(in[k],out[k],1));
		}
	}
	return 0;
}
