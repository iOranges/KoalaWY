#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(x,y) ((x) > (y) ? (x) : (y))
using std::sort;
struct node{
	char s[205];
	int len;
	bool operator < (const node b) const{
		return len < b.len;
	}
}ch[10];
char s[205];
int f[205][45],c[205][205];

int main()
{
	int p,K,n,m;
	scanf("%d %d",&p,&K);
	n = p * 20;
	register int i,j,k,q;
	for(i = 1;i <= p;++ i)
		scanf("%s",s + (i - 1) * 20 + 1);
	scanf("%d",&m);
	for(i = 1;i <= m;++ i)
	{
		scanf("%s",ch[i].s + 1);
		ch[i].len = strlen(ch[i].s + 1);	
	}
	sort(ch + 1,ch + m + 1);
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= m;++ j)
			if(s[i] == ch[j].s[1])
			{
				bool flag = true;
				for(k = 2;k <= ch[j].len;++ k)
					if(s[i + k - 1] != ch[j].s[k])
					{
						flag= false;
						break;						
					}
				if(flag)
				{
					for(k = i;k > 0; -- k)
						for(q = i + ch[j].len - 1;q <= n;++ q)
							++ c[k][q];
					break;
				}
			}
	for(j = 1;j <= K;++ j)
		for(i = j;i <= n;++ i)
			for(k = j - 1;k < i;++ k)
				f[i][j] = max(f[i][j],f[k][j - 1] + c[k + 1][i]);
	printf("%d",f[n][K]);
	return 0;
}
 
