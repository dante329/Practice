#include<iostream>

using namespace std;

const int N = 30;

int n,m; //n��������ιţ������ m����Ҫ��ά����������  
int v[N]; //��С��Ҫ
int g[N][N]; //������Ϣ 
int path,st; //���� 
int cnt,ret = N; //������

bool check()
{
	for(int i=1;i<=m;i++)
	{
		int sum = 0;
		for(int j=1;j<=n;j++)
		{
			if((path >> j) & 1) sum += g[j][i];
		}
		if(sum < v[i]) return false;
	}
	return true;
}

void dfs(int pos)
{
	if(cnt >= ret) return; //cnt��ʹ����ret�ֵ���Ҳ��ret��
	if(check()) //check path�Ƿ��Ѿ�������ţ��Ҫ 
	{
		ret = cnt;
		st = path;
		return;
	}
	
	if(pos > n) return;
	
	//ѡ
	cnt++;
	path |= (1 << pos);
	dfs(pos+1);
	cnt--;
	path &= ~(1 << pos);
	//��ѡ 
	dfs(pos+1);	
}

int main()
{
	cin >> m;
	
	for(int i=1;i<=m;i++) cin >> v[i];
	
	cin >> n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> g[i][j];

	dfs(1);
	
	cout << ret << " ";
	
	for(int i=1;i<=n;i++)
	{
		if((st >> i) & 1) cout << i << " ";
	}
	
	return 0;
}


 
