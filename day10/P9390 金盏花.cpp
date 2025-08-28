//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//typedef long long LL;
//
//LL x,y,z;
//
//// ����10��n����
//LL power10(int n) 
//{
//    LL result = 1;
//    for (int i = 0; i < n; i++) 
//	{
//        result *= 10;
//    }
//    return result;
//}
//
//int calc(LL x)
//{
//	int cnt = 0;
//	while(x)
//	{
//		x /= 10;
//		cnt++;
//	}
//	
//	return cnt;
//}
//
//int main() 
//{
//	cin >> y >> z;
//	
//	int cnt1,cnt2;
//	
//	cnt1 = calc(y);
//	cnt2 = calc(z);
//	
//	if(cnt2 <= cnt1) 
//	{
//		cout << abs(1LL * 1e11 + y - z) << endl; 
//	}
//	else
//	{
//		LL rem = z % power10(cnt1);
//		
//		//ȡ����7λ�� 
//		int t = z % power10(cnt1+1);
//		t /= power10(cnt1); 
//		
//		if(cnt2 == 12) //���zΪ12λ
//		{
//			//ȡ����5λ
//			LL head = z / power10(7);
//			//�Ƚ�t��t+1��t-1�ֱ�ƴ�Ӻ�Ĵ�С
//			LL ret = power10(12); 
//			for(int i=t-1;i<=t+1;i++)
//			{
//				ret = min(ret, head * power10(7) + i * power10(6) + y - z); 
//			}
//			cout << abs(ret);
//		} 
//		else
//		{
//			//ȡ����λ
//			LL head = z / power10(7);
//			//�Ƚ�t��t+1��t-1�ֱ�ƴ�Ӻ�Ĵ�С
//			LL ret = power10(12); 
//			for(int i=t-1;i<=t+1;i++)
//			{
//				ret = min(ret, power10(11) + head * power10(7) + i * power10(6) + y - z); 
//			}
//			cout << abs(ret);
//		}
//	}
//	
//	
//	return 0;
//}

#include <iostream>

using namespace std;

typedef long long LL;

LL y,z;

int main() 
{
	cin >> y >> z;
	
	LL ret = 1e12;
	
	for(LL i=100000;i<=999999;i++)
	{
		ret = min(ret, abs(i * 1000000 + y - z));
	}
	
	cout << ret;
	
	return 0;
}
