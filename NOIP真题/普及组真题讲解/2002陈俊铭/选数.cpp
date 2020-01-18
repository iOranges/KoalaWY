#include<bits/stdc++.h>
using namespace std;
int n,m,x[23],ans;
bool f[23];
inline bool check(int x){
    for(int i=2;i<=sqrt(x);i++)if(x%i==0)return false;
    return true;
}
inline void dfs(int a,int step,int sum){
    if(step==m){
        if(check(sum))ans++;
        return;
    }
    for(int i=a;i<=n;i++)
        if(!f[i]){f[i]=1;dfs(i,step+1,sum+x[i]);f[i]=0;}
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    for(int i=1;i<=n;i++){
        f[i]=1;
        dfs(i,1,x[i]);
    }
    printf("%d\n",ans);
    return 0;
}
