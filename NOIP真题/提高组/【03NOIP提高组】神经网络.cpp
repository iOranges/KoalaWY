#include<cstdio>
struct node{
	int to,nxt,v;
}e[2005];
int q[1005],p[1005],d[1005],h[1005],tot,c[1005],s[1005];
inline void read(int &x)
{
	x = 0;int f = 1;char ch = getc(stdin);
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getc(stdin);}
	while(ch >= '0'&&ch <= '9') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
	x *= f;
}

inline void add(int a,int b,int k)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	e[tot].v = k;
	h[a] = tot;
}

int main()
{
	int n,m,a,b,k;
	register int i,l = 1,r = 0;
	read(n),read(m);
	for(i = 1;i <= n;++ i)
	{
		read(c[i]),read(p[i]);
		if(c[i]) q[++ r] = i;
		else c[i] -= p[i];
	}
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b),read(k);
		++ d[a],++ s[b];
		add(a,b,k);
	}
	while(l <= r)
	{
		int u = q[l ++];
		for(i = h[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(c[u] > 0)
				c[v] += c[u] * e[i].v;
			-- s[v];
			if(!s[v]) q[++ r] = v;
		}
	}
	bool flag = true;
	for(i = 1;i <= n;++ i)
		if(!d[i]&&c[i] > 0)
		{
			printf("%d %d\n",i,c[i]);
			flag = false;			
		}	
	if(flag) printf("NULL");
	return 0;
}
