#include<bits/stdc++.h>
using namespace std;
int n;
void mmp(int n)
{
    if(n==1){printf("2(0)");return;}
    else if(n==2){printf("2");return;}
    else
    {
        int j=1,i=0;
        while(1)
        {
            j*=2;
            if(j>n)
            {
                j/=2;
                if(i==1)printf("2");
                else
                {
                    printf("2(");
                    mmp(i);
                    printf(")");
                }
                if(n-j!=0){printf("+");mmp(n-j);}
                return;
            }
            else i++;
        }
    }  
}
int main()
{
    scanf("%d",&n);mmp(n);
}
