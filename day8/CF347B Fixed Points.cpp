#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int main()
{
	cin >> n;
	
	int sum = 0; 
	//�����ݣ������ȱ���һ�飬�������ٸ�������ԭλ��  
	for(int i=0;i<n;i++) 
	{
		cin >> a[i];
		if(a[i] == i) sum++;
	}
	if(sum == n)
	{
		cout << n;
		return 0;
	}
		
	//������Щ�������໥��λ�ģ������ĵ���һ�Կ��������������		
	for(int i=0;i<n;i++)
	{
		if(a[i] == i) continue;
		if(a[a[i]] == i) 
		{
			cout << sum + 2;
			return 0;
		}
	}
	
	cout << sum + 1;
	return 0;
}
