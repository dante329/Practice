//#include<iostream>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//
//bool st[N];
//
//int n, a[N];
//
//int main()
//{
//	cin >> n;
//	
//	for(int i=1;i<=n;i++) 
//	{
//		cin >> a[i];
//		if(!a[i]) st[i] = true;
//	}
//	
//	int
//	
//	return 0;
//}

#include<iostream>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int n, a[N];

int main()
{
	cin >> n;
	
	LL ret = 0;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		if(a[i] > a[i-1]) ret += a[i] - a[i-1];
	}
	
	cout << ret;
	
	return 0;
}
