#include<iostream>
#include<queue>

using namespace std;

const int N = 2e5 + 10;

int ne[N], in[N]; //ne存结点的后继，in存结点的入度 
//为什么本题不用vector存i的出边信息，因为本题中每个结点i只有一条出边，入边可以有多条 

bool st[N];

int cnt;

void dfs(int u)
{
	cnt++;
	st[u] = true;
	
	int v = ne[u];
	if(!st[v]) dfs(v); //我准备特殊判断ne[x]不能为0的，但是输入格式保证ne[x]不会出现0 

}

int main()
{
	int n; cin >> n;
	
	for(int i=1;i<=n;i++) //记录关系 
	{
		cin >> ne[i];
		in[ne[i]]++;
	}
	
	//拓扑排序
	queue<int> q;
	
	//把所有入度为0的点加入队列 
	for(int i=1;i<=n;i++)
	{
		if(in[i] == 0) 
		{
			q.push(i);
			st[i] = true; //也可以不标记，初初始入度为0的点不会被其他点指向，所以它们不会在拓扑排序中被标记，但由于它们不在环中，后续DFS也不会处理它们
		}
		
	} 
	 
	while(q.size())
	{
		auto u = q.front(); q.pop();
		int v = ne[u]; //删掉入度为0的结点的边 
		in[v]--;
		if(in[v] == 0) 
		{
			q.push(v);
			st[v] = true;
		}		
	} 
	
	//最后遍历所有结点，如果有没入队的，就存在环，进行dfs求最短环长 
	int ret = n;
	for(int i=1;i<=n;i++)
	{
		if(!st[i]) 
		{
			cnt = 0;
			dfs(i);
			ret = min(ret,cnt);
		}
	} 
	
	cout << ret << endl;
	return 0;
 } 
