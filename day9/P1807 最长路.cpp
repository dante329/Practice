//bf�㷨 
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int N = 1510, INF = 0x3f3f3f3f;

typedef pair<int,int> PII;

vector<PII> edge[N];

int n,m,dist[N],s; 

//ÿ������̱߳�������n-1�θ��¾Ϳ����ҵ����е�����·�� 
void bf()
{
	memset(dist,0x3f,sizeof dist); //dist��ʼ��Ϊ����
	
	dist[s] = 0;
	
	bool flag = false;
	//���ִ��n-1�Σ��Ϳ���ȷ���������·�ıߡ������һ�β���û���κ�relax������ǰ���� 
	for(int i=1;i<n;i++)
	{
		flag = false;
		//��ͼ��ÿһ���߽���relax  
		for(int u=1;u<=n;u++)
		{
			for(auto& t:edge[u])
			{
				int v = t.first, w = t.second;
				if(dist[u] + w < dist[v]) //s->u->v�ľ���С��s->v�ľ���͸���dist[v] 
				{
					dist[v] = dist[u] + w;
					flag = true;
				}
			}
		}	
		if(!flag) break;	
	}		
}

int main()
{
	cin >> n >> m;
	s = 1;
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		edge[u].push_back({v,-w}); //����ߣ����෴�� 
	}
	
	bf();
	
	if(dist[n] == INF) cout << -1 << endl;
	else cout << -dist[n] << endl;
	
	return 0;
} 

//spfa
//��bf�Ļ������ö����Ż�����relax���Ľ�������У������ϱ�ǡ�ֱ������Ϊ�ս����� 
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int,int> PII;

const int N = 1510, INF = 0x3f3f3f3f;

vector<PII> edge[N];

int n,m,s,dist[N];

bool st[N];

void spfa()
{
	memset(dist,0x3f,sizeof dist);
	
	dist[s] = 0;
	
	queue<int> q;
	
	q.push(s);
	st[s] = true;
	
	while(q.size())
	{
		int u = q.front(); q.pop();
		st[u] = false; //����ȡ����ǣ����� 
		
		for(auto& t:edge[u])
		{
			int v = t.first, w = t.second;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				//��Ϊv����relax�ˣ���v������в����ϱ�� 
				if(!st[v]) //һ��Ҫ���v�Ƿ��Ѿ��ڶ������ˣ����� 
				{
					q.push(v);
					st[v] = true;
				} 
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	s = 1;
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w; cin >> u >> v >> w;
		edge[u].push_back({v,-w}); 
	}
	
	spfa();
	
	if(dist[n] == INF) cout << -1 << endl;
	else cout << -dist[n] << endl;
	
	return 0;
}


//���ˣ�û�������������Ϊ0�ĵ��·��
//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//typedef pair<int,int> PII;
//
//const int N = 1510;
//
//vector<PII> edge[N];
//
//int n,m,s,in[N],f[N]; //f[i]:��ʾ��1��i�߹����· 
//
//int main()
//{
//	cin >> n >> m;
//	s = 1;
//	
//	for(int i=1;i<=m;i++)
//	{
//		int u,v,w; cin >> u >> v >> w;
//		edge[u].push_back({v,w}); 
//		in[v]++;
//	}
//	
//	//��������
//	queue<int> q;
//	
//	//�Ȱ��������Ϊ0�Ľ�������� 
//	for(int i=1;i<=n;i++)
//	{
//		if(in[i] == 0) q.push(i);
//		f[i] = -1e9;
//	}
//	 
//	while(q.size())
//	{
//		int u = q.front(); q.pop();
//			
//		for(auto& t:edge[u])
//		{
//			int v = t.first, w = t.second;
//			in[v]--;
//			f[v] = max(f[v], f[u] + w);
//			if(in[v] == 0) q.push(v);
//		}
//	}
//	
//	if(f[n] == -1e9) cout << -1 << endl;
//	else cout << f[n] << endl;
//	
//	return 0;
//}

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> PII;

const int N = 1510;

vector<PII> edge[N];

int n,m,s,in[N],f[N]; //f[i]:��ʾ��1��i�߹����· 

int main()
{
	cin >> n >> m;
	s = 1;
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w; cin >> u >> v >> w;
		edge[u].push_back({v,w}); 
		in[v]++;
	}
	
	//��������
	queue<int> q;
	
	//�Ȱѳ�1���������Ϊ0�Ľ�������� 
	for(int i=2;i<=n;i++)
	{
		if(in[i] == 0) q.push(i);
		f[i] = -1e9;
	}
	 
	while(q.size())
	{
		int u = q.front(); q.pop();
			
		for(auto& t:edge[u])
		{
			int v = t.first;
			in[v]--;
			if(in[v] == 0) q.push(v);
		}
	}
	
	q.push(1);
	 
	while(q.size())
	{
		int u = q.front(); q.pop();
			
		for(auto& t:edge[u])
		{
			int v = t.first, w = t.second;
			in[v]--;
			f[v] = max(f[v], f[u] + w);
			if(in[v] == 0) q.push(v);
		}
	}
	
	if(f[n] == -1e9) cout << -1 << endl;
	else cout << f[n] << endl;
	
	return 0;
}
