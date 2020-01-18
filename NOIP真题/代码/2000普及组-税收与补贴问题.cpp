#include<bits/stdc++.h>
using namespace std;
int yuqi,price,sale,a[100005],b[100005],add,tot1=1;
double minn=99999999,maxx=-99999999;
int main()
{
	scanf("%d",&yuqi);
	scanf("%d%d",&a[1],&b[1]);
	while(1)
	{
		scanf("%d%d",&price,&sale);
		if(price==-1&&sale==-1) break;
		a[++tot1]=price,b[tot1]=sale;
	}
	scanf("%d",&add);int n=tot1;
	for(int i=1;i<n;i++)
		for(int j=a[i]+1;j<a[i+1];j++)
			if(b[i]-add*(j-a[1])>0)
				a[++tot1]=j,b[tot1]=b[i]-add*(j-a[i]);
	for(int i=a[n]+1;i<=a[n]+b[n]/add;i++)
		a[++tot1]=i,b[tot1]=b[n]-add*(i-a[n]);
	for(int i=1;i<=tot1;i++)
		if(a[i]==yuqi) {n=b[i];break;}
	for(int i=1;i<=tot1&&i!=n;i++)
	{
		int x=yuqi-a[1],y=n-b[i],z=a[i]-a[1];
		if(y>0) maxx=max(maxx,(double)(1.0*(z*b[i]-x*n)/y));
		else minn=min(minn,(double)(1.0*(z*b[i]-x*n)/y));
	}
	if(maxx>minn) printf("NO SOLUTION");
	else if(maxx>0) printf("%.0lf",ceil(maxx));
	else if(minn<0) printf("%.0lf",floor(minn)); 
	else printf("0");
}
