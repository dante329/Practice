#include<iostream>

using namespace std;

const int N = 55;

//ע��f��һά������ 
int n,m,f[N+N][N][N],a[N][N]; //f[s][i1][i2]����ʾ���������Ϊs����һ����·�ĺ�����Ϊi1���ڶ�����·�ĺ�����Ϊi2ʱ������·���ĺøжȺ����ֵ 

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	
	for(int s=2;s<=n+m;s++) //s��2��ʼö�٣���Ϊ��������· 
	{
		for(int i1=1;i1<=n;i1++)
		{
			for(int i2=1;i2<=n;i2++)
			{
				if(i1 == i2 && s != n + m) continue; //�����ߵ�ͬһ�����ӣ������½��������� 
				int j1 = s - i1, j2 = s - i2;
				if(j1 <= 0 || j2 <= 0 || j1 > m || j2 > m) continue; //s_max=n+m,i_min=1,j_max=n+m-1����jʱ���ܳ���m�ģ�Ҫ������ 
				int& t = f[s][i1][i2]; //���������������浱ǰ״̬ 
				t = max(t,f[s-1][i1-1][i2-1]);
				t = max(t,f[s-1][i1-1][i2]);
				t = max(t,f[s-1][i1][i2-1]);
				t = max(t,f[s-1][i1][i2]);
				t += a[i1][j1] + a[i2][j2]; 
			}
		}
	}
	
	cout << f[n+m][n][n];
}
