//找规律
#include <iostream>

using namespace std;

const int N = 110;

int n,m;

int main() 
{
	cin >> n >> m;
	if(n < m) swap(n,m);
	
	int ans1 = 0, ans2 = 0;
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

//暴力枚举
#include <iostream>

using namespace std;

const int N = 110;

int n,m;

int main() 
{
	cin >> n >> m;
	
	int ans1 = 0, ans2 = 0; //ans1统计正方形个数，ans2统计长方形个数 
	//枚举矩形的左上和右下两个顶点
	for(int x1=0;x1<=n;x1++) //x1、y1从0开始枚举 
		for(int y1=0;y1<=m;y1++)
			for(int x2=x1+1;x2<=n;x2++) //x2、y2的枚举要大于x1、y1 
				for(int y2=y1+1;y2<=m;y2++)
				{ 
					int dx = x2 - x1, dy = y2 - y1;
					if(dx == dy) ans1++;
					else ans2++;
				}		 
	
	cout << ans1 << " " << ans2;
	
	return 0;
}
