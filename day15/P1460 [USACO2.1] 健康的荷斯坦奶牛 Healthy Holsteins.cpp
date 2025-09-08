#include<iostream>

using namespace std;

const int N = 30;

int n,m; //n：可用来喂牛的饲料 m：需要的维他命种类数  
int v[N]; //最小需要
int g[N][N]; //饲料信息 
int path,st; //方案 
int cnt,ret = N; //总数量

bool check()
{
	for(int i=1;i<=m;i++)
	{
		int sum = 0;
		for(int j=1;j<=n;j++)
		{
			if((path >> j) & 1) sum += g[j][i];
		}
		if(sum < v[i]) return false;
	}
	return true;
}

void dfs(int pos)
{
	if(cnt >= ret) return; //cnt即使等于ret字典序也比ret大
	if(check()) //check path是否已经满足奶牛需要 
	{
		ret = cnt;
		st = path;
		return;
	}
	
	if(pos > n) return;
	
	//选
	cnt++;
	path |= (1 << pos);
	dfs(pos+1);
	cnt--;
	path &= ~(1 << pos);
	//不选 
	dfs(pos+1);	
}

int main()
{
	cin >> m;
	
	for(int i=1;i<=m;i++) cin >> v[i];
	
	cin >> n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> g[i][j];

	dfs(1);
	
	cout << ret << " ";
	
	for(int i=1;i<=n;i++)
	{
		if((st >> i) & 1) cout << i << " ";
	}
	
	return 0;
}


 
