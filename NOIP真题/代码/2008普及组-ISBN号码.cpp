#include<bits/stdc++.h>
using namespace std;
int a[20],tot,sum;
char s[20];
int main()
{
    cin>>s+1;int len=strlen(s+1);
    for(int i=1;i<=12;i++)
        if(s[i]>='0'&&s[i]<='9') a[++tot]=s[i]-'0';
    for(int i=1;i<=9;i++) {sum+=a[i]*i;}sum%=11;
    if(sum==10&&s[len]=='X') cout<<"Right";
    else if(sum<10&&sum==s[len]-'0') cout<<"Right";
    else
    {
        for(int i=1;i<=12;i++) cout<<s[i];
        if(sum==10) cout<<'X';
        else cout<<sum;
    }
}
