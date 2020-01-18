#include<cstdio>
#include<cstring>
char s[1000005];
int nxt[1000005];

int main()
{
	int n;
	register int i,j;
	while(true)
	{
		scanf("%s",s+1);
		if(s[1] == '.') break;
		n = strlen(s+1);
		for(i = 2,j = 0;i <= n;++ i)
		{
			while(j > 0&&s[i] != s[j+1]) j = nxt[j];
			if(s[i] == s[j+1]) ++j;
			nxt[i] = j;
		}
		int t = n - nxt[n];
		if(n%t) printf("1\n");
		else printf("%d\n",n/t);
	}
	return 0;
}
