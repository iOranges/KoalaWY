#include<bits/stdc++.h>
#define rg register 
using namespace std;
int n,m1,m2,si,tot,prime[6666],prime_cell[30005],prime_pipe[30005];
int minn=0x7f7f7f7f,temp,sum;
inline bool find(int a)//判断质数 
{
	int st=sqrt(a);
	for(rg int i=2;i<=st;++i)
		if(a%i==0)
			return false;
	return true;
}
inline void prime_serach()
/*找到30000以内质数，同时将m1的m2次方的质因数记录下来，方便下面计算*/
{
	for(rg int i=2;i<=30000;++i)
		if(find(i))
		{
			++tot;
			prime[tot]=i;
		}
	rg int i=1;
	while(m1!=1)//分解m1的质因数 
	{
		while(m1%prime[i]==0)
		{
			m1/=prime[i];
			prime_pipe[i]+=m2;//因为是m1^m2，所以出现次数应该乘以m2 
		}
		++i;
	}
}
inline void prime_factorize(int aim)//质因数分解 
{
	memset(prime_cell,0,sizeof prime_cell);//置0 
	sum=0;
	for(rg int i=1;i<=tot;++i)
	{
		if(prime[i]>aim) break;//若prime[i]已经大于aim，跳出循环 
		while(aim%prime[i]==0)//若prime[i]为aim质因数，记录下来 
		{
			aim/=prime[i];
			++prime_cell[i];
		}
	}
	for(rg int i=1;i<=tot;++i)
	{
		if(prime_cell[i]==0&&prime_pipe[i]!=0)
		/*
		若该质数是试管数的因数而不是细胞数的因数，
		证明该种细胞无法成功 
		*/
		{
			sum=0;
			break;
		}
		if(prime_cell[i]!=0&&prime_pipe[i]!=0)//该种细胞当前可以成功 
		{
			if(prime_pipe[i]%prime_cell[i]==0)
			/*
			若该质因数在试管数中出现次数模以该质因数在细胞数中出现次数
			等于零，则需要prime_pipe[i]/prime_cell[i]次增长 
			*/ 
				sum=max(sum,prime_pipe[i]/prime_cell[i]);//存储最大时间 
			else
			/*
			若该质因数在试管数中出现次数模以该质因数在细胞数中出现次数
			不等于零，则需要prime_pipe[i]/prime_cell[i]+1次增长
			*/ 
				sum=max(sum,prime_pipe[i]/prime_cell[i]+1);//存储最大时间 
		}
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%d %d",&m1,&m2);
	if(m1==1)//若只有一只试管，直接可以进行试验 
	{
		printf("0");
		return 0;
	}
	prime_serach();
	for(rg int i=1;i<=n;++i)
	{
		scanf("%d",&temp);
		prime_factorize(temp);
		/*如果sum被更新，则更新每次最大时间的最小值*/
		if(sum<minn&&sum!=0) minn=sum;
	}
	if(minn==0x7f7f7f7f) printf("-1");//minn值未被更新，则表示没有细胞满足条件 
	else printf("%d",minn);
}
