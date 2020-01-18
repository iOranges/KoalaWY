#include<cstdio>
#include<cstring>
struct e{
	int len,num[45];
}f[7][45];
int n,K,w[45];
char s[45];

inline e calc(e a,int l,int r)
{
	e b,ans;
	register int i,j;
	memset(b.num,0,sizeof b.num);
	memset(ans.num,0,sizeof ans.num);
	b.len = r - l + 1;
	int l1 = a.len,l2 = b.len;
	for(i = l2;i > 0;-- i) b.num[i] = w[r - i + 1];
	for(i = 1;i <= l1;++ i)
		for(j = 1;j <= l2;++ j)
			ans.num[i + j - 1] += a.num[i] * b.num[j];
	int l3 = l1 + l2 - 1;
	for(i = 1;i <= l3;++ i)
	{
		ans.num[i+1] += ans.num[i] / 10;
		ans.num[i] %= 10;
	}
	if(ans.num[l3 + 1]) l3++;
	ans.len = l3;
	return ans;
}

inline e max(e a,e b)
{
	if(a.len > b.len)
		return a;
	else if(a.len < b.len)
		return b;
	else 
	{
		int len = a.len;
		for(register int i = len;i > 0;-- i)
			if(a.num[i] > b.num[i]) return a;
			else if(a.num[i] < b.num[i]) return b;
		return a;
	}
}

int main()
{
	scanf("%d%d",&n,&K);
	scanf("%s",s + 1);
	int m = strlen(s + 1);
	register int i,j,k;
	for(i = 1;i <= m;++ i)
		w[i] = s[i] - '0';
	for(i = 1;i <= m;++ i)
		for(j = i;j >= 1;-- j)
			f[0][i].num[++f[0][i].len] = w[j];
	for(i = 1;i <= n;++ i)
		for(k = 1;k <= K&&k <= i - 1;++ k)
			for(j = k;j < i;++ j)
				f[k][i] = max(f[k][i],calc(f[k-1][j],j + 1,i));
	for(i = f[K][n].len;i > 0;-- i)
		putchar(f[K][n].num[i] + '0');
	return 0; 
 } 
