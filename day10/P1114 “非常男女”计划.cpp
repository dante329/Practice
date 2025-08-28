#include<iostream>
#include<unordered_map>

using namespace std;

int n;

unordered_map<int,int> mp;

int main()
{
	cin >> n;
	
	int sum = 0, ret = 0; //sum用来模拟前缀和
	
	mp[0] = 0; 
	
	for(int i=1;i<=n;i++)
	{
		int t; cin >> t;
		t = (t == 0 ? -1 : t);
		sum += t;
		
		if(mp.count(sum)) ret = max(ret, i - mp[sum]);
		else mp[sum] = i;
	}
	
	cout << ret;
	
	return 0;
}
