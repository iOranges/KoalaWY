#include<cstdio>
#include<cstring>
#define max(x,y) ((x) > (y) ? (x) : (y))
int nxt[1000005];
char s[1000005];

int main()
{
	scanf("%s",s+1);
	int n = strlen(s+1),maxx = 0;
	register int i,j;
	for(i = 2,j = 0;i <= n;++ i)
	{
		while(j > 0&&s[i] != s[j+1]) j = nxt[j];
		if(s[i] == s[j+1]) ++j;
		nxt[i] = j;
		if(i != n) maxx = max(j,maxx);
	}
	int t = nxt[n];
	while(t > maxx) t = nxt[t];
	if(!t) printf("Just a legend");
	else
		for(i = 2;i < n;++ i)
			if(nxt[i] == t)
			{
				for(j = 1;j <= nxt[i];++ j)
					putchar(s[j]);	
				break;			
			}
	return 0;
}
