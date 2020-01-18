#include<bits/stdc++.h>
#define maxn 9005
#define base 10000
using namespace std;
struct bign{
    int len,s[maxn];
    bign(){len=1;memset(s,0,sizeof s);}
    void zero(){while(len>1&&s[len]==0)len--;}
    void write(char a[]){
        int lena=strlen(a),k=1;len=1;
        for(int i=0;i<lena;i++){s[len]+=(a[lena-i-1]-'0')*k;k*=10;if(k==base)k=1,len++;}
    }
    void read(){char a[maxn*4];scanf("%s",a);write(a);}
    void print(){zero();printf("%d",s[len]);for(int i=len-1;i>=1;i--)printf("%04d",s[i]);}
    bign operator = (int b){char a[maxn*4];sprintf(a,"%d",b);write(a);}
    bign operator * (bign b){
        bign c;c.len=len+b.len+1;
        for(int i=1;i<=len;i++){
            int x=0;
            for(int j=1;j<=b.len;j++){c.s[i+j-1]+=s[i]*b.s[j]+x;x=c.s[i+j-1]/base;c.s[i+j-1]%=base;}
            c.s[i+b.len]=x;
        }
        c.zero();return c;
    }
    bign operator * (int b){bign c;c=b;return *this*c;}
};
char s[50];
int n[50],k,x,y,tot[50];
bign ans;
bool f[50][50];
int main(){
    ans=1;
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++)n[i]=s[i]-'0';
    scanf("%d",&k);
    for(int i=1;i<=k;i++){scanf("%d%d",&x,&y);f[x][y]=1;}
    for(int i=0;i<=9;i++)f[i][i]=1;
    for(int l=0;l<=9;l++)
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                if(f[i][l]&&f[l][j])f[i][j]=1;
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++)
            if(f[i][j])tot[i]++;
    for(int i=0;i<len;i++)ans=ans*tot[n[i]];
    ans.print();
    return 0;
}
