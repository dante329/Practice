#include <iostream>

using namespace std;

int n,m,f[110];

int main() 
{
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int x,y; cin >> x >> y;
		f[x] += 1, f[y+1] -= 1;
	}
	
	bool flag = false;
	int index = 0;
	for(int i=1;i<=n;i++)
	{
		f[i] += f[i-1];
		if(f[i] != 1) 
		{
			flag = true;
			index = i;
			break;
		}
	}

//	for(int i=1;i<=n;i++) cout << f[i] << " ";
	
	if(flag) cout << index << " " << f[index];
	else cout << "OK";
	
	return 0;
}
