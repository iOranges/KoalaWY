#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort; 
long long lazy[1001],a[1000005],b[1000005];
int l[1001],r[1001],num[1000005],cnt,n,m;

void build()
{
	register int i;
	int block = sqrt(n);
	cnt = n / block;
	if(n % block) cnt ++;
	for(i = 1;i <= cnt;++ i)
	{
		l[i] = (i - 1) * block + 1;
		r[i] = i * block;
	}
	r[cnt] = n;
	for(i = 1;i <= n;++ i)
//	{
		num[i] = (i - 1) / block + 1;
//		b[i] = a[i];		
//	}
	memcpy(b + 1,a + 1,sizeof(long long) * n);
	for(i = 1;i <= cnt;++ i)
		sort(b + l[i],b + r[i] + 1);
}

void reset(int x)
{
//	for(i = l[x];i <= r[x];++ i)
//		b[i] = a[i];
	memcpy(b + l[x],a + l[x],sizeof(long long) * (r[x] - l[x] + 1));
	sort(b + l[x],b + r[x] + 1);
 } 

void add(int x,int y,long long k)
{
	register int i;
	if(num[x] == num[y])
	{
		for(i = x;i <= y;++ i)
			a[i] += k;
		reset(num[x]);
		return;
	}
	for(i = x;i <= r[num[x]]; ++ i)
		a[i] += k;
	reset(num[x]);
	for(i = l[num[y]];i <= y; ++ i)
		a[i] += k;
	reset(num[y]);
	for(i = num[x] + 1;i < num[y]; ++ i)
		lazy[i] += k;
}

int query(int x,int y,long long k)
{
	register int i,cnt = 0,L,R,mid;
	if(num[x] == num[y])
	{
		k -= lazy[num[x]];
		for(i = x;i <= y;++ i)
			if(a[i] >= k)
				++ cnt;
		return cnt;
	}	
	long long temp = k - lazy[num[x]];
	for(i = x;i <= r[num[x]]; ++ i)
		if(a[i] >= temp)
			++ cnt;	
	temp = k - lazy[num[y]];
	for(i = l[num[y]];i <= y; ++ i)
		if(a[i] >= temp)
			++ cnt;
	for(i = num[x] + 1;i < num[y]; ++ i)
	{
		temp = k - lazy[i];
		L = l[i],R = r[i];
		while(L <= R)
		{
			mid = (L + R) >> 1;
			if(b[mid] >= temp)
				R = mid - 1;
			else
				L = mid + 1;
		}
		cnt += (r[i] - L + 1);
	}
	return cnt;
}

int main()
{
	int x,y;
	char ch[5];
	long long k;
	register int i;
	scanf("%d%d",&n,&m);
	for(i = 1;i <= n;++ i)
		scanf("%lld",&a[i]);
	build();
	for(i = 1;i <= m;++ i)
	{
		scanf("%s%d%d%lld",ch,&x,&y,&k);
		if(ch[0] == 'M')
			add(x,y,k);
		else
			printf("%d\n",query(x,y,k));
	}
	return 0;
 } 
