#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int,int> PII; //{���ۣ�����}

const int N = 5010;

int n,m;

PII a[N];

bool cmp(PII x, PII y)
{
	return x.first < y.first;
}

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=m;i++) cin >> a[i].first >> a[i].second;

	sort(a+1,a+1+m,cmp); //���� 
	
	int ret = 0;
	
	for(int i=1;i<=m;i++)
	{
		if(n == 0) break;
		int x = a[i].first, y = a[i].second; //x���ۣ�y���� 
		if(n - y > 0) //�㹻����a[i]�ҵ�ţ�� 
		{
			ret += x * y;
			n -= y;
		}
		else
		{
			ret += x * n;
			n = 0;
		}
	}
	
	cout << ret << endl;
	return 0;
}
