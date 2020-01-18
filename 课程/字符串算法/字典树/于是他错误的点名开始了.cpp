#include<cstdio>
#include<cstring>
char s[55];
bool end[500005],use[500005];
int t[500005][26],tot;
inline void insert()
{
	int p = 0,len = strlen(s + 1);
	register int i;
	for(i = 1;i <= len;++ i)
	{
		int ch = s[i] - 'a';
		if(!t[p][ch]) t[p][ch] = ++ tot;
		p = t[p][ch];
	}
	end[p] = true;
}

inline int count()
{
	register int i;
	int p = 0,len = strlen(s + 1);
	for(i = 1;i <= len;++ i)
	{
		int ch = s[i] - 'a';
		if(!t[p][ch]) return 0;
		p = t[p][ch];
	}
	if(!end[p]) return 0;
	if(use[p]) return -1;
	use[p] = true;
	return 1;
}

int main()
{
	int n,m,k;
	scanf("%d",&n);
	register int i;
	for(i = 1;i <= n;++ i)
	{
		scanf("%s",s + 1);
		insert();
	}
	scanf("%d",&m);
	for(i = 1;i <= m;++ i)
	{
		scanf("%s",s + 1);
		k = count();
		if(!k) puts("WRONG");
		else if(k == -1) puts("REPEAT");
		else puts("OK");
	}
	return 0;	
 } 
