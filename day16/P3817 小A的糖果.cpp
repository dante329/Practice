//�����޸�ǰһ������ a[i] ��ֵ���Ӷ������ƻ�ǰһ�� (i-1, i) �Ѿ������Լ��������֮ǰ���޺á���λ�ñ��ٴ�Ū����Υ����ȷ̰�ĵĲ�����ԭ��
//��ȷ̰��Ӧ��ֻ����ǰ�ҺС������ڴ���� (i-1, i) ʱ��ֻ���� a[i]��������ͷ�� a[i-1]��
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
//			else a[i] -= t; //�ƻ������޺õ�����Լ��
//		}
//	}
//	
//	cout << ret;
//	return 0;
//}

//��ȷ 
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
