#include<bits/stdc++.h>
using namespace std;
int a,b,l,m,n;
int pd(int x,int y)
{
	if(__gcd(x,y)==1) return true;
	return false;
}
int main()
{
	scanf("%d%d%d",&a,&b,&l);
	double x=1.0*a/b,maxx=l;
	for(int i=1;i<=l;i++)
		for(int j=1;j<=l;j++)
			if(1.0*i/j>=x&&fabs(1.0*i/j-x)<=maxx&&pd(i,j)){maxx=fabs(1.0*i/j-x);m=i,n=j;}
	printf("%d %d",m,n);
}
