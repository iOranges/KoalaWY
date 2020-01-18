#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int i,money = 0,need,sum = 0,k;
    for(i=1;i<=12;i++)
    {
        cin >> need;
        money+=300;
        money-=need;
        if(money < 0)
        {
            cout << "-" << i;   
            return 0;
        }
        if(money >= 100)
        {
            k = money/100;
            sum += k*100;
            money-=k*100;
        }
    }
    cout << sum*1.2+money;
    return 0;
}
