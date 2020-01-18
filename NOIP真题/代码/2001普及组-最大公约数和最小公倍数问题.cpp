#include<bits/stdc++.h>
using namespace std;
int x,y,tot;
int main()
{
	scanf("%d%d",&x,&y);
	for(int i=x;i<=sqrt(x*y);i++)
		if(x*y%i==0&&__gcd(i,(x*y/i))==x) tot++;
	printf("%d",tot*2);
}
