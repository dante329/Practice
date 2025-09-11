#include<iostream>
#include<set>

using namespace std;

const int N = 1e4 + 10;

int n,f[N],h,id,r;

set<pair<int,int>> st;

int main()
{
	cin >> n >> id >> h >> r;
	
	
	for(int i=1;i<=r;i++)
	{
		int a,b; cin >> a >> b;
		if(a > b) swap(a,b);
		if(st.count({a,b})) continue;
		else 
		{
			f[a + 1]--;
			f[b]++;
			st.insert({a,b});
		}
	}
	
	for(int i=1;i<=n;i++) 
	{
		f[i] += f[i-1];
		cout << f[i]+h << endl;
	}
	
	return 0;
 } 
