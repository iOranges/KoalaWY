#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
bool f[25010],cut[105];
int a[105],h[25010];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int n,t,tot,m;
	read(t);
	register int i,j;
	while(t --)
	{
		memset(f,0,sizeof f);
		memset(h,0,sizeof h);
		memset(cut,0,sizeof cut);
		read(n);
		for(i = 1;i <= n;++ i)
			read(a[i]);
		sort(a + 1,a + n + 1);
		for(i = 1;i <= n;++ i)
			h[a[i]] = i;
		tot = n;
		m = a[n];
		f[0] = true;
		for(i = 1;i <= n;++ i)
			for(j = a[i];j <= m;++ j)
			{
				f[j] = f[j] || f[j - a[i]];
				if(f[j]&&h[j] > i&&!cut[h[j]]) -- tot,cut[h[j]] = true;
			}
		printf("%d\n",tot);
	}
	return 0;
}
