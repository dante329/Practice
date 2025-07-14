#include<iostream>

using namespace std;

typedef long long LL;

const int N = 5e3 + 10;

//当矩形中所有数都变为0时，差分数组中的所有数也会全部变为0。这样可以从枚举k x k的所有点优化成只枚举k x k的左上端点 
int n,m,k;

LL f[N][N]; 

void insert(int x1, int y1, int x2, int y2, int z)
{
	f[x1][y1] += z;
	f[x1][y2 + 1] -= z;
	f[x2 + 1][y1] -= z;
	f[x2 + 1][y2 + 1] += z;
}

int main()
{
	cin >> n >> m >> k;
	
	while(m--)
	{
		int x,y,z; cin >> x >> y >> z;
		insert(x, y, x, y, z);
	}
	
	LL sum = 0; //总操作次数可能超过int范围
	 
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=1;j<=n-k+1;j++)
		{
			sum += abs(f[i][j]);
			insert(i, j, i + k - 1, j + k - 1, -f[i][j]); //-f[i][j]为了抵消原f[i][j]，使其值变为0 
		}
	}
	
	//检查n x n范围内的差分数组的值有没有不为0的，如果有就代表无法完成 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j])
			{
				cout << -1 << endl;
				return 0;
			}
		
	cout << sum << endl;
	return 0;
}
