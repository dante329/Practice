#include <iostream>
#include <algorithm>

using namespace std; 

typedef pair<int,int> PII;

const int N = 5010;

int n, a, b, s; 

PII x[N];

bool cmp(PII x, PII y)
{
	return x.second < y.second; 
}

int main() 
{
	cin >> n >> s >> a >> b;
	
	for(int i=1;i<=n;i++) cin >> x[i].first >> x[i].second;
	
	sort(x + 1, x + 1 + n, cmp);
	
	int ret = 0;
	for(int i=1;i<=n;i++) 
	{
		if(s >= x[i].second && a + b >= x[i].first)
		{
			ret++;
			s -= x[i].second;
		}
	}
	
	cout << ret;
	
	return 0;
}
