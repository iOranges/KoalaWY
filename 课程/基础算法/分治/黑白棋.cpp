#include<iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::swap;
int n,step=0,empet;
char ch[1001];
char ha[5][10]=
{
	{'o','o','o','-','-','*','*','*','o','*'},
	{'o','o','o','*','o','*','*','-','-','*'},
	{'o','-','-','*','o','*','*','o','o','*'},
	{'o','*','o','*','o','*','-','-','o','*'},
	{'-','-','o','*','o','*','o','*','o','*'},
};
void print()
{
	printf("step%2d:",step++);
	for(int i=1;i<=2*n+2;i++)
		cout << ch[i];
	cout << "\n";
 } 
 
void move(int k)
{
	for(int j=0;j<=1;j++)
		swap(ch[empet+j],ch[k+j]);
	empet = k;
	print();
}

int main()
{
	int i,temp,j,k;
	cin >> n;
	empet = 2*n+1;	
	for(i=1;i<=n;i++)
	{
		ch[i]='o';
		ch[i+n]='*';
	}
	ch[empet+1]=ch[empet]='-';
	print();
	temp = n;
	while(temp!=4)
	{
		move(temp);
		move(2*temp-1);
		temp--;
	}
	for(i=0;i<5;i++)
	{
		printf("step%2d:",step++);
		for(j=0;j<10;j++)
			cout << ha[i][j];
		for(k=11;k<=2*n+2;k++)
			cout << ch[k];
		cout << "\n";
	}
	return 0;
 } 
