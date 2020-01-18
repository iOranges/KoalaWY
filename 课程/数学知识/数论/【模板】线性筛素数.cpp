#include<cstdio>
bool f[10000005];
int n,prime[1000005],tot;

inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

void work()
{
	register int i,j;
	for(i = 2;i <= n;++ i)
	{
		if(!f[i]) prime[++tot] = i;
		for(j = 1;j <= tot;++ j)
		{
			if(i * prime[j] > n) break;
			f[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

int main()
{
	int m,a;
	register int i;
	read(n),read(m);
	f[1] = true;
	work();
	for(i = 1;i <= m;++ i)
	{
		read(a);
		if(f[a]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
 } 
