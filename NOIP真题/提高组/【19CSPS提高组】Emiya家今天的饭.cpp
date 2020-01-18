#include<cstdio>
#include<cstring>
#define N 105
#define M 2005
const long long p = 998244353;
int a[N][M];//a[i][j]��i����⿷�����⿵�j��ʳ�ĵķ����� 
long long f[N][N << 1],s[N];//f[i][j + n]��ʾǰi����⿷����в��õĶ���һ���ʳ��k-����ʳ�ĵ�����Ϊj�ķ�����������j����Ϊ����������Ҫ+n 
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
			read(a[i][j]),s[i] = (s[i] + a[i][j]) % p;//s[i]��ʾ��⿷���Ϊiʱ������⿵Ĳ�Ʒ���� 
	long long ans = 1;
	for(i = 1;i <= n;++ i)
		ans = ans * (s[i] + 1) % p;//��(s[i] + 1)��ʾÿ����⿷���ֻѡһ�ֲ�Ʒ(��ѡ(��+1))���ܹ���ķ�������(����Rin��Ҫ��) 
	ans = (ans - 1 + p) % p;//��ȥȫ������ѡ�ķ��� 
	for(k = 1;k <= m;++ k)//ö�ٵ�ǰ��һ��ʳ�ĳ�����ʹ�õ�һ��(Yazid������Ҫ��) 
	{
		memset(f,0,sizeof f);
		f[0][n] = 1;
		for(i = 1;i <= n;++ i)
			for(j = -i;j <= i;++ j)	
				f[i][j + n] = (f[i - 1][j + n] + f[i - 1][j + n - 1] * a[i][k]%p + f[i - 1][j + n + 1] * ((s[i] - a[i][k] + p)%p)%p)%p;
		//f[i - 1][j + n]����ǰ��⿷��������ײ�Ʒ��f[i - 1][j + n - 1] * a[i][k]����ǰ����������k�Ų�Ʒ
		// f[i - 1][j + n + 1] * (s[i] - a[i][k])��ʾ��ǰ���������˳�k�������һ��Ʒ 
		for(i = 1;i <= n;++ i)
			ans = (ans - f[n][i + n] + p) % p;//���ܷ�������ȥ���Ϸ��ķ����� 
	}
	printf("%lld",ans);
	return 0; 
}

