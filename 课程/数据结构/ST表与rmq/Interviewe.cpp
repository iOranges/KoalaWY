#include<cstdio>
#include<cstring>
#include<iostream>
using std::max;
int n,k,maxx[200005][21],s[200005];

void rmq()
{
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			maxx[i][j] = max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);
}

int ask(int l,int r)
{
	int x=s[r-l+1];
	return max(maxx[l][x],maxx[r+1-(1<<x)][x]);
}

void loog()
{
	s[1] = 0;
	for(int i=2;i<=200000;i++)
		s[i] = s[i/2] + 1;
}

int main()
{
	int i,m,j;
	long long sum;
	loog();
	while(~scanf("%d%d",&n,&k))
	{
		if(n<0&&k<0) break;
		memset(maxx,0,sizeof maxx);
		sum = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&maxx[i][0]);
			sum+=maxx[i][0];
		}
		if(sum<=k)
		{
			printf("-1\n");
			continue;
		}
		rmq();
		sum=ask(1,n);
		if(sum>k)
		{
			printf("1\n");
			continue;
		}
		for(m=k/sum;m<=n;m++)
		{
			sum = 0;
			i = n/m;
			for(j=1;j<=m;j++)
				sum += ask((j-1)*i+1,j*i);
			if(sum>k)
			{
				printf("%d\n",m);
				break;
			}
		}
	}
	return 0;
}
