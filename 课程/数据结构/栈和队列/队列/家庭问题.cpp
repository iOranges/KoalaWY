#include<iostream>
using namespace std;
int a[1001][2],lie[100001];
bool b[101];

int main()
{
	int n,k,i,head=0,tail=1,l,cnt=0,maxx=0;
	cin >> n >> k;
	for(i=1;i<=k;i++)
		cin >> a[i][0] >> a[i][1];
	for(l=1;l<=n;l++)
	{
		if(!b[l])
		{
			head=1,tail=1;
			cnt++;
			lie[1]=l;
			b[l] = true;			
			while(head<=tail)
			{
				for(i=1;i<=k;i++)
				{
					int x=a[i][0],y=a[i][1];
					if(x==lie[head]&&!b[y]) tail++,lie[tail]=y,b[y]=true;
					else if(y==lie[head]&&!b[x]) tail++,lie[tail]=x,b[x]=true;
				}
				head++;
			}	
			maxx=max(maxx,tail);
		}
	}
	cout << cnt << " " << maxx;
	return 0;
}
