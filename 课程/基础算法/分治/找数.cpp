#include<iostream>
using namespace std;
int a[10001],m;
bool flag=false;
void dc(int l,int r)
{
	int k = (l+r)/2;
	if(l > r)
		return;
	else if(a[k]==m)
	{
		flag=true;
		return;	
	}
	if(l<k)	dc(l,k-1);
	if(k<r)	dc(k+1,r);		
} 

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	cin >> m;
	dc(1,n);
	if(flag) cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}
