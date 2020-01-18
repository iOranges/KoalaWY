#include<string>
#include<cstring>
#include<iostream>
using namespace std;
bool cannotdetermine,fake[21],ffffff = true;
int n,m,p,faker,belong[105],isguilty[21],date[8];
string guilty[21],notguilty[21],name[21],ans = "There is no ans.";
string days[8] = {"","Today is Monday.","Today is Tuesday.","Today is Wednesday.","Today is Thursday.","Today is Friday.","Today is Saturday.","Today is Sunday."};
string saying[105];
bool check()
{
	memset(date,0,sizeof date);
	memset(isguilty,0,sizeof isguilty);
	register int i,j;
	int who = 0,today = 0,t,WHO = 0;bool flag;
	for(i = 1;i <= p;++ i)
	{
		flag = false;
		if(saying[i] == guilty[0])
		{
			t = fake[belong[i]] ? -1 : 1;
			if(isguilty[belong[i]]&&isguilty[belong[i]] != t) return false;
			isguilty[belong[i]] = t;continue;
		}
		else if(saying[i] == notguilty[0])
		{
			t = fake[belong[i]] ? 1 : -1;
			if(isguilty[belong[i]]&&isguilty[belong[i]] != t) return false;
			isguilty[belong[i]] = t;continue;
		}
		for(j = 1;j <= 7;++ j)
			if(days[j] == saying[i])
			{
				t = fake[belong[i]] ? -1 : 1,flag = true;
				if(date[j]&&date[j] != t) return false;
				date[j] = t;break;	
			}
		if(flag) continue;
		for(j = 1;j <= n;++ j)
			if(guilty[j] == saying[i])
			{		
				t = fake[belong[i]] ? -1 : 1,flag = true;
				if(isguilty[j]&&isguilty[j] != t) return false;	
				isguilty[j] = t;break;
			}
		if(flag) continue;
		for(j = 1;j <= n;++ j)
			if(notguilty[j] == saying[i])
			{
				t = fake[belong[i]] ? 1 : -1,flag = true;
				if(isguilty[j]&&isguilty[j] != t) return false;	
				isguilty[j] = t;break;
			}
	}
	flag = false;
	for(i = 1;i <= 7;++ i)
		if(date[i] == 1) 
		{
			flag = true;
			if(!today) today = i;
			else return false;	
		}
		else if(date[i] == 0) flag = true;
	if(!flag) return false;
	for(i = 1;i <= n;++ i)
		if(isguilty[i] == 1)
		{
			if(who == 0) who = i;
			else who = -1;
		}
		else if(isguilty[i] == 0)
		{
			if(WHO == 0) WHO = i;
			else WHO = -1;
		}
	if(who == 0&&WHO > 0) who = WHO;
	if(who > 0) 
	{
		if(ans == "There is no ans.") ans = name[who];
		else if(ans != name[who]) cannotdetermine = true;
	}
	if(who == -1) return false;
	return true;
}

void dfs(int x)
{
	if(x > n)
	{
		if(faker == m)
			if(!check()||ans != "There is no ans.")
				ffffff = false; 
		return;
	}
	if(faker < m)
	{
		fake[x] = true,++ faker;
		dfs(x + 1);
		fake[x] = false,-- faker;		
	}
	dfs(x + 1);
}

int main()
{
	cin >> n >> m >> p;
	register int i,j;
	guilty[0] = "I am guilty.",notguilty[0] = "I am not guilty.";
	for(i = 1;i <= n;++ i)
	{
		cin >> name[i];
		guilty[i] = name[i] + " is guilty.";
		notguilty[i] = name[i] + " is not guilty.";
	}
	string nm;
	for(i = 1;i <= p;++ i)
	{
		cin >> nm;
		nm.erase(nm.end() - 1);
		for(j = 1;j <= n;++ j)
			if(nm == name[j])
			{
				belong[i] = j;
				break;
			} 
		getline(cin,saying[i]);
		saying[i].erase(saying[i].begin());
		if(*(saying[i].end() - 1) == '\r') saying[i].erase(saying[i].end() - 1);
	 } 
	dfs(1);
	if(ffffff) cannotdetermine = true;
	if(cannotdetermine) cout << "Cannot Determine";
	else if(ans != "There is no ans.") cout << ans;
	else cout << "Impossible";
	return 0;
}
