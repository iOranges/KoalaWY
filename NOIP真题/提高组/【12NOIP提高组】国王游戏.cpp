#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(x,y) ((x) > (y) ? (x) : (y))
using std::sort;
struct number{
	int a[5005],len;
	number(bool f = false){
		memset(a,0,sizeof a);
		len = 0;
		if(f) len = a[1] = 1;
	}
	void operator *= (const int b){
		register int i;
		for(i = 1;i <= len;++ i)
			a[i] *= b;
		for(i = 1;i <= len;++ i)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		while(a[i])
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
			++ i,++ len;
		}
	}
	void operator /= (const int b){
		register int i;
		for(i = len;i >= 1;-- i)
		{
			a[i - 1] += (a[i] % b) * 10;
			a[i] = a[i] / b;
		}
		while(!a[len]) -- len; 
	}
	bool operator > (const number b) const {
		if(len != b.len) return len > b.len;
		register int i;
		for(i = len;i >= 1;-- i)
			if(a[i] != b.a[i])	return a[i] > b.a[i];
		else return false;
	}
	void print()
	{
		register int i;
		for(i = len;i >= 1;-- i)
			putchar(a[i] + '0');
	}
}ans,t(true),temp;

struct node{
	int a,b;
	bool operator < (const node y) const{
		return a * b < y.a * y.b;
	}
}p[1005];

int main()
{
	int n;
	register int i;
	scanf("%d",&n);
	for(i = 0;i <= n;++ i)
		scanf("%d%d",&p[i].a,&p[i].b);
	sort(p + 1,p + 1 + n);
	for(i = 1;i <= n;++ i)
	{
		t *= p[i - 1].a;
		temp = t;
		temp /= p[i].b;
		ans = max(ans,temp);
	}
	ans.print();	
	return 0;
}

