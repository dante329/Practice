#include <iostream>
using namespace std;

int main() 
{
	int n; cin >> n;
	
	string s; cin >> s;
		
	s = " " + s;
	
	if(n % 2 == 0) //ż����ȫ���ֳ�2���� 
	{
		for(int i=1;i<=n;i++)
		{
			cout << s[i];
			if(i % 2 == 0 && i < n) cout << "-"; 
		}
	}
	else //��������һ��3����������ȫ���ֳ�2���� 
	{
		cout << s.substr(1,3); 
		if(n > 3) cout << "-"; 
		for(int i=4;i<=n;i++)
		{
			cout << s[i];
			if(i % 2 == 1 && i < n) cout << "-"; 
		}
	}
	
	return 0;
}

//������ 
#include <iostream>
using namespace std;

int main() 
{
	int n; cin >> n;
	
	string s; cin >> s;
	
	if(n % 2 == 0) //ż����ȫ���ֳ�2���� 
	{
		for(int i=0;i<n;i++)
		{
			cout << s[i];
			if(i % 2 == 1 && i < n - 2) cout << "-"; 
		}
	}
	else //������ǰ��ȫ���ֳ�2����������һ��3����
	{
		for(int i=0;i<n;i++)
		{
			cout << s[i];
			if(i % 2 == 1 && i < n - 3) cout << "-"; 
		}
	}
	
	return 0;
}
