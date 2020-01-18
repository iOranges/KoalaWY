#include<iostream>        //BUG!!!!!!!!!!!!
using namespace std;
int size=0,heap[30000001],f[10001][3];
int cnt(int p,int x)
{
	return f[p][0]*x*x+f[p][1]*x+f[p][2];
}

void put(int x)
{
	int dad,son=++size;
	heap[son] = x;
	while(son > 1)
	{
		dad = son / 2;
		if(heap[son]<heap[dad])
			swap(heap[son],heap[dad]);
		son = dad;
	}
}

int get()
{
	int dad=1,son,temp=heap[1];
	heap[1]=heap[size--];
	while(dad * 2 <= size)
	{
		son = dad * 2;
		if(son+1<=size&&heap[son]>heap[son+1]) son++;
		if(heap[son] < heap[dad])
			swap(heap[son],heap[dad]);
		dad = son;
	}
	return temp;
}

int main()
{
	int i,j,n,m,x,y;
	cin >> n >> m;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<3;j++)
			cin >> f[i][j];	
		for(j=1;j<=m;j++)	
		{
			x=cnt(i,j);
			if(size<m||x<heap[m])
				put(x);	
			else 
				break;
		}
	}
	for(i=1;i<=m;i++)
		cout << get() << " ";
	return 0;
}
