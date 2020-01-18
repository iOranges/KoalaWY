#include<cstdio>
char s[200005]; 

int main()
{
	int n,m,cnt = 0;
	bool flag = false;
	register int i;
	scanf("%d%s",&n,s + 1);
	if(n & 1) 
	{
		printf("No");
		return 0;
	 } 
	for(i = 1;i <= n;++ i)
	{
		if(s[i] == ')')
		{
			if(!cnt)
			{
				if(!flag) 
					flag = true;
				else 
				{
					printf("No");
					return 0;					
				}		
			}
			else cnt--;
		}
		else ++ cnt;
	}
	if((cnt == 1&&flag)||(cnt == 0&&!flag))
		printf("Yes");
	else
		printf("No");
	return 0;
}
