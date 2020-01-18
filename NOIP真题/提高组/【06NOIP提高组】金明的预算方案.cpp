#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
int f[35000][2],w[205],q[65][5],v[205];

int main()
{
	int m,n,tot = 0,opt,a,b,ans = 0;
	scanf("%d%d",&m,&n);
	register int i,j,k,p = 0;
	for(i = 1;i <= n;++ i)
	{
		scanf("%d%d%d",&a,&b,&opt);
		if(!opt)
		{
			w[++ tot] = a * b;;	
			v[tot] = a,q[i][0] = 1;
			q[i][1] = tot;
		}
		else
		{
			w[++ tot] = a * b + w[q[opt][1]];
			v[tot] = a + v[q[opt][1]],++ q[opt][0];
			q[opt][q[opt][0]] = tot;
			if(q[opt][0] == 3)
			{
				w[++ tot] = a * b + w[q[opt][2]];
				v[tot] = a + v[q[opt][2]],++ q[opt][0];
				q[opt][q[opt][0]] = tot;				
			}
		}
	}
	for(i = 1;i <= n;++ i)
	{
		for(j = m;j >= 0;-- j)
			f[j][p] = f[j][p ^ 1];
		for(k = 1;k <= q[i][0];++ k)
			for(j = m;j >= v[q[i][k]];-- j)
			{
				f[j][p] = max(f[j][p],f[j - v[q[i][k]]][p ^ 1] + w[q[i][k]]);	
				ans = max(ans,f[j][p]);			
			}
		p ^= 1;
	}
	printf("%d",ans);
	return 0;
}
