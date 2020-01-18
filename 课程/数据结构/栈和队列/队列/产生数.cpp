#include<iostream>
using namespace std;
int role[101][2],lie[100001],num[5];
bool b[9999];
int main()
{
	int k,i,head=0,tail=1,n=0,j,m=0,l,temp,p=0;
	cin >> n >> k;
	for(i=1;i<=k;i++)
		cin >> role[i][0] >> role[i][1];
	temp = n;
	while(temp!=0)
	{
		temp/=10;
		m++;
	}
	lie[1]=n;
	b[n]=true;
	do{
		head++;
		l=0,temp=lie[head];
		do
		{
			num[l]=temp%10;
			temp/=10;
			l++;
		}while(l<m);
		for(l=0;l<m;l++)
			for(j=1;j<=k;j++)
			{
				if(role[j][0]==num[l])	
				{
					p=0;
					num[l]=role[j][1];
					for(i=m-1;i>=0;i--)
						p=10*p+num[i];
					if(!b[p])
					{
						tail++;
						lie[tail]=p;
						b[p]=true;
					}
					num[l]=role[j][0];
				}
			}
	}while(head<tail);
	cout << tail;
	return 0;
}
