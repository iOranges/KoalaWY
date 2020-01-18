#include<cmath>
#include<cstdio>
#define exit(x) {printf("%d\n",x);continue;}
int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a % b);
}

inline int work(int x)
{
	int ans = 2,sq = sqrt(x);
	for(register int i = 2;i <= sq;++ i)
		if(x % i == 0) ans += 2;
	if(sq * sq == x) -- ans;
	return ans;
 } 

int main()
{
	int n,a1,a2,b1,b2,k,z,k2;
	scanf("%d",&n);
	register int i;
	for(i = 1;i <= n;++ i)
	{
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		k = b2 / b1,z = k;
		do
		{
			k2 = gcd(b1,k);
			b1 /= k2,z *= k2;
		}while(k2 != 1);
		k = a2 / gcd(z,a2);
		if(b1 % k != 0) exit(0)
		else b1 /= k;
		do
		{
			k = gcd(b1,a1 / a2);
			b1 /= k;	
		}while(k != 1);
		if(gcd(b1 * z * (a2 / gcd(z,a2)),a1) != a2) exit(0);
		printf("%d\n",work(b1));
	}
	return 0;
}

