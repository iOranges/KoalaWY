#include<cstdio>
#include<cstring>
int p[260];
char s[10000005];
bool hash[16000005];

int main()
{
	int n,m;
	register int i,j,cnt = 0;
	scanf("%d%d%s",&n,&m,s + 1);
	int len = strlen(s + 1);
	for(i = 1,j = 0;i <= len;++ i)
	{
		if(!p[s[i]]) p[s[i]] = ++ j;
		if(j == m) break;
	}
	for(i = 1;i <= len - n + 1;++ i)
	{
		int ha = 0;
		for(j = i;j <= i + n - 1;++ j)
			ha = ha * m + p[s[j]];
		if(!hash[ha])
			hash[ha] = true,++ cnt;
	}
	printf("%d",cnt);
	return 0;
}
