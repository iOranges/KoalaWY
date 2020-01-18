#include<cstdio>
void exgcd(long long a,long long b,long long &x,long long &y)
{
	if(!b)
	{
		x = 1,y = 0;
		return;
	}
	exgcd(b,a%b,x,y);
	long long z = x;
	x = y;
	y = z - a / b * y;
}

int main()
{
	long long a,b,x,y;
	scanf("%lld%lld",&a,&b);
	exgcd(a,b,x,y);
	x = (x % b + b) % b;
	printf("%lld",x);
	return 0;
}
