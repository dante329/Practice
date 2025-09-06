#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n,c,f[N];

int main() 
{
	cin >> n >> c;
	
	int cur1 = 1, cur2 = 1;
	
	for(int i=1;i<=n;i++) 
	{
		int t; cin >> t;
		f[i] += t;
		f[i+1] -= t;
		
		if(f[cur2] > c) cur1 = cur2;
		cur2++;
	}
	
	cout << cur2 - cur1;
	
	return 0;
}
