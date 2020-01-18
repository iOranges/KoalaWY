#include<cstdio>
#include<iostream>
using namespace std;
int n,m,tot,s[201],c[201],f[3][201][201],num[201];

bool fit(int x,int k)
{
	return !(s[x]&c[k]);
}

int getnum(int x)
{
	int cnt = 0;
	while(x)
	{
		++cnt;
		x -= (x&(-x));
	}
	return cnt;
}

int main()
{
	int sum,i,j,k,q,maxx=-1 * 0x7fffffff;
	char ch[11];
	scanf("%d%d",&n,&m);
	sum = (1 << m) - 1;
	for(i=1;i<=n;++i)
		{
			scanf("%s",ch+1);
			for(j=1;j<=m;j++)
				if(ch[j] == 'H')
					c[i] += (1<<(m-j));
		}
	for(i=0;i<sum;++i)
		if((!(i&(i<<1)))&&(!(i&(i<<2)))&&(!(i&(i>>1)))&&(!(i&(i>>2))))
		{
			s[++tot] = i;	
			num[tot] = getnum(i);	
			if(fit(tot,1))	f[1][tot][0] = num[tot];
		}
	for(i=1;i<=tot;++i)
		for(j=1;j<=tot;++j)
			if(fit(j,2))
				if(!(s[i]&s[j]))
					f[2][j][i] = max(f[2][j][i],f[1][i][0] + num[j]);
	for(i=3;i<=n;++i)
		for(j=1;j<=tot;++j)
			if(fit(j,i))
				for(k=1;k<=tot;++k)
					if(!(s[j]&s[k]))
						for(q=1;q<=tot;++q)
							if(!(s[q]&s[k]))
								if(!(s[q]&s[j]))
									f[i%3][j][k] = max(f[i%3][j][k],f[(i-1)%3][k][q]+num[j]);
	for(i=1;i<=tot;++i)
		for(j=1;j<=tot;++j)
			maxx = max(f[n%3][j][i],maxx);
	printf("%d",maxx);
	return 0;
}
