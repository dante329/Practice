#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int n,m,r[N],d[N],s[N],t[N];

int f[N]; //差分数组 

bool check(int x) //执行1~x个订单，看是否会导致非法 
{
	//初始化差分数组   
	for(int i=1;i<=n;i++) f[i] = r[i] - r[i-1];
	
	for(int i=1;i<=x;i++)
	{
		int t1 = s[i], t2 = t[i]; //t1开始日期，t2结束日期 
		f[t1] -= d[i], f[t2 + 1] += d[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		f[i] = f[i-1] + f[i];
		if(f[i] < 0) return false; //非法返回false 
	}
	
	return true; //合法返回true 
}

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> r[i];
	
	for(int i=1;i<=m;i++) cin >> d[i] >> s[i] >> t[i];
	
	int left = 1, right = m;
	
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(check(mid)) left = mid + 1; //合法落在左区间，调整left 
		else right = mid;
	}

//可以判断left是否等于m来确定是不是m个订单都能满足 
//	if(left == m) cout << 0 << endl; //所有订单均可满足
//	else 
//	{
//		cout << -1 << endl;
//		cout << left << endl;
//	} 


	//也可以对二分结束后的left check一下，看返回值是t or f 
	if(check(left)) cout << 0 << endl; //check(left)为false，落在左边，所有订单均可满足
	else cout << -1 << endl << left << endl;
	
	return 0;
} 
