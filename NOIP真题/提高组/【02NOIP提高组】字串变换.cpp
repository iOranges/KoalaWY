#include<map>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
int n = 1;
string a[8],b[8],fr,to;
struct node{
	string s;
	int step;
	node(string ssss = "",int sssss = 0): s(ssss),step(sssss){}
};
map<string,bool> vis;
queue<node> q;
void bfs()
{
	node u,v;
	q.push(node(fr,0));
	int ans = 0,len,l;
	register int i,j;
	while(!q.empty())
	{
		u = q.front();q.pop();
		if(vis[u.s]) continue;
		vis[u.s] = true;
		if(u.s == to)
		{
			ans = u.step;
			break;
		}
		len = u.s.length();
		for(i = 0;i < len;++ i)
			for(j = 1;j < n;++ j)
			{
				l = a[j].size();
				if(i + l <= len)
					if(u.s.substr(i,l) == a[j])
					{
						string temp = u.s.substr(0,i) + b[j] + u.s.substr(i + l);
						q.push(node(temp,u.step + 1));
					}
			}
	}
	if(ans <= 10&&ans != 0)
		cout << ans;
	else cout << "NO ANSWER!";
}

int main()
{
	cin >> fr >> to;
	while(cin >> a[n] >> b[n]) ++ n;
	bfs();
	return 0;
}

