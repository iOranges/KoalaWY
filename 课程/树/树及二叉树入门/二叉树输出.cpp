#include<cstring>
#include<iostream>
using namespace std;
string s1,s2;
int i=-1,a[256];

int work(int l,int r)
{
	int tot=0,k=++i;
	int m = s2.find(s1[k]);
	if(m>l) tot+=work(l,m-1);
	if(m<r) tot+=work(m+1,r);
	if(l == r) tot=1;
	a[s1[k]]=tot;
	return tot;
}

int main()
{
	cin >> s1 >> s2;
	work(0,s1.length()-1);
	for(int i=0;i<s2.length();i++)
	{
		for(int j=1;j<=a[s1[i]];j++)
			cout << s1[i];
		cout << endl;
	}
	return 0;
}
