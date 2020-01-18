#include<cstdio>
#include<cstring>
bool have[100005];
int n,m,h[100005],s[100005],tot,l[100005],r[100005],cnt;
struct node{
	int to,next;
	node(int u=0,int v=0,int k=0)
	{
		to = v;
		next = h[u];
		h[u] = k;
	}
}e[200005];

inline int lowbit(int x)
{
	return x & (-x);
}

void add(int x,int k)
{
	for(int i=x;i<=cnt;i+=lowbit(i))
		s[i] += k;
}

void dfs(int u,int pre)
{
	l[u] = ++cnt;
	for(int i=h[u];i;i=e[i].next)
		if(e[i].to!=pre)
			dfs(e[i].to,u);
	r[u] = cnt;
}

int query(int x)
{
	int sum = 0;
	for(int i=x;i>0;i-=lowbit(i))
		sum += s[i];
	return sum;
}

int main()
{
	char ch[5];
	int i,a,b,x;
	while(~scanf("%d",&n))
	{
		tot = cnt = 0;
		memset(s,0,sizeof s);
		memset(h,0,sizeof h);
		memset(e,0,sizeof e);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			++tot;
			e[tot] = node(a,b,tot);
			++tot;
			e[tot] = node(b,a,tot);
		}
		dfs(1,0);
		for(i=1;i<=n;i++)
		{
			have[i] = true;
			add(l[i],1);
		}		
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%s%d",ch,&x);
			if(ch[0] == 'C')
			{
				if(have[x]) add(l[x],-1);
				else	add(l[x],1);
				have[x] = !have[x];
			}
			else
				printf("%d\n",query(r[x]) - query(l[x] - 1));
		}		
	}
	return 0;
}
