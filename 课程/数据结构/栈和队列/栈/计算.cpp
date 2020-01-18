#include<cmath>
#include<cstdio>
#include<cstring>
char ch[2001],b[2001];
int a[2001],top=1;
void plus()
{
	switch(b[top])
	{
		case '+':a[top-1]+=a[top];break;
		case '-':a[top-1]-=a[top];break;
		case '*':a[top-1]*=a[top];break;
		case '/':a[top-1]/=a[top];break;
		case '^':a[top-1]=pow(a[top-1],a[top]);break;
	}
	top--;
}

int first(char x)
{
	if(x=='+'||x=='-') return 1;
	if(x=='*'||x=='/') return 2;
	if(x=='^') return 3;
	return 0;
}

int main()
{
	int i=0,x;
	scanf("%s",ch);
	int len = strlen(ch);
	ch[len]=')';
	b[1]='(';
	for(i=0;i<=len;i++)
	{
		while(ch[i]=='(')
		{
			b[++top] = '(';
			i++;
		}
		if(ch[i]>='0'&&ch[i]<='9')
		{
			x=0;
			while(ch[i]>='0'&&ch[i]<='9')
				x = x*10+ch[i++]-48;
			a[top] = x;			
		}
		while(true)
		{
			if(ch[i]==')')
			{
				while(b[top]!='(') plus();
				a[top-1]=a[top];	
				top--;
			}
			else
			{
				while(first(ch[i])<=first(b[top])) plus();
				b[++top] = ch[i];
				break;
			}
			i++;
			if(i>len) break;
		}
	}
	printf("%d",a[0]);
	return 0;
}
