#include<cstdio>
#include<cstring>
char s[1000010];
unsigned long long base = 131;
unsigned long long f[1000010],p[1000010]; 
void read(int &x)
{
	x = 0;char ch;
	ch = getchar();
	while(ch<'0'||ch>'9') ch = getchar();
	while(ch>='0'&&ch<='9') {x = (x<<1)+(x<<3)+ch-'0';ch = getchar();}
}

int main()
{
	int n,i,l1,l2,r1,r2,m;
	scanf("%s",s+1);
	read(m);
	p[0] = 1;
	n = strlen(s+1);
	for(i=1;i<=n;i++)
	{
		f[i] = f[i-1] * base + (s[i]-'a'+1);
		p[i] = p[i-1] * base;
	}
	for(i=1;i<=m;i++)
	{
		read(l1),read(r1),read(l2),read(r2);
		if((f[r1]-f[l1-1]*p[r1-l1+1])==(f[r2]-f[l2-1]*p[r2-l2+1]))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
