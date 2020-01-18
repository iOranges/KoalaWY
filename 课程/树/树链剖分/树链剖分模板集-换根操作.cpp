#include<bits/stdc++.h>
#define N 100005
#define lc (k<<1)
#define rc (k<<1)|1
#define in read()
#define int long long
using namespace std;
inline int read(){
	char ch;int f=1,res=0;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') f=-1;
	while(ch>='0'&&ch<='9'){res=(res<<3)+(res<<1)+ch-'0';ch=getchar();}
	return f==1?res:-res;
}
int n,m,a[N],root;
int top[N],idx[N<<2],pos[N<<2],tot=0;
int fa[N],son[N],sze[N],dep[N];
int lzy[N<<2],sum[N<<2];
int nxt[N<<1],to[N<<1],head[N],ecnt=0;
inline void add(int x,int y){
	nxt[++ecnt]=head[x];head[x]=ecnt;to[ecnt]=y;
	nxt[++ecnt]=head[y];head[y]=ecnt;to[ecnt]=x;
}
void dfs1(int u,int fu){
	sze[u]=1;
	for(int e=head[u];e;e=nxt[e]){
		int v=to[e];
		if(v==fu) continue;
		dep[v]=dep[u]+1;fa[v]=u;
		dfs1(v,u);
		sze[u]+=sze[v];
		if(sze[v]>sze[son[u]]) son[u]=v;
	}
}
void dfs2(int u){
	if(son[u]){
		int v=son[u];
		idx[pos[v]=++tot]=v;
		top[v]=top[u];
		dfs2(v);
	}
	for(int e=head[u];e;e=nxt[e]){
		int v=to[e];
		if(v==fa[u]||v==son[u]) continue;//
		idx[pos[v]=++tot]=v;
		top[v]=v;
		dfs2(v);
	}
}
inline void build(int k,int l,int r){
	if(l==r){
		sum[k]=a[idx[l]];
		return ;
	}
	int mid=l+r>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	sum[k]=sum[lc]+sum[rc];
}
inline void pushdown(int k,int l,int r){
	int mid=l+r>>1;
	lzy[lc]+=lzy[k];sum[lc]+=(mid-l+1)*lzy[k];
	lzy[rc]+=lzy[k];sum[rc]+=(r-mid)*lzy[k];
	lzy[k]=0;
}
inline void modify(int k,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		lzy[k]+=v;sum[k]+=(r-l+1)*v;
		return;
	}
	if(lzy[k]) pushdown(k,l,r);
	int mid=l+r>>1;
	if(x<=mid) modify(lc,l,mid,x,y,v);
	if(y>mid) modify(rc,mid+1,r,x,y,v);
	sum[k]=sum[lc]+sum[rc];
}
inline void modifypath(int x,int y,int v){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		modify(1,1,n,pos[top[x]],pos[x],v);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	modify(1,1,n,pos[y],pos[x],v);
}
inline int getlca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]>dep[y]?y:x;
}
inline int find(int x,int y){//找 x 到 y 路径上第一个儿子 
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		if(fa[top[x]]==y) return top[x];
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return son[y];
}
inline void modifysub(int u,int k){
	if(u==root)  return modify(1,1,n,1,n,k);
	int lca=getlca(u,root);
	if(lca!=u) return modify(1,1,n,pos[u],pos[u]+sze[u]-1,k);
	else {
		int child=find(u,root);
		modify(1,1,n,1,n,k);
		modify(1,1,n,pos[child],pos[child]+sze[child]-1,-k);
		return;
	}
}

inline int query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y){return sum[k];}
	int res=0;
	if(lzy[k]) pushdown(k,l,r);
	int mid=l+r>>1;
	if(x<=mid) res+=query(lc,l,mid,x,y);
	if(y>mid) res+=query(rc,mid+1,r,x,y);
	return res;
} 
inline int querypath(int x,int y){
	int res=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		res+=query(1,1,n,pos[top[x]],pos[x]);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	res+=query(1,1,n,pos[y],pos[x]);
	return res;
}
inline int querysub(int x){
	if(x==root) return query(1,1,n,1,n);
	int lca=getlca(x,root);
	if(lca!=x) return query(1,1,n,pos[x],pos[x]+sze[x]-1);
	int child=find(x,root);
	int res=query(1,1,n,1,n);
	res-=query(1,1,n,pos[child],pos[child]+sze[child]-1);
	return res;
}
signed main(){
	n=in;root=1;
	int i,j,k;
	for(i=1;i<=n;++i) a[i]=in;
	for(i=2;i<=n;++i){ j=in;add(i,j); }
	dfs1(1,0);
	idx[1]=1;pos[1]=++tot;top[1]=1;
	dfs2(1);
	build(1,1,n);
	m=in;int u,v;
	while(m--){
		int op=in;
		if(op==1){ u=in;root=u; }
		else if(op==2){
			u=in;v=in;k=in;
			modifypath(u,v,k);
		}
		else if(op==3){
			u=in;k=in;
			modifysub(u,k);
		}
		else if(op==4){
			u=in;v=in;
			cout<<querypath(u,v)<<'\n';
		}
		else {
			u=in;
			cout<<querysub(u)<<'\n';
		}
	}
	return 0;
}
 
