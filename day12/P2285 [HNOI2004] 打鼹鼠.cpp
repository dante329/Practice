//暴力超时orz 
//#include<iostream>
//#include<queue>
//#include<cstring>
//
//using namespace std;
//
//typedef pair<int,int> PII;
//
//const int N = 1e3 + 10, INF = 0x3f3f3f3f;
//
//int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
//
//int n,m,t[N][N],dist[N][N];
//
//int bfs(int a,int b) //返回能打死多少只鼹鼠 
//{ 
//	memset(dist,0x3f,sizeof dist);
//	
//	queue<PII> q;
//	
//	//以(a,b)为起点
//	dist[a][b] = 0;
//	q.push({a,b}); 
//	
//	int sum = 0;
//	
//	while(q.size())
//	{
//		auto tmp = q.front(); q.pop();
//		
//		int x = tmp.first, y = tmp.second;
//		
//		for(int k=0;k<4;k++)
//		{
//			int i = x + dx[k], j = y + dy[k];
//			if(i < 0 || j < 0 || i > n || j > n) continue;
//			if(dist[i][j] != INF) continue;
//			dist[i][j] = dist[x][y] + 1;
//			if(dist[i][j] == t[i][j]) sum++;
//			
//			q.push({i,j}); 
//		}
//	}
//	
//	return sum;
//}
//
//int main()
//{
//	cin >> n >> m;
//	
//	for(int i=1;i<=m;i++)
//	{
//		int z,x,y; cin >> z >> x >> y; 	
//		t[x][y] = z;
//	} 
//	
//	int ret;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			ret = max(ret, bfs(i,j));
//		}
//	}
//	
//	cout << ret;
//	
//	return 0;
//}


#include<iostream>

using namespace std;

const int N = 1e4 + 10;

int n,m,f[N],x[N],y[N],z[N]; // f[i]:以第i个鼹鼠为结尾的最长子序列 

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=m;i++)
	{
		cin >> z[i] >> x[i] >> y[i];	
	}
	
	for(int i=1;i<=m;i++)
	{
		f[i] = 1;
		for(int j=1;j<i;j++) //枚举i以前的鼹鼠
		{
			//计算曼哈顿距离，判断当前鼹鼠能不能被抓上 
			if(abs(x[i]-x[j]) + abs(y[i]-y[j]) <= z[i]-z[j]) 
			{
				f[i] = max(f[i],f[j] + 1);
			}
		} 
	}
	
	int ret = 0;
	for(int i=1;i<=m;i++) ret = max(ret,f[i]);
	
	cout << ret;
	
	return 0;
}
