//�ҹ���
#include <iostream>

using namespace std;

const int N = 110;

int n,m;

int main() 
{
	cin >> n >> m;
	if(n < m) swap(n,m);
	
	int ans1 = 0, ans2 = 0;
	for(int i=1;i<=n;i++) //���������ε�ʱ��ö�ٽ�С��n 
	{
		ans1 += (n - i + 1) * (m - i + 1);
	}	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i == j) continue;
			ans2 += (n - i + 1) * (m - j + 1);	 
		} 
	}
	
	cout << ans1 << " " << ans2;
	return 0;
} 

//����ö��
#include <iostream>

using namespace std;

const int N = 110;

int n,m;

int main() 
{
	cin >> n >> m;
	
	int ans1 = 0, ans2 = 0; //ans1ͳ�������θ�����ans2ͳ�Ƴ����θ��� 
	//ö�پ��ε����Ϻ�������������
	for(int x1=0;x1<=n;x1++) //x1��y1��0��ʼö�� 
		for(int y1=0;y1<=m;y1++)
			for(int x2=x1+1;x2<=n;x2++) //x2��y2��ö��Ҫ����x1��y1 
				for(int y2=y1+1;y2<=m;y2++)
				{ 
					int dx = x2 - x1, dy = y2 - y1;
					if(dx == dy) ans1++;
					else ans2++;
				}		 
	
	cout << ans1 << " " << ans2;
	
	return 0;
}
