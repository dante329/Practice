//错误思路 
//#include<iostream>
//
//using namespace std;
//
//string s, b;
//int k;
//
//int main()
//{
//	cin >> s >> k;
//	
//	int pos = 0, sum = 0;
//	
//	for(int i=1;i<=9;i++)
//	{
//		while(s.find(to_string(i), pos) != -1)
//		{
//			pos = s.find(to_string(i), pos);
//			pos++;
//			sum++;
//			b.append(to_string(i));
//			if(sum == s.size() - k) 
//			{
//				cout << b;
//				return 0;
//			}	
//		}
//	} 
//	
//	cout << b;
//	return 0;
//}


//单调栈 
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string n;
//int k;
//
//int main() {
//    cin >> n >> k;
//    
//    string res;  // 用字符串模拟栈
//    
//    for (char c : n) {
//        // 如果还能删数字，并且当前数字比栈顶小，就删栈顶的数字
//        while (k > 0 && !res.empty() && res.back() > c) {
//            res.pop_back();
//            k--;
//        }
//        res.push_back(c);  // 当前数字入栈
//    }
//    
//    // 如果还没删够k个数字，就从末尾继续删
//    while (k > 0 && !res.empty()) {
//        res.pop_back();
//        k--;
//    }
//    
//    // 去掉前导零
//    int start = 0;
//    while (start < res.size() && res[start] == '0') {
//        start++;
//    }
//    
//    // 如果全删光了，就输出0，否则输出去掉前导零后的结果
//    if (start == res.size()) {
//        cout << "0";
//    } else {
//        cout << res.substr(start);
//    }
//    
//    return 0;
//}

#include<iostream>

using namespace std;

string s;

int k;

int main()
{
	cin >> s >> k;
	
	for(int i=1;i<=k;i++)
	{
		bool flag = false;
		for(int j=1;j<s.size();j++)
		{
			if(s[j-1] > s[j]) 
			{
				s.erase(j-1, 1);
				flag = true;
				break;
			}
		}
		if(!flag) s.pop_back(); 
	}
	
	//消除前导零 
	while(s.size() > 1 && s[0] == '0') s.erase(0,1); 
	
	cout << s;
	return 0;
}
