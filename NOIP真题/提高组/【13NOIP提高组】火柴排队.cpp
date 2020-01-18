#include<cstdio>
#include<algorithm>
using std::sort;
const long long mod = 99999997;
struct node{
	int num,id;
	bool operator < (const node b) const{
		return num < b.num;
	}
}a[100005],b[100005];
int pos[100005],p[100005],c[100005],n;

inline int lowbit(int x)
{
	return x & (-x);
}

void add(int x)
{
	for(register int i = x;i <= n;i += lowbit(i))
		c[i] = (c[i] + 1) % mod;
 } 
 
long long query(int x)
{
	long long res = 0;
	for(register int i = x;i > 0;i -= lowbit(i))
		res = (res + c[i]) % mod;
	return res;
}

int main()
{
	long long ans = 0;
	register int i;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
	{
		scanf("%d",&a[i].num);
		a[i].id = i;
	}
	sort(a + 1,a + n + 1);
	for(i = 1;i <= n;++ i)
		p[a[i].id] = i;
	for(i = 1;i <= n;++ i)
	{
		scanf("%d",&b[i].num);
		b[i].id = i;
	}
	sort(b + 1,b + n + 1);
	for(i = 1;i <= n;++ i)
		pos[i] = b[i].id;
	for(i = n;i >= 1;-- i)
	{
		ans = (ans + query(pos[p[i]])) % mod;
		add(pos[p[i]]);
	}
	printf("%lld",ans);
	return 0;
}

