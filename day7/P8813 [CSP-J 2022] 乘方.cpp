#include<iostream>
//#include<climits>

using namespace std;

long long a,b;

int main()
{
	cin >> a >> b;
		
	long long ret = 1;
	
	while(b)
	{
		//·ÀÖ¹long longÒç³ö 
		if(a > 1e9) 
		{
			cout << -1;
			return 0;
		}
		if(b&1) ret *= a;
		if(ret > 1e9) 
		{
			cout << -1;
			return 0;
		}
		b >>= 1;
		a *= a;
	}
	
	cout << ret;
	
	return 0;
} 
