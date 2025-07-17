//二维 
//#include<iostream>
//
//using namespace std;
//
//typedef long long LL; 
//
//int n;
// 
//LL f[40][800]; //f[i][j]:从前i个数中选出数值和为j的方案数 
//
//int main()
//{
//	cin >> n;
//
//	int sum = (1 + n) * n / 2; //等差数列求和 
//	
//	if(sum % 2 == 1) //总和是奇数就凑不出来两堆数值相同的 
//	{
//		cout << 0;
//		return 0;
//	}
//	
//	sum /= 2; //sum/2作为限制条件 
//
//	f[0][0] = 1; //当状态表示为方案数的时候，不要忘记初始化！！！ 
//	 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=sum;j++)
//		{
//			f[i][j] += f[i-1][j]; //不选 
//			if(j >= i) f[i][j] += f[i-1][j-i]; //选 
//		}
//	}	
//	
//	cout << f[n][sum] / 2; //题目问的是可以分成多少对 
// 	
//	return 0;
//}


//一维
#include<iostream>

using namespace std;

typedef long long LL; 

int n;
 
LL f[800];  

int main()
{
	cin >> n;

	int sum = (1 + n) * n / 2; //等差数列求和 
	
	if(sum % 2 == 1) //总和是奇数就凑不出来两堆数值相同的 
	{
		cout << 0;
		return 0;
	}
	
	sum /= 2; //sum/2作为限制条件 

	f[0] = 1; //当状态表示为方案数的时候，不要忘记初始化！！！ 
	 
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=i;j--)
		{
			f[j] = f[j] + f[j-i];
		}
	}	
	
	cout << f[sum] / 2; //题目问的是可以分成多少对 
 	
	return 0;
}
