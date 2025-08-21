//�����Ȳ�������һʱ��û�з�Ӧ�������ڿ���άǰ׺�͡����ڿ���ѵ��������� 
//#include<iostream>
//
//using namespace std;
//
//int a[1010][1010];
//
//int n,m,c;
//
//int main()
//{
//	cin >> n >> m >> c;
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	
//	int ret = 0;
//	//ö�����϶��� 
//	for(int i=1;i<=n-c+1;i++)
//	{
//		for(int j=1;j<=m-c+1;j++)
//		{
//			int sum = 0;
//			for(int x=0;x<c;x++)
//			{
//				for(int y=0;y<c;y++)
//				{
//					sum += a[i+x][j+y];
//				}
//			} 
//			ret = max(ret,sum);
//		}
//	}
//	
//	cout << ret;
//	
//	return 0;
//}

#include<iostream>

using namespace std;

typedef long long LL;

LL f[1010][1010];

int n,m,c;

//��ô���ڱ����������ӳ������ˣ��������ѵ�OK���� 
//LL calc(int x, int y)
//{
//	LL sum = 0;
//	for(int i=x;i<x+c;i++) 
//	{
//		for(int j=y;j<y+c;j++)
//		{
//			sum += f[i][j];
//		}
//	}
//	
//	return sum;
//}

int main()
{
	cin >> n >> m >> c;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x; cin >> x;
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + x;
		}
	}
	
	LL ret = -1e18;
	int x,y;
	//ö�����϶��� 
	for(int i=1;i<=n-c+1;i++)
	{
		for(int j=1;j<=m-c+1;j++)
		{
			//�����¶��� 
			int x1 = i, y1 = j, x2 = i + c - 1, y2 = j + c - 1; 
			LL t = f[x2][y2] - f[x2][y1-1] - f[x1-1][y2] + f[x1-1][y1-1]; 
			if(ret < t)
			{
				ret = t;
				x = x1, y = y1;
			}
		}
	}
	
	cout << x << " " << y;
	
	return 0;
}
