#include<cstdio>
#define swap(x,y) (x^=y,y^=x,x^=y)
int f[12][11],s[12];
inline int abs(int x)
{
	return x > 0 ? x : -x;
}

inline void pre_deal()
{
	register int i,j,k;
	for(i = 0;i <= 9;++ i)
		f[1][i] = 1;
	for(i = 2;i <= 10;++ i)
		for(j = 0;j <= 9;++ j)
			for(k = 0;k <= 9;++ k)
				if(abs(j - k) >= 2)
					f[i][j] += f[i - 1][k];
}

int work(long long x)
{
	register int i,j;
	int ans = 0,top = 0;
	do
	{
		s[++top] = x % 10;
		x /= 10;
	}while(x);
	for(i = 1;i < top;++ i)	
		for(j = 1;j <= 9;++ j)
			ans += f[i][j];
	for(i = 1;i < s[top];++ i)
		ans += f[top][i];
	for(i = top - 1;i > 0;-- i)
	{
		for(j = 0;j < s[i];++ j)
			if(abs(j - s[i + 1]) >= 2)
				ans += f[i][j];
		if(abs(s[i] - s[i + 1]) < 2) break;
	}
	return ans;
}

int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	pre_deal();
	printf("%d",work(b + 1) - work(a));
	return 0;
 } 
