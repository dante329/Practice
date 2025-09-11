//错因：修改前一个盒子 a[i] 的值，从而可能破坏前一对 (i-1, i) 已经满足的约束，导致之前“修好”的位置被再次弄坏，违反正确贪心的不回退原则。
//正确贪心应“只动当前右盒”，即在处理对 (i-1, i) 时，只减少 a[i]，绝不回头动 a[i-1]。
//#include <iostream>
//
//using namespace std;
//
//int n,x,a[100010];
//
//int main() 
//{
//	cin >> n >> x;
//	
//	for(int i=1;i<=n;i++) cin >> a[i];
//	
//	int ret = 0;
//	for(int i=1;i<n;i++)
//	{
//		if(a[i] + a[i+1] > x)
//		{
//			int t = a[i] + a[i+1] - x;
//			ret += t;
//			if(a[i+1] >= t) a[i+1] -= t;
//			else a[i] -= t; //破坏了已修好的相邻约束
//		}
//	}
//	
//	cout << ret;
//	return 0;
//}

//正确 
#include <iostream>

using namespace std;

int n,x,a[100010];

int main() 
{
	cin >> n >> x;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	long long ret = 0;
	for(int i=1;i<=n;i++)
	{
		long long t = a[i-1] + a[i] - x;
		if(t > 0) 
		{
			a[i] = x - a[i-1];
			ret += t;
		}
		
	}
	
	cout << ret;
	return 0;
}
