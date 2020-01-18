#include<cstdio>
#define N 100005
int sum[N],cnt[N],son[N][2],fa[N],w[N];
//sum:该点及其子树的元素总数 cnt:该点表示元素的个数 
//son:0左儿子,1右儿子 fa:父亲 w:权值 
int n,m; //n为节点数，m为元素数 	
#define root son[0][1] //根节点 
inline void pushup(int rt)
{
	sum[rt] = sum[son[rt][0]] + sum[son[rt][1]] + cnt[rt]; //记得加上自己	
}

inline int getid(int rt)
{
	return son[fa[rt]][0] == rt ? 0 : 1; //获取编号 
}

inline void connect(int rt,int f,int id) //连接两点 
{
	fa[rt] = f;
	son[f][id] = rt;
}

inline void rotate(int rt) //将自己旋转至父亲的位置上 
{
	int f = fa[rt],rtid = getid(rt); //f为当前节点父亲，gf即父亲的父亲 
	int gf = fa[f],fid = getid(f); //rtid为当前点是父节点的哪个儿子,fid同理 
	connect(son[rt][rtid ^ 1],f,rtid);//连接自己的儿子与父亲 
	connect(f,rt,rtid ^ 1),connect(rt,gf,fid);//连接父亲与自己，自己与祖父 
	pushup(f),pushup(rt); //父亲是你的儿子，先更新老父亲，再更新你 
} 

void splay(int rt,int to) //将当前节点旋转至指定节点
{
	to = fa[to];
	while(fa[rt] ^ to) //即e[rt].fa != to 
	{
		int up = fa[rt];
		if(fa[up] == to)  rotate(rt); //父亲即为指定节点
		else if(getid(rt) ^ getid(up)) //不在一条线上，将自己向上旋转两次
			rotate(rt),rotate(rt);
		else //如果你和你的祖父在一条线上，先旋转父亲，再旋转自己
			rotate(up),rotate(rt); 
	}
}

inline void create(int v,int f,int id) //建一个新结点 
{
	++ n;
	w[n] = v;
	connect(n,f,id);
	sum[n] = cnt[n] = 1;
}

inline int find(int v) //找到权值等于或最接近V的节点 
{
	int rt = root;
	while(true)
	{
		if(w[rt] == v) return rt;
		int nxt = w[rt] > v ? 0 : 1;
		if(!son[rt][nxt]) return rt; //如果没有相等的元素，当前节点为最接近v的节点
		rt = son[rt][nxt];
	} 
}

void insert(int v) //插入元素 
{
	int rt = root;
	if(!m) create(v,root,1),rt = 1;
	else
		while(true)
		{
			++ sum[rt];//新节点肯定在下方，所以当前节点及其子树包含的元素++ 
			if(v == w[rt])
			{
				++ cnt[rt]; //有该元素便++出现次数 
				break;
			}
			int nxt = w[rt] > v ? 0 : 1;
			if(!son[rt][nxt])
			{
				create(v,rt,nxt); //没有则新建一个节点 
				rt = n;
				break;
			}
			rt = son[rt][nxt];
		}
	++ m;
	splay(rt,root);//因为新建节点可能会拉出一条链，所以需要将该节点splay到根节点。沿途rotate可恢复平衡
}

inline int get_rank(int v) //找到v在当前的排名 
{
	int k = find(v);
	if(v != w[k]) return -1;
	splay(k,root);
	return sum[son[root][0]] + 1;
}

int atrank(int k) //找到第k小的数 
{
	if(k > m) return -1;
	int rt = root;
	while(true)
	{
		int minuse = sum[rt] - sum[son[rt][1]];
		if(k > sum[son[rt][0]]&&k <= minuse) break; //x即为rt
		if(k < minuse) rt = son[rt][0]; //在左儿子中 
		else
		{
			k -= minuse; //减去比他小的个数
			rt = son[rt][1]; //在右儿子中 
		}
	}
	splay(rt,root); 
	return rt;
}

int pre(int v) //找前驱，即小于v的最大的数 
{
	splay(find(v),root);
	if(w[root] < v) return root;  
	int rt = son[root][0]; //跳到左儿子 
	while(son[rt][1]) rt = son[rt][1]; //在左儿子中一直找右儿子 
	return rt;
} 

int last(int v) //找后继，即大于v的最小的数 
{
	splay(find(v),root);
	if(w[root] > v) return root;
	int rt = son[root][1];
	while(son[rt][0]) rt = son[rt][0];
	return rt;
}

void remove(int v)
{
	int del = find(v);
	if(w[del] != v) return;
	-- m;
	splay(del,root);
	if(cnt[del] > 1) //如果有多个元素，删掉一个 
	{
		-- cnt[del];
		-- sum[del]; 
		return;
	}
	if(!son[del][0]) //没有左儿子，右儿子当根 
	{
		root = son[del][1];
		fa[root] = 0;
	}
	else //有左儿子，找到左儿子中最大的，令其成为左儿子，左儿子便没了它的右儿子 
	{
		int lef = son[del][0],rig = son[del][1];
		while(son[lef][1]) lef = son[lef][1];
		splay(lef,son[del][0]);
		connect(rig,lef,1),connect(lef,0,1); //把右儿子接在没了右儿子的左儿子上，左儿子当根
		root = lef;
		pushup(root);
	} 
}
#undef root
template<typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);int f = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getc(stdin);}
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
	x *= f;
}

int main()
{
	int p,opt,x;
	register int i;
	read(p);
	for(i = 1;i <= p;++ i)
	{
		read(opt),read(x);
		switch(opt)
		{
			case 1:insert(x);break;
			case 2:remove(x);break;
			case 3:printf("%d\n",get_rank(x));break;
			case 4:printf("%d\n",w[atrank(x)]);break;
			case 5:printf("%d\n",w[pre(x)]);break;
			case 6:printf("%d\n",w[last(x)]);break;
		}
	}
	return 0;
}
