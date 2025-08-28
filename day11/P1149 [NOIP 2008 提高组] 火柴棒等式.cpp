#include <iostream>

using namespace std;

int a[] = {6,2,5,5,4,5,6,3,7,6};

int calc(int x)
{
	if(x==0) return a[0];
	int s = 0;
	while(x)
	{
		s += a[x%10];
		x /= 10;
	}
	return s;
}

int main() 
{
	int n; cin >> n;
	
	n -= 4;
	
	int ret = 0;
	
	for(int i=0;i<=999;i++)
	{
		for(int j=0;j<=999;j++)
		{
			if(calc(i) + calc(j) + calc(i + j) == n) ret++;	
		}
	}
	
	cout << ret << endl;
	return 0;
}
