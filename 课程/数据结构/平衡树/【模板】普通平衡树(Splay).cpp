#include<cstdio>
#define N 100005
int sum[N],cnt[N],son[N][2],fa[N],w[N];
//sum:�õ㼰��������Ԫ������ cnt:�õ��ʾԪ�صĸ��� 
//son:0�����,1�Ҷ��� fa:���� w:Ȩֵ 
int n,m; //nΪ�ڵ�����mΪԪ���� 	
#define root son[0][1] //���ڵ� 
inline void pushup(int rt)
{
	sum[rt] = sum[son[rt][0]] + sum[son[rt][1]] + cnt[rt]; //�ǵü����Լ�	
}

inline int getid(int rt)
{
	return son[fa[rt]][0] == rt ? 0 : 1; //��ȡ��� 
}

inline void connect(int rt,int f,int id) //�������� 
{
	fa[rt] = f;
	son[f][id] = rt;
}

inline void rotate(int rt) //���Լ���ת�����׵�λ���� 
{
	int f = fa[rt],rtid = getid(rt); //fΪ��ǰ�ڵ㸸�ף�gf�����׵ĸ��� 
	int gf = fa[f],fid = getid(f); //rtidΪ��ǰ���Ǹ��ڵ���ĸ�����,fidͬ�� 
	connect(son[rt][rtid ^ 1],f,rtid);//�����Լ��Ķ����븸�� 
	connect(f,rt,rtid ^ 1),connect(rt,gf,fid);//���Ӹ������Լ����Լ����游 
	pushup(f),pushup(rt); //��������Ķ��ӣ��ȸ����ϸ��ף��ٸ����� 
} 

void splay(int rt,int to) //����ǰ�ڵ���ת��ָ���ڵ�
{
	to = fa[to];
	while(fa[rt] ^ to) //��e[rt].fa != to 
	{
		int up = fa[rt];
		if(fa[up] == to)  rotate(rt); //���׼�Ϊָ���ڵ�
		else if(getid(rt) ^ getid(up)) //����һ�����ϣ����Լ�������ת����
			rotate(rt),rotate(rt);
		else //����������游��һ�����ϣ�����ת���ף�����ת�Լ�
			rotate(up),rotate(rt); 
	}
}

inline void create(int v,int f,int id) //��һ���½�� 
{
	++ n;
	w[n] = v;
	connect(n,f,id);
	sum[n] = cnt[n] = 1;
}

inline int find(int v) //�ҵ�Ȩֵ���ڻ���ӽ�V�Ľڵ� 
{
	int rt = root;
	while(true)
	{
		if(w[rt] == v) return rt;
		int nxt = w[rt] > v ? 0 : 1;
		if(!son[rt][nxt]) return rt; //���û����ȵ�Ԫ�أ���ǰ�ڵ�Ϊ��ӽ�v�Ľڵ�
		rt = son[rt][nxt];
	} 
}

void insert(int v) //����Ԫ�� 
{
	int rt = root;
	if(!m) create(v,root,1),rt = 1;
	else
		while(true)
		{
			++ sum[rt];//�½ڵ�϶����·������Ե�ǰ�ڵ㼰������������Ԫ��++ 
			if(v == w[rt])
			{
				++ cnt[rt]; //�и�Ԫ�ر�++���ִ��� 
				break;
			}
			int nxt = w[rt] > v ? 0 : 1;
			if(!son[rt][nxt])
			{
				create(v,rt,nxt); //û�����½�һ���ڵ� 
				rt = n;
				break;
			}
			rt = son[rt][nxt];
		}
	++ m;
	splay(rt,root);//��Ϊ�½��ڵ���ܻ�����һ������������Ҫ���ýڵ�splay�����ڵ㡣��;rotate�ɻָ�ƽ��
}

inline int get_rank(int v) //�ҵ�v�ڵ�ǰ������ 
{
	int k = find(v);
	if(v != w[k]) return -1;
	splay(k,root);
	return sum[son[root][0]] + 1;
}

int atrank(int k) //�ҵ���kС���� 
{
	if(k > m) return -1;
	int rt = root;
	while(true)
	{
		int minuse = sum[rt] - sum[son[rt][1]];
		if(k > sum[son[rt][0]]&&k <= minuse) break; //x��Ϊrt
		if(k < minuse) rt = son[rt][0]; //��������� 
		else
		{
			k -= minuse; //��ȥ����С�ĸ���
			rt = son[rt][1]; //���Ҷ����� 
		}
	}
	splay(rt,root); 
	return rt;
}

int pre(int v) //��ǰ������С��v�������� 
{
	splay(find(v),root);
	if(w[root] < v) return root;  
	int rt = son[root][0]; //��������� 
	while(son[rt][1]) rt = son[rt][1]; //���������һֱ���Ҷ��� 
	return rt;
} 

int last(int v) //�Һ�̣�������v����С���� 
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
	if(cnt[del] > 1) //����ж��Ԫ�أ�ɾ��һ�� 
	{
		-- cnt[del];
		-- sum[del]; 
		return;
	}
	if(!son[del][0]) //û������ӣ��Ҷ��ӵ��� 
	{
		root = son[del][1];
		fa[root] = 0;
	}
	else //������ӣ��ҵ�����������ģ������Ϊ����ӣ�����ӱ�û�������Ҷ��� 
	{
		int lef = son[del][0],rig = son[del][1];
		while(son[lef][1]) lef = son[lef][1];
		splay(lef,son[del][0]);
		connect(rig,lef,1),connect(lef,0,1); //���Ҷ��ӽ���û���Ҷ��ӵ�������ϣ�����ӵ���
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
