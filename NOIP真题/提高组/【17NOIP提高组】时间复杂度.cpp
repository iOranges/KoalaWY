#include<cstdio>
#include<cstring>
int o[105];
bool use[50];
char s[105],stack[105];

int main()
{
	int t,n,len,O,cnt,top,flag3,flag4;
	register int i,j;
	scanf("%d",&t);
	while(t --)
	{
		memset(o,0,sizeof o);
		memset(use,0,sizeof use);
		scanf("%d",&n);
		gets(s);
		len = strlen(s);
		bool flag1 = false,flag2 = false,flag5 = false;
		O = cnt = top = flag3 = flag4 = 0;
		for(i = 0;i < len;++ i)
		{
			if(s[i] == '(') flag1 = true;
			else if(s[i] == ')') flag1 = false;
			else if(flag1&&s[i] == 'n') flag2 = true;
			else if(s[i] <= '9'&&s[i] >= '0')
				if(flag2) 
					while(s[i] <= '9'&&s[i] >= '0'&&i < len) 
						O = O * 10 + s[i ++] - '0';
		}
		for(i = 1;i <= n;++ i)
		{
			gets(s);
			len = strlen(s);
			flag1 = flag2 = flag3 = false;
			if(s[0] == 'F') 
			{
				++ cnt;
				for(j = 1;j < len;++ j)
				{
					if(s[j] >= 'a'&&s[j] <= 'z')
					{
						if(!flag1) 
						{
							flag1 = true;
							stack[++ top] = s[j];
							if(use[s[j] - 'a' + 1])
								flag5 = true;
							else use[s[j] - 'a' + 1] = true;
						}
						else if(!flag2)
							flag2 = true,flag3 = 0;
						else
						{
							if((!flag3)||flag4) o[cnt] = 0;
							else o[cnt] = 1;
						}
					}
					else if(s[j] >= '0'&&s[j] <= '9')
					{
						if(!flag2)
						{
							flag2 = true;
							while(s[j] >= '0'&&s[j] <= '9')
								flag3 = flag3 * 10 + s[j ++] - '0';
						}
						else
						{
							int z = 0;
							while(s[j] >= '0'&&s[j] <= '9')
								z = z * 10 + s[j ++] - '0';							
							if((!flag3)||(flag3 > z)) flag4 = cnt;
							o[cnt] = 0;	
						}
					}
				}			
			}
			else if(s[0] == 'E') 
			{
				int thy = 0;
				for(j = 1;j <= cnt;++ j)
					thy += o[j];
				if(thy > o[0]) o[0] = thy;	
				if(cnt == flag4) flag4 = 0;
				-- cnt;
				use[stack[top --] - 'a' + 1] = false;
			}
		}
		if(cnt != 0||flag5) 
			printf("ERR\n");
		else if(o[0] == O)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0; 
}
