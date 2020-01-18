#include <bits/stdc++.h>
using namespace std;
char s[30][30],c[10],t1[500],t2[500];
int used[30],n,maxx;
void mycopy(char ss[],char tt[],int a,int b)
{
	int i=0;
	while(a<=b)
		ss[i++]=tt[a++];
	ss[i]='\0';
}
void dfs(int x,int sum)
{
	maxx=max(sum,maxx);
	if(used[x]>2) return;
	int len=strlen(s[x]);
	for(int i=1;i<=n;i++)
	{
		if(used[i]==2) continue;
		int len2=strlen(s[i]);
		for(int l=1;l<=len-1;l++)
		{
			if(l>=len2) break;
			mycopy(t1,s[x],len-l,len-1);
			mycopy(t2,s[i],0,l-1);
			if(strcmp(t1,t2)==0)
			{
				used[i]++;
				dfs(i,sum+len2-l);
				used[i]--;
			}
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		int lenn=strlen(s[i]);
		for(int j=0;j<lenn;j++)
			if(s[i][j]>='A' && s[i][j]<='Z')  s[i][j]+=32;
	}
	scanf("%s",c);
	if(c[0]>='A'&&c[0]<='Z') c[0]+=32;
	for(int i=1;i<=n;i++)
	{
		memset(used,0,sizeof used);
		if(s[i][0]==c[0])
		{
			used[i]=1;
			dfs(i,strlen(s[i]));
			used[i]=0;
		}
	}
	cout<<maxx;
}
