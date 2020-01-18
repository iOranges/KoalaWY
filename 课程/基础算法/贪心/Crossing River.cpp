#include<iostream>
using namespace std;
int a[10001];
void qsort(int l,int r)
{
	int i=l,j=r;
	double mid=a[(l+r)/2];
	do{
		while(a[i]<mid)	i++;
		while(a[j]>mid)	j--; 
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++,j--; 
		}
	}while(i<=j);
	if(l<j)	qsort(l,j);
	if(r>i)	qsort(i,r);
}

int main()
{
	int n,t,time;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		time = 0;
		cin >> t;
		for(int j=1;j<=t;j++)
			cin >> a[j];
		qsort(1,t);
		while(t>3)
		{
			int x=a[1]*2+a[t-1]+a[t];
			int y=a[1]+a[2]*2+a[t];
			time+=min(x,y);
			t-=2;
		}
		if(t==1) time += a[1];
		else if(t==2) time+=a[2];
		else if(t==3) time+=(a[1]+a[2]+a[3]);
		cout << time << endl;	
	 } 
	return 0;
}
