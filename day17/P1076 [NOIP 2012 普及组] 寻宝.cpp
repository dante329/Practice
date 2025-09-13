#include <iostream>

using namespace std;

const int N = 1e4 + 10, M = 110, MOD = 20123;

int n,m,x[N][M],cnt[N];

bool st[N][M];

int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a,b; cin >> a >> b;
			x[i][j] = b;
			if(a) 
			{
				st[i][j] = true;
				cnt[i]++;
			}
		}
	}
	
	int pos; cin >> pos;
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		ret = (ret + x[i][pos]) % MOD;
		
		int step = x[i][pos] % cnt[i];
		if(!step) step = cnt[i]; //���step��������˵��Ҫ��ʱ������cnt[i] 
 		
		while(1)
		{
			if(st[i][pos]) step--;
			if(step == 0) break;
			pos++; //���ܺ���д��if(st[i][pos++]) step--;��Ϊpos����һ��ѭ���л�Ҫʹ�� 
			if(pos == m) pos = 0; 
		}
	}	

	cout << ret << endl;
	return 0;
}
