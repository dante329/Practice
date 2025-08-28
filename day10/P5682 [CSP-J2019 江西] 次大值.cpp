#include<iostream>
#include<algorithm>

using namespace std;

int n,a[200010]; 

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	n = unique(a + 1, a + 1 + n) - (a + 1); //去重(unique只能去除相邻的相同元素) 
	
	if(n == 1) cout << -1;
	else if(n == 2) cout << a[2] % a[1];
	else cout << max(a[n-2], a[n] % a[n-1]);
	
	return 0;
} 
