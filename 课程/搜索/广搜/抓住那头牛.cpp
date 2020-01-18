#include<iostream>
using namespace std;
int move[2]={1,-1};
int a[10000001],b[10000001];
bool s[10000001];
void out(int q)
{
	int tot=0;
	while(b[q])
	{
		q=b[q];
		tot++;
	}
	cout << tot;
}

int main()
{
	int n,k,tail=1,head=0,i,x;
	cin >> n >> k;
	a[1]=n;
	b[1]=0;
	s[n]=true;
	do{
		head++;
		for(i=0;i<=2;i++)
		{
			if(i<2) x=a[head]+move[i];
			else x=2*a[head]; 
			if(x>=0&&x<=1000000&&s[x]==false)
			{
				s[x]=true;
				a[++tail]=x;
				b[tail]=head;
				if(x==k)
				{
					out(tail);
					head = tail;
					break;
				}
			}
		}
	}while(head<tail);
	return 0;
}
