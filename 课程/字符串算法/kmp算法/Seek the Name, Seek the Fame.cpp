#include<cstdio>
#include<cstring>
char s[400005];
int nxt[400005];

void print(int x)
{
	if(!x) return;
	print((nxt[x]));
	printf("%d ",x);
}

int main()
{
	while(~scanf("%s",s+1))
	{
		int n = strlen(s+1);
		register int i,j;
		for(i = 2,j = 0;i <= n;++ i)
		{
			while(j > 0&&s[i] != s[j+1]) j = nxt[j];
			if(s[i] == s[j+1]) ++ j;
			nxt[i] = j;
		} 
		print(n);
		printf("\n");
	}
	return 0;
 } 
