#include<cstdio>
#define SIZE 1<<20
int pos[100005],b[100005],d[100005],len;
char buf[SIZE],*S = buf,*T = buf;
inline char gc() {return S == T && (T = (S = buf) + fread(buf,1,SIZE,stdin),S == T) ? -1 : *S++;}
#define getc(stdin) gc()
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int n,a;
	read(n);
	register int i,l,r,mid;
	for(i = 1;i <= n;++ i)
	{
		read(a);
		pos[a] = i;
	}
	for(i = 1;i <= n;++ i)
		read(b[i]);
	d[++ len] = pos[b[1]];
	for(i = 2;i <= n;++ i)
	{
		if(pos[b[i]] > d[len]) d[++ len] = pos[b[i]];
		else 
		{
			l = 1,r = len;
			while(l <= r)
			{
				mid = (l + r) >> 1;
				if(d[mid] > pos[b[i]]) r = mid - 1;
				else l = mid + 1;
			}
			d[l] = pos[b[i]];
		}
	}
	printf("%d",len);
	return 0;
}
