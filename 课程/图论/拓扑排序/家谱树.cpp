#include<iostream>
using namespace std;
int son[101][101],r[101],c[101],top[101];

int main()
{
	int n,i,j,tot=0,num=0,temp;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		do{
			cin >> j;
			if(j!=0)
			{
				c[i]++;
				son[i][c[i]]=j;
				r[j]++;
			}
		}while(j!=0);
	}
	for(i=1;i<=n;i++)
		if(r[i]==0)
			top[++tot] = i;
	do{
		temp = top[tot];
		cout << temp << ' ';
		tot--,num++;
		for(i=1;i<=c[temp];i++)
		{
			r[son[temp][i]]--;
			if(r[son[temp][i]] == 0)
				top[++tot] = son[temp][i];
		}
	}while(num!=n);
	return 0;
}
