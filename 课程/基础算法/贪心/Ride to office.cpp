#include<iostream>
using namespace std;

int main()
{
	int n,min,t,a1,a2;
	double time;
	while(true)
	{
		cin >> n;
		if(n==0) break;
		min = 999999;
		for(int i=1;i<=n;i++)
		{
			cin >> a1 >> a2;
			if(a2>=0)
			{
				time = 4500.0/a1*3.6;
				if(time > (int)time) time++;
				t = (int)time + a2;
				if(t < min) min = t;
			}	
		} 
		cout << min <<endl;
	}
	return 0;
}
