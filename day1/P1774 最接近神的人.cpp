#include<iostream>

using namespace std; 

typedef long long LL;

const int N = 5e5 + 10;

int n, a[N], tmp[N];

LL merge(int left, int right)
{
	if(left >= right) return 0;
	
	//1.一分为二
	int mid = (left + right) >> 1; 
	
	//2.计算左右数组
	LL ret = 0; 
	ret += merge(left, mid);
	ret += merge(mid + 1, right);
	
	//3.合并左右数组
	int cur1 = left, cur2 = mid + 1, i = left;
	while(cur1 <= mid && cur2 <= right)
	{
		if(a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];
		else
		{
			tmp[i++] = a[cur2++];
			ret += mid - cur1 + 1; 
		}	
	} 
	
	while(cur1 <= mid) tmp[i++] = a[cur1++];
	while(cur2 <= right) tmp[i++] = a[cur2++];
	
	for(int j=left;j<=right;j++) a[j] = tmp[j];
	
	return ret;
}


int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	cout << merge(1,n) << endl;	
	
	return 0;
}
