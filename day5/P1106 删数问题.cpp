//����˼· 
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


//����ջ 
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
//    string res;  // ���ַ���ģ��ջ
//    
//    for (char c : n) {
//        // �������ɾ���֣����ҵ�ǰ���ֱ�ջ��С����ɾջ��������
//        while (k > 0 && !res.empty() && res.back() > c) {
//            res.pop_back();
//            k--;
//        }
//        res.push_back(c);  // ��ǰ������ջ
//    }
//    
//    // �����ûɾ��k�����֣��ʹ�ĩβ����ɾ
//    while (k > 0 && !res.empty()) {
//        res.pop_back();
//        k--;
//    }
//    
//    // ȥ��ǰ����
//    int start = 0;
//    while (start < res.size() && res[start] == '0') {
//        start++;
//    }
//    
//    // ���ȫɾ���ˣ������0���������ȥ��ǰ�����Ľ��
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
	
	//����ǰ���� 
	while(s.size() > 1 && s[0] == '0') s.erase(0,1); 
	
	cout << s;
	return 0;
}
