#include<bits/stdc++.h>
using namespace std;
 
int ans;
int rd[2000],dis[2000];//���;������;
int head[2000],tot=0;//ǰ����������õ��ġ�����
bool vis[1005][1005];
int yes[2000],no[2000],stop[2000];//yes��ʾͣ��վ��no��ʾ��ͣ��վ
 
struct node
{
    int y,nxt;//y��վ��
}edge[1000005];
 
void add(int x,int y)//����һ�������
{
    tot++;
    edge[tot].y=y;
    edge[tot].nxt=head[x];
    head[x]=tot;
}
 
void Init()//ÿ�˳��ε�ͣ�����
{
    memset(stop,0,sizeof(stop));//��Ҫ���ǳ�ʼ��
    int k,t=0;
    scanf("%d",&k);//��k��ͣ����
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&yes[i]);
        stop[yes[i]]=1;//��¼ͣ��վ��stop���ͣ��վ
    }   
    for(int i=yes[1];i<=yes[k];i++)//�����˳��ε���ʼ��Χ��ѭ��ÿ��ͣ����
        if(stop[i]==0)
            no[++t]=i;//ɸѡ��ͣ��վ
    //t �����˳����ж��ٸ���ͣ����
//  if(k+t==yes[k]-yes[1]+1)
//      printf("���������\nk=%d t=%d �ܾ���վ��=%d\n",k,t,yes[k]-yes[1]+1);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=t;j++)
            if(vis[yes[i]][no[j]]==0)
            {
                vis[yes[i]][no[j]]=1;//��ʾ��·���ѳ���
                add(yes[i],no[j]);//�������ߣ���ʾyes[i]'s level��no[j]'s level
                rd[no[j]]++;//�����Ȳ�Ϊ0
            }
    return;
}
 
void dfs(int u,int deep)
{
    if(deep<=dis[u])return ;//�����Ȳ�����ԭ����ȣ��ͷ���--����������
    dis[u]=deep;//���������
    for(int i=head[u];i!=-1;i=edge[i].nxt)//����������
        dfs(edge[i].y,deep+1);//����һ�����������
}
                                                                                                  
int main()
{
    //����
    int n,m;cin>>n>>m;//n ����վ m �˳���
    //��ʼ��
    memset(rd,0,sizeof(rd));//rd:�ж�i������Ƿ�Ϊ0���Ƿ��б�ָ��i�㣩
    memset(dis,0,sizeof(dis));//dis:������һ�㵽i�������ȣ��복վ�����෴��
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));// ������
    //Ԥ����
    for(int i=1;i<=m;i++)// m �˳��� ��m���ߣ�
        Init();
    //DFS   
    for(int i=1;i<=n;i++)//n����վ��n����㣩
        if(rd[i]==0)//�Ǹ���㣿����   
            dfs(i,1);//������Ϊ0������г���
    //ans=������
    for(int i=1;i<=n;i++)
        if(dis[i]>ans)
            ans=dis[i];//�Ƚϵó�������
    //���
    cout<<ans;//ԭ�������Ⱦ���Ҫ�ֶ��ٸ�levelѽ ������
    return 0;
}
