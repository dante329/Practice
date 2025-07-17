#include<iostream>

using namespace std;

const int N = 10;

int n,m,ret;

bool st[N][N];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};


void dfs(int x, int y)
{
	//����
	if(x < 1 || x >= n || y < 1 || y >= m) 
	{
		ret++; //return�˾ʹ����ҵ���·�ˣ��õ���һ���·��� 
		return;
	}
	
	st[x][y] = true; //���Ƿ�ֹdfs(i,j)�ֵݹ������ 
	for(int k=0;k<4;k++)
	{
		int i = x + dx[k], j = y + dy[k];
		if(!st[i][j]) dfs(i,j);		 
	}
	st[x][y] = false;
	 
}

int main()
{
	cin >> n >> m;
	
	//�����濪ʼ�� 
	for(int i=1;i<n;i++) //�ܿ��Ľ� 
	{
		//(i,0)->(i,1) 
		st[i][0] = true; //��(i,0)���ϱ�Ǵ����Ѿ��߹��ˣ�Ȼ���(i,1)��ʼ�ѣ������ͱ�����Ҫ��dfs�����еݹ���ڲ�����(i,0)�������㣩 
		dfs(i,1);
		st[i][0] = false;
	}
	
	//������� 
	for(int j=1;j<m;j++)
	{
		//(0,j)->(1,j)
		st[0][j] = true;
		dfs(1,j);
		st[0][j] = false;
	}
	
	cout << ret << endl;
	return 0;
}
