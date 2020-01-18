#include<cstdio>
#include<cstring>
char s[1001][25];
struct node{
	int son[26],v;
}tire[400005];
int tot = 1,end[400005];
void insert(char *s,int x)
{
	register int i, p = 1;
	int len = strlen(s+1);
	for(i = 1;i <= len;++ i)
	{
		int ch = s[i] - 'a';
		if(tire[p].son[ch] == 0) tire[p].son[ch] = ++ tot;
		p = tire[p].son[ch];
		tire[p].v ++;
	}
	end[p] = x;
}

int find(char *s,int x)
{
	register int i, p = 1;
	int len = strlen(s+1);
	for(i = 1;i <= len;++ i)
	{
		p = tire[p].son[s[i] - 'a'];
		if(tire[p].v == 1||end[p] == x) return (int)i;
	}
}

int main()
{
	int n = 1;
	register int i,j;
	while(~scanf("%s",s[n] + 1))
	{
		insert(s[n],n);
		++ n;
	}
	for(i = 1;i < n;++ i)
	{
		int m = find(s[i],i);
		printf("%s ",s[i]+1);
		for(j = 1;j <= m;++ j)
			putchar(s[i][j]);
		putchar('\n');
	}
	return 0;
}
