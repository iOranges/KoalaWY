/*
题目：
时间：
方法：
标签：
数据范围：
*/
/*-----------------------非算法区-------------------------*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#define M 1005
#define N 10005
#define inf 0x7f7f7f7f
#define pi 0e-18
#define re register
#define un unsigned
#define ll long long
#define F1(a,b,c,d) for(register int d=a;d<=b;d+=c)
#define F2(a,b,c,d) for(register int d=a;d>=b;d-=c)
#define maxm 1000005
#define oo 2147483647
using namespace std;
/*-----------------------变量定义区-----------------------*/
int B[101][101][11],S[101][101][11];//区间[l,r]内分成i段的最大/小值
int n,m;
int a[101];//a存放前缀和
/*----------------------结构体区--------------------------*/
//struct eg{
//  int to,val,nxt;
//}c[maxm];
/*---------------------优化输入输出区---------------------------*/
inline void read(int &x){
    x=0;char c=getchar();int f=1;
    for(;c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
    for(;c<='9'&&c>='0';c=getchar())x=x*10+c-'0';
    x*=f;
}
inline void write(int x){
    int num=0;char c[15];
    if(x==0) putchar(48);
    if(x<0) x*=-1,putchar('-');
    while(x)c[++num]=x%10+'0',x/=10;
    while(num)putchar(c[num--]);
    putchar('\n');
}
/*---------------------函数区-------------------------*/
//void add(int x,int y,int w){
//  c[++tot].to=y;
//  c[tot].val=w;
//  c[tot].nxt=head[x];
//  head[x]=tot;
//}
int mod(int x){
    return (x%10+10)%10;
    //照顾负数：
    //将负数mo到个位再加上10
    //保证负数为正数
}
/*---------------------主函数区-----------------------*/
int main(){
    read(n);read(m);
    F1(1,n,1,i){read(a[i]);a[i+n]=a[i];}//模拟首尾相连
    F1(1,n<<1,1,i) a[i]+=a[i-1];//前缀和
    F1(1,n<<1,1,l)
    F1(l,n<<1,1,r)
    B[l][r][1]=S[l][r][1]=mod(a[r]-a[l-1]);
    //l:当左端点为l时
    //r:当右端点为r时
    //1:当分段数为1时
    //当从l到r时的数字之和
    //模拟不分段的情况
    F1(2,m,1,i)
    F1(1,n<<1,1,j)
    F1(i+j-1,n<<1,1,r)
    S[j][r][i]=oo;
    //置初值
    F1(2,m,1,i)//枚举分段数
    F1(1,n<<1,1,l)//枚举左端点
    F1(l+i-1,n<<1,1,r)//枚举右端点
    F1(l+i-2,r-1,1,k)//枚举当前分的断点
    //s[l][k][i-1]从l到k时分出i-1段的最大值
    //a[r]-a[k],断点右端到当前分的右端点
    S[l][r][i]=min(S[l][r][i],S[l][k][i-1]*mod(a[r]-a[k])),
    B[l][r][i]=max(B[l][r][i],B[l][k][i-1]*mod(a[r]-a[k]));
    int maxn=0,minn=oo;
    F1(1,n,1,i){
        maxn=max(maxn,B[i][i+n-1][m]);//从前往后扫一遍
        minn=min(minn,S[i][i+n-1][m]);
    }
    write(minn);write(maxn);
    return 0;
}
