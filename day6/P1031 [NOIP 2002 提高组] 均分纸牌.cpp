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
//	sum /= n; //平均数
//	
//	for(int i=1;i<=n;i++)
//	{
//		pq.push({abs(a[i]-sum),i}); //插入{初始值与平均值的差值，编号} 
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
	
	sum /= n; //平均数
	
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
