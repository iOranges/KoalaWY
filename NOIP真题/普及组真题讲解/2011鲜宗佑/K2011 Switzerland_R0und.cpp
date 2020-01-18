#include <bits/stdc++.h>
using namespace std;
/*
cnbb sort是个tle算法..
sort运用快排原理实现 当原数列已有序时退化成O(n^2)
那么.. 
手写归并get√ 
*/
using namespace std;
int n,r,q,qwq;
int data[233333],win[233333]/*传奇组(雾)*/,lose[233333]/*挑战者组(雾)*/,score[233333],power[233333];
//win和lose里面承载的都是编号
bool cmp (int x,int y)
{
	if (score[x] == score[y])//分数相等 
	{
		if (x < y) return true;//编号优先 
		return false;
	}
	if (score[x] > score[y])/*分数不等*/  return true;//大分优先 
	return false;
}
void guibing()//归并排序 
//就tm是个模板
//并用不来结构体(因为sort用这个cmp会崩) 
{
	//左序就是传奇组,右序就是挑战者组
	//然后快乐的开始归并
	int left = 1,right = 1,temp = 0/*编号重载*/;
	while (left <= qwq && right <= qwq) 
	{
		temp++;
		if (cmp(win[left],lose[right]))//传奇组这个逼分多些,排在前面 
		{
			data[temp] = win[left];
			left++;
		}
		else//传奇组还没挑战者组分多.. 
		{
			data[temp] = lose[right];
			right++;
		}
	}
	while (left <= qwq)//传奇组还有几个逼没算上 
	{
		temp++;
		data[temp] = win[left];
		left++;
	}
	while (right <= qwq)//挑战者组还有几个逼没算上 
	{
		temp++;
		data[temp] = lose[right];
		right++;
	}
}
int main()
{
	cin >> n >> r >> q;
	n *= 2;
	for (int i = 1;i <=	n;i++)
	{
		cin >> score[i];
		data[i] = i;
	}
	for (int i = 1;i <=	n;i++)
	{
		cin >> power[i];
	}
	sort(data + 1,data + 1 + n,cmp);//Round 1 Fight!
	//第一步别tm用归并,qwq都没置值
	//就sort一次不会怀孕啦.. 
	for (int i = 1;i <=	r;i++)
	{
		qwq = 0;//这个逼算的是当前对战2人组 
		for (int j = 1;j <=	n;j += 2)//两两对战就加2 
		{
			qwq++;
			if(power[data[j]] > power[data[j + 1]])//实力比较 
			{
				score[data[j]]++;//Goal! 
				win[qwq] = data[j];//晋级传奇组 
				lose[qwq] = data[j + 1];//滚回挑战者组 
			}
			else
			{
				score[data[j + 1]]++;//Goal!
				win[qwq] = data[j + 1];//晋级传奇组 
				lose[qwq] = data[j];//滚回挑战者组 
			}
		}
		guibing();
	}
	cout << data[q];
}
