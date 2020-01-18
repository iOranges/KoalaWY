#include<cstring>
#include<cstdio>
char ch[300];
int a[300];
int main()
{
	int n,i,top;
	bool ok;
	scanf("%d\n",&n);
	for(int k=1;k<=n;k++)
	{
		i=0,top=0,ok=true;
		gets(ch);
		int len=strlen(ch);
		while(i<len)
		{
			switch(ch[i]) 
			{
				case'<':a[++top]=-1;break;
				case'>':a[++top]=1;break;
				case'(':a[++top]=-2;break;
				case')':a[++top]=2;break;
				case'[':a[++top]=-3;break;
				case']':a[++top]=3;break;
				case'{':a[++top]=-4;break;
				case'}':a[++top]=4;break;
			}
			if(a[top]>0&&a[top-1]<0)
			{
				if(a[top]+a[top-1]==0)
					top-=2;			
			}
			else if(a[top]<0&&a[top-1]>0)
			{
				ok = false;
				break;				
			}
			else if(a[top]>0&&a[top-1]>0)
			{
				ok = false;
				break;				
			}
			else if(a[top]<0&&a[top-1]<0&&a[top]<a[top-1])
			{
				ok = false;
				break;
			}
			i++;
		}
		if(top==0&&ok) printf("YES\n");
		else printf("NO\n");		
	} 
	return 0;
}
