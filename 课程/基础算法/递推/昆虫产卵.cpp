#include<cstdio>
long long a[55],b[55];
int main()
{
	int x,y,z,i,j;
	scanf("%d%d%d",&x,&y,&z); //隔x月产卵,一次产y个卵,总计z月 
	for(i=1;i<=x;i++)
		a[i]=1;
	for(i=x+1;i<=z+1;i++)
	{
		b[i]=a[i-x]*y;
		a[i]=a[i-1]+b[i-2];
	}
	printf("%lld",a[z+1]);
	return 0;
}
