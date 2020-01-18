#include<bits/stdc++.h>
using namespace std;
int f[10][10],ff[10],fff[1000],x,y,n,z;
char s[35];
long long sum;
int main()
{
	scanf("%s%d",s,&n);int len=strlen(s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		f[x][y]=1;
	}
	for(int i=0;i<=9;i++) f[i][i]=1; 
	for(int k=0;k<=9;k++)
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
				if(f[i][k]&&f[k][j]) f[i][j]=1;
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			if(f[i][j]) ff[i]++;
	fff[0]=1;
	for(int i=0;i<len;i++)
	{
		int x=ff[s[i]-'0'];
		for(int i=0;i<100;i++)
		{
			fff[i]=fff[i]*x+z;
			z=fff[i]/10;
			fff[i]%=10;
		}
	}
	int tot=100;
	while(fff[tot]==0) tot--;
	while(tot>=0) cout<<fff[tot--];
}
