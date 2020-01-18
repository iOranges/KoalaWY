#include<iostream>
using namespace std;
int ju[9][9]={{0,0,0,0,0,0,0,0,0},
			  {0,1,0,0,0,1,0,1,1},
			  {0,0,1,1,1,1,0,1,1},
			  {0,0,1,1,0,0,1,1,1},
			  {0,0,1,0,1,1,1,0,1},
			  {0,1,1,0,1,1,1,0,0},
			  {0,0,0,1,1,1,1,1,0},
			  {0,1,1,1,0,0,1,1,0},
			  {0,1,1,1,1,0,0,0,1}};
int a[101],b[101]; //a是队列，b表前驱，s判断 
bool s[9];
void out(int p)
{
	cout << char(a[p]+64);
	while(b[p])
	{
		p = b[p];
		cout << "--" << char(a[p]+64);
	}
	cout << endl;
}

void Bfs()
{
	int head=0,tail=1,i;
	a[1]=1,b[1]=0,s[1]=true;
	do{
		head++;
		for(i=1;i<=8;i++)
			if((!ju[a[head]][i])&&(!s[i]))
			{
				++tail;
				a[tail]=i,b[tail]=head;
				s[i]=true;
				if(i==8)
				{
					out(tail);
					head=tail;
					break;
				}
			}
	}while(head<tail);
} 

int main()
{
	Bfs();
	return 0;
}
