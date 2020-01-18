#include<cstdio>
const long long mod = 1000000007;
int h[300005],tot,n,l[300005],r[300005],num[300005],cnt,d[300005];
long long c[300005][2];
struct node{
	int to,next;
	void add(int a,int b)
	{
		to = b;
		next = h[a];
		h[a] = tot;
	}
}t[300005];

inline void read(int &x)
{
	char ch;x=0;
	ch = getc(stdin);
	while(ch<'0'||ch>'9') ch = getc(stdin);
	while(ch<='9'&&ch>='0') {x = (x<<1) + (x<<3) + (ch^48);ch = getc(stdin);}
}

inline int lowbit(int x)
{
	return x&(-x);
}

void dfs(int u)
{
	l[u] = ++ cnt;
	num[cnt] = u;
	for(int i=h[u];i;i=t[i].next)
	{
		d[t[i].to] = d[u] + 1;
		dfs(t[i].to);		
	}
	r[u] = cnt;
}

void add(int x,long long k,int f)
{
	for(register int i=x;i<=n;i+=lowbit(i))
		c[i][f] = (c[i][f] + k) % mod;
}

long long query(int x)
{
	long long ans = 0,res = 0;
	for(register int i=x;i>0;i-=lowbit(i))
		ans += c[i][0],res += c[i][1];
	return ((ans - d[num[x]] * res)%mod + mod) % mod;
}

int main()
{
	register int i;
	int a,b,m,k,x,j;
	read(n);
	for(i=2;i<=n;i++)
	{
		read(a);
		++ tot;
		t[tot].add(a,i);
	}
	dfs(1);
	read(m);
	for(i=1;i<=m;i++)
	{
		read(a),read(b);
		if(a == 1)
		{
			read(x),read(k);
			add(l[b],1ll * x + 1ll * d[b] * k,0);
			add(r[b] + 1,-1ll * x - 1ll * d[b] * k,0);
			add(l[b],k,1);
			add(r[b] + 1,-k,1);
		}
		else
			printf("%lld\n",query(l[b]));
	}
	return 0;
}

