#include<cstdio>
#include<cstring>
struct node{
	int e,next;
}tree[200001];
int h[100001],n,m,tot,Maxdep,nd;

inline void read(int& x) {
    int f = 1; x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

inline void print(int x)
{
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

void add(int a,int b)
{
	tree[++tot].e = b;
	tree[tot].next = h[a];
	h[a] = tot; 
}

void dfs(int dep,int u,int pre)
{
	if(dep > Maxdep)
	{
		Maxdep = dep;
		nd = u;
	}
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
			dfs(dep+1,tree[i].e,u);
}

int main()
{
	int i,t,j,a,b,k;
	read(t);
	for(i=1;i<=t;i++)
	{
		read(n),read(m);
		tot = 0,Maxdep = 0;
		memset(h,0,sizeof h);
		memset(tree,0,sizeof tree);
		for(j=1;j<n;j++)
		{
			read(a),read(b);
			add(a,b),add(b,a);
		}
		dfs(0,1,0);
		dfs(0,nd,0);
		for(j=1;j<=m;j++)
		{
			read(k);
			if(k<=Maxdep+1)
				print(k-1);
			else 
				print(2*k-Maxdep-2);
			putchar('\n');
		}
	}
	return 0;
}
