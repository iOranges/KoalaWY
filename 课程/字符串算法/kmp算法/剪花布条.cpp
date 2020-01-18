#include<cstdio>
#include<cstring>
char s1[1005],s2[1005];
int nxt[1005];

int main()
{
	register int i,j,cnt;
	while(true)
	{
		scanf("%s",s1 + 1);
		if(s1[1] == '#') break;
		cnt = 0;
		scanf("%s",s2 + 1);
		int n = strlen(s1 + 1),m = strlen(s2 + 1); 
		for(i = 2,j = 0;i <= m;++ i)
		{
			while(j > 0&&s2[j+1] != s2[i]) j = nxt[j];
			if(s2[j+1] == s2[i]) ++j;
			nxt[i] = j;
		}
		for(i = 1,j = 0;i <= n;++ i)
		{
			while(j > 0&&s1[i] != s2[j+1]) j = nxt[j];
			if(s2[j+1] == s1[i]) ++j;
			if(j == m)
				++cnt,j = 0;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
