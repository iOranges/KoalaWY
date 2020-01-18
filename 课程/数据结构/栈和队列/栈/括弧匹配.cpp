#include<cstring>
#include<cstdio>
char ch[300];
int a[300];
int main()
{
	int i=0,top=0;
	gets(ch);
	int len=strlen(ch);
	while(i<len)
	{
		switch(ch[i])
		{
			case'(':a[++top]=-1;break;
			case'[':a[++top]=-2;break;
			case')':a[++top]=1;break;
			case']':a[++top]=2;break;
		}
		if(a[top]+a[top-1]==0&&a[top]>0) top-=2;
		i++;
	}
	if(top==0) printf("OK");
	else printf("Wrong");
	return 0;
}
