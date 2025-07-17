//#include <iostream>
//
//using namespace std;
//
//int n;
//
//bool check(int x)
//{
//	if(x != 1)
//	{ 
//	 	int ret = 0;
//		while(x)
//		{
//			ret += x & 1;
//			x >>= 1;
//		}
//		if(ret == 1) return true;
//	}
//	return false;
//}
//
//int main() 
//{
//	cin >> n;
//	
//	if(check(n))
//	{
//		cout << n;
//		return 0;
//	}
//	
//	int tmp = 2;
//	while(n > 0)
//	{
//		n -= tmp;
//		tmp *= 2;	
//	}
//	
//	if(n == 0) 
//	{
//		for(int i=tmp/2;i>=2;i/=2) cout << i << " ";
//	}
//	else
//	{
//		cout << -1;
//	}
//	
//	return 0;
//}

//原版改进 
//#include <iostream>
//
//using namespace std;
//
//int n;
//
//int main() 
//{
//	cin >> n;
//	if(n & 1) 
//	{
//		cout << -1 ;
//		return 0;
//	}
//	
//	int x = n;
//	
//	int tmp = 1 << 30;
//	while(n > 0)
//	{
//		if(n >= tmp) n -= tmp;
//		tmp /= 2;
//	}
//	
//	if(n == 0) //能被优秀拆分 
//	{
//		int tmp = 1 << 30;
//		while(x > 0)
//		{
//			if(x >= tmp) 
//			{
//				x -= tmp;
//				cout << tmp << " ";
//			}
//			tmp /= 2;	
//		}
//	}
//	
//	return 0;
//}
//依旧太冗余

//最终简洁代码
#include <iostream>

using namespace std;

int n;

int main() 
{
	cin >> n; 
	
	if(n & 1) //是奇数直接结束 
	{
		cout << -1;
		return 0;
	}
	
	int t = 30;
	while(t >= 1)
	{
		if(n & (1 << t)) cout << (1 << t) << " ";
		t--;
	}
	
	return 0;
}



