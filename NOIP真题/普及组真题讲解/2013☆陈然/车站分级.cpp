#include<bits/stdc++.h>
using namespace std;
 
int ans;
int rd[2000],dis[2000];//入度;最大深度;
int head[2000],tot=0;//前向星里面会用到的▲▲▲
bool vis[1005][1005];
int yes[2000],no[2000],stop[2000];//yes表示停靠站，no表示非停靠站
 
struct node
{
    int y,nxt;//y：站点
}edge[1000005];
 
void add(int x,int y)//构建一条有向边
{
    tot++;
    edge[tot].y=y;
    edge[tot].nxt=head[x];
    head[x]=tot;
}
 
void Init()//每趟车次的停靠情况
{
    memset(stop,0,sizeof(stop));//不要忘记初始化
    int k,t=0;
    scanf("%d",&k);//有k个停靠点
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&yes[i]);
        stop[yes[i]]=1;//记录停靠站，stop标记停靠站
    }   
    for(int i=yes[1];i<=yes[k];i++)//在这趟车次的起始范围里循环每个停靠点
        if(stop[i]==0)
            no[++t]=i;//筛选非停靠站
    //t ：此趟车次有多少个非停靠点
//  if(k+t==yes[k]-yes[1]+1)
//      printf("是真的诶！\nk=%d t=%d 总经历站点=%d\n",k,t,yes[k]-yes[1]+1);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=t;j++)
            if(vis[yes[i]][no[j]]==0)
            {
                vis[yes[i]][no[j]]=1;//表示此路径已出现
                add(yes[i],no[j]);//添加有向边，表示yes[i]'s level＞no[j]'s level
                rd[no[j]]++;//标记入度不为0
            }
    return;
}
 
void dfs(int u,int deep)
{
    if(deep<=dis[u])return ;//如果深度不大于原有深度，就返回--更新最大深度
    dis[u]=deep;//标记最大深度
    for(int i=head[u];i!=-1;i=edge[i].nxt)//▲▲▲▲▲
        dfs(edge[i].y,deep+1);//到下一点▲▲▲▲▲
}
                                                                                                  
int main()
{
    //输入
    int n,m;cin>>n>>m;//n 个火车站 m 趟车次
    //初始化
    memset(rd,0,sizeof(rd));//rd:判断i点入度是否为0（是否有边指向i点）
    memset(dis,0,sizeof(dis));//dis:从任意一点到i的最大深度（与车站级数相反）
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));// ▲▲▲
    //预处理
    for(int i=1;i<=m;i++)// m 趟车次 （m条边）
        Init();
    //DFS   
    for(int i=1;i<=n;i++)//n个火车站（n个结点）
        if(rd[i]==0)//是个起点？？？   
            dfs(i,1);//如果入度为0，则进行尝试
    //ans=最大深度
    for(int i=1;i<=n;i++)
        if(dis[i]>ans)
            ans=dis[i];//比较得出最大深度
    //输出
    cout<<ans;//原来最大深度就是要分多少个level呀 ▲▲▲
    return 0;
}
