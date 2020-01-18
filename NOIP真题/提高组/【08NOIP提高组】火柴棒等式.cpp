#include<cstdio>
int c[10] = {6,2,5,5,4,5,6,3,7,6};
inline int calc(int x)
{
	if(!x) return 6;
	static int s[25];
	int top = 0,cnt = 0;
	while(x)
	{
		s[++ top] = x % 10;
		x /= 10;
	}
	for(register int i = 1;i <= top;++ i)
		cnt += c[s[i]];
	return cnt;
}

int main()
{
	int n,cnt = 0;
	register int i,j;
	scanf("%d",&n);
	n -= 4;
	for(i = 0;i <= 2000;++ i)
	{
		int t = n;
		t -= calc(i);
		for(j = i;j <= 10000;++ j)
		{
			int temp = t;
			temp -= calc(j) + calc(i + j);
			if(temp == 0) cnt += (i == j ? 1 : 2);
		}
	 } 
	printf("%d",cnt);
	return 0;
}
