#include<iostream>
using namespace std;
int f[1000001],n,m;
int find(int x)
{
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}

bool check(int a,int b)
{
	a = find(a),b = find(b);
	if(a!=b)
	{
		f[a] = b;
		return true;
	}
	return false;
}

int v(int x,int y)
{
	return (x-1)*n+y;
}

int main()
{
	int i,j,x1,y1,x2,y2,o,o1,o2,cnt=0;
	cin >> m >> n;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			o = v(i,j);	
			f[o] = o;		
		}
	while(cin >> x1 >> y1 >> x2 >> y2)
	{
		o1 = v(x1,y1),o2 = v(x2,y2);
		check(o1,o2);		
	}
	for(i=1;i<=m-1;i++)
		for(j=1;j<=n;j++)
		{
			if(check(v(i,j),v(i+1,j)))
				cnt++;
		}
	for(i=1;i<=m;i++)
		for(j=1;j<=n-1;j++)
		{
			if(check(v(i,j),v(i,j+1)))
				cnt+=2;
		}	
	cout << cnt;
	return 0;
}
