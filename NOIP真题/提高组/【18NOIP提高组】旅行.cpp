#include<map>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
using std::vector;
using std::priority_queue;
struct node{
	int to,nxt;
}e[10010];
bool isloop[5005],ok,flag;
int ban[2],tot,h[5005],n,m,res[5005],s[5005],cnt,loop[5005],f[5005],dfn[5005],idx,top;
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs(int u,int pre)
{
	s[++cnt] = u;
	if((res[cnt] < s[cnt]&&ok)||flag) 
	{
		flag = true;
		return;
	}
	if(res[cnt] > s[cnt]) ok = false;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre||(u == ban[0]&&v == ban[1])||(u == ban[1]&&v == ban[0])) continue;
		dfs(v,u);
	}
	if(u == 1&&cnt == n)
		for(register int i = 1;i <= n;++ i)
			res[i] = s[i];
}

void lx_ak_ioi(int u) //get_loop
{
	dfn[u] = ++ idx;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == f[u]) continue;
		if(dfn[v])
		{
			if(dfn[v] < dfn[u]) continue;
			loop[++ top] = v;
			isloop[v] = true;
			while(v != u)
			{
				v = f[v];
				loop[++ top] = v;
				isloop[v] = true;
			}
		}
		else
		{
			f[v] = u;
			lx_ak_ioi(v);
		}
	}
}

vector<int> vec[5005];
priority_queue<int> q[5005];
int main()
{
//	freopen("1.out","w",stdout);
	int a,b,v;
	read(n),read(m);
	register int i,j;
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b);
		q[a].push(b),q[b].push(a);
	}
	for(i = 1;i <= n;++ i)
		while(!q[i].empty())
		{
			add(i,q[i].top());
			vec[i].push_back(q[i].top());
			q[i].pop();
		}
	memset(res,0x3f,sizeof res);
	res[0] = 0;
	if(m == n - 1)
		dfs(1,0);
	else{
		lx_ak_ioi(1);
//		loop[top + 1] = loop[1];
		for(i = 1;i < top;++ i)
		{
			ban[0] = loop[i];
/*			for(j = 0;j < vec[ban[0]].size();++ j)
				if(isloop[vec[ban[0]][j]])
				{
					ban[1] = vec[ban[0]][j];
					cnt = 0;
					ok = true;
					dfs(1,0);			
				}*/
			ban[1] = loop[i + 1];
			cnt = 0;ok = true;
			flag = false;
			dfs(1,0);
		}
	}
	for(i = 1;i <= n;++ i)
		printf("%d ",res[i]);
	return 0;
}
