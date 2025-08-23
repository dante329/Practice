#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int main()
{
	cin >> n;
	
	int sum = 0; 
	//读数据，并且先遍历一遍，看看多少个数字在原位上  
	for(int i=0;i<n;i++) 
	{
		cin >> a[i];
		if(a[i] == i) sum++;
	}
	if(sum == n)
	{
		cout << n;
		return 0;
	}
		
	//看看哪些数字是相互错位的，这样的调整一对可以增加两个结果		
	for(int i=0;i<n;i++)
	{
		if(a[i] == i) continue;
		if(a[a[i]] == i) 
		{
			cout << sum + 2;
			return 0;
		}
	}
	
	cout << sum + 1;
	return 0;
}
