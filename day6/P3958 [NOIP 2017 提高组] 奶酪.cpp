#include<iostream>
#include<cmath>

using namespace std;

typedef long long LL;

const int N = 1e3 + 10;

LL n,h,r;

int fa[N]; //并查集 

LL x[N],y[N],z[N];

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
	fa[find(x)] = find(y);
}

bool check(int a, int b)
{
	//为了避免涉及double的比较，计算的是距离的平方
	LL d = (x[a]-x[b]) * (x[a]-x[b]) + (y[a]-y[b]) * (y[a]-y[b]) + (z[a]-z[b]) * (z[a]-z[b]);
	return d <= 4 * r * r;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		cin >> n >> h >> r;
		//初始化并查集，从0~n+1 
		for(int i=0;i<=n+1;i++) fa[i] = i;
		for(int i=1;i<=n;i++)
		{
			cin >> x[i] >> y[i] >> z[i];
			//判断与下表面是否连通
			if(z[i] <= r) merge(i,0);
			//判断上表面
			if(z[i] >= h - r) merge(i,n+1);
			//判断当前空洞与之前所有的空洞是否相连。这一步是必须的，因为题目给出的空洞的顺序不是有序的 
			for(int j=1;j<i;j++) 
			{
				if(check(i,j)) merge(i,j);	
			}	
		} 
		if(find(0) == find(n+1)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
} 
