#include<iostream>
#include<queue>

using namespace std;

const int N = 2e5 + 10;

int ne[N], in[N]; //ne����ĺ�̣�in�������� 
//Ϊʲô���ⲻ��vector��i�ĳ�����Ϣ����Ϊ������ÿ�����iֻ��һ�����ߣ���߿����ж��� 

bool st[N];

int cnt;

void dfs(int u)
{
	cnt++;
	st[u] = true;
	
	int v = ne[u];
	if(!st[v]) dfs(v); //��׼�������ж�ne[x]����Ϊ0�ģ����������ʽ��֤ne[x]�������0 

}

int main()
{
	int n; cin >> n;
	
	for(int i=1;i<=n;i++) //��¼��ϵ 
	{
		cin >> ne[i];
		in[ne[i]]++;
	}
	
	//��������
	queue<int> q;
	
	//���������Ϊ0�ĵ������� 
	for(int i=1;i<=n;i++)
	{
		if(in[i] == 0) 
		{
			q.push(i);
			st[i] = true; //Ҳ���Բ���ǣ�����ʼ���Ϊ0�ĵ㲻�ᱻ������ָ���������ǲ��������������б���ǣ����������ǲ��ڻ��У�����DFSҲ���ᴦ������
		}
		
	} 
	 
	while(q.size())
	{
		auto u = q.front(); q.pop();
		int v = ne[u]; //ɾ�����Ϊ0�Ľ��ı� 
		in[v]--;
		if(in[v] == 0) 
		{
			q.push(v);
			st[v] = true;
		}		
	} 
	
	//���������н�㣬�����û��ӵģ��ʹ��ڻ�������dfs����̻��� 
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
