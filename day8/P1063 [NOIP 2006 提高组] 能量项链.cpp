//#include<iostream>
//
//using namespace std;
//
//typedef pair<int,int> PII;
//
//const int N = 110;
//
//int n,f[N];
//
//PII a[N];
//
//int main()
//{
//	cin >> n;
//	
//	for(int i=1;i<=n;i++) cin >> a[i].first;
//
//	for(int i=1;i<n;i++) a[i].second = a[i+1].first;
//	a[n].second = a[i].first;
//	
//	int ret = 0;
//	for(int i=1;i<=n;i++)
//	{
//		int x = a[i].first, y = a[i].second;
//		for(int j=1;j<=n;j++)
//		{
//			if(a[j].second == y) //����ѡ��ǰi��
//			{
//				f[i]
//			} 
//		}
//		
//	}
//	
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//typedef pair<int,int> PII;
//
//const int N = 110;
//
//int n,f[N];
//
//PII a[N];
//
//int main()
//{
//	cin >> n;
//	
//	for(int i=1;i<=n;i++) cin >> a[i].first;
//
//	for(int i=1;i<n;i++) a[i].second = a[i+1].first;
//	a[n].second = a[1].first;
//	
//	int ret = 0;
//	for(int i=1;i<=n;i++)
//	{
//		int x = a[i].first, y = a[i].second;
//		int j = i + 1;
//		while(j != i)
//		{
//			ret = max(ret,x*y*a[j].second);
//			y = a[j].second;
//			j++;
//			if(j == n) j = 1; 
//		}
//	}
//	
//	cout << ret;
//	return 0;
//}


#include<iostream>

using namespace std;

typedef pair<int,int> PII;

const int N = 210;

int n,f[N][N];

int a[N];

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		a[i+n] = a[i]; //�������������
	}

	//ö�ٳ��ȣ������n+1�� 
	for(int len=3;len<=n+1;len++) 
	{
		//ö����˵� 
		for(int i=1;i+len-1<=2*n;i++)
		{ 
			int j = i + len - 1; //�Ҷ˵� 
			//ö�ٷָ��
			for(int k=i+1;k<j;k++)
			{
				f[i][j] = max(f[i][j],f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
			} 
		}
	}
	
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		ret = max(ret, f[i][i+n]);
	}
	
	cout << ret;
		
	return 0;
}
