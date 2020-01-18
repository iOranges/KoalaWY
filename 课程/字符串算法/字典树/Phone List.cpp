#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
struct node{
	char s[15];
	int len;
	bool operator < (const node b) const{
		return len == b.len ? strcmp(s,b.s) < 0 : len < b.len;
	}
}p[10005];
bool end[400005];
int tire[400005][10],tot = 1;
bool insert(char * s,int len)
{
	register int i,p = 1;
	for(i = 1;i <= len;++ i)
	{
		int ch = s[i] - '0';
		if(tire[p][ch] == 0) tire[p][ch] = ++ tot;
		p = tire[p][ch];
		if(end[p]) return false;
	}
	end[p] = true;
	return true;
}

int main()
{
	int t,n;
	register int i,j;
	scanf("%d",&t);
	while(t --)
	{
		memset(p,0,sizeof p);
		memset(tire,0,sizeof tire);
		memset(end,0,sizeof end);
		tot = 1;
		scanf("%d",&n);
		for(i = 1;i <= n;++ i)
		{
			scanf("%s",p[i].s + 1);
			p[i].len = strlen(p[i].s + 1);
		}
		sort(p + 1,p + n + 1);
		bool flag = true;
		for(i = 1;i <= n;++ i)
			if(!insert(p[i].s,p[i].len))
			{
				flag = false;
				printf("NO\n");
				break;				
			}
		if(flag) printf("YES\n");
	}
	return 0;
}
