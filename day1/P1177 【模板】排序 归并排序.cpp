#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, a[N], tmp[N]; //a存数据，tmp辅助归并排序时合并两个数组 

void merge_sort(int left, int right)
{
	if(left >= right) return; //left == right只有一个元素，有序，返回 

	//1.数组一分为二 
	int mid = (left + right) / 2;
	
	//2.将左右数组都排好序 
	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	
	//3.合并左右有序数组到tmp中 
	int cur1 = left, cur2 = mid + 1, i = left; //i帮助写入临时数组 
	
	while(cur1 <= mid && cur2 <= right)
	{
		if(a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];
		else tmp[i++] = a[cur2++];
	}
	
	while(cur1 <= mid) tmp[i++] = a[cur1++];
	while(cur2 <= right) tmp[i++] = a[cur2++];
	
	//4.将tmp中的[left,right]区间转移到a的[left,right]区间 
	for(int j=left;j<=right;j++) a[j] = tmp[j]; //最容易错的一步，要知道在merge_sort函数中，我们是对[left, right]区间进行排序而不是[0, n] 
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	merge_sort(1,n);
	
	for(int i=1;i<=n;i++) cout << a[i] << " ";

	return 0;
}
