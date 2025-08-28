#include<iostream>

using namespace std;

const int N = 30, M = 3e4 + 10;

int f[M];

int n,m;

int v[N],p[N];

int main()
{
	cin >> m >> n;
	
	for(int i=1;i<=n;i++)
	{
		cin >> v[i] >> p[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=v[i];j--)
		{
			f[j] = max(f[j],f[j-v[i]] + v[i] * p[i]);

		}
	}
	
	cout << f[m];
	
	return 0;
 } 
