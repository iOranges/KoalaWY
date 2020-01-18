#include<cstdio>
#include<cstring>
int a[1000005],b[10005],nxt[10005];

template <typename e> inline void read(e &x)
{
	int f=1;x=0;char ch;
	ch = getc(stdin);
	while(ch < '0'||ch > '9') {if(ch == '-') f = -1;ch = getc(stdin);}
	while(ch >= '0'&&ch <= '9') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
	x *= f;
}

int main()
{
	int n,m,t;
	register int i,j;
	read(t);
	while(t--)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(nxt,0,sizeof nxt);
		read(n),read(m);
		for(i = 1;i <= n;++ i)
			read(a[i]);
		for(i = 1;i <= m;++ i)
			read(b[i]);
		for(i = 2,j = 0;i <= m;++ i)
		{
			while(j > 0&&b[i] != b[j+1]) j = nxt[j];
			if(b[i] == b[j+1]) ++j;
			nxt[i] = j;
		}
		bool flag = true;
		for(i = 1,j = 0;i <= n;++ i)
		{
			while(j > 0&&a[i] != b[j+1]) j = nxt[j];
			if(a[i] == b[j+1]) ++j;
			if(j == m)
			{
				printf("%d\n",i - m + 1);
				flag = false;
				break;
			}
		}
		if(flag) printf("-1\n");
	}
	return 0;	
}
