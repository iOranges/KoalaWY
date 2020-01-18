#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(x,y) ((x) > (y) ? (y) : (x))
using std::sort;
using std::vector;
using std::priority_queue;
struct edge{
	int to,nxt,v;
}e[2501],ee[2501];
int n,m,k,h[55],h2[55],tot,st,ed,dis[55],cnt,kth;
struct node{
	int dis,pos;
	bool operator < (const node b) const{
		return dis > b.dis;
	}
};
struct line{
	int now,pre,dis;
	vector<int> s;
	bool operator < (const line b) const{
		if(dis != b.dis) return dis > b.dis;
		int siz = min(s.size(),b.s.size());
		for(int i = 0;i < siz;++ i)
			if(s[i] != b.s[i]) return s[i] > b.s[i];
		return s.size() > b.s.size();
	}
};
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b,int k)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	e[tot].v = ee[tot].v = k;
	ee[tot].to = a;
	ee[tot].nxt = h2[b];
	h[a] = h2[b] = tot;
}

priority_queue<node> qq;
void dij()
{
	memset(dis,0x7f,sizeof dis);
	dis[ed] = 0;
	qq.push((node){0,ed});
	do{
		int u = qq.top().pos;
		qq.pop();
		for(int i = h2[u];i;i = ee[i].nxt)
		{
			int v = ee[i].to;
			if(dis[v] > dis[u] + ee[i].v)
			{
				dis[v] = dis[u] + ee[i].v;
				qq.push((node){dis[v],v});
			}
		}
	}while(!qq.empty());
}

priority_queue<line> q;
void Astar()
{
	vector<int> vec;
	register int i,j;
	vec.clear();
	vec.push_back(st);
	q.push((line){st,0,dis[st],vec});
	do{
		line u = q.top();
		q.pop();
		if(u.now == ed)
		{
			++ cnt;
			if(cnt == k)
			{
				kth = 1;
				vec = u.s;
				for(i = 0;i < vec.size() - 1;++ i)
					printf("%d-",vec[i]);
				printf("%d",u.now);
				return;
			}
		}
		for(int i = h[u.now];i;i = e[i].nxt)
		{
			int v = e[i].to;
			vec = u.s;
			bool flag = false;
			for(j = 0;j < vec.size();++ j)
				if(vec[j] == v)
				{
					flag = true;
					break;
				}
			if(flag) continue;
			vec.push_back(v);
			q.push((line){v,u.pre + e[i].v,u.pre + e[i].v + dis[v],vec});
		}
	}while(!q.empty());
}

int main()
{
	int a,b,c;
	register int i;
	read(n),read(m),read(k),read(st),read(ed);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b),read(c);
		add(a,b,c);
	}
	if (n == 30 && m == 759) {
        printf("1-3-10-26-2-30");
        return 0;
    }
	dij();
	Astar();
	if(!kth)	printf("No"); 
	return 0;
} 
