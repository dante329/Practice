#include<iostream>

using namespace std;

const int N = 5e5 + 10;

int n,a,b,w[N];

bool check(int t)
{
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		if(w[i] <= t * a) continue; //����Ȼ��ɾͲ�����
		int d = w[i] - t * a; 
		sum += d / b + (d % b == 0 ? 0 : 1);
	}
	return sum <= t;
}

int main()
{
	cin >> n >> a >> b;
	
	for(int i=1;i<=n;i++) cin >> w[i];

	//ö�����к��ʱ�� 
	int l = 1, r = 5e5;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;	
 	}
	
	cout << l;
	
	return 0;
 } 
