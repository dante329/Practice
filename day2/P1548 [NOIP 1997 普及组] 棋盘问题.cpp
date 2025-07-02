#include <iostream>

using namespace std;

const int N = 110;

int n,m;

int main() 
{
	cin >> n >> m;
	if(n < m) swap(n,m);
	
	int ans1 = 0,ans2 = 0;
	for(int i=1;i<=n;i++) //计算正方形的时候枚举较小的n 
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
