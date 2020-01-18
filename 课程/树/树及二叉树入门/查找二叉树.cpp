#include<iostream>
using namespace std;
int tree[101][3],cnt=0,m;
void inorder(int bt) 
{
	if(bt)
	{	
		inorder(tree[bt][1]);
		cnt++;
		if(tree[bt][0]==m)
		{
			cout << cnt;	
			return;		
		}
		inorder(tree[bt][2]);
	}
}

int main()
{
	int n,i,lson,rson;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
	inorder(1);
	return 0;
 } 
