#include<cstdio>
#define abs(x) ((x)>0?(x):-(x))
int n,x,y;
struct node{
	int ud,lr;
}s[200005];

bool check(int k)
{
	register int i;
	for(i=1;i<=n-k+1;i++)
	{
		int cnt = 0;
		cnt += abs(y - (s[i-1].ud + s[n].ud - s[i+k-1].ud));
		cnt += abs(x - (s[i-1].lr + s[n].lr - s[i+k-1].lr));
		if(k >= cnt&&(k - cnt)%2 == 0) return true;
	}
	return false;
}

int main()
{
	char ch[200005];
	int i,l,r,mid;
	scanf("%d",&n);
	scanf("%s",ch + 1);
	for(i=1;i<=n;i++)
		switch(ch[i])
		{
			case 'U':s[i].ud = s[i-1].ud + 1;s[i].lr = s[i-1].lr;break;
			case 'D':s[i].ud = s[i-1].ud - 1;s[i].lr = s[i-1].lr;break;
			case 'L':s[i].lr = s[i-1].lr - 1;s[i].ud = s[i-1].ud;break;
			case 'R':s[i].lr = s[i-1].lr + 1;s[i].ud = s[i-1].ud;break;
		}
	scanf("%d%d",&x,&y);
	l = 0,r = n;
	while(l<=r)
	{
		mid = (l + r) >> 1;
		if(check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	if(l > n) printf("%d",-1);
	else printf("%d",l);
	return 0;
}
