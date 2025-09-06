#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], len, n, k;

bool check(int x) //�տ�ָ��Ϊxʱ����Ҫ����С·������ 
{
	int cnt = 0;
	for(int i=1;i<n;i++)
	{
		int lenth = a[i+1] - a[i];
		cnt += lenth/x;
		if(lenth % x == 0) cnt--;
	}
	return cnt > k;
}

int main()
{
	cin >> len >> n >> k;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	//���ֿտ�ָ�� 
	int l = 1, r = len;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	
	cout << l;
	
	return 0;
}
