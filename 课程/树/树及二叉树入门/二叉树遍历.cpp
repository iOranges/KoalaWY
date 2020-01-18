#include<string>
#include<iostream>
using namespace std;
char map[256];
string s1,s;

void work(int l,int r)
{
	if(l>r) return;
	int minn=999999,k;
	for(int i=l;i<=r;i++)
		if(map[s1[i]]<minn)
		{
			minn = map[s1[i]];
			k = i;
		}
	cout << s1[k];
	work(l,k-1);
	work(k+1,r);
}

int main()
{
	cin >> s1 >> s;
	int l = s.length();
	for(int i=0;i<l;i++)
		map[s[i]]=i;
	work(0,l-1);
	return 0;
}
