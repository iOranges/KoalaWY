#pragma G++ optimize(2)
#include<cstdio>
template <typename e> e gcd(e a,e b)
{
	return b ? gcd(b,a%b) : a;
}

template <typename e> inline e GCD(e a,e b)
{
	e t; 
	while(b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	} 
	return a;
}

template <typename e> inline e lcm(e a,e b)
{
	return a / GCD(a,b) * b;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d %d",GCD(a,b),lcm(a,b));
	return 0;
 } 
