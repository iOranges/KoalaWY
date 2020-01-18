#include<bits/stdc++.h>
using namespace std;
int a[10005],n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    while(m--) next_permutation(a+1,a+n+1);
//    while(m--) prev_permutation(a+1,a+n+1);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
}
/* next_permutation()会取得[first,last)所标示之序列的下一个排列组合;
利用next_permutation的返回值，判断是否全排列结束 如果没有下一个排列组合，便返回false;
否则返true; STL提供了两个用来计算排列组合关系的算法; 分别是next_permutation和prev_permutation;
下一个全排列（next_Permutation） 前一个全排列（prev_permutation）
*/
