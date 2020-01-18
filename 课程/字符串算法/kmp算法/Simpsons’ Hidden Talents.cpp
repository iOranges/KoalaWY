#include<cstdio>
#include<cstring>
char s1[50005],s2[50005];
int nxt[50005];

int main()
{
	register int i,j;
	while(~scanf("%s%s",s1+1,s2+1))
	{
		int n = strlen(s1 + 1),m = strlen(s2 + 1);
/*		s1[n + 1] = '&';
		memcpy(s1 + n + 2,s2 + 1,sizeof(char) * strlen(s2 + 1));
		n = strlen(s1 + 1);*/
		for(i = 2,j = 0;i <= n;++ i)
		{
			while(j > 0&&s1[i] != s1[j+1]) j = nxt[j];
			if(s1[i] == s1[j+1]) ++j;
			nxt[i] = j;
		}
		for(i = 1,j = 0;i <= m;++ i)
		{
			while(j > 0&&s2[i] != s1[j+1]) j = nxt[j];
			if(s2[i] == s1[j+1]) ++j;
			if(j == n&&i != m) j = nxt[j];
		}
		for(i = 1;i <= j;++ i)
			putchar(s1[i]);
		if(j) putchar(' ');
		printf("%d\n",j);
	}
	return 0;
}
