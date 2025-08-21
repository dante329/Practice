#include<iostream>

using namespace std;

const int N = 10, M = 1010;

int n = 6, m = 1000;

int w[N] = {0,1,2,3,5,10,20}; //�������� 

int a[N]; //��¼ÿ����������� 

int f[N][M]; //һάdp�� 

int main()
{
	for(int i=1;i<=n;i++) cin >> a[i];	
	
	f[0][0] = true;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			//�ȳ�ʼ��Ϊ��ѡ��ǰ���� 
			f[i][j] = f[i-1][j];
			if(f[i][j] == true) continue; //����������j�������ѡ��ǰ������Ѿ��ǿ��е��ˣ�������һ������
			for(int k=1;k<=a[i] && k*w[i]<=j;k++)
			{
//				f[i][j] = f[i][j] || f[i-1][j-k*w[i]];
				//����������j���ҵ�һ�ֿ��еľͲ���������
				if(f[i-1][j-k*w[i]] == true)
				{
					f[i][j] = true;
					break;
				} 
		
			}
		}
	}
	
	int ret = 0;
	for(int j=1;j<=m;j++)
	{
		if(f[n][j] == true) ret++;
	}
	
	cout << "Total=" << ret;
	
	return 0;
}

//#include<iostream>
//
//using namespace std;
//
//const int N = 10, M = 1010;
//
//int n = 6, m = 1000;
//
//int w[N] = {0,1,2,3,5,10,20}; //�������� 
//
//int a[N]; //��¼ÿ����������� 
//
//int f[M]; //һάdp�� 
//
//int main()
//{
//	for(int i=1;i<=n;i++) cin >> a[i];	
//	
//	f[0] = true;
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=m;j>=0;j--)
//		{
//			for(int k=1;k<=a[i] && k*w[i]<=j;k++)
//			{
//				f[j] = f[j] || f[j-k*w[i]];
//			}
//		}
//	}
//	
//	int ret = 0;
//	for(int j=1;j<=m;j++)
//	{
//		if(f[j] == true) ret++;
//	}
//	
//	cout << "Total=" << ret;
//	
//	return 0;
//}
