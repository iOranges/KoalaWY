#include<iostream>
using namespace std;
int tree[1001];
int main()
{
	int n,i,j,m,son,dad,root,maxdad,maxson=0;
	cin >> n >> m;
	for(i=1;i<=m;i++)
	{
		cin >> dad >> son;
		tree[son]=dad;
	}
	for(i=1;i<=n;i++)
		if(tree[i] == 0)
		{
			root = i;	
			break;		
		}
	for(i=1;i<=n;i++)
	{
		son=0;
		for(j=1;j<=n;j++)
			if(tree[j] == i) son++;
		if(son > maxson)
		{
			maxson=son;
			maxdad = i;
		}
	}
	cout << root << endl << maxdad << endl;
	for(i=1;i<=n;i++)
		if(tree[i] == maxdad)
			cout << i << " ";
}
