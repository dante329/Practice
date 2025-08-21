#include<iostream>

using namespace std;

const int N = 10, M = 1010;

int n = 6, m = 1000;

int w[N] = {0,1,2,3,5,10,20}; //砝码重量 

int a[N]; //记录每个砝码的数量 

int f[N][M]; //一维dp表 

int main()
{
	for(int i=1;i<=n;i++) cin >> a[i];	
	
	f[0][0] = true;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			//先初始化为不选当前法码 
			f[i][j] = f[i-1][j];
			if(f[i][j] == true) continue; //对于总重量j，如果不选当前砝码就已经是可行的了，就找下一个重量
			for(int k=1;k<=a[i] && k*w[i]<=j;k++)
			{
//				f[i][j] = f[i][j] || f[i-1][j-k*w[i]];
				//对于总重量j，找到一种可行的就不继续找了
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
//int w[N] = {0,1,2,3,5,10,20}; //砝码重量 
//
//int a[N]; //记录每个砝码的数量 
//
//int f[M]; //一维dp表 
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
