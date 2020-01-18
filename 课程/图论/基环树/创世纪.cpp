#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<stack>
#define LL long long
#define debug cout<<"bug"<<endl;
using namespace std;
const int maxn=1000010;
inline void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    x*=f;}
struct node{int v,nxt;}e[maxn];
int head[maxn],tot;
inline void add(int x,int y){
	tot++;
	e[tot].v =y;
	e[tot].nxt =head[x];
	head[x]=tot;
}
int n,a,cnt,ra[maxn],rb[maxn],now;

int fa[maxn];
inline int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
    return fa[x];
}

int f[maxn],g[maxn];//f �� g ���� 
inline void dfs(int x)
{
	int t=1<<30;
	g[x]=0;
	for(int i=head[x];i;i=e[i].nxt )
	{
		int v=e[i].v ;
		if(v!=now)
		    dfs(v);
		g[x]+=max(g[v],f[v]);
		t=min(t, max(g[v],f[v])-g[v] ); //û����˾������еļ��� 
	}
	f[x]=g[x]+1-t;
}
int main()
{
	int ans=0;
	read(n);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
	    read(a);
		if(find(a)!=find(i))
		{
		    add(a,i);
			fa[fa[a]]=fa[i];
		}
		else
		{
			cnt++,ra[cnt]=a,rb[cnt]=i;//�����ڻ����ǲ���ͨ�� 
		}
	} 
	for(int i=1;i<=cnt;i++)//ɭ�� 
	{
		dfs(ra[i]);
//		now=ra[i];//�ϻ� 
		dfs(rb[i]),a=f[rb[i]];//����һ�ֵ�dfs���ǲ���ȥ���� ra[i]���ӵ�f gֵ�ģ����±���û��ra[i]��ֵҲ��û�еģ�������Ҫ��һ����ǰ������� 
		f[ra[i]]=g[ra[i]]+1;//ǿ������ ����max�г���һ����ѡ��f������������ƽڵ�rb[i]���ᱻѡ�� �������������ĳ�������� 
		dfs(rb[i]), ans+=max(g[rb[i]],a);
	}
	printf("%d",ans);
	return 0;
}
