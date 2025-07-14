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
//		int b; cin >> b; //第i个音符持续的节拍
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

//由于结束时间是递增的，所以我们可以使用二分来确定某个时间所对应的节拍 
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
		f[i] = f[i-1] + t; //做完前缀和之后，f中的值代表第i个节拍结束的时间 
	}
	
	while(Q--)
	{
		int t; cin >> t;
		cout << check(t) << endl;
	}
	return 0;
 } 
