#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int lx(int n,int i,int j)
{
	if(i==1) return j;
	if(i==n) return 3*n-j-1;
	if(j==1) return 4*n-2-i;
	if(j==n) return n+i-1;
	return lx(n-2,i-1,j-1)+4*n-4;
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	printf("%d\n",lx(n,a,b));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%4d",lx(n,i,j));
		cout<<endl;
	}
}
