#include<cstdio>
#include<cstring>
struct node{
	int e,next,v;
}tree[80010],query[410];
int f[40010],h1[40010],cnt,dis[40010],lca[205],h2[40010],tot;
//h2�������Ϊ40010,������410������ 
bool visit[40010];
int find(int x)			//�Ҹ��� 
{
	if(x!=f[x]) f[x] = find(f[x]);
	return f[x];
}

void add1(int a,int b,int k) //add���� 
{
	tree[++cnt].e = b;
	tree[cnt].next = h1[a];
	tree[cnt].v = k;
	h1[a] = cnt;
}

void add2(int a,int b,int k) //add��ѯ�� 
{
	query[++tot].e = b;
	query[tot].next = h2[a];
	query[tot].v = k;
	h2[a] = tot;
}

void dfs(int u,int pre)
{
	//���� visit[u] = true;Ҳ���� 
	for(int i=h1[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
		{
			dis[tree[i].e] = dis[u] + tree[i].v;
			dfs(tree[i].e,u);
			f[tree[i].e] = u; 
		}
	visit[u] = true; 
	for(int i=h2[u];i;i=query[i].next)
		if(visit[query[i].e])
			lca[query[i].v] = dis[query[i].e]+dis[u]-2*dis[find(query[i].e)];
}

int main()
{
	int t,k,i,n,a,b,m;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof f);
		memset(h1,0,sizeof h1);
		memset(h2,0,sizeof h2);
		memset(lca,0,sizeof lca);
		memset(dis,0,sizeof dis);
		memset(visit,0,sizeof visit);
		cnt = tot = 0;				    //��� 
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			f[i] = i;
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&k);
			add1(a,b,k),add1(b,a,k);	
		}
		int cc = 0; //cc�����ѯ���� 
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			add2(a,b,++cc);
			add2(b,a,cc);
		}
		dfs(1,0);
		for(i=1;i<=cc;i++)
			printf("%d\n",lca[i]);
	}
	return 0;
}
