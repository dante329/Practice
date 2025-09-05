//���� 
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
//		return; //�����������return����Ҫ��returnǰ���� 
//	}
//	//�ַ�������ϴ��󣬲����ڱ����ӽڵ��ʱ����ݣ���Ϊdfs(t)���ܵݹ��˶�㣡����������ֻ������һ�� 
//	//���������ԭ�������Ƶݹ麯����˼·����������д�����д����ʱ������dfs������������ɻ��ݹ��ܣ�ʵ���ϻ�ûд�꣬�ں����Ľ�β����л��� 
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

//�ⷨ1��dfs 
#include<iostream>
#include<vector>

using namespace std;

const int N = 25;

int n, ret, sum, a[N];

vector<int> edge[N], path, best_path;

//��ôȥ�����dfs�Ľ�β���л��ݡ�
//ʵ��������dfs������������һ������״̬��������һ�����֮��������¡������ǵ����֮�����ӵ�״̬����һ����ͨ�˾�������ˡ� 
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
	
	//��ȷ����������dfs����ĩβͳһ����
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

//�ⷨ����dp�����������
#include<iostream>
#include<vector>

using namespace std;

const int N = 25;

int n, a[N], f[N], e[N][N], pre[N]; //pre��¼ǰ�� 

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
		for(int j=1;j<i;j++) //ö��ǰ�� 
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
	
	fun(index); //�ѵ���Ȼ�������·�� 
	
	cout << endl << ret << endl;
	
	return 0;
}
 
