#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e4 + 10;

int n,k,a[N],f[N],g[N]; 
//����Ҫ������չʾ����һ��չʾ�������ʯ�����������һ��������л�Ӱ��ڶ��������е�����ȡ�
//������ȷ�ķ�ʽ����ͬʱ�󣬱���ö��������������ķָ�㣬���һ���������������ڲ���
//���û�������Ԥ����f��g�������飬��ö�ٷָ���ʱ����f[i-1]+g[i]�����ֵ��������������������ѡ�����ĸ��������������������� 
//f[i]:[1,i]�����ڵ�������� 
//g[i]:[i,n]�����ڵ�������� 

int main()
{
	cin >> n >> k;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	//���򻬶����� 
	for(int left=1,right=1;right<=n;right++)
	{
		while(a[right] - a[left] > k) left++; //�Ƿ� 
		
		//����while�ͺϷ�
		f[right] = max(f[right-1],right-left+1); 
	}
	
	//���򻬶����� 
	for(int left=n,right=n;left>=1;left--)
	{
		while(a[right] - a[left] > k) right--; //�Ƿ� 
		
		//����while�ͺϷ�
		g[left] = max(g[left+1],right-left+1); 
	}
	
	//ö�ٷָ��
	int ret = 0;
	for(int i=2;i<=n;i++) 
	{
		ret = max(ret,f[i-1] + g[i]);
	}
	
	cout << ret;
	return 0;
}
