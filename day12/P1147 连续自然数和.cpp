#include<iostream>
#include<unordered_map>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

unordered_map<LL,int> mp;

int m; 

int main()
{
	cin >> m;
	
	mp[0] = 0;
	
	LL sum = 0;
	
	for(int i=1;i<=m/2+1;i++) 
	{
		sum += i;
		
		if(mp.count(sum-m))
		{
			int index = mp[sum-m];
			cout << index + 1 << " " << i << endl;
		}
		
		mp[sum] = i;
	}
	
	return 0;
}
