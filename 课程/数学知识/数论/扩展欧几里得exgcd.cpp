#pragma G++ optimize(2)
#include<cstdio>

template <typename e> e exgcd(e a,e b,e &x,e &y)
{
	if(b == 0) 
	{
		x = 1,y = 0;
		return a;
	}
	e gcd = exgcd(b,a%b,x,y);
	e z = x;
	x = y;
	y = z - (a/b) * y;
	return gcd; 
}

int main()
{
	int x,y,a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",exgcd(a,b,x,y));
	printf("%d %d",x,y);
	return 0;
}
