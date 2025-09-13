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
		if(!step) step = cnt[i]; //如果step被整除了说明要逆时针走完cnt[i] 
 		
		while(1)
		{
			if(st[i][pos]) step--;
			if(step == 0) break;
			pos++; //不能合体写成if(st[i][pos++]) step--;因为pos在下一轮循环中还要使用 
			if(pos == m) pos = 0; 
		}
	}	

	cout << ret << endl;
	return 0;
}
