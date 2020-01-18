#include<bits/stdc++.h>
using namespace std;
int x,sum,a[1005];
char s[505];
bool hw(int n)
{
	for(int i=1;i<=n/2;i++)
		if(a[i]!=a[n-i+1]) return false;
	return true;                  //判断是否是回文数 
}
int jia(int n)
{
	int c[1001]={0};
	for(int i=1;i<=n;i++)
	{
		c[i]+=a[i]+a[n-i+1];
		c[i+1]+=c[i]/x;
		c[i]%=x;
	}
	if(c[n+1]) n++;
	for(int i=n;i>=1;i--) a[i]=c[i];
	return n;                     //注意返回新的位数 n 
}
int main()
{
	scanf("%d%s",&x,s+1);int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]<65) a[i]=s[i]-'0';
		else a[i]=s[i]-55;        //为16进制准备 
	}
	while(sum<=30)
	{
		if(hw(len))
		{
			printf("STEP=%d",sum);
			return 0;
		}
		sum++;
		len=jia(len);
	}
	puts("Impossible!");
}
