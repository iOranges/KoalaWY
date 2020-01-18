#include <bits/stdc++.h>
using namespace std;
struct node
{
    int score,power,data;
}player[2333333];
bool cmp (node a,node b)
{
    if (a.score > b.score) return true;
    return false;
}
int main()
{
    int n,r,q;
    scanf("%d%d%d",&n,&r,&q);//_(:§Ù¡¹¡Ï)_
    n *= 2;
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&player[i].score);
        player[i].data = i;
    }
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&player[i].power);
    }
    for (int i = 1;i <= r;i++)
    {
        stable_sort(player + 1,player + 1 + n,cmp);
        for (int j = 1;j <= n;j += 2)
        {
            if (player[j].power > player[j + 1].power) player[j].score++;
            else player[j + 1].score++;
        }
    }
    stable_sort(player + 1,player + 1 + n,cmp);
    for (int i = 1;i <= q;i++)
    {
        if (player[i].score == player[i + 1].score && player[i].data > player[i + 1].data)
        {
            swap(player[i],player[i + 1]);
        }
    }
    cout << player[q].data;
}
