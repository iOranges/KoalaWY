#include<cmath>
#include<cstdio>
int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a%b);
}

int main()
{
	int x,y,cnt = 0;
	register int i;
	scanf("%d%d",&x,&y);
	for(i = 1;i <= sqrt(y);++ i)
		if(y % i == 0)
			if(gcd(y / i,i) == x) ++ cnt;
	printf("%d",cnt * 2);
}
