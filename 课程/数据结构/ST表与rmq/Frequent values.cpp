#include<cmath> 
#include<cstdio> 
#include<cstring>
#include<iostream>
using std::max; 
int n,m,num[1000001],maxx[1000001][21];

void rmq()
{
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			maxx[i][j] = max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);
}

int ask(int l,int r)
{
	if(l>r) return 0;
	int x = log(r-l+1)/log(2.0);
	return max(maxx[l][x],maxx[r+1-(1<<x)][x]);
}

int main()
{
	int i,x,y,j;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		scanf("%d",&m);
		for(i=1;i<=n;i++)
			scanf("%d",&num[i]);
		maxx[1][0]=1;
		for(i=2;i<=n;i++)
			if(num[i]==num[i-1]) maxx[i][0]=maxx[i-1][0]+1;
			else maxx[i][0] = 1;
		rmq();
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			j=x;
			while(j<=y&&num[j]==num[j-1])
				j++;
			printf("%d\n",max(j-x,ask(j,y)));
		}
	}
	return 0;
 } 
