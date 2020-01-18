#include<cstdio>
#include<cstring>
int s[12],num[10] = {0,1,2,3,4,5,6,8,9};
long long f[12][12][2];
template <typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

long long work(long long x)
{
	int n = 0;
	long long ans = 0;
	while(x)
	{
		s[++ n] = x % 10;
		x /= 10;
	}
	register int i,j,k;
	for(i = 0;i < 9&&num[i] < s[n];++ i)
		f[n][num[i]][0] = 1;
	f[n][s[n]][1] = 1; 
	for(i = n - 1;i > 0;-- i)
	{
		for(j = 0;j < 9;++ j)
		{
			for(k = 0;k < 9;++ k)
				f[i][num[j]][0] += f[i + 1][num[k]][0];
			if(num[j] < s[i]) f[i][num[j]][0] += f[i + 1][s[i + 1]][1];
			else if(num[j] == s[i])
				f[i][num[j]][1] += f[i + 1][s[i + 1]][1];
		}
	}
	for(i = 0;i < 9;++ i)
		ans += f[1][num[i]][0] + f[1][num[i]][1];
	return ans;
}

int main()
{
	int t;
	long long n;
	read(t);
	while(t --)
	{
		read(n);
		memset(f,0,sizeof f);
		printf("%lld\n",work(n) - 1);
	}
	return 0;
}
