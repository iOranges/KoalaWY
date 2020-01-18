#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
struct node{
	int x,y,w;
}e[1001];
int n;
double ansx,ansy,answ;
double t,down = 0.98;

inline void read(int &x)
{
	char ch;int f =1;x = 0;
	ch = getc(stdin);
	while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch = getc(stdin);}
	while(ch<='9'&&ch>='0'){x = (x<<1) + (x<<3) + (ch^48);ch = getc(stdin);}
	x *= f;
}

double energy(double x,double y)
{
	double res = 0,dx,dy;
	for(int i=1;i<=n;i++)
	{
		dx = x - 1.0 * e[i].x;
		dy = y - 1.0 * e[i].y;
		res += sqrt(dx*dx+dy*dy) * 1.0 * e[i].w;
	}
	return res;
}

void SA()
{
	t = 2050;
	while(t>1e-14)
	{
		double ex = ansx + (rand()*2 - RAND_MAX) * t;
		double ey = ansy + (rand()*2 - RAND_MAX) * t;
		double ew = energy(ex,ey);
		double delta = ew - answ;
		if(delta < 0)
		{
			ansx = ex;
			ansy = ey;
			answ = ew;
		}
		else if(exp((-delta)/t)*RAND_MAX>rand())
		{
			ansx = ex;
			ansy = ey;
		}
		t *= down;
	}
	
}

int main()
{
	int i;
	read(n);
	srand(19260817);
	srand(rand());
	srand(rand());
	for(i=1;i<=n;i++)
	{
		read(e[i].x),read(e[i].y),read(e[i].w);
		ansx += e[i].x,ansy += e[i].y;
	}
	ansx /= 1.0 * n;
	ansy /= 1.0 * n;
	answ = energy(ansx,ansy);
	while ((double)clock()/CLOCKS_PER_SEC<0.8) 
		SA();
	printf("%.3lf %.3lf",ansx,ansy);
	return 0;
}
