#include<cstdio>
#include<cstring>
char s1[1000005],s2[1000005];
int next[1000005];

int main()
{
	scanf("%s",s1 + 1);
	scanf("%s",s2 + 1);
	int n = strlen(s1+1);
	int m = strlen(s2+1);
	register int i,j;
	next[1] = j = 0;
	for(i = 2;i <= m;++ i)
	{
		while(j > 0&&s2[i] != s2[j+1]) j = next[j];
		if(s2[i] == s2[j+1]) ++j;
		next[i] = j;
	}
	for(i = 1;i <= n;++ i)
	{
		while(j > 0&&s1[i] != s2[j+1]) j = next[j];
		if(s1[i] == s2[j+1]) ++j;
		if(j == m)
		{
			printf("%d\n",i - j + 1);
			j = next[j];
		}
	}
	for(i = 1;i <= m;++ i)
		printf("%d ",next[i]);
	return 0;
}
