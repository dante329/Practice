#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N][N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0][0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=a[i] && k<=j;k++)
			{
				f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;
			}
		}
	}
	
	cout << f[n][m];
	return 0;
}


//һά 
#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			for(int k=0;k<=a[i] && k<=j;k++)
			{
				f[j] = (f[j] + f[j-k]) % MOD;
			}
		}
	}
	
	cout << f[m];
	return 0;
}

//�� 
#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			for(int k=1;k<=a[i] && k<=j;k++)
			{
				f[j] = (f[j] + f[j-k]) % MOD;
			}
		}
	}
	
	cout << f[m];
	return 0;
}

//���ر���ģ�� 
#include <iostream>

using namespace std;

const int N = 110;

int x[N],w[N],v[N],f[N][N];
int n,m;
 
int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> x[i] >> w[i] >> v[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			//�Ȳ�ѡ
			f[i][j] = f[i-1][j];
			//��ö��ѡ1~k��
			for(int k=1;k<=x[i] && k*w[i]<=j;k++)
			{
				f[i][j] = max(f[i-1][j],f[i-1][j-k*w[i]]+k*v[i]);
			}
			//��������пռ��Ż���ȷʵ����д������������k=0��ʱ��ʹ����š���ѡ����������������1~kmax�ʹ���ѡ1~k�Ρ�
			//����һ���ռ��Ż��ʹ��ˣ����Ի���Ҫ����ѡ��ѡ������ֿ���
			//for(int k=0;k<=x[i] && k*w[i]<=j;k++)
			//{
			//	  f[i][j] = max(f[i-1][j],f[i-1][j-k*w[i]]+k*v[i]);
			//}
		}
	}
	
	cout << f[n][m];
	
	return 0;
}
