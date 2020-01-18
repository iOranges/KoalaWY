#include<iostream> //ÓÐBUG 
#include<cstdio>
#include<cstring>
using namespace std; 
char num[241];
int main()
{
	int s,k=0,i,j;
	gets(num);
	cin >> s;
	k=strlen(num);
	for(i=1;i<=s;i++)
	{
		for(j=0;j<k-1;j++)
			if(num[j]>num[j+1])
			{
				for(int l=j;l<k-1;l++)
					num[l]=num[l+1];
				break;
			}
		k--;
	}
	i=0;
    while(i<=k-1&&num[i]=='0')i++;
    if(i==k) cout << 0;
    else
        for(j=i;j<k;j++)
            cout << num[j]; 	
	return 0;
} 
