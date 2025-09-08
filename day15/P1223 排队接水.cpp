//#include <iostream>
//#include <algorithm>
//
//using namespace std;
// 
//const int N = 1010;
// 
//int n, f[N];
//struct node
//{
//	int v,id;	
//}t[N]; 
//
//bool cmp(node& a,node& b)
//{
//	return a.v < b.v; 
//}
//
//int main() 
//{
//	cin >> n;
//	
//	for(int i=1;i<=n;i++) 
//	{
//		cin >> t[i].v;
//		t[i].id = i; 
//	}
//	
//	sort(t+1,t+1+n,cmp);
//	
//	for(int i=1;i<=n;i++)
//	{
//		f[i] += t[i].v - t[i-1].v; //��һ�����ˣ���ĿҪ��ĵȴ�ʱ���ǲ����Լ��Ľ�ˮʱ��ģ���һ�����Լ���ʱ��Ҳ������ 
//		f[i+1] += t[i].v;
//		f[n+1] -= t[i].v; 
//		if(t[i].v == t[i+1].v)
//		{
//			if(t[i].id < t[i+1].id) cout << t[i].id << " ";
//			else cout << t[i+1].id << " ";
//		}
//		else cout << t[i].id << " ";
//	}
//	
//	//��ԭ���� 
//	double ret = 0;
//	for(int i=1;i<=n;i++)
//	{
//		f[i] = f[i-1] + f[i];
//		ret += f[i];
//	}
//	
//	cout << ret/n << endl;
//	
//	return 0;
//}

#include <iostream>
#include <algorithm>

using namespace std;
 
const int N = 1010;
 
int n, f[N];
struct node
{
	int v,id;	
}t[N]; 

bool cmp(node& a,node& b)
{
	return a.v < b.v; 
}

int main() 
{
	cin >> n;
	
	for(int i=1;i<=n;i++) 
	{
		cin >> t[i].v;
		t[i].id = i; 
	}
	
	sort(t+1,t+1+n,cmp);
	
	for(int i=1;i<=n;i++)
	{ 
		if(t[i].v == t[i+1].v)
		{
			if(t[i].id < t[i+1].id) cout << t[i].id << " ";
			else cout << t[i+1].id << " ";
		}
		else cout << t[i].id << " ";
	}
	cout << endl;	
	
	double ret = 0, wait = 0;
	for(int i=1;i<=n;i++)
	{
		ret += wait;
		wait += t[i].v;
	}
	
	printf("%.2lf\n",ret/n);
	
	return 0;
}
