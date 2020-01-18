#include<iostream>
using namespace std;
int p[10001],c[10001],v[10001];
int main()
{
	int m,i,j,c1,p1,x,y,k,l,ll,q,money=-1,n,mx=-999999,o=0;
	cin >> m >> c1 >> p1;
	p[c1] = p1;
	while(cin >> x >> y)
	{
		if(x==-1&&y==-1)
			break;
		p[x] = y;
		mx = max(mx,x);
		c[x] = (x-c1)*y;
		j = x;
		while(--j)
			if(p[j])
			{
				k = j;	
				break;				
			}
		l = (p[k]-p[x]) / (x-k);
		for(j=k+1;j<x;j++)
			p[j] = p[j-1] - l,c[j] = p[j]*(j-c1);		
	}
	if(!p[m])
	{
		i = m;
		while(--i)
			if(p[i])
			{
				j = i;
				break;				
			}
		while(--j)
			if(p[j])
				break;
		l = (p[j]-p[i]) / (i-j);
		for(k=i+1;k<=m;k++)
			p[k] = p[k-1] - l,c[k] = (k-c1)*p[k];
	}
	cin >> ll;
	q = p[mx],i=mx;
	while((q-ll)>0)
	{
		q-=ll;
		p[++i] = q;
		c[i] = p[i]*(i-c1);
	}
	n = i,k = c[m];
	for(i=c1;i<=n;i++)
		c[i] = c[i] - k,v[i] = c[i];
	while(true)
	{
		o++;
		bool flag1 = false,flag2 = true;
		for(i=c1;i<=n;i++)
		{
			v[i] = v[i]-(p[m]-p[i])*o;
			if(v[i]>0&&v[i]>c[i])
			{
				flag1 = true;
				break;
			}
			if(v[i]>0)
				flag2 = false;
		}
		if(flag1) break;
		if(flag2) 
		{
			cout << o;
			return 0;
		}
		for(i=c1;i<=n;i++)
			v[i] = c[i];
	}
	o = 0;
	while(true)
	{
		o--;
		bool flag1 = false,flag2 = true;
		for(i=c1;i<=n;i++)
		{
			v[i] = v[i]-(p[m]-p[i])*o;
			if(v[i]>0&&v[i]>c[i])
			{
				flag1 = true;
				break;
			}
			if(v[i]>0)
				flag2 = false;
		}
		if(flag1) break;
		if(flag2) 
		{
			cout << o;
			return 0;
		}	
		for(i=c1;i<=n;i++)
			v[i] = c[i];			
	}
	cout << "NO SOLUTION";
	return 0;
 } 
