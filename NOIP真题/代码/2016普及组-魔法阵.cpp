#include<bits/stdc++.h>
using namespace std;
int n,m,num[40005],a[40005],b[40005],c[40005],d[40005],magic[400005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{                              //Xd-Xc=x
		scanf("%d",&magic[i]);     //Xb-Xa=2*x
		num[magic[i]]++;           //Xc-Xb>6*x 
	}
	for(int x=1;x*9<n;x++)
	{
		int na,nb,nc,nd,tot=0;
		for(nd=x*9+2;nd<=n;nd++)
		{
			nc=nd-x;
			nb=nd-x*7-1;
			na=nd-x*9-1;
			tot+=num[na]*num[nb];
			c[nc]+=num[nd]*tot;
			d[nd]+=num[nc]*tot;
		}
		tot=0;
		for(na=n-x*9-1;na>=1;na--)
		{
			nb=na+x*2;
			nc=na+x*8+1;
			nd=na+x*9+1;
			tot+=num[nc]*num[nd];
			a[na]+=num[nb]*tot;
			b[nb]+=num[na]*tot;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d %d %d %d\n",a[magic[i]],b[magic[i]],c[magic[i]],d[magic[i]]);
}
