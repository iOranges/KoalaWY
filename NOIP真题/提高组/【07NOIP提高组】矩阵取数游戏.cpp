#include<cstdio>
#include<cstring> 
#define max(x,y) ((x) > (y) ? (x) : (y))
class ll{
	public:
		int a[500],len;
		ll() {
			memset(a,0,sizeof a);
			len = 0;
		}
		ll operator + (const ll o) const{
			register int i;
			ll ans = *this,b = o;
			if(ans.len < b.len)
			{
				ll temp = ans;
				ans = b;
				b = temp;
			}
			for(i = 1;i <= ans.len;++ i)
			{
				ans.a[i] += b.a[i];
				ans.a[i + 1] += ans.a[i] / 10;
				ans.a[i] %= 10;
			}
			if(ans.a[i]) ++ ans.len;
			return ans;
		}
		void operator += (const ll b){
			*this = *this + b;
		}
		ll operator * (const int b) const{
			ll ans = *this;
			register int i;
			for(i = 1;i <= ans.len;++ i)
				ans.a[i] *= b;
			for(i = 1;i <= ans.len;++ i)
			{
				ans.a[i + 1] += ans.a[i] / 10;
				ans.a[i] %= 10;
			}
			while(ans.a[i])
			{
				ans.a[i + 1] += ans.a[i] / 10;
				ans.a[i ++] %= 10;	
				++ ans.len;		
			}
			return ans;
		}
		bool operator > (const ll b) const{
			if(len != b.len) return len > b.len;
			register int i;
			for(i = len;i >= 1;-- i)
				if(a[i] != b.a[i]) return a[i] > b.a[i];
			return false; 
		}
		void print()
		{
			register int i;
			for(i = len;i >= 1;-- i)
				putchar(a[i] + '0');
		}
}f[105][105],ans,pw[100];
int w[105][105];

int main()
{
	int n,m;
	register int i,j,k;
	scanf("%d%d",&m,&n);
	for(i = 1;i <= m;++ i)
		for(j = 1;j <= n;++ j)
			scanf("%d",&w[i][j]);
	pw[0].len = pw[0].a[1] = 1;
	for(i = 1;i <= n;++ i)
		pw[i] = pw[i - 1] * 2;
	for(k = 1;k <= m;++ k)
	{
		memset(f,0,sizeof f);
		for(i = 0;i <= n;++ i)
			for(j = 0;j + i <= n;++ j)
			{
				if(i > 0) f[i][j] = max(f[i][j],f[i - 1][j] + pw[i + j] * w[k][i]);
				if(j > 0) f[i][j] = max(f[i][j],f[i][j - 1] + pw[i + j] * w[k][n - j + 1]);
			}
		ll res;
		for(i = 0;i <= n;++ i)
			res = max(res,f[i][n - i]);
		ans += res;
	}
	ans.print();
	return 0;
}

