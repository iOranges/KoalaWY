#include<bits/stdc++.h>
using namespace std;
int n,temp,tot;
bool flag;
int main()
{
	scanf("%d",&n);
	for(int i=n;i>=0;--i)
	{
		flag=false;
		scanf("%d",&temp);
		if(temp||(i==0&&tot==0))//�ж�ϵ���Ƿ�Ϊ�㣬��������ж�һ�� 
		{
			++tot;
			flag=true;
		}
		if(flag==false) continue;//��Ϊ��Ļ���Ҫ���������ж� 
		if(i>1)//��������1ʱ 
		{
			if(tot==1)//��Ϊ��һ��������� 
			{
				if(temp==1) printf("x^%d",i);
				else if(temp==-1) printf("-x^%d",i);
				else printf("%dx^%d",temp,i);
			}
			else if(tot>1)//��Ϊ��һ��ʱ 
			{
				if(temp>0)//ϵ������0 
				{
					if(temp==1) printf("+x^%d",i);//ϵ������1 
					else printf("+%dx^%d",temp,i);//ϵ��������1 
				}
				else//ϵ��С���� 
				{
					if(temp==-1) printf("-x^%d",i);//ϵ������-1 
					else printf("%dx^%d",temp,i);//ϵ��������-1 
				}
			}
		}
		else if(i==1)//��������1ʱ�������ָ�����������ͬ�� 
		{
			if(tot==1)
			{
				if(temp==1) printf("x");
				else printf("%dx",temp);
			}
			else if(tot>1)
			{
				if(temp>0)
				{
					if(temp==1) printf("+x");
					else printf("+%dx",temp);
				}
				else
				{
					if(temp==-1) printf("-x");
					else printf("%dx",temp);
				}
			}
		}
		else if(i==0)//��������ϵ����ָ�� 
		{
			if(tot==1) printf("%d",temp);//ͳ�ƺ�ֻ�г����� 
			else if(tot>1)//��ֹ�г����� 
			{
				if(temp>0) printf("+%d",temp);
				else printf("%d",temp);
			}
			return 0;
		}
	}
}
