#include<set>
#include<ctime>
#include<cstdio>
#include<algorithm>
#define N 50005
#define max(x,y) ((x) > (y) ? (x) : (y))
using std::multiset;
using std::lower_bound;
struct node{
	int v,nxt,to;
}e[N << 1];
int h[N],tot,m,n,len,w[N],num;
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
}

inline void add(int a,int b,int c)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	e[tot].v = c;
	h[a] = tot;
}

void dfs1(int u,int pre)
{
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		w[v] = e[i].v;
		dfs1(v,u);
	}
}

int dfs2(int u,int pre)
{
	multiset<int> s;	
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		int k = dfs2(v,u);
		if(k != -1) s.insert(k);
	}
	multiset<int>::iterator it;
	int maxx = 0;
	while(!s.empty())
	{
		if(s.size() == 1) {
			maxx = max(*s.begin(),maxx);
			break;
		}
		it = s.lower_bound(len - *s.begin());
		if(it == s.begin()) ++ it;
		if(it != s.end()) s.erase(it),++ num,s.erase(s.begin());
		else {
			maxx = max(maxx,*s.begin());
			s.erase(*s.begin());
		}
	}
	if(w[u] + maxx >= len){
		++ num;
		return -1;
	}
	return maxx + w[u];
}

bool check(int mid)
{
	len = mid,num = 0;
	dfs2(1,0);
	if(num >= m) return true;
	else return false;
}

int main()
{
	int a,b,c;
	read(n),read(m);
	register int i,l = 0,r = 0,mid;
	for(i = 1;i < n;++ i)
	{
		read(a),read(b),read(c);
		add(a,b,c),add(b,a,c),r += c;
	} 
	dfs1(1,0);r /= m; 
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d",r);
	return 0;
}
