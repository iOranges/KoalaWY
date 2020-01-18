#include<cstdio>
char f[] = {"0123456789ABCDEFGHIJKLMNOQRSTUVWXYZ"};
void work(int x,int R)
{
	int top = 0,k;
	static int s[101];
	while(x)
	{
		s[++top] = x % R;
		x /= R; 
		if(s[top] < 0) s[top] -= R,++ x;
	}
	while(top)
	{
		k = s[top --];
		putchar(f[k]);
	 } 
}

int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	printf("%d=",n);
	work(n,r);
	printf("(base%d)",r);
	return 0;
}
