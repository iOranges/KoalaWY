#include<bits/stdc++.h>
#define rg register 
using namespace std;
int n,m1,m2,si,tot,prime[6666],prime_cell[30005],prime_pipe[30005];
int minn=0x7f7f7f7f,temp,sum;
inline bool find(int a)//�ж����� 
{
	int st=sqrt(a);
	for(rg int i=2;i<=st;++i)
		if(a%i==0)
			return false;
	return true;
}
inline void prime_serach()
/*�ҵ�30000����������ͬʱ��m1��m2�η�����������¼�����������������*/
{
	for(rg int i=2;i<=30000;++i)
		if(find(i))
		{
			++tot;
			prime[tot]=i;
		}
	rg int i=1;
	while(m1!=1)//�ֽ�m1�������� 
	{
		while(m1%prime[i]==0)
		{
			m1/=prime[i];
			prime_pipe[i]+=m2;//��Ϊ��m1^m2�����Գ��ִ���Ӧ�ó���m2 
		}
		++i;
	}
}
inline void prime_factorize(int aim)//�������ֽ� 
{
	memset(prime_cell,0,sizeof prime_cell);//��0 
	sum=0;
	for(rg int i=1;i<=tot;++i)
	{
		if(prime[i]>aim) break;//��prime[i]�Ѿ�����aim������ѭ�� 
		while(aim%prime[i]==0)//��prime[i]Ϊaim����������¼���� 
		{
			aim/=prime[i];
			++prime_cell[i];
		}
	}
	for(rg int i=1;i<=tot;++i)
	{
		if(prime_cell[i]==0&&prime_pipe[i]!=0)
		/*
		�����������Թ���������������ϸ������������
		֤������ϸ���޷��ɹ� 
		*/
		{
			sum=0;
			break;
		}
		if(prime_cell[i]!=0&&prime_pipe[i]!=0)//����ϸ����ǰ���Գɹ� 
		{
			if(prime_pipe[i]%prime_cell[i]==0)
			/*
			�������������Թ����г��ִ���ģ�Ը���������ϸ�����г��ִ���
			�����㣬����Ҫprime_pipe[i]/prime_cell[i]������ 
			*/ 
				sum=max(sum,prime_pipe[i]/prime_cell[i]);//�洢���ʱ�� 
			else
			/*
			�������������Թ����г��ִ���ģ�Ը���������ϸ�����г��ִ���
			�������㣬����Ҫprime_pipe[i]/prime_cell[i]+1������
			*/ 
				sum=max(sum,prime_pipe[i]/prime_cell[i]+1);//�洢���ʱ�� 
		}
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%d %d",&m1,&m2);
	if(m1==1)//��ֻ��һֻ�Թܣ�ֱ�ӿ��Խ������� 
	{
		printf("0");
		return 0;
	}
	prime_serach();
	for(rg int i=1;i<=n;++i)
	{
		scanf("%d",&temp);
		prime_factorize(temp);
		/*���sum�����£������ÿ�����ʱ�����Сֵ*/
		if(sum<minn&&sum!=0) minn=sum;
	}
	if(minn==0x7f7f7f7f) printf("-1");//minnֵδ�����£����ʾû��ϸ���������� 
	else printf("%d",minn);
}
