#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N][N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0][0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=a[i] && k<=j;k++)
			{
				f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;
			}
		}
	}
	
	cout << f[n][m];
	return 0;
}


//一维 
#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			for(int k=0;k<=a[i] && k<=j;k++)
			{
				f[j] = (f[j] + f[j-k]) % MOD;
			}
		}
	}
	
	cout << f[m];
	return 0;
}

//改 
#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			for(int k=1;k<=a[i] && k<=j;k++)
			{
				f[j] = (f[j] + f[j-k]) % MOD;
			}
		}
	}
	
	cout << f[m];
	return 0;
}

//多重背包模板 
#include <iostream>

using namespace std;

const int N = 110;

int x[N],w[N],v[N],f[N][N];
int n,m;
 
int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> x[i] >> w[i] >> v[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			//先不选
			f[i][j] = f[i-1][j];
			//再枚举选1~k次
			for(int k=1;k<=x[i] && k*w[i]<=j;k++)
			{
				f[i][j] = max(f[i-1][j],f[i-1][j-k*w[i]]+k*v[i]);
			}
			//如果不进行空间优化，确实可以写成下面这样，k=0的时候就代表着“不选”这种情况，后面的1~kmax就代表选1~k次。
			//但是一但空间优化就错了，所以还是要将不选和选的情况分开来
			//for(int k=0;k<=x[i] && k*w[i]<=j;k++)
			//{
			//	  f[i][j] = max(f[i-1][j],f[i-1][j-k*w[i]]+k*v[i]);
			//}
		}
	}
	
	cout << f[n][m];
	
	return 0;
}
