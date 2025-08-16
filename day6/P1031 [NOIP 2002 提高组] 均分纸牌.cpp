//#include<iostream>
//#include<queue>
//using namespace std;
//
//typedef pair<int,int> PII;
//
//priority_queue<PII> pq; 
//
//int n,a[110];
//
//int main()
//{
//	cin >> n;
//	
//	int sum = 0;
//	for(int i=1;i<=n;i++) 
//	{
//		cin >> a[i];
//		sum += a[i];
//	}
//	
//	sum /= n; //ƽ����
//	
//	for(int i=1;i<=n;i++)
//	{
//		pq.push({abs(a[i]-sum),i}); //����{��ʼֵ��ƽ��ֵ�Ĳ�ֵ�����} 
//	}
//	
//	while(pq.size())
//	{
//		auto t = pq.top();
//		int val = t.first, ind = t.second;
//				
//		
//	} 
//	return 0;
//}

#include<iostream>
#include<queue>
using namespace std;

typedef pair<int,int> PII;

priority_queue<PII> pq; 

int n,a[110];

int main()
{
	cin >> n;
	
	int sum = 0;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		sum += a[i];
	}
	
	sum /= n; //ƽ����
	
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i] == sum) continue;
		
		ret++;
		
		a[i+1] -= sum - a[i];
	}

	cout << ret << endl;

	return 0;
}
