#include<cstdio>
#define min(x,y) ((x) < (y) ? (x) : (y))
int d[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int a,b,cnt = 0;
	scanf("%d-%d",&a,&b);
	if(a == 0)
	{
		++ cnt;
		if(b > 31||b == 0) ++ cnt;
	}
	else if(a > 0&&a < 13)
	{
		if(b == 0||b > d[a]) ++ cnt;
	}
	else if(a > 0&&a < 20)
	{
		++ cnt;
		if(b > 31) ++ cnt; 
	}
	else 
	{
		++ cnt;
		a = a % 10;
		if(a == 0) a = 10;
		if(a > 0&&a < 3)
			cnt += min(b > d[a] || b == 0,b > d[a + 10] || b == 0);
		else
			cnt += b > d[a] || b == 0;
	}
	printf("%d",cnt);
	return 0;
}
