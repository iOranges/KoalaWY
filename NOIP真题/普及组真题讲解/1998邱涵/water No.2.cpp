#include<bits/stdc++.h>
#define R(a,b,c) for(register int a=b;a<=c;a++)
#define nR(a,b,c) for(register int a=b;a>=c;a--)
#define N 2005
#define INF 0x7f7f7f7f
#define Fill(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read()
{
    register int s=0,f=1;register char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    while(isdigit(c))s=s*10+(c^'0'),c=getchar();
    return s*f;
}
string cal(int x,int i=0,string s=string(""))
{
    if(x==0)return string("0");
    do if(x&1)s=(i==1?"2":"2("+cal(i)+")")+(s==""?"":"+")+s;
    while(++i,x>>=1);
    return s;
}
int main()
{
    cout<<cal(read())<<endl;
}
