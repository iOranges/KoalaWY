/*
��Ŀ��
ʱ�䣺
������
��ǩ��
���ݷ�Χ��
*/
/*-----------------------���㷨��-------------------------*/
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
/*-----------------------����������-----------------------*/
int B[101][101][11],S[101][101][11];//����[l,r]�ڷֳ�i�ε����/Сֵ
int n,m;
int a[101];//a���ǰ׺��
/*----------------------�ṹ����--------------------------*/
//struct eg{
//  int to,val,nxt;
//}c[maxm];
/*---------------------�Ż����������---------------------------*/
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
/*---------------------������-------------------------*/
//void add(int x,int y,int w){
//  c[++tot].to=y;
//  c[tot].val=w;
//  c[tot].nxt=head[x];
//  head[x]=tot;
//}
int mod(int x){
    return (x%10+10)%10;
    //�չ˸�����
    //������mo����λ�ټ���10
    //��֤����Ϊ����
}
/*---------------------��������-----------------------*/
int main(){
    read(n);read(m);
    F1(1,n,1,i){read(a[i]);a[i+n]=a[i];}//ģ����β����
    F1(1,n<<1,1,i) a[i]+=a[i-1];//ǰ׺��
    F1(1,n<<1,1,l)
    F1(l,n<<1,1,r)
    B[l][r][1]=S[l][r][1]=mod(a[r]-a[l-1]);
    //l:����˵�Ϊlʱ
    //r:���Ҷ˵�Ϊrʱ
    //1:���ֶ���Ϊ1ʱ
    //����l��rʱ������֮��
    //ģ�ⲻ�ֶε����
    F1(2,m,1,i)
    F1(1,n<<1,1,j)
    F1(i+j-1,n<<1,1,r)
    S[j][r][i]=oo;
    //�ó�ֵ
    F1(2,m,1,i)//ö�ٷֶ���
    F1(1,n<<1,1,l)//ö����˵�
    F1(l+i-1,n<<1,1,r)//ö���Ҷ˵�
    F1(l+i-2,r-1,1,k)//ö�ٵ�ǰ�ֵĶϵ�
    //s[l][k][i-1]��l��kʱ�ֳ�i-1�ε����ֵ
    //a[r]-a[k],�ϵ��Ҷ˵���ǰ�ֵ��Ҷ˵�
    S[l][r][i]=min(S[l][r][i],S[l][k][i-1]*mod(a[r]-a[k])),
    B[l][r][i]=max(B[l][r][i],B[l][k][i-1]*mod(a[r]-a[k]));
    int maxn=0,minn=oo;
    F1(1,n,1,i){
        maxn=max(maxn,B[i][i+n-1][m]);//��ǰ����ɨһ��
        minn=min(minn,S[i][i+n-1][m]);
    }
    write(minn);write(maxn);
    return 0;
}
