#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int N = 1010;

vector<int> edge[N];

vector<int> a;

int k,n,m,cnt[N]; 

bool st[N];

void dfs(int u)
{
	cnt[u]++;
	st[u] = true;
	for(int v:edge[u])
	{
		if(!st[v]) dfs(v);
	}
}

int main()
{
	cin >> k >> n >> m;
	
	for(int i=1;i<=k;i++)
	{
		int t; cin >> t; //tºÅÄÁ³¡ÓĞÄÌÅ£ 
		a.push_back(t); 
	}
	
	for(int i=1;i<=m;i++)
	{
		int u,v; cin >> u >> v;
		edge[u].push_back(v); 
	}
	
	for(int t:a)
	{
		memset(st,0,sizeof st);
		dfs(t);
	}
	
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i] == k) ret++;
	}
	
	cout << ret;
	
	return 0;
}
