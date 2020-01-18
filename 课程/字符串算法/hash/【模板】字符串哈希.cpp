#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
const long long p = 19260817,mod = 1e9 + 7;
char s[1505];
long long h[10005];

int main()
{
	int n,len,tot;
	scanf("%d",&n);
	register int i,j; 
	for(i = 1;i <= n;++ i)
	{
		scanf("%s",s + 1);
		len = strlen(s + 1);
		for(j = 1;j <= len;++ j)
			h[i] = (h[i] * p % mod + s[j]) % mod;
	}
	sort(h + 1,h + n + 1);
	tot = n;
	for(i = 1;i <= n;++ i)
		if(h[i] == h[i - 1]) -- tot;
	printf("%d",tot);
	return 0;
}
