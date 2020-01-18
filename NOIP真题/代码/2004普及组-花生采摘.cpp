#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,k,a[23][23],tot=0,b[500],tot1=0,tot2=0,p,q;
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            if(a[i][j]!=0)
            {
                tot++;
                b[tot]=a[i][j];
            }  
    }
    stable_sort(b+1,b+tot+1);
    for(int l=tot;l>=1;l--)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]==b[l])
                {
                    tot2++;
                    if(tot2==1)
                    {
                        if(k-2*i-1>=0)
                        {
                            tot1+=b[l];
                            k-=i+1;
                            if(tot==1)
                            {
                                cout<<tot1;
                                return 0;  
                            }
                        }
                        else
                        {
                            cout<<0;
                            return 0;
                        }
                    }
                    else
                    {
                        if(k-abs(i-p)-abs(j-q)-i-1>=0)
                        {
                            tot1+=b[l];
                            k-=abs(i-p)+abs(j-q)+1;
                            if(tot2==tot)
                            {
                                cout<<tot1;
                                return 0;
                            }
                        }
                        else
                        {
                            cout<<tot1;
                            return 0;
                        }
                    }
                    p=i,q=j;
                }
            }
        }
    }
}
