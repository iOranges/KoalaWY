#include<cstdio>
#include<cstring>
#define abs(x) (((x)>0)?(x):-(x))
#define calc(x) (f[x] + d[x+1] - p[x+1])
int d[100005],w[100005],q[100005],f[100005],p[100005];

int main()
{
	int n,t,c,head,tail,i,x,y,v,prex,prey;
	scanf("%d",&t);
	while(t--)
	{
		memset(d,0,sizeof d);
		memset(w,0,sizeof w);
		memset(q,0,sizeof q);
		memset(f,0,sizeof f);
		memset(p,0,sizeof p);
		scanf("%d%d",&c,&n);
		prex = prey = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&v);
			d[i] = x + y;
			w[i] = w[i-1] + v;
			p[i] = p[i-1] + abs(x - prex) + abs(y - prey);
			prex = x,prey = y;
		}
		head = tail = 0;
		for(i=1;i<=n;i++)
		{
			while(head <= tail&&w[i] - w[q[head]] > c) head ++;
			f[i] = calc(q[head]) + p[i] + d[i];
			while(head <= tail&&calc(q[tail]) >= calc(i)) tail --;
			q[++tail] = i;
		}
		printf("%d\n",f[n]);
		if(t) printf("\n");
	}
	return 0;
}
