#include<cstdio>
#include<cstring>
char s[100005];
int nxt[100005];

int main()
{
	int t,n;
	register int i,j;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%s",s+1);
		n = strlen(s+1);
		for(i = 2,j = 0;i <= n;++ i)
		{
			while(j > 0&&s[i] != s[j+1]) j = nxt[j];
			if(s[i] == s[j+1]) ++j;
			nxt[i] = j;
		}
		int t = n - nxt[n];
		if(n%t == 0&&n/t > 1) printf("0\n");
		else
			printf("%d\n",t - n%t);
	} 
	return 0;
}
