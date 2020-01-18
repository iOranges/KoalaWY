#include<cstdio>
int order[1005],nowo[50][50],t[50],T[50][50];
int beg[50][50],nowt[50][50],end[50],onum[50],nxt[50][50],lst[50];

int main()
{
	int n,m,ans = 0;
	register int i,j,k,p;
	scanf("%d%d",&m,&n);
	for(i = 1;i <= m * n;++ i)
		scanf("%d",&order[i]);
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= m;++ j)
			scanf("%d",&nowo[i][j]);
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= m;++ j)
			scanf("%d",&nowt[i][j]);
	for(k = 1;k <= n * m;++ k)
	{
		i = order[k],p = nowo[i][++ onum[i]];
		bool flag = true;
		for(j = 1;j <= T[p][0] && j;j = nxt[p][j])
			if(beg[p][j] >= end[i]&&T[p][j] >= nowt[i][onum[i]])
			{
				T[p][j] -= nowt[i][onum[i]];
				end[i] = beg[p][j] + nowt[i][onum[i]];
				beg[p][j] = end[i];
				flag = false;
				break;
			}
			else if(T[p][j] - nowt[i][onum[i]] + beg[p][j] >= end[i]&&T[p][j] >= nowt[i][onum[i]])
			{
				++ T[p][0];
				nxt[p][T[p][0]] = nxt[p][j];
				if(!nxt[p][T[p][0]]) lst[p] = T[p][0]; 
				nxt[p][j] = T[p][0];
				T[p][T[p][0]] = T[p][j] - nowt[i][onum[i]] + beg[p][j] - end[i];
				T[p][j] = end[i] - beg[p][j];
				beg[p][T[p][0]] = end[i] = end[i] + nowt[i][onum[i]];
				flag = false;
				break;
			}
		if(flag)
		{
			if(t[p] >= end[i])
				end[i] = t[p] = t[p] + nowt[i][onum[i]];
			else 
			{
				T[p][++T[p][0]] = end[i] - t[p];
				nxt[p][lst[p]] = T[p][0];
				lst[p] = T[p][0]; 
				beg[p][T[p][0]] = t[p];
				end[i] = t[p] = end[i] + nowt[i][onum[i]];
			}
		}
	}
	for(i = 1;i <= m;++ i)
		if(t[i] > ans) ans = t[i];
	printf("%d",ans);
	return 0;
}

