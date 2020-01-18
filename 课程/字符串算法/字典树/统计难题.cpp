#include<cstdio>
#include<cstring>
struct node{
	int son[26],v;
}tire[400005];
int cnt,tot = 1;
char ch[15];
inline bool read(char * s)
{
	cnt = 0;
	char c = getc(stdin);
	while(c < 'a'||c > 'z') 
	{
		if(c == '\n') return false;
		c = getc(stdin);
	}
	while(c >= 'a'&&c <= 'z') 
	{
		s[++ cnt] = c;
		c = getc(stdin);
	}
	return true;
}

void insert()
{
	register int i,p = 1;
	for(i = 1;i <= cnt;++ i)
	{
		char c = ch[i] - 'a';
		if(tire[p].son[c] == 0) tire[p].son[c] = ++ tot;
		p = tire[p].son[c];
		tire[p].v ++;
	}
}

int search()
{
	register int i,p = 1;
	for(i = 1;i <= cnt;++ i)
	{
		p = tire[p].son[ch[i] - 'a'];
		if(p == 0) return 0;
	}
	return tire[p].v;
}

int main()
{
	register int i;
//	memset(tire,0,sizeof tire);
	while(read(ch))
		insert();
	while(scanf("%s",ch+1)!=EOF)
	{
		cnt = strlen(ch+1);
		printf("%d\n",search());
	}
	return 0;
}
