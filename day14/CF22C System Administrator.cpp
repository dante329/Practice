#include<iostream>

using namespace std;

int n,m,v;

int main()
{
	cin >> n >> m >> v;
	
	if(m < n-1 || m > (n-1)*(n-2)/2+1) 
	{
		cout << -1;
		return 0;
	}
	
	//v����Ҫ���������е������������ 
	for(int i=1;i<=n;i++)
	{
		if(i == v) continue;
		cout << v << " " << i << endl;
		m--;
	}
	
	//ѡ��һ����ֻ��v��������������ϵ�v�������ô����ͼ�ض�����ͨ 
	int w = 1;
	if(w == v) w = 2;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(!m) return 0;
			if(i == v || j == v || i == w || j == w) continue;
			cout << i << " " << j << endl;
			m--;
		}
	}
	
	return 0;
}
