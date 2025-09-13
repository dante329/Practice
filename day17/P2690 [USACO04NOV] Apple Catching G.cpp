#include<iostream>

using namespace std;

const int N = 1010, M = 40;

int t,w,f[N][M],a[N]; //f[i][j]：表示第i时刻，移动次数为j次时，接住的最大苹果数量

int main()
{
	cin >> t >> w;
	
	for(int i=1;i<=t;i++) cin >> a[i];
	
	for(int i=1;i<=t;i++)
	{
		for(int j=0;j<=w;j++)
		{
			int c = 0;
			if((j%2==0 && a[i]==1) || (j%2==1 && a[i]==2)) c = 1;
			f[i][j] = f[i-1][j] + c;
			if(c) f[i][j] = max(f[i][j],f[i-1][j-1] + c); 
		} 
	}
	
	int ret = 0;
	for(int j=1;j<=w;j++)
	{
		ret = max(ret,f[t][j]);
	}
	
	cout << ret;
	
	return 0;
 } 
