//正难则反，我想的是先把地图标记一遍，再看看能不能走通
//实际上可以读数据的时候标记地图，用INF初始化代替st数组判断是否第一次遍历。 
//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//typedef pair<int,int> PII;
//
//const int N = 310, M = 5e4 + 10;
//
//int a[N][N], m, x[M], y[M], t[M];
//
//bool st[N][N];
//
//int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
//
//void bfs()
//{
//	queue<PII> q;
//	
//	q.push({0,0});
//	st[0][0] = true;
//	
//	while(q.size())
//	{
//		auto t = q.front(); q.pop();
//		int x = t.first, y = t.second;
//		for(int k=0;k<4;k++)
//		{
//			int i = x + dx[k], j = y + dy[k];
//			if(i<0||i>300||j<0||j>300||st[i][j]) continue;
//			a[i][j] = a[x][y] + 1;
//			st[i][j] = true;
//			q.push({i,j}); 
//		}
//	}
//}
//
//int main()
//{
//	cin >> m;
//	
//	for(int i=1;i<=m;i++) cin >> x[i] >> y[i] >> t[i];
//	
//	bfs();
//	
//	for(int i=1;i<=m;i++)
//	{
//		
//	}
//	
//	return 0;
//}


#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int,int> PII;

const int N = 310, INF = 0x3f3f3f3f;

int t[N][N], dist[N][N], m;

int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

int bfs()
{ 
	if(t[0][0] == INF) return 0; //起点未被破坏，直接逃出 
		
	queue<PII> q;
	
	memset(dist,0x3f,sizeof dist);
	
	dist[0][0] = 0;
	q.push({0,0});
	
	while(q.size())
	{
		auto tmp = q.front(); q.pop();
		int x = tmp.first, y = tmp.second;
		
		for(int k=0;k<4;k++)
		{
			int i = x + dx[k], j = y + dy[k];
			if(i < 0 || j < 0) continue; //越界 
			if(dist[i][j] != INF) continue; //已经更新过了，这句话相当于st数组判断当前位置是否走过 
			if(dist[x][y] + 1 >= t[i][j]) continue; //当前方块已经被破坏了
			
			dist[i][j] = dist[x][y] + 1;
			if(t[i][j] == INF) return dist[i][j];
			
			q.push({i,j}); 		 
		}		
	} 
	
	return -1;
}

int main()
{
	cin >> m;
	
	memset(t,0x3f,sizeof t);
	
	for(int i=1;i<=m;i++) 
	{
		int x,y,z; cin >> x >> y >> z;
		t[x][y] = min(t[x][y], z);
		
		for(int k=0;k<4;k++)
		{
			int i = x + dx[k], j = y + dy[k];
			if(i < 0 || j < 0) continue;
			t[i][j] = min(t[i][j], z);
		}
	}
	
	cout << bfs() << endl;
	
	return 0;
}
