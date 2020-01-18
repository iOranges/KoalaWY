#include<cstring>
#include<iostream>
using namespace std;
int up[2001],lie[200001],fa[200001];
bool f[2001];
int main()
{
	memset(f,false,sizeof(f));
	int n,a,b,i,head = 0,tail = 1,x;
	cin >> n >> a >> b;
	for(i=1;i<=n;i++)
		cin >> up[i];
	if(a==b)
	{
		cout << 0;
		return 0;
	}
	lie[1]=a;
	f[a]=true;
	fa[1]=0;
	do{
		head++;
		for(i=1;i<=2;i++)
		{
			if(i==1) x = lie[head]+up[lie[head]];
			else x = lie[head]-up[lie[head]];
			if(x>=1&&x<=n&&!f[x])
			{
				f[x]=true;
				lie[++tail]=x;
				fa[tail]=head;
				if(x==b)
				{
					int temp=tail,cnt = 0;
					while(fa[temp])
					{
						temp=fa[temp];
						cnt++;
					}
					cout << cnt << '\n';
					return 0;
				}
			}
		}
	}while(head<tail);
	cout << "-1\n";
	return 0;
}
