#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],d[1005],ans,f[1005],vis[1005][1005],c[1005][1005];
int dfs(int x)
{
	if(f[x]) return f[x];
	for(int i=1;i<=c[x][0];i++) f[x]=max(f[x],dfs(c[x][i]));
	return ++f[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[0]);int p=1;
		for(int j=1;j<=a[0];j++) scanf("%d",&a[j]);
		for(int j=a[1];j<a[a[0]];j++)
		{
			if(a[p]==j) p++;
			else
			{
				for(int k=1;k<=a[0];k++)
					if(!vis[a[k]][j]) c[a[k]][++c[a[k]][0]]=j,vis[a[k]][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans,dfs(i));
	printf("%d",ans);
}
