#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int n,minn[50001][20],maxx[50001][20];
void rmq()
{
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<=n;i++)
			if(i+(1<<j)-1<=n)
			{
				maxx[i][j] = max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);
				minn[i][j] = min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
			}
}

void ask(int l,int r)
{
	int x=log(r-l+1)/log(2);
	printf("%d\n",max(maxx[l][x],maxx[r+1-(1<<x)][x])-min(minn[l][x],minn[r+1-(1<<x)][x]));
}

int main()
{
	int q,i,m,x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		maxx[i][0] = minn[i][0] = m;
	}
	rmq();
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		ask(x,y);
	}
	return 0;
}
