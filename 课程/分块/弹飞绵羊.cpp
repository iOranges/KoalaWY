#include<cmath> 
#include<cstdio> 
int l[501],r[501],next[200005],g[200005],h[200005],num[200005],cnt,n,m;

void build()
{
	register int i,j,p;
	int block = sqrt(n);
	cnt = n / block;
	if(n % block) ++ cnt;
	for(i = 1;i <= cnt;++ i)
	{
		l[i] = (i - 1) * block + 1;
		r[i] = i * block;		
	}
	r[cnt] = n;
	for(i = 1;i <= n; ++ i)
		num[i] = (i - 1) / block + 1;
	for(i = n;i >= 1; -- i)	
		if(num[i] != num[i+h[i]])
		{
			next[i] = i + h[i];
			g[i] = 1;
		}
		else
		{
			next[i] = next[i + h[i]];
			g[i] = g[i + h[i]] + 1;
		}	
}

void update(int x,int k)
{
	h[x] = k;
	for(register int i = r[num[x]];i >= l[num[x]];-- i)
		if(num[i] != num[i+h[i]])
		{
			next[i] = i + h[i];
			g[i] = 1;
		}
		else
		{
			next[i] = next[i + h[i]];
			g[i] = g[i + h[i]] + 1;
		}
}

int query(int x)
{
	int tot = 0;
	do{
		tot += g[x];
		x = next[x];
	}while(x <= n);
	return tot;
}

int main()
{
	int opt,a,b;
	register int i;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		scanf("%d",&h[i]);
	build();
	scanf("%d",&m);
	for(i = 1;i <= m;++ i)
	{
		scanf("%d%d",&opt,&a);
		if(opt == 1)
			printf("%d\n",query(a + 1));
		else
		{
			scanf("%d",&b);
			update(a + 1,b);
		}
	}
	return 0;
 } 
