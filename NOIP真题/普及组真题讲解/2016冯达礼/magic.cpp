#include<bits/stdc++.h>
using namespace std;
int n,sum,x,s,m,a[15005],b[15005],c[15005],d[15005],tot[15005],w[40005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
		tot[w[i]]++;
	}
	for(int i=1;i*9+1<=n;i++)
	{
		x=i*9+1,s=0;
		for(int j=9*i+2;j<=n;j++)
		{
			s+=tot[j-x]*tot[j-x+i*2];
			c[j-i]+=s*tot[j];
			d[j]+=s*tot[j-i];
		}
		s=0;
		for(int j=n-x;j>=1;j--)
		{
			s+=tot[j+x]*tot[j+x-i];
			a[j]+=s*tot[j+i*2];
			b[j+i*2]+=s*tot[j];
		}
	}
	for(int i=1;i<=m;i++) printf("%d %d %d %d\n",a[w[i]],b[w[i]],c[w[i]],d[w[i]]);
}
