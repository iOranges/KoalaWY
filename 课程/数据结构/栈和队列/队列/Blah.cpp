#include<iostream>
using namespace std;
long long Ba[1000010];

int main()
{
	int n,a,m,two,thr,q,a1,a2;
	while(cin >> a >> n)
	{
		m=2;
		Ba[1]=a;
		two=thr=1;
		while(m<=n)
		{
			a1=Ba[two]*2+1,a2=Ba[thr]*3+1;
			if(a1>=a2)
				thr++,q=a2;
			else 
				two++,q=a1;
			if(q!=Ba[m-1])
				Ba[m++]=q;
		 } 
		 cout << Ba[n] << endl;
	}
	return 0;
}

