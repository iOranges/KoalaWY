#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005][105],b[10005][105],sum,k,c[10005];
const int p=20123;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d%d",&a[i][j],&b[i][j]);
			c[i]+=a[i][j];
		}
	scanf("%d",&k);
	for(int i=1;i<=n;i++)
	{
		sum=(sum+b[i][k])%p;
		int tot=0,q=k;
		b[i][q]=(b[i][q]-1)%c[i]+1;
		while(tot<b[i][q])
		{
			tot+=a[i][k];
			if(tot==b[i][q]) break;
			k++;
			if(k==m) k=0;
		}
	}
	printf("%d",sum%p);
}
