//#include<iostream>
//
//using namespace std;
//
//string s;
//
//int n, Q;
//
//int main()
//{
//	cin >> n >> Q;
//	
//	for(int i=1;i<=n;i++)
//	{
//		int b; cin >> b; //��i�����������Ľ���
//		char ch = i + '0'; 
//		s.append(b, ch); 
//	}
//	
//	while(Q--)
//	{
//		int t; cin >> t;
//		cout << s[t] << endl;
//	}
//	return 0;
// } 

#include<iostream>

using namespace std;

const int N = 5e4 + 10; 

int n, Q, f[N];

//���ڽ���ʱ���ǵ����ģ��������ǿ���ʹ�ö�����ȷ��ĳ��ʱ������Ӧ�Ľ��� 
int check(int x)
{
	int l = 1, r = n;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(f[mid] > x) r = mid;
		else l = mid + 1;
	}
	
	return l;
}

int main()
{
	cin >> n >> Q;
	
	for(int i=1;i<=n;i++)
	{
		int t; cin >> t;
		f[i] = f[i-1] + t; //����ǰ׺��֮��f�е�ֵ�����i�����Ľ�����ʱ�� 
	}
	
	while(Q--)
	{
		int t; cin >> t;
		cout << check(t) << endl;
	}
	return 0;
 } 
