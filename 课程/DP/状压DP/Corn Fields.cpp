#include<cstdio>
int mod = 100000000,n,m,state[1501],cur[1501],f[15][1501],tot;
void read(int &x)
{
	char ch;x=0;
	ch = getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch<='9'&&ch>='0') {x = (x<<1)+(x<<3)+(ch^48);ch = getchar();}
}

bool fit(int x,int k)
{
	return !(state[x]&cur[k]); //当前的第x个状态符不符合第k排的情况 
}

int main()
{
	int i,j,k,sum;
	read(n),read(m);
	sum = 1<<m;
	for(i=0;i<sum;i++)
		if(!(i&(i<<1)))
			state[++tot] = i;	//枚举每行可能出现的无相邻的状态 
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			read(k);
			if(!k)
				cur[i] += (1<<(m-j));
		}
	for(i=1;i<=tot;i++)
		if(fit(i,1))
			f[1][i] = 1;
	for(i=2;i<=n;i++)
		for(j=1;j<=tot;j++)
			if(fit(j,i))
				for(k=1;k<=tot;k++)
					if(fit(k,i-1))
						if(!(state[k]&state[j]))
							f[i][j] = (f[i][j] + f[i-1][k]) % mod;
	sum = 0;
	for(i=1;i<=tot;i++)
		sum = (sum + f[n][i]) % mod;
	printf("%d",sum);
	return 0;
}
