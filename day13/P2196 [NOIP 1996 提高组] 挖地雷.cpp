//错误 
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int N = 25;
//
//int n, ret, sum, a[N];
//
//vector<int> edge[N], path, best_path;
//
//void dfs(int u)
//{
//	path.push_back(u); 	
//	sum += a[u];
//	
//	if(edge[u].empty()) 
//	{
//		if(sum > ret) 
//		{
//			ret = sum;
//			best_path = path;
//		}
//		return; //并且这里如果return，就要在return前回溯 
//	}
//	//又犯了这个老错误，不能在遍历子节点的时候回溯，因为dfs(t)可能递归了多层！！！而这里只回溯了一层 
//	//犯这个错误原因就是设计递归函数的思路不清晰，在写道这行代码的时候不相信dfs函数本身能完成回溯功能，实际上还没写完，在函数的结尾会进行回溯 
//	for(int t:edge[u])
//	{
//		dfs(t);
//		sum -= a[t];
//		path.pop_back();
//	}
//	
//}
//
//int main()
//{
//	cin >> n;
//	
//	for(int i=1;i<=n;i++) cin >> a[i];
//	
//	for(int i=1;i<n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			int t; cin >> t;
//			if(t) edge[i].push_back(j); 
//		}
//	}
//	
//	for(int i=1;i<=n;i++)
//	{
//		sum = 0;
//		path.clear();
//		dfs(i);
//	}
//	
//	for(auto t:best_path) cout << t << " ";
//	
//	cout << endl << ret << endl;
//	
//	return 0;
//}

//解法1：dfs 
#include<iostream>
#include<vector>

using namespace std;

const int N = 25;

int n, ret, sum, a[N];

vector<int> edge[N], path, best_path;

//怎么去理解在dfs的结尾进行回溯。
//实际上整个dfs函数是在描述一个结点的状态，即进入一个结点之后该做的事。而不是点与点之间连接的状态，这一点想通了就能理解了。 
void dfs(int u)
{
	path.push_back(u); 	
	sum += a[u];
	
	if(edge[u].empty()) 
	{
		if(sum > ret) 
		{
			ret = sum;
			best_path = path;
		}
	}
	else for(int t:edge[u]) dfs(t);
	
	//正确的做法是在dfs函数末尾统一回溯
	sum -= a[u];
	path.pop_back();
	return;	
}

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int t; cin >> t;
			if(t) edge[i].push_back(j); 
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		sum = 0;
		path.clear();
		dfs(i);
	}
	
	for(auto t:best_path) cout << t << " ";
	
	cout << endl << ret << endl;
	
	return 0;
}

//解法二：dp最长上升子序列
#include<iostream>
#include<vector>

using namespace std;

const int N = 25;

int n, a[N], f[N], e[N][N], pre[N]; //pre记录前驱 

void fun(int x)
{
	if(pre[x]) fun(pre[x]);
	cout << x << " ";
}

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cin >> e[i][j]; 
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		f[i] = a[i];
		for(int j=1;j<i;j++) //枚举前驱 
		{
			if(e[j][i] && f[j] + a[i] > f[i])
			{
				f[i] = f[j] + a[i];
				pre[i] = j;
			}
		}
	}
	
	int index = 0, ret = 0;
	for(int i=1;i<=n;i++) 
	{
		if(f[i] > ret)
		{
			ret = f[i];
			index = i;
		}
	}
	
	fun(index); //搜到底然后倒叙输出路径 
	
	cout << endl << ret << endl;
	
	return 0;
}
 
