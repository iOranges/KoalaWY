#include<bits/stdc++.h>
using namespace std;
const int p=10000;
char s[10000000],a[10000000];
int sum,m[10000000],n[10000000],c,k,tot,tot2,t;
int main()
{
	cin>>s+1;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(k>0)
		{
			k--;
			continue;
		}
		else if(k==0)
		{
			if(s[i]=='+'||s[i]=='*') {a[++tot]=s[i];}
			else
			{
				tot2++;c=i;t=0;
				while(s[c+t]>='0'&&s[c+t]<='9')
				{
					m[tot2]=(m[tot2]*10+s[c+t]-'0')%p;
					t++;
				}
				k=t-1;
			}
		}
	}
	for(int i=1;i<=tot2;i++)
		if(a[i]=='*')
		{
			m[i+1]=m[i]*m[i+1]%p;
			m[i]=0;
		}
	for(int i=1;i<=tot2;i++) sum=(sum+m[i])%p;
	printf("%d",sum);
}
