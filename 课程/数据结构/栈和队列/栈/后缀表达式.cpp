#include<cstdio>
#include<cstring>
long long a[1001];
char ch[1001];
int main()
{
	int i=0,top=0,k=0;
	long long x;
	gets(ch);
	while((ch[i]>='0'&&ch[i]<='9')||ch[i]==' ')
	{
		x=0;	
		while(ch[i]>='0'&&ch[i]<='9')
			x = x*10+ch[i++]-48,k=i;
		a[++top] = x;
		i++;
	}
	while(ch[k]!='@')
	{
		switch(ch[k])
		{
			case'+':a[--top]+=a[top+1];break;
			case'-':a[--top]-=a[top+1];break;
			case'*':a[--top]*=a[top+1];break;
			case'/':a[--top]/=a[top+1];break;
		}
		k++;
	}
	printf("%lld",a[1]);
	return 0;
}
