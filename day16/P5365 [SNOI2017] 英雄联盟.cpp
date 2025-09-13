#include<iostream>

using namespace std;

typedef long long LL;

const int N = 300, M = 1e5 + 10; 

LL n,m,f[N][M]; //f[i][j]:表示从1~i个英雄中选择购买其皮肤，花费恰好为j种时的最大展示策略数量。 

LL cnt[N],c[N],sum;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> cnt[i];
	for(int i=1;i<=n;i++) 
	{
		cin >> c[i];
		sum += cnt[i] * c[i]; //计算最大花费 
	}
	
	f[0][0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			f[i][j] = f[i-1][j];
			for(int k=1;k<=cnt[i]&&k*c[i]<=j;k++)
			{				
				f[i][j] = max(f[i][j],f[i-1][j-k*c[i]] * k);
			}
		}
	}
	
	for(int i=1;i<=sum;i++)
	{
		if(f[n][i] >= m)	
		{
			cout << i;
			break;
		}
	}
	
	return 0;
}

//#include<iostream>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 300, M = 1e6 + 10; 
//
//LL n,m,f[M]; //f[i][j]:表示从1~i个英雄中选择购买其皮肤，花费恰好为j种时的最大展示策略数量。 
//
//LL cnt[N],c[N],sum;
//
//int main()
//{
//	cin >> n >> m;
//	
//	for(int i=1;i<=n;i++) cin >> cnt[i];
//	for(int i=1;i<=n;i++) 
//	{
//		cin >> c[i];
//		sum += cnt[i] * c[i]; //计算最大花费 
//	}
//	
//	f[0] = 1;
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=sum;j>=0;j--)
//		{
//			for(int k=1;k<=cnt[i]&&k*c[i]<=j;k++)
//			{				
//				f[j] = max(f[j],f[j-k*c[i]] * k);
//			}
//		}
//	}
//	
//	for(int i=1;i<=sum;i++)
//	{
//		if(f[i] >= m)	
//		{
//			cout << i;
//			break;
//		}
//	}
//	
//	return 0;
//}
