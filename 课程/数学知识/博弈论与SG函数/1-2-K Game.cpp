#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000005
using std::sort;
bool vis[N];
int f[N],sg[N],m,n;
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

void I_Play_For_SG()
{
	sort(f + 1,f + 3 + 1);
	sg[0] = 0;
	register int i,j;
	for(i = 1;i <= n;++ i)
	{
		memset(vis,0,sizeof vis);
		for(j = 1;j <= 3&&f[j] <= i;++ j)
			vis[sg[i - f[j]]] = true;
		for(j = 0;j <= n;++ j)
			if(!vis[j])
			{
				sg[i] = j;
				break;
			 } 
		printf("%d:%d\n",i,sg[i]);
	}
}

int main()
{
	register int i;
/*	n = 30;
	for(i = 1;i <= 20;++ i)
	{
		f[1] = 1,f[2] = 2,f[3] = i;
		printf("%d:\n",i);
		I_Play_For_SG(); 
	}*/
	int t,n,k,a,p;
	read(t);
	while(t --)
	{
		read(n),read(k);
		int ans = 0;
		if(k % 3) ans = n % 3;
		else if(k == n) ans = 1;
		else ans = (n % (k + 1)) % 3||(n % (k + 1)) == k; 
		if(ans) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
