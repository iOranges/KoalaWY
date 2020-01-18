#include<iostream>
using namespace std;
int size=0,heap[30001];
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
	int n,i,x,sum=0,a,b;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> x;
		put(x);
	}
	for(i=1;i<=n-1;i++)
	{
		a=get();
		b=get();
		sum+=a+b;
		put(a+b);
	}
	cout << sum; 
	return 0;
}
