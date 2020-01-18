#include<bits/stdc++.h>
using namespace std;
int a[25],b[25],t,n,k,tot,sum[10005],summ;
void zh(int m,int k)
{
	for(int i=m;i>=k;i--)
	{
		a[k]=b[i];
		if(k>1) zh(i-1,k-1);
		else
		{
			tot++;
			for(int k=a[0];k>=1;k--) sum[tot]+=a[k];
		}
	}
}
int zs(int x)
{
	if(x==1) return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	stable_sort(b+1,b+n+1);
	a[0]=k;zh(n,k);
	for(int i=1;i<=tot;i++)
		if(zs(sum[i])) summ++;
	printf("%d",summ);
}
