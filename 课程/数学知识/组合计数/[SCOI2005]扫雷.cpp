#include<cstdio>
int a[10005],w[10005];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int n,cnt = 0;
	register int i,j;
	read(n);
	for(i = 1;i <= n;++ i)
		read(w[i]);
	for(j = 0;j < 2;++ j)
	{
		a[1] = j,a[2] = w[1] - a[1];
		bool flag = true;
		for(i = 2;i < n;++ i)
		{
			a[i + 1] = w[i] - a[i] - a[i - 1];
			if(a[i] < 0||a[i] > 1)		
			{
				flag = false;
				break;
			}
		}
		if(!flag) continue;
		if((a[n] == 0||a[n] == 1)&&a[n] + a[n - 1] == w[n]) ++cnt;
	}
	printf("%d",cnt);
	return 0; 
 } 
