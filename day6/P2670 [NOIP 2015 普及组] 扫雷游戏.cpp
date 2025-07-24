#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int n,m;

int a[110][110];

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 1, 0, -1, 1, -1, 0};

int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch; cin >> ch;
			if(ch == '*') 
			{
				a[i][j] = INF;
				for(int k=0;k<8;k++)
				{
					int x = i + dx[k], y = j + dy[k];
					a[x][y]++;
				}
			}

		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j] >= INF) cout << "*";
			else cout << a[i][j];	
		}
		cout << endl;
	}
	
	return 0;
}
