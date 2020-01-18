#include<cstdio>//∏¥‘”∂»a(n) 
int size[10005],f[10005];
int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]); 
}

void marge(int a,int b)
{
	a = find(a),b = find(b);
	if(size[a] < size[b]) f[a] = b,size[b] += size[a];
	else f[b] = a,size[a] += size[b];
}

int main()
{
	int n,a,b;
	register int i;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		size[i] = 1;
	for(i = 1;i <= n;++ i)
		scanf("%d %d",&a,&b);
	marge(a,b);
	return 0;
}
