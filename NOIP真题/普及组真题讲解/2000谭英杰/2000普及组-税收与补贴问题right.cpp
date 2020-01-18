#include<bits/stdc++.h>
using namespace std;
int a[12000];
int b[12000];
int lx;
int readyy;
int readyx;
int ry;
int p,n,py;
int X;
double Min=-99999999.0;
double Max=99999999.0;
int main()
{
    cin>>p;
    n=1;
    cin>>a[1]>>b[1];
    while(1)
    {
        cin>>readyx>>ry;
        if(readyx==-1&&ry==-1)
		{
			break;
		} 
        lx=a[n];readyy=b[n];
        for(int i=lx+1;i<=readyx;i++)
        {
            n++;
            a[n]=a[n-1]+1;
            b[n]=b[n-1]+(ry-readyy)/(readyx-lx);
        }
    }
    cin>>X;
    if(p>=a[n])
    {
        lx=a[n];readyy=b[n];
        for(int i=lx+1;i<=p+1;i++)
        {
            n++;
            a[n]=a[n-1]+1;
            b[n]=b[n-1]-X;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==p)
        {
            py=b[i];
            break;
        }
    }
   
    for(int i=1;i<=n;i++)
    {
        if(py-b[i]>0)
        {
            Min=max(Min,(double)((double)(a[i]-a[1])*b[i]-(double)(p-a[1])*py)/(double)(py-b[i]));
        } 
		else
        {
            Max=min(Max,(double)((double)(a[i]-a[1])*b[i]-(double)(p-a[1])*py)/(double)(py-b[i]));
        }
    }
    if(Min>Max)
	{
		printf("NO SOLUTION\n"); 
	} 
	else if(Min>0)
	{
		printf("%.0lf",ceil(Min));
	} 
	else if(Max<0)
	{
		printf("%.0lf",floor(Max)); 
	}
    else
	{
		 printf("0");
	} 
    return 0;
}
