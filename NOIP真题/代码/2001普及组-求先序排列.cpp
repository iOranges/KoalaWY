#include<bits/stdc++.h>
using namespace std;
char s1[10],s2[10];
int len;
inline int find(char x)
{
    for(int i=0;i<len;i++)
        if(s1[i]==x) return i;
    return 0;
}
void dfs(int l1,int r1,int l2,int r2)
{
    int m=find(s2[r2]);cout<<s2[r2];
    if(m>l1) /*����������*/dfs(l1,m-1,l2,r2-r1+m-1);//r1-mΪ����������� 
    if(m<r1) /*����������*/dfs(m+1,r1,l2+m-l1,r2-1);//m-l1Ϊ�������ڵ���
}
int main()
{
    cin>>s1>>s2;
    len=strlen(s1);
    dfs(0,len-1,0,len-1);
}
