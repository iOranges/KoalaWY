#include<bits/stdc++.h>
using namespace std;
int m,n,p,a[1005][1005],maxx,maxn,z[6]={2,1,0,0,0,0},s[6]={6,6,6,6,5,4};
char c[1005][1005],c1[10][10]={
"  +---+",
" /   /|",
"+---+ |",
"|   | +",
"|   |/",
"+---+",
};
void mmp(int a,int b)
{
	for(int i=5;i>=0;i--)
		for(int j=z[i];j<=s[i];j++)
		{
			c[5-i+a][j+b]=c1[i][j];
			if(5-i+a>maxx) maxx=5-i+a;
			if(j+b>maxn) maxn=j+b;
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<a[i][j];k++)
				mmp((n-i)*2+3*k+1,(n-i)*2+4*j+1);
	for(int i=maxx;i>=1;i--)
	{	
		for(int j=1;j<=maxn;j++)
		{
			if(c[i][j]=='\0') printf(".");
			else printf("%c",c[i][j]);
		}
		puts("");
	}
}
