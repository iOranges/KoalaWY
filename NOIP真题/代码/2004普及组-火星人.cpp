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
/* next_permutation()��ȡ��[first,last)����ʾ֮���е���һ���������;
����next_permutation�ķ���ֵ���ж��Ƿ�ȫ���н��� ���û����һ��������ϣ��㷵��false;
����true; STL�ṩ��������������������Ϲ�ϵ���㷨; �ֱ���next_permutation��prev_permutation;
��һ��ȫ���У�next_Permutation�� ǰһ��ȫ���У�prev_permutation��
*/
