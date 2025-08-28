#include<iostream>
#include<cstring>

using namespace std;

const int N = 100;

int n, f[N][2*N], t[N], w[N]; //f[i][j]:表示从1~i本书中选，厚度和恰好为j的最小宽度 

int main()
{
	cin >> n;
	int sum = 0;
	for(int i=1;i<=n;i++) 
	{
		cin >> t[i] >> w[i];
		sum += t[i];		
	}
	
	memset(f,0x3f,sizeof f);
	
	f[0][0] = 0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= t[i]) f[i][j] = min(f[i][j], f[i-1][j-t[i]]+w[i]);	
		}		
	}
	
	for(int j=sum;j>=0;j--)
	{
		if(f[n][j] <= sum-j) 
		{
			cout << sum-j;
			break;
		}
	}
	
	return 0;
} 
