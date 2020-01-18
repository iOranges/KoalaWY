#include<cstdio>
#include<cstring>
#define N 105
#define M 2005
const long long p = 998244353;
int a[N][M];//a[i][j]第i种烹饪方法烹饪第j种食材的方案数 
long long f[N][N << 1],s[N];//f[i][j + n]表示前i中烹饪方法中采用的多余一半的食材k-其他食材的数量为j的方案数，由于j可能为负数，所以要+n 
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0'&&ch <= '9') {x = x * 10 + (ch ^ 48);ch = getchar();}
}

int main()
{
	int n,m;
	read(n),read(m);
	register int i,j,k;
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= m;++ j)
			read(a[i][j]),s[i] = (s[i] + a[i][j]) % p;//s[i]表示烹饪方法为i时可以烹饪的菜品总数 
	long long ans = 1;
	for(i = 1;i <= n;++ i)
		ans = ans * (s[i] + 1) % p;//∏(s[i] + 1)表示每种烹饪方法只选一种菜品(或不选(即+1))所能构造的方案总数(满足Rin的要求) 
	ans = (ans - 1 + p) % p;//减去全部都不选的方案 
	for(k = 1;k <= m;++ k)//枚举当前哪一个食材超过了使用的一半(Yazid的逆向要求) 
	{
		memset(f,0,sizeof f);
		f[0][n] = 1;
		for(i = 1;i <= n;++ i)
			for(j = -i;j <= i;++ j)	
				f[i][j + n] = (f[i - 1][j + n] + f[i - 1][j + n - 1] * a[i][k]%p + f[i - 1][j + n + 1] * ((s[i] - a[i][k] + p)%p)%p)%p;
		//f[i - 1][j + n]即当前烹饪方法不贡献菜品，f[i - 1][j + n - 1] * a[i][k]即当前方案贡献了k号菜品
		// f[i - 1][j + n + 1] * (s[i] - a[i][k])表示当前方案贡献了除k以外的任一菜品 
		for(i = 1;i <= n;++ i)
			ans = (ans - f[n][i + n] + p) % p;//用总方案数减去不合法的方案数 
	}
	printf("%lld",ans);
	return 0; 
}

