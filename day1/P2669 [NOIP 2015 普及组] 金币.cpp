#include <iostream>

using namespace std;

int main() 
{
	int k;
	cin >> k;
	int sum = 0, cnt = 1;
	for(int i=1;i<=k;)
	{
		if(i+cnt>k)
		{
			sum += (k-i+1) * cnt;
			break;
		}
		
		sum += cnt * cnt;		
		i += cnt;
		cnt++;
		
	}
	
	cout << sum;
	return 0;
}
