#include<cstdio>
#include<cstring>
char s[100001],ch[100001];
bool end[200005];
int tire[200005][26],tot = 1,len,kkk = 0;
long long cnt;
void insert(char *s1)
{
	register int i,p = 1;
	for(i = 1;i <= len;++ i)
	{
		int ch = s1[i] - 'a';
		if(tire[p][ch] == 0) tire[p][ch] = ++ tot;
		p = tire[p][ch];
	}
	if(!end[p])
		end[p] = true,++ cnt;
}

int main()
{
	while(gets(s))
	{
		if(s[0] == '#') break;
		memset(tire,0,sizeof tire);
		memset(end,false,sizeof end);
		tot = cnt = len = 0;
		int n = strlen(s);
		s[n] = '.';
		for(register int i = 0;i <= n;++i)
		{
			if(s[i] >= 'a'&&s[i] <= 'z')
				ch[++len] = s[i];
			else
			{
				if(len == 0) continue;
				insert(ch);
				len = 0;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
