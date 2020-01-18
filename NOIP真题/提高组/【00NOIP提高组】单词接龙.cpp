#include<cstdio>
#include<cstring>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
int n,len[21],f[21][21],ans = 0,use[21];
char s[21][1001];
void dfs(int x,int s)
{
	ans = max(s,ans);
	for(int i = 1;i <= n;++ i)
		if(f[x][i] > 0&&use[i])
		{
			-- use[i];
			dfs(i,s + len[i] - f[x][i]);
			++ use[i];
		}
}

int main()
{
	register int i,j,k,q,p;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
	{
		scanf("%s",s[i] + 1);
		len[i] = strlen(s[i] + 1);
		use[i] = 2;
	}
	char beg[10];
	scanf("%s",beg);
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= n;++ j)
		{
			int l = min(len[i],len[j]);
			for(k = 1;k < l;++ k)
			{
				bool flag = true;
				for(q = len[i] - k + 1,p = 1;q <= len[i]&&p <= k;++ q,++ p)	
					if(s[i][q] != s[j][p]) {flag = false;break;}
				if(flag) {f[i][j] = k;break;}		
			}		
		}
	for(i = 1;i <= n;++ i)
		if(s[i][1] == beg[0])
		{
			-- use[i];
			dfs(i,len[i]);	
			++ use[i];		
		}
	printf("%d",ans);
	return 0;
}
