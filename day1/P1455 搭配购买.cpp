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
//		if(u != i) //���ײ����Լ�����������Ʒ���ϲ��۸�ͼ�ֵ 
//		{
//			c[u] += c[i]; //����ǰ������Ʒ�ļ۸��ۼӵ�������Ʒ�ļ۸� 
//			c[i] = 0; //c[i]�ÿգ���ҪӰ��״̬ת�ƣ���Ϊ���ǻ��ǰ���n����Ʒ������	
//			d[u] += d[i];
//			d[i] = 0;
//		} 
//	}
	
	for(int i=1;i<=n;i++)
	{
		if(fa[i] != i) //���ײ����Լ�����������Ʒ���ϲ��۸�ͼ�ֵ 
		{
			int u = find(i); //��Ҫ�ҵ���ǰ��Ʒ�ĸ���㣬��Ȼ��·��ѹ�������ǲ��ܱ�֤fa[i]����i�ĸ��ڵ� 
			c[u] += c[i]; //����ǰ������Ʒ�ļ۸��ۼӵ�������Ʒ�ļ۸� 
			c[i] = 0; //c[i]�ÿգ���ҪӰ��״̬ת�ƣ���Ϊ���ǻ��ǰ���n����Ʒ������	
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


//�ռ��Ż� 
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
//		if(fa[i] != i) //���ײ����Լ�����������Ʒ���ϲ��۸�ͼ�ֵ 
//		{
//			int u = find(i); //��Ҫ�ҵ���ǰ��Ʒ�ĸ���㣬��Ȼ��·��ѹ�������ǲ��ܱ�֤fa[i]����i�ĸ��ڵ� 
//			c[u] += c[i]; //����ǰ������Ʒ�ļ۸��ۼӵ�������Ʒ�ļ۸� 
//			c[i] = 0; //c[i]�ÿգ���ҪӰ��״̬ת�ƣ���Ϊ���ǻ��ǰ���n����Ʒ������	
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

vector<int> edges[N]; //����ͼ 

//dfs��Ҫst�����ж��Ƿ�������ˣ�cntͳ����ͨ�������cc�µļ۸�dd�µļ�ֵ 
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
