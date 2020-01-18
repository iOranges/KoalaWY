#include<bits/stdc++.h>
using namespace std;
char s[100000],s1[50000],s2[50000],x;
int tot1,tot2,tot,a1,a2;
int main()
{
	scanf("%s",s+1);int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='-'&&s[i-1]=='-') s[i]='+',s[i-1]='\0';
		if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')) x=s[i];
	}
	while(s[++tot]!='=') s1[++tot1]=s[tot];
	for(int i=tot+1;i<=len;i++) s2[++tot2]=s[i];
	for(int i=1;i<=tot1;i++)
	{
		if(s1[i]==x)
		{
			s1[i]='\0';
			int w=i,ans=1,sum1=0;
			if(s1[i-1]=='\0'||s1[i-1]=='-'||s1[i-1]=='+') sum1=1;
			while(s1[--w]>='0'&&s1[w]<='9')
			{
				sum1+=(s1[w]-'0')*ans;
				ans*=10;
				s1[w]='\0';
			}
			if(s1[w]=='-') a1-=sum1;
			else a1+=sum1;
			s1[w]='\0';
		}
	}
	for(int i=1;i<=tot1;i++)
	{
		if(s1[i]<'0'||(s1[i]>='0'&&i==1))
		{
			int w=i,ans=1,sum1=0,flag=true;
			if(s1[w]=='-'&&w==1)
			{
				while(s1[++w]>='0')
				{
					sum1*=ans;
					sum1+=(s1[w]-'0');
					ans*=10;
				}
			}
			else if(w==1)
			{
				while(s1[w]>='0')
				{
					sum1*=ans;
					sum1+=(s1[w]-'0');
					ans*=10;w++;
					flag=false;
				}
			}
			else
			{
				while(s1[++w]>='0')
				{
					sum1*=ans;
					sum1+=(s1[w]-'0');
					ans*=10;
				}
			}
			if((s1[w]<'0'&&s1[w-1]!=0)&&w==2&&flag) sum1+=s1[1]-'0';
			if(s1[i]=='-') a2+=sum1;
			else a2-=sum1;
		}
	}
	for(int i=1;i<=tot2;i++)
	{
		if(s2[i]==x)
		{
			s2[i]='\0';
			int w=i,ans=1,sum2=0;
			if(s2[i-1]=='\0'||s2[i-1]=='-'||s2[i-1]=='+') sum2=1;
			while(s2[--w]>='0'&&s2[w]<='9')
			{
				sum2+=(s2[w]-'0')*ans;
				ans*=10;
				s2[w]='\0';
			}
			if(s2[w]=='-') a1+=sum2;
			else a1-=sum2;
			s2[w]='\0';
		}
	}
	for(int i=1;i<=tot2;i++)
	{
		if(s2[i]<'0'||(s2[i]>='0'&&i==1))
		{
			int w=i,ans=1,sum2=0,flag=true;
			if(s2[w]=='-'&&w==1)
			{
				while(s2[++w]>='0')
				{
					sum2*=ans;
					sum2+=(s2[w]-'0');
					ans*=10;
				}
			}
			else if(w==1)
			{
				while(s2[w]>='0')
				{
					sum2*=ans;
					sum2+=(s2[w]-'0');
					ans*=10;w++;
					flag=false;
				}
			}
			else
			{
				while(s2[++w]>='0')
				{
					sum2*=ans;
					sum2+=(s2[w]-'0');
					ans*=10;
				}
			}
			if((s2[w]<'0'&&s2[w-1]!=0)&&w==2&&flag) sum2+=s2[1]-'0';
			if(s2[i]=='-') a2-=sum2;
			else a2+=sum2;
		}
	}
	if(a2==0&&a1<0) printf("%c=0.000",x);
	else printf("%c=%.3lf",x,1.0*a2/a1);
}
