//#include <iostream>
//
//using namespace std;
//
//int main() 
//{
//	int T; cin >> T;
//	while(T--)
//	{
//		string s; cin >> s;
//		
//		int ret = 9, index = 0;
//		
//		//找到最小的数字 
//		for(int i=0;i<s.size();i++)
//		{	
//			if(s[i] - '0' < ret)
//			{
//				ret = s[i] - '0';
//				index = i;
//			}
//		}
//		
//		s[index] = '9';
//		
//		ret = 0;
//		for(auto ch:s)
//		{
//			ret += ch - '0';	
//		}
//		
//		cout << ret << endl;
//	}
//	
//	return 0;
//}


#include <iostream>

using namespace std;

int main() 
{
	int T; cin >> T;
	while(T--)
	{
		string s; cin >> s;
		
		int ret = 9, index = 0, cnt = 0;
		
		//找到最小的数字 
		for(auto ch:s)
		{	
			ret = min(ret,ch-'0');
			cnt += ch - '0';
		}
		
		if(ret == 0) cnt += 9;
		else cnt += 8;
		
		cout << cnt << endl;
	}
	
	return 0;
}
