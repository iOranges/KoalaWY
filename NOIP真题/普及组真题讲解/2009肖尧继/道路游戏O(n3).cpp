#include<bits/stdc++.h>
#define rg register int
#define N 2333
using namespace std;
int n,m,p,pre,sum;
int coin[N][N],dp[N],cost[N];
int main()
{
	scanf("%d%d%d",&n,&m,&p);//������n,��λʱ��m,������������ߴ���p
	memset(dp,-0x7f,sizeof dp);
	dp[0]=0;//��ʼ��dp����
	for(rg i=1;i<=n;++i)
		for(rg j=1;j<=m;++j)
			scanf("%d",&coin[i][j]);//��j����λʱ��,��i����·�Ľ���� 
	for(rg i=1;i<=n;++i)
		scanf("%d",&cost[i]);//ÿ�������Ļ������ۼ� 
	for(rg i=1;i<=m;++i)//ö�ٵ�ǰʱ��
		for(rg j=1;j<=n;++j)//ö�ٵ�ǰ��·��� 
		{
			if(j==1) pre=n;
			/*�����ǳ�ʼ������ʱ��Ϊ1ʱ�ĵ�·��źͽ������ */
			else pre=j-1;//j�ŵ�·��ǰһ����·
			sum=coin[pre][i];//j�ŵ�·��ǰһ����·�ĵ�ǰ����� 
			for(rg k=1;k<=p;++k)//ö�ٵ�ǰ���������ߴ���
			{
				if(i-k<0) break;//����ʱ�䲻�ܴ��ڵ�ǰʱ��
				dp[i]=max(dp[i],dp[i-k]+sum-cost[pre]);
				/*
				��������ǣ� 
				kʱ��ǰ���������+�߹�k�ο����ռ��Ľ������-�ڴ˹���������˵ļ۸�
				*/
				--pre;
				if(pre==0) pre=n;//����ʱ�����Ӵ�����Ҫö�ٸ�ǰһ����· 
				sum+=coin[pre][i-k];
				/*
				��Ϊ������ֻҪ������·�Σ� 
				��Ҫ����·�ε�Ǯһ���ռ���
				�����ܽ����Ҫ���ϸõ�·�ĵ�ǰ�����
				*/
			}
		}
	printf("%d",dp[m]);
}
