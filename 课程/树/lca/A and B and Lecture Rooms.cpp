#include<cstdio>
struct node{
	int next,son;
}t[200005];
struct node2{
	int v,next,son;
}q[200005];
bool visit[100005];
int h1[100005],h2[100005],tot,cnt,lca[100005];
int d[100005],f[100005],s[100005],g[100005][2],fa[100005];

void read(int &x)
{
    x=0;int f=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;	
}

void write(int x)
{
    if(x<0)x=-x,putchar('-');
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}

inline void add1(int a,int b)
{
	t[++tot].son = b;
	t[tot].next = h1[a];
	h1[a] = tot;
}

inline void add2(int a,int b,int k)
{
	q[++cnt].son = b;
	q[cnt].next = h2[a];
	q[cnt].v = k;
	h2[a] = cnt;
}

inline int find(int x)
{
	if(x!=f[x]) f[x] = find(f[x]);
	return f[x];
}

void dfs(int u,int pre)
{
	s[u] = 1;
	d[u] = d[pre] + 1;
	fa[u] = pre;
	for(int i=h1[u];i;i=t[i].next)
		if(t[i].son!=pre)
		{
			dfs(t[i].son,u);
			s[u] += s[t[i].son];
			f[t[i].son] = u;
		}
	visit[u] = true;
	for(int i=h2[u];i;i=q[i].next)
		if(visit[q[i].son])
			lca[q[i].v] = find(q[i].son);
}

inline void work1(int x,int step,int pre)
{
	if(step == 0)
		write(s[x] - s[pre]);
	else
		work1(fa[x],step-1,x);
}

inline int work2(int x,int aim)
{
	if(fa[x] == aim) return s[x];
	return work2(fa[x],aim);
}

int main()
{
	int n,i,a,b,m;
	read(n);
	for(i=1;i<n;i++)
	{
		read(a),read(b);
		add1(a,b),add1(b,a);
	}
	for(i=1;i<=n;i++)
		f[i] = i;
	read(m);
	for(i=1;i<=m;i++)
	{
		read(g[i][0]),read(g[i][1]);
		add2(g[i][0],g[i][1],i);
		add2(g[i][1],g[i][0],i);
	}
	dfs(1,0);
	for(i=1;i<=m;i++)
	{
		if(g[i][0] == g[i][1])
			write(s[1]);
		else if(g[i][0] == lca[i])
			if((d[g[i][1]] - d[lca[i]])&1) putchar('0');
			else work1(g[i][1],(d[g[i][1]] - d[lca[i]])>>1,0);
		else if(g[i][1] == lca[i])
			if((d[g[i][0]] - d[lca[i]])&1) putchar('0');
			else work1(g[i][0],(d[g[i][0]] - d[lca[i]])>>1,0);
		else if((d[g[i][0]] + d[g[i][1]] - (d[lca[i]] << 1))&1)
			putchar('0');
		else if(d[g[i][0]] > d[g[i][1]])
			work1(g[i][0],(d[g[i][0]] + d[g[i][1]] - (d[lca[i]] << 1))>>1,0);
		else if(d[g[i][0]] < d[g[i][1]])
			work1(g[i][1],(d[g[i][0]] + d[g[i][1]] - (d[lca[i]] << 1))>>1,0);
		else 
			write(s[1] - work2(g[i][0],lca[i]) - work2(g[i][1],lca[i]));
		putchar('\n');
	}
	return 0;
}
