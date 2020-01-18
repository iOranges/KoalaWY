#include<string>
#include<iostream>
using namespace std;
struct node{
	int lson,rson;
	char ch; 
}tree[3001];
string s;
int i=0;

void plant(int dad,bool left)
{
	if(s[++i]!='.')
	{
		int j=i+1;
		tree[j].ch = s[i];
		if(left)
			tree[dad].lson=j;
		else
			tree[dad].rson=j;
		plant(j,true);
		plant(j,false);
	}
}

void print1(int bt)
{
	if(bt)
	{
		print1(tree[bt].lson);
		cout << tree[bt].ch;
		print1(tree[bt].rson);
	}
}

void print2(int bt)
{
	if(bt)
	{
		print2(tree[bt].lson);
		print2(tree[bt].rson);		
		cout << tree[bt].ch;
	}
}

int main()
{
	cin >> s;
	tree[1].ch=s[0];
	plant(1,true);
	plant(1,false);
	print1(1);
	cout << endl;
	print2(1);
	cout << endl;
	return 0;
}
