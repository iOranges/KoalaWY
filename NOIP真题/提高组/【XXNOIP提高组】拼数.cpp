#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(x,y) ((x) < (y) ? (x) : (y))
using std::sort;
struct number{
	int len;
	char ch[1005];
	number()
	{
		len = 0;
		memset(ch,0,sizeof ch);
	}
	number operator + (const number b)
	{
		number c;
		register int i;
		c.len = len + b.len;
		for(i = 1;i <= len;++ i)
			c.ch[i] = ch[i];
		for(i = len + 1;i <= c.len;++ i)
			c.ch[i] = b.ch[i - len];
		return c;
	}
	void print()
	{
		register int i;
		for(i = 1;i <= len;++ i)
			putchar(ch[i]);
	}
}num[25];

bool cmp(number a,number b)
{
	int l = min(a.len,b.len);
	register int i;
	for(i = 1;i <= l;++ i)
		if(a.ch[i] != b.ch[i])
			return a.ch[i] > b.ch[i];
	number c = a + b;
	number d = b + a;
	l = a.len + b.len;
	for(i = 1;i <= l;++ i)
		if(c.ch[i] != d.ch[i])
			return c.ch[i] > d.ch[i];
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	register int i; 
	for(i = 1;i <= n;++ i)
	{
		scanf("%s",num[i].ch + 1);
		num[i].len = strlen(num[i].ch + 1);
	}
	sort(num + 1,num + n + 1,cmp);
	for(i = 1;i <= n;++ i)
		num[i].print();
	return 0;
}
