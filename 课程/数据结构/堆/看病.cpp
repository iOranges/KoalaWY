#include<iostream>
using namespace std;
int size=0;
string s1,s2;
struct patient{
	int level;
	string name;
}heap[100001];

void put(int x,string y)
{
	int now=++size,next;
	heap[now].level = x;
	heap[now].name = y;
	while(now>1)
	{
		next = now/2;
		if(heap[next].level<heap[now].level)
			swap(heap[next],heap[now]);
		now = next;
	}
}

void get()
{
	cout << heap[1].name << " " << heap[1].level << endl;
	swap(heap[size--],heap[1]);
	int now,next=1;
	while(next * 2 <= size)
	{
		now = next*2;
		if(now+1<=size&&heap[now+1].level>heap[now].level) now++;
		if(heap[now].level>heap[next].level)
			swap(heap[now],heap[next]);
		next = now;
	}
}

int main()
{
	int n,i,x;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> s1;
		if(s1 == "push")
		{
			cin >> s2 >> x; 
			put(x,s2);
		}
		else 
		{
			if(size == 0)
				cout << "none\n";
			else 
				get();
		}
	}
	return 0;
 } 
