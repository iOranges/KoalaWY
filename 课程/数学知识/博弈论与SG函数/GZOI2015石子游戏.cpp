#include<cstdio>
#include<cstring>
#define N 1000005
#define min(x,y) ((x) < (y) ? (x) : (y))
bool vis[N];
int sg[N],prime[N],tot;

inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

namespace da_biao{ //打表找规律 
	int gcd(int a,int b)
	{
		return b == 0 ? a : gcd(b,a % b);
	}
	
	void I_Play_For_SG()
	{
		sg[0] = 0;
		register int i,j;
		for(i = 1;i <= N;++ i)
		{
			memset(vis,0,sizeof vis);
			for(j = 1;j < i;++ j)
				if(gcd(i,j) == 1)
					vis[sg[i - j]] = true;
			vis[0] = true;
			for(j = 0;j <= N;++ j)
				if(!vis[j])
				{
					sg[i] = j;
					break;
				} 
			printf("%d:%d\n",i,sg[i]);
		}
	}	
};

void work()
{
	int k ;
	register int i,j;
	for(i = 2;i <= N;++ i)
	{
		if(!vis[i]) prime[++tot] = i,sg[i] = tot + 1;
		for(j = 1;j <= tot;++ j)
		{
			k = prime[j] * i;
			if(k > N) break;
			vis[k] = true,sg[k] = min(sg[i],sg[prime[j]]);
			if(i % prime[j] == 0) break;
		}
	}
}

int main()
{
	sg[0] = 0;sg[1] = 1;
	work();	
	int n,t,ans,a;
	register int i;
	read(t);
	while(t --)
	{
		read(n);
		ans = 0;
		for(i = 1;i <= n;++ i)
		{
			read(a);
			ans ^= sg[a]; 
		}
		if(ans) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
