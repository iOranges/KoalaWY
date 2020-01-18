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
		if(temp||(i==0&&tot==0))//判断系数是否为零，常数项单独判断一次 
		{
			++tot;
			flag=true;
		}
		if(flag==false) continue;//不为零的话就要进入下列判断 
		if(i>1)//次数大于1时 
		{
			if(tot==1)//若为第一项，单独处理 
			{
				if(temp==1) printf("x^%d",i);
				else if(temp==-1) printf("-x^%d",i);
				else printf("%dx^%d",temp,i);
			}
			else if(tot>1)//不为第一项时 
			{
				if(temp>0)//系数大于0 
				{
					if(temp==1) printf("+x^%d",i);//系数等于1 
					else printf("+%dx^%d",temp,i);//系数不等于1 
				}
				else//系数小于零 
				{
					if(temp==-1) printf("-x^%d",i);//系数等于-1 
					else printf("%dx^%d",temp,i);//系数不等于-1 
				}
			}
		}
		else if(i==1)//次数等于1时，不输出指数，其余操作同上 
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
		else if(i==0)//常数项无系数、指数 
		{
			if(tot==1) printf("%d",temp);//统计后只有常数项 
			else if(tot>1)//不止有常数项 
			{
				if(temp>0) printf("+%d",temp);
				else printf("%d",temp);
			}
			return 0;
		}
	}
}
