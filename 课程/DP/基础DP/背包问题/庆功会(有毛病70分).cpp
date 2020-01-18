#include<iostream>//RE
using namespace std;
int w[10001],c[10001],f[6001];
int main()
{
	int m,n,i,v,s,q,x,y;
	cin >> n >> m;
	for(i=1,q=1;i<=n;i++,q++)
	{
		cin >> w[q] >> c[q] >> s;
		x = w[q],y = c[q];
		while(--s)
		{	
			++q;
			w[q]=x;
			c[q]=y;
		 } 
	 } 
	for(i=1;i<=q;i++)
		for(v=m;v>=w[i];v--)
			f[v]=max(f[v-w[i]]+c[i],f[v]);
	cout << f[m];
	return 0;
}
