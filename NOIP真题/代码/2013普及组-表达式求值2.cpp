#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=10000;
char s[10000005],s1[10000005];
ll s2[10000005];
int tot1,tot2,sum;
int main()
{
	cin>>s+1;int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]<'0')
		{
			s1[++tot1]=s[i];
			int w=i;ll ans=1;tot2++;
			while(s[--w]>='0'&&s[w]<='9')
			{
				s2[tot2]+=(ll)(s[w]-'0')*ans;
				ans*=10;
			}
		}
	}
	tot2++;ll ans=1;
	for(int i=len;s[i]>='0'&&s[i]<='9';i--)
	{
		s2[tot2]+=(s[i]-'0')*ans;
		ans*=10;
	}
	for(int i=1;i<=tot1;i++)
	{
		if(s1[i]=='*')
		{
			s2[i+1]=(s2[i]%p*s2[i+1]%p)%p;
			s2[i]=0;
		}
	}
	for(int i=1;i<=tot2;i++) sum=(sum+s2[i]%p)%p;
	printf("%d",sum);
}
