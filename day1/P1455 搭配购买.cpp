#include<iostream>
#include<vector>

using namespace std;

const int N = 1e4 + 10; 

int n,m,w,c[N],d[N],f[N][N];

int fa[N];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void un(int a,int b)
{
	fa[find(a)] = find(b);
}

int main()
{
	cin >> n >> m >> w;
	
	for(int i=1;i<=n;i++)
	{
		cin >> c[i] >> d[i];
	}
	
	for(int i=1;i<=n;i++) fa[i] = i; 
	
	for(int i=1;i<=m;i++)
	{
		int u,v; cin >> u >> v;
		un(u,v); 
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		int u = fa[i];
//		if(u != i) //父亲不是自己，有捆绑物品，合并价格和价值 
//		{
//			c[u] += c[i]; //将当前儿子物品的价格累加到父亲物品的价格 
//			c[i] = 0; //c[i]置空，不要影响状态转移，因为我们还是按照n个物品来遍历	
//			d[u] += d[i];
//			d[i] = 0;
//		} 
//	}
	
	for(int i=1;i<=n;i++)
	{
		if(fa[i] != i) //父亲不是自己，有捆绑物品，合并价格和价值 
		{
			int u = find(i); //先要找到当前物品的根结点，虽然有路径压缩，但是不能保证fa[i]就是i的根节点 
			c[u] += c[i]; //将当前儿子物品的价格累加到父亲物品的价格 
			c[i] = 0; //c[i]置空，不要影响状态转移，因为我们还是按照n个物品来遍历	
			d[u] += d[i];
			d[i] = 0;
		} 
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= c[i])
			{
				f[i][j] = max(f[i-1][j-c[i]] + d[i],f[i][j]);
			} 
		}
	}
	
	cout << f[n][w] << endl;
	return 0;
}


//空间优化 
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int N = 1e4 + 10; 
//
//int n,m,w,c[N],d[N],f[N];
//
//int fa[N];
//
//int find(int x)
//{
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//
//void un(int a,int b)
//{
//	fa[find(a)] = find(b);
//}
//
//int main()
//{
//	cin >> n >> m >> w;
//	
//	for(int i=1;i<=n;i++)
//	{
//		cin >> c[i] >> d[i];
//	}
//	
//	for(int i=1;i<=n;i++) fa[i] = i; 
//	
//	for(int i=1;i<=m;i++)
//	{
//		int u,v; cin >> u >> v;
//		un(u,v); 
//	}
//	
//	for(int i=1;i<=n;i++)
//	{
//		if(fa[i] != i) //父亲不是自己，有捆绑物品，合并价格和价值 
//		{
//			int u = find(i); //先要找到当前物品的根结点，虽然有路径压缩，但是不能保证fa[i]就是i的根节点 
//			c[u] += c[i]; //将当前儿子物品的价格累加到父亲物品的价格 
//			c[i] = 0; //c[i]置空，不要影响状态转移，因为我们还是按照n个物品来遍历	
//			d[u] += d[i];
//			d[i] = 0;
//		} 
//	}
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=w;j>=c[i];j--)
//		{
//			f[j] = max(f[j-c[i]] + d[i],f[j]);
//		}
//	}
//	
//	cout << f[w] << endl;
//	return 0;
//}

#include<iostream>
#include<vector>

using namespace std;

const int N = 1e4 + 10;

int n,m,w,c[N],d[N],f[N];

vector<int> edges[N]; //无向图 

//dfs需要st数组判断是否遍历过了，cnt统计连通块个数，cc新的价格，dd新的价值 
bool st[N]; 
int cnt,cc[N],dd[N];

void dfs(int x)
{
	if(st[x]) return; 
	
	st[x] = true;
	
	cc[cnt] += c[x];
	dd[cnt] += d[x];
	
	for(auto v:edges[x])
	{
		if(!st[v]) dfs(v);
	}
}

int main()
{
	cin >> n >> m >> w;
	
	for(int i=1;i<=n;i++) cin >> c[i] >> d[i];
	
	for(int i=1;i<=m;i++) 
	{
		int a,b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a); 
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!st[i])
		{
			cnt++;
			dfs(i);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=w;j>=cc[i];j--)
		{
			f[j] = max(f[j-cc[i]] + dd[i], f[j]);
		}
	}
	
	cout << f[w] << endl;
	
	return 0;
}
