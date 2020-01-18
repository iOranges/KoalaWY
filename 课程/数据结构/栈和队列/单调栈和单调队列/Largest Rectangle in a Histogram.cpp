#include<cstdio>
#include<cstring>
#define max(x,y) (x)>(y)?(x):(y) 
int h[100001],w[100001],s[100001];

int main()
{
	int n,i,top;
	while(scanf("%d",&n))
	{
		if(!n) break;
		long long ans = -1;
		memset(s,0,sizeof s);
		memset(w,0,sizeof w);
		for(i=1;i<=n;i++)
			scanf("%d",&h[i]);
		h[n+1] = top = 0;
		s[++top] = h[1];
		w[top] = 1;
		for(i=2;i<=n+1;i++)
			if(s[top] < h[i])
				s[++top] = h[i],w[top] = 1;
			else
			{
				int width = 0;
				while(s[top] >= h[i]&&top)
				{
					width += w[top];
					ans = max(ans,width * 1ll * s[top]);
					top --;					
				}
				s[++top] = h[i],w[top] = width + 1;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
