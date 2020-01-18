#include<cstdio>
#include<cstring>
#define min(x,y) ((x) < (y) ? (x) : (y))
int n,num[15],f[24][12][8][6][3],ans,q[4],card[6];
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
}

int dp(int i,int j,int k,int l,int p) //i个单牌,j对对子,k个三张牌，l个4张牌，p张王
{
	if(f[i][j][k][l][p] != -1) return f[i][j][k][l][p];
	int t = 0x7f7f7f7f;
	if(i > 0) t = min(t,dp(i - 1,j,k,l,p) + 1);
	if(j > 0) t = min(t,dp(i,j - 1,k,l,p) + 1);
	if(j > 0) t = min(t,dp(i + 2,j - 1,k,l,p)); 
	if(k > 0) t = min(t,dp(i,j,k - 1,l,p) + 1);
	if(k > 0&&i > 0) t = min(t,dp(i - 1,j,k - 1,l,p) + 1);
	if(k > 0&&p > 0) t = min(t,dp(i,j,k - 1,l,p - 1) + 1);
	if(k > 0&&j > 0) t = min(t,dp(i,j - 1,k - 1,l,p) + 1);
	if(k > 0&&p > 1) t = min(t,dp(i,j,k - 1,l,p - 2) + 1);
	if(k > 0) t = min(t,dp(i + 1,j + 1,k - 1,l,p));
	if(k > 0) t = min(t,dp(i + 3,j,k - 1,l,p));
	if(l > 0) t = min(t,dp(i,j,k,l - 1,p) + 1);
	if(l > 0&&i > 1) t = min(t,dp(i - 2,j,k,l - 1,p) + 1);
	if(l > 0&&j > 0) t = min(t,dp(i,j - 1,k,l - 1,p) + 1);
	if(l > 0&&j > 1) t = min(t,dp(i,j - 2,k,l - 1,p) + 1);
	if(l > 0&&p > 1) t = min(t,dp(i,j,k,l - 1,p - 2) + 1);
	if(l > 0&&p > 0&&i > 0) t = min(t,dp(i - 1,j,k,l - 1,p - 1) + 1);
	if(l > 0&&p > 1&&j > 0) t = min(t,dp(i,j - 1,k,l - 1,p - 2) + 1);
	if(l > 0) t = min(t,dp(i + 2,j + 1,k,l - 1,p));
	if(l > 0) t = min(t,dp(i,j + 2,k,l - 1,p));
	if(l > 0) t = min(t,dp(i + 1,j,k + 1,l - 1,p));
	if(l > 0) t = min(t,dp(i + 4,j,k,l - 1,p));
	if(p > 0) t = min(t,dp(i,j,k,l,p - 1) + 1);
	if(p > 1) t = min(t,dp(i,j,k,l,p - 2) + 1);
	f[i][j][k][l][p] = t;
	return t;
 } 

void dfs(int cnt)
{
	register int i,j,k,l,tot = 0;
	for(j = 1;j <= 3;++ j)
		for(i = 1;i <= 12;++ i)
		{
			k = i,tot = 0;
			while(k <= 12)
			{
				if(num[k] >= j) ++ tot;
				else break;
				if(tot >= q[j])
				{
					for(l = 0;l < tot;++ l)
						num[k - l] -= j;
					dfs(cnt + 1);
					for(l = 0;l < tot;++ l)
						num[k - l] += j;	
				}
				++ k;
			}
		}
	for(i = 1;i <= 5;++ i) card[i] = 0; 
	card[5] = num[14];
	for(i = 1;i <= 13;++ i) 
		++ card[num[i]];
	ans = min(ans,cnt + dp(card[1],card[2],card[3],card[4],card[5])); 
}

int main()
{
	int t,a,b;
	read(t),read(n);
	register int i;
	memset(f,-1,sizeof f);
	f[0][0][0][0][0] = 0;
	q[1] = 5,q[2] = 3,q[3] = 2;
	while(t --)
	{
		memset(num,0,sizeof num);
		for(i = 1;i <= n;++ i)
		{
			read(a),read(b);
			if(a == 1) a = 12;
			else if(a == 2) a = 13;
			else if(a == 0) a = 14;
			else a -= 2;
			++ num[a];
		}		
		ans = 0x7f7f7f7f;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}

