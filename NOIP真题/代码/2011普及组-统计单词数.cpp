#include<bits/stdc++.h>
using namespace std;
char s[2330033],s1[20000];
int tot,sum,f;
int main()
{
    gets(s1+1);gets(s);
    int len=strlen(s),len1=strlen(s1+1);
    for(int i=0;i<len;i++)
    {
        if(s[i]!=' ') sum++;
        else
        {
            int x=i,tot1=0;
            if(sum==len1)
            {
                for(int j=sum;j>=1;j--)
                {
                    x--;
                    if(s[x]>=97) s[x]-=32;
                    if(s1[j]>=97) s1[j]-=32;
                    if(s[x]==s1[j]) tot1++;
                }
                if(tot1==len1)
                {
                    tot++;
                    if(tot==1) f=i-len1;
                }
            }
            sum=0;
        }
    }
    if(!tot) cout<<-1;
    else cout<<tot<<' '<<f;
}
