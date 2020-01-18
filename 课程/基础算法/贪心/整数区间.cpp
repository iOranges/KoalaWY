#include<iostream>
using namespace std;
int a[10001][2];
void qsort(int x,int y) 
{ 
	int i=x,j=y,mid1,mid2,t;
	mid1=a[(x+y)/2][1];
	mid2=a[(x+y)/2][0];
	while(i<=j)
	{ 
		while(a[i][1]<mid1||((a[i][1]==mid1)&&(a[i][0]<mid2)))  ++i;
    	while(a[j][1]>mid1||((a[j][1]==mid1)&&(a[j][0]>mid2)))  --j;
    	if(i<=j)
     	{ 
     		swap(a[i],a[j]);
    		++i;  --j; 
    	}
   }
  if(x<j) qsort(x,j);
  if(i<y) qsort(i,y);
}


int main()
{
	int n,i,k=-1,cnt=0;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> a[i][0] >> a[i][1];
	qsort(1,n);
	for(i=1;i<=n;i++)
	{
		if(k>=a[i][0]) continue;
		cnt++,k=a[i][1];
	} 
	cout << cnt << endl;
	return 0;
}
