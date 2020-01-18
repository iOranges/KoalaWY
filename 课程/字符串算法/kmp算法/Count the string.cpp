#include<cstdio>
int nxt[200005];
char s[200005];

int main()
{
	register int i,j;
	int t,n,cnt;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		scanf("%s",s + 1);
		cnt = n%10007;
		for(i = 2,j = 0;i <= n;++ i)
		{
			while(j > 0&&s[i] != s[j+1]) j = nxt[j];
			if(s[i] == s[j+1]) ++j;
			nxt[i] = j;
			if(j > 0) cnt = (cnt + 1)%10007;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
