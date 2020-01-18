#include<bits/stdc++.h>
#define rg register int
#define N 2333
using namespace std;
int n,m,p,pre,sum;
int coin[N][N],dp[N],cost[N];
int main()
{
	scanf("%d%d%d",&n,&m,&p);//工厂数n,单位时间m,机器人最大行走次数p
	memset(dp,-0x7f,sizeof dp);
	dp[0]=0;//初始化dp数组
	for(rg i=1;i<=n;++i)
		for(rg j=1;j<=m;++j)
			scanf("%d",&coin[i][j]);//第j个单位时间,第i号马路的金币数 
	for(rg i=1;i<=n;++i)
		scanf("%d",&cost[i]);//每个工厂的机器人售价 
	for(rg i=1;i<=m;++i)//枚举当前时间
		for(rg j=1;j<=n;++j)//枚举当前道路编号 
		{
			if(j==1) pre=n;
			/*以下是初始化行走时间为1时的道路编号和金币总数 */
			else pre=j-1;//j号道路的前一条道路
			sum=coin[pre][i];//j号道路的前一条道路的当前金币数 
			for(rg k=1;k<=p;++k)//枚举当前机器人行走次数
			{
				if(i-k<0) break;//行走时间不能大于当前时间
				dp[i]=max(dp[i],dp[i-k]+sum-cost[pre]);
				/*
				最优情况是： 
				k时间前的最优情况+走过k次可以收集的金币总数-在此工厂买机器人的价格
				*/
				--pre;
				if(pre==0) pre=n;//行走时间增加代表需要枚举更前一条道路 
				sum+=coin[pre][i-k];
				/*
				因为机器人只要经过该路段， 
				就要将该路段的钱一并收集。
				所以总金币数要加上该道路的当前金币数
				*/
			}
		}
	printf("%d",dp[m]);
}
