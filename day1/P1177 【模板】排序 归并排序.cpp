#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, a[N], tmp[N]; //a�����ݣ�tmp�����鲢����ʱ�ϲ��������� 

void merge_sort(int left, int right)
{
	if(left >= right) return; //left == rightֻ��һ��Ԫ�أ����򣬷��� 

	//1.����һ��Ϊ�� 
	int mid = (left + right) / 2;
	
	//2.���������鶼�ź��� 
	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	
	//3.�ϲ������������鵽tmp�� 
	int cur1 = left, cur2 = mid + 1, i = left; //i����д����ʱ���� 
	
	while(cur1 <= mid && cur2 <= right)
	{
		if(a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];
		else tmp[i++] = a[cur2++];
	}
	
	while(cur1 <= mid) tmp[i++] = a[cur1++];
	while(cur2 <= right) tmp[i++] = a[cur2++];
	
	//4.��tmp�е�[left,right]����ת�Ƶ�a��[left,right]���� 
	for(int j=left;j<=right;j++) a[j] = tmp[j]; //�����״��һ����Ҫ֪����merge_sort�����У������Ƕ�[left, right]����������������[0, n] 
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	merge_sort(1,n);
	
	for(int i=1;i<=n;i++) cout << a[i] << " ";

	return 0;
}
