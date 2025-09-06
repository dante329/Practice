#include<iostream>
#include<algorithm>

using namespace std;

const int N = 4e4 + 10, M = 1e5 + 10;

struct node
{
	int x,y,z;
}a[M];

int n,m,fa[N];

bool cmp(node& a, node& b)
{
	return a.z > b.z;
}

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void un(int x, int y)
{
	fa[find(x)] = find(y);
}

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=m;i++) cin >> a[i].x >> a[i].y >> a[i].z;
	
	sort(a + 1, a + 1 + m, cmp);
	
	for(int i=1;i<=n+n;i++) fa[i] = i;
	
	//贪心
	for(int i=1;i<=m;i++)
	{
		int x = a[i].x, y = a[i].y, z = a[i].z;
		un(x,y+n); 
		un(y,x+n);
		if(find(x) == find(y)) //发现x、y分不开 
		{
			cout << z << endl;
			return 0;	
		}	
	}	
	
	cout << 0 << endl;
	
	return 0;
}

