#include<cstdio>
int main()
{
	int n,i,j,f0=1,f1=1,f2;
	scanf("%d",&n);
	if(n==1||n==2)
		printf("1");
	else
	{
		for(i=3;i<=n;i++)
		{
			f2=f0+f1;
			f0=f1;
			f1=f2;	
		}
		printf("%d",f2);
	}
	return 0;
}
