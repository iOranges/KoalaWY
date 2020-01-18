#include<cmath>
#include<iostream>
using namespace std;
char a[1000];
struct node{
	char ch;
	int lson,rson;
}tree[4001];
void postorder(int bt)
{
	if(bt)
	{
		postorder(tree[bt].lson);
		postorder(tree[bt].rson);
		cout << tree[bt].ch;
	}
}

int main()
{
	int d,k,n=0,j,i;
	cin >> d;
	for(i=1;i<=d+1;i++)
		n += pow(2,i-1);
	k = pow(2,d);
	cin >> a;
	for(i=0;i<k;i++)
		switch(a[i])
		{
			case '1':a[i]='I';break;
			case '0':a[i]='B';break;
		}
	for(i=0;i<k;i++)
	{
		j=i+n-k+1;
		tree[j].lson = tree[j].rson = 0;
		tree[j].ch = a[i];
		if(j%2==0)
			tree[j/2].lson = j;
		else
			tree[(j-1)/2].rson = j;
	}
	for(i=n-k;i>=1;--i)
	{
		if(tree[tree[i].lson].ch=='F'||tree[tree[i].rson].ch=='F')
			tree[i].ch = 'F';
		else if(tree[tree[i].lson].ch=='B'&&tree[tree[i].rson].ch=='B')
			tree[i].ch = 'B';
		else if(tree[tree[i].lson].ch=='I'&&tree[tree[i].rson].ch=='I')
			tree[i].ch = 'I';
		else
			tree[i].ch = 'F';
		if(i>1)
		{
			if(i%2==0)
				tree[i/2].lson = i;
			else
				tree[(i-1)/2].rson = i;			
		}
	}
	postorder(1);
	return 0;
}
