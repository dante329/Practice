#include<iostream>

using namespace std;

const int N = 1e4 + 10;

int n;
int a[N];

int main()
{
	cin >> n; 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	int ret = 0;
	for(int i=1;i<=n;)
	{
		if(a[i]<a[i-1]) 
		{
			swap(a[i],a[i-1]);
			ret++;
			i--;		
		} 
		else
		{
			i++;
		} 
	}
	
	cout << ret;
	return 0;
}
