#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
char s[11][65],p[65];
struct node{
	char s[65];
	int len;
	bool operator < (const node b) const{
		len != b.len ? len > b.len : (strcmp(s,b.s) < 0);
	}
}ans[1500000];
int n,m = 60,nxt[65],len;

void getnxt()
{
	register int i,j;
	for(i = 2,j = 0;i <= len;++ i)
	{
		while(j > 0&&p[i] != p[j + 1]) j = nxt[j];
		if(p[i] == p[j + 1]) ++j;
		nxt[i] = j;
	}
}

bool kmp()
{
	register int i,j,k;
	for(k = 2;k <= n;++ k)
	{
		bool flag = false;
		for(i = 1,j = 0;i <= m;++ i)
		{
			while(j > 0&&s[k][i] != p[j + 1]) j = nxt[j];
			if(s[k][i] == p[j + 1]) ++j;
			if(j == len)
			{
				flag = true;
				break;				
			}
		}
		if(!flag) return false;
	}
	return true;
}

int main()
{
	int t;
	register int i,j;
	scanf("%d",&t);
	while(t --)
	{
		int cnt = 0;
		scanf("%d",&n);
		for(i = 1;i <= n;++ i)
			scanf("%s",s[i] + 1);
		for(i = 1;i <= m - 2;++ i)
			for(j = i + 2;j <= m;++ j)
			{
				memcpy(p + 1,s[1] + i,sizeof(char) * (j - i + 1));
				p[j - i + 2] = '\0';
				len = strlen(p + 1);
				getnxt();
				if(kmp())
				{
					strcpy(ans[++cnt].s,p + 1);
					ans[cnt].len = len;
				}
				else break;
			}
		if(cnt)
		{
			sort(ans + 1,ans + cnt);
			printf("%s\n",ans[1].s);
		}
		else
			printf("no significant commonalities\n");		
	}
	return 0;
}
