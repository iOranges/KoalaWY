#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
struct node{
	int to,nxt;
}e[400005];
int h[200005],tot,w[200005];
const long long p = 10007;
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

int main()
{
	int n,a,b,maxx = 0;
	long long ans = 0;
	register int i,j;
	read(n);
	for(i = 1;i < n;++ i)
	{
		read(a),read(b);
		add(a,b),add(b,a);
	}
	for(i = 1;i <= n;++ i)
		read(w[i]);
	for(i = 1;i <= n;++ i)
	{
		int fir = 0,sec = 0;
		long long sum = 0;
		for(j = h[i];j;j = e[j].nxt)
		{
			int v = e[j].to;
			sum += w[v];
			if(w[v] > fir) sec = fir,fir = w[v];
			else if(w[v] > sec) sec = w[v];
		}
		maxx = max(maxx,fir * sec);
		for(j = h[i];j;j = e[j].nxt)
		{
			int v = e[j].to;
			ans = (ans + w[v] * 1ll * (sum - w[v]) % p) % p; 
		 } 
	}
	printf("%d %lld",maxx,ans);
	return 0;
}
