#include<cstdio>
#include<cstring>
char s[1000005];

int main()
{
	char unkown;
	int f = 1,pre = 1,x = 0,y = 0,num;
	register int i;
	scanf("%s",s + 1);
	int n = strlen(s + 1);
	for(i = 1;i <= n;++ i)
	{
		if(s[i] == '=')
			f = -1,pre = 1;
		else if(s[i] == '-')
			pre = -1;
		else if(s[i] == '+')
			pre = 1;
		else if(s[i] >= '0'&&s[i] <= '9')
		{
			num = 0;
			while(s[i] >= '0'&&s[i] <= '9')
				num = num * 10 + s[i++] - '0';
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				unkown = s[i];	
				x += num * pre * f;			
			}
			else 
			{
				y += num * pre * f;	
				-- i;			
			}
		 } 
		else if(s[i] >= 'a' && s[i] <= 'z')
			x += f * 1 * pre;
	}
	double ans = y * -1.0 / x;
	if(ans < 0.000001&&ans >= -0.0000001)
		ans = 0;
	printf("%c=%.3lf",unkown,ans);
	return 0;
}
