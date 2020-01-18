#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int time;
	int next;
}a[1000001];
int main()
{
	int n,i,q=1,out,cnt,p,k=0,t;
	cin >> n;
	for(i=1;i<n;i++)
	{
		cin >> a[i].time;	
		a[i].next=i+1;
	}
	cin >> a[n].time;
	a[n].next=1;
	cnt = n,p = n,t=a[1].time;
	while(cnt>1)
	{
		k++;
		if(k<t)
		{
			p=q;
			q=a[q].next;
		} 
		else
		{
			k=0;
			cnt--;
			a[p].next=a[q].next;
			q = a[q].next;
			t = a[q].time;
		}
	}
	cout << q;
	return 0;
}
