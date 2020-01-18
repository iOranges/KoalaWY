#include<string>
#include<iostream>
using namespace std;
string a[50001],s;
int c[101],f[101][101],r[101],ans[101],line[101];

int main()
{
	int n,i,j,x,y,cnt=0,tot=0,num=0,temp,k='a',o=0;
	cin >> n >> a[1];
	for(i=2;i<=n;i++)
	{
		cin >> a[i];
		for(j=0;j<a[i-1].size();j++)
			if(a[i-1][j]!=a[i][j])
			{
				x = a[i-1][j]-'a'+1;
				y = a[i][j] - 'a'+1;
				c[x]++,r[y]++;
				f[x][c[x]] = y;
				cnt = max(cnt,max(x,y));
				break;
			}
	}
	for(i=1;i<=cnt;i++)
		if(r[i]==0)
		{
			if(o>=1)
			{
				cout << 0;		
				return 0;		
			}
			o++;
			ans[++tot] = i;			
		}
	while(tot!=0)
	{
		o=0;
		temp = ans[tot];
		tot--,num++;
		line[temp] = k++;
		for(i=1;i<=c[temp];i++)
		{
			r[f[temp][i]]--;
			if(r[f[temp][i]]==0)
			{
				if(o>=1)
				{
					cout << 0; 		
					return 0;			
				}
				ans[++tot] = f[temp][i];	
				o++;			
			}
		}
	}
	if(num!=cnt)
		cout << 0;
	else
	{
		cin >> s;
		for(i=0;i<s.size();i++)
			if(line[s[i]-'a'+1]==0)
			{
				cout << 0;
				return 0;
			}
		for(i=0;i<s.size();i++)	
			cout << char(line[s[i]-'a'+1]);			
	}
	return 0;
 } 
