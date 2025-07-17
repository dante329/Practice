#include<iostream>

using namespace std;

const int N = 10;

int n,m,ret;

bool st[N][N];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};


void dfs(int x, int y)
{
	//出口
	if(x < 1 || x >= n || y < 1 || y >= m) 
	{
		ret++; //return了就代表找到出路了，得到了一个新方案 
		return;
	}
	
	st[x][y] = true; //打标记防止dfs(i,j)又递归回来了 
	for(int k=0;k<4;k++)
	{
		int i = x + dx[k], j = y + dy[k];
		if(!st[i][j]) dfs(i,j);		 
	}
	st[x][y] = false;
	 
}

int main()
{
	cin >> n >> m;
	
	//从上面开始搜 
	for(int i=1;i<n;i++) //避开四角 
	{
		//(i,0)->(i,1) 
		st[i][0] = true; //将(i,0)打上标记代表已经走过了，然后从(i,1)开始搜，这样就避免了要在dfs中特判递归出口不能是(i,0)（出发点） 
		dfs(i,1);
		st[i][0] = false;
	}
	
	//从左边搜 
	for(int j=1;j<m;j++)
	{
		//(0,j)->(1,j)
		st[0][j] = true;
		dfs(1,j);
		st[0][j] = false;
	}
	
	cout << ret << endl;
	return 0;
}
