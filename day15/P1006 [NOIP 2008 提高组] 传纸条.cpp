#include<iostream>

using namespace std;

const int N = 55;

//注意f第一维开两倍 
int n,m,f[N+N][N][N],a[N][N]; //f[s][i1][i2]：表示横纵坐标和为s，第一条线路的横坐标为i1，第二条线路的横坐标为i2时，两条路径的好感度和最大值 

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	
	for(int s=2;s<=n+m;s++) //s从2开始枚举，因为有两条线路 
	{
		for(int i1=1;i1<=n;i1++)
		{
			for(int i2=1;i2<=n;i2++)
			{
				if(i1 == i2 && s != n + m) continue; //不能走到同一个格子，在右下角相遇除外 
				int j1 = s - i1, j2 = s - i2;
				if(j1 <= 0 || j2 <= 0 || j1 > m || j2 > m) continue; //s_max=n+m,i_min=1,j_max=n+m-1所以j时可能超过m的，要做过滤 
				int& t = f[s][i1][i2]; //可以用引用来代替当前状态 
				t = max(t,f[s-1][i1-1][i2-1]);
				t = max(t,f[s-1][i1-1][i2]);
				t = max(t,f[s-1][i1][i2-1]);
				t = max(t,f[s-1][i1][i2]);
				t += a[i1][j1] + a[i2][j2]; 
			}
		}
	}
	
	cout << f[n+m][n][n];
}
