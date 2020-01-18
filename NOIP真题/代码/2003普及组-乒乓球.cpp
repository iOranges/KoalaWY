#include<bits/stdc++.h>
using namespace std;
char s,ss[10000000];
int s1[30000][2],s2[30000][2],tot1,tot2,len1,len2,len3,len4,tot;
int main()
{
    while(1)
    {
        cin >> s;
        if(s=='E') break;
        ss[++tot]=s;
    }
    for(int i=1;i<=tot;i++)
    {
        if(ss[i]=='W') len1++;
        else len2++;
        if(abs(len1-len2)>=2&&len1>=11||abs(len1-len2)>=2&&len2>=11)
        {
            s1[++tot1][0]=len1,s1[tot1][1]=len2;
            len1=len2=0;
        }
    }
    for(int i=1;i<=tot;i++)
    {
        if(ss[i]=='W') len3++;
        else len4++;
        if(abs(len3-len4)>=2&&len3>=21||abs(len3-len4)>=2&&len4>=21)
        {
            s2[++tot2][0]=len3,s2[tot2][1]=len4;
            len3=len4=0;
        }
    }
    for(int i=1;i<=tot1;i++) printf("%d:%d\n",s1[i][0],s1[i][1]);
    printf("%d:%d\n",len1,len2);
    puts("");
    for(int i=1;i<=tot2;i++) printf("%d:%d\n",s2[i][0],s2[i][1]);
    printf("%d:%d",len3,len4);
}
