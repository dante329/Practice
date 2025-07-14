#include<iostream>

using namespace std;

typedef long long LL;

const int N = 5e3 + 10;

//������������������Ϊ0ʱ����������е�������Ҳ��ȫ����Ϊ0���������Դ�ö��k x k�����е��Ż���ֻö��k x k�����϶˵� 
int n,m,k;

LL f[N][N]; 

void insert(int x1, int y1, int x2, int y2, int z)
{
	f[x1][y1] += z;
	f[x1][y2 + 1] -= z;
	f[x2 + 1][y1] -= z;
	f[x2 + 1][y2 + 1] += z;
}

int main()
{
	cin >> n >> m >> k;
	
	while(m--)
	{
		int x,y,z; cin >> x >> y >> z;
		insert(x, y, x, y, z);
	}
	
	LL sum = 0; //�ܲ����������ܳ���int��Χ
	 
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=1;j<=n-k+1;j++)
		{
			sum += abs(f[i][j]);
			insert(i, j, i + k - 1, j + k - 1, -f[i][j]); //-f[i][j]Ϊ�˵���ԭf[i][j]��ʹ��ֵ��Ϊ0 
		}
	}
	
	//���n x n��Χ�ڵĲ�������ֵ��û�в�Ϊ0�ģ�����оʹ����޷���� 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j])
			{
				cout << -1 << endl;
				return 0;
			}
		
	cout << sum << endl;
	return 0;
}
