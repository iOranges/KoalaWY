#include <bits/stdc++.h>
using namespace std;
/*
cnbb sort�Ǹ�tle�㷨..
sort���ÿ���ԭ��ʵ�� ��ԭ����������ʱ�˻���O(n^2)
��ô.. 
��д�鲢get�� 
*/
using namespace std;
int n,r,q,qwq;
int data[233333],win[233333]/*������(��)*/,lose[233333]/*��ս����(��)*/,score[233333],power[233333];
//win��lose������صĶ��Ǳ��
bool cmp (int x,int y)
{
	if (score[x] == score[y])//������� 
	{
		if (x < y) return true;//������� 
		return false;
	}
	if (score[x] > score[y])/*��������*/  return true;//������� 
	return false;
}
void guibing()//�鲢���� 
//��tm�Ǹ�ģ��
//���ò����ṹ��(��Ϊsort�����cmp���) 
{
	//������Ǵ�����,���������ս����
	//Ȼ����ֵĿ�ʼ�鲢
	int left = 1,right = 1,temp = 0/*�������*/;
	while (left <= qwq && right <= qwq) 
	{
		temp++;
		if (cmp(win[left],lose[right]))//����������Ʒֶ�Щ,����ǰ�� 
		{
			data[temp] = win[left];
			left++;
		}
		else//�����黹û��ս����ֶ�.. 
		{
			data[temp] = lose[right];
			right++;
		}
	}
	while (left <= qwq)//�����黹�м�����û���� 
	{
		temp++;
		data[temp] = win[left];
		left++;
	}
	while (right <= qwq)//��ս���黹�м�����û���� 
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
	//��һ����tm�ù鲢,qwq��û��ֵ
	//��sortһ�β��ỳ����.. 
	for (int i = 1;i <=	r;i++)
	{
		qwq = 0;//���������ǵ�ǰ��ս2���� 
		for (int j = 1;j <=	n;j += 2)//������ս�ͼ�2 
		{
			qwq++;
			if(power[data[j]] > power[data[j + 1]])//ʵ���Ƚ� 
			{
				score[data[j]]++;//Goal! 
				win[qwq] = data[j];//���������� 
				lose[qwq] = data[j + 1];//������ս���� 
			}
			else
			{
				score[data[j + 1]]++;//Goal!
				win[qwq] = data[j + 1];//���������� 
				lose[qwq] = data[j];//������ս���� 
			}
		}
		guibing();
	}
	cout << data[q];
}
