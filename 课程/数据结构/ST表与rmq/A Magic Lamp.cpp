#include<cstdio>
#include<cstring>
#include<iostream>
int n,m,s[1001],q;
int c[1001],a[1001],minn[1001][11];

void rmq()
{
	for(int j=1;(1<<j)<=m;j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
		{
			if(a[minn[i][j-1]]<=a[minn[i+(1<<(j-1))][j-1]])
				minn[i][j] = minn[i][j-1];
			else if(a[minn[i][j-1]]>a[minn[i+(1<<(j-1))][j-1]])
				minn[i][j] = minn[i+(1<<(j-1))][j-1];		
		}
}

void loog()
{
	s[1] = 0;
	for(int i=2;i<=1001;i++)
		s[i] = s[i/2] + 1;
}

int ask(int l,int r)
{
	int x=s[r-l+1];
	if(a[minn[l][x]]<=a[minn[r+1-(1<<x)][x]])
		return minn[l][x];
	return minn[r+1-(1<<x)][x];
}

int main()
{
	int i,j;
	char ch[1001];
	loog();
	while(scanf("%s%d",ch,&n)==2)
	{
		q=0;
		memset(minn,0,sizeof minn);
		memset(a,0,sizeof a);
		memset(c,0,sizeof c);
		m = strlen(ch);
		for(i=0;i<m;i++)
			a[i+1] = ch[i]-'0';
		for(i=1;i<=m;i++)
			minn[i][0] = i;
		rmq();
		i=1;
		for(j=1;j<=m-n;j++)
		{
			i = ask(i,n+j);
			c[++q] = a[i++];
		}
		i=1;
		while(c[i]==0&&i<q) i++;
		for(;i<=q;i++)
			printf("%d",c[i]);
		if(q==0) printf("0");
		printf("\n");
	}
	return 0;
}
