//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//typedef pair<int,int> PII;
//
//const int N = 1e6 + 10;
//
//string s, a[N];
//
//vector<PII> id[30];
//
//string fun(string t)
//{
//	char ch = t[0];
//	if(islower(ch)) return t;
//	t = char(tolower(ch)) + t.substr(1);
//	return t;	
//}
//
//int main() 
//{
//	cin >> s;
//	s = fun(s);
//	
//	string t; //����ÿ������ 
//	int pos = 0, cnt = 1; //pos��¼����ĸ��ȫ���е��±꣬cnt��¼�ǵڼ������� 
//	
//	while(cin >> t)
//	{
//		t = fun(t); //ȫ�����Сд��ĸ
//		
//		a[cnt] = t;
//		 
//		char ch = t[0];
//		id[ch-'a'].push_back({pos,cnt}); 
//		
//		pos += t.size() + 1;
//		cnt++;
//	}
//	
//	for(int i=1;i<=20;i++) cout << a[i] << endl;
//	for(auto tmp:id['t'-'a'])
//	{
//		int x=tmp.first,y=tmp.second;
//		cout << "pos:" << x << " " << "index:" << y;
//	}
//
//	char ch = s[0];
//	int first_index = 0, sum = 0;
//	bool flag = true;
//	for(auto tmp:id[ch-'a']) //�ַ�ch���ֹ����±�λ�� 
//	{
//		int x = tmp.first, y = tmp.second;
//		if(s == a[y]) 
//		{
//			if(flag) 
//			{
//				first_index = x;
//				flag = false;
//			}
//			sum++;
//		}
//	}
//
//	if(sum) cout << sum << " " << first_index;
//	else cout << -1 << endl;
//	
//		
//	return 0;
//}

#include <iostream>

using namespace std;

string s,t;

int main()
{
	cin >> s;
	getchar();
	getline(cin,t);
	
	s = " " + s + " ";
	t = " " + t + " ";
	
	for(int i=0;i<s.size();i++) s[i] = tolower(s[i]); 
	
	for(int i=0;i<t.size();i++) t[i] = tolower(t[i]); 
	
	int f = 0,cnt = 0;
	if(t.find(s) == -1) cout << -1;
	else
	{		
		f = t.find(s);
		int pos = 0;
		while(t.find(s, pos) != -1)
		{
			pos = t.find(s, pos);
			cnt++;
			pos++; //����һ��λ�ü����� 	
		} 
		
		cout << cnt << " " << f; 
	}
		
	return 0;
}
