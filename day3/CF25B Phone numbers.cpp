#include <iostream>
using namespace std;

int main() 
{
	int n; cin >> n;
	
	string s; cin >> s;
		
	s = " " + s;
	
	if(n % 2 == 0) //偶数，全部分成2个数 
	{
		for(int i=1;i<=n;i++)
		{
			cout << s[i];
			if(i % 2 == 0 && i < n) cout << "-"; 
		}
	}
	else //奇数，分一个3个数，其他全部分成2个数 
	{
		cout << s.substr(1,3); 
		if(n > 3) cout << "-"; 
		for(int i=4;i<=n;i++)
		{
			cout << s[i];
			if(i % 2 == 1 && i < n) cout << "-"; 
		}
	}
	
	return 0;
}

//更精炼 
#include <iostream>
using namespace std;

int main() 
{
	int n; cin >> n;
	
	string s; cin >> s;
	
	if(n % 2 == 0) //偶数，全部分成2个数 
	{
		for(int i=0;i<n;i++)
		{
			cout << s[i];
			if(i % 2 == 1 && i < n - 2) cout << "-"; 
		}
	}
	else //奇数，前面全部分成2个数，最后分一个3个数
	{
		for(int i=0;i<n;i++)
		{
			cout << s[i];
			if(i % 2 == 1 && i < n - 3) cout << "-"; 
		}
	}
	
	return 0;
}
