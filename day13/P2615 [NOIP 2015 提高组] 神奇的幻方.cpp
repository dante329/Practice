#include <iostream>

using namespace std;

typedef pair<int,int> PII;

const int N = 45;

int n, a[N][N];

PII pos[N*N];

int main() 
{
	cin >> n;
	
	a[1][n/2+1] = 1;
	
	pos[1] = {1,n/2+1}; 
	
	for(int i=2;i<=n*n;i++)
	{
		PII t = pos[i-1];
		int x = t.first, y = t.second;
		if(x == 1 && y != n) 
		{
			a[n][y+1] = i;
			pos[i] = {n,y+1};
		}
		else if(y == n && x != 1)
		{
			a[x-1][1] = i;
			pos[i] = {x-1,1};
		}
		else if(x == 1 && y == n) 
		{
			a[x+1][y] = i;
			pos[i] = {x+1,y};
		}
		else if(x != 1 && y != n) 
		{
			if(a[x-1][y+1] == 0) 
			{
				a[x-1][y+1] = i;
				pos[i] = {x-1,y+1};
			}
			else 
			{
				a[x+1][y] = i;
				pos[i] = {x+1,y};
			}
		}
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
