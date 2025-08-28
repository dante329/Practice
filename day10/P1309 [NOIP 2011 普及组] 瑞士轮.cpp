#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2e5 + 10;

struct node
{
	int id,s,w;
}a[N];

node x[N],y[N]; //胜部、败部 

int n,r,q;

bool cmp(node& x,node& y)
{
	if(x.s == y.s) return x.id < y.id;
	return x.s > y.s;
}

void merge()
{
	int cur1 = 1, cur2 = 1, i = 1;
	
	while(cur1 <= n && cur2 <= n)
	{
		if(x[cur1].s > y[cur2].s || (x[cur1].s == y[cur2].s && x[cur1].id < y[cur2].id)) //x排前面 
		{
			a[i++] = x[cur1++];
		}
		else
		{
			a[i++] = y[cur2++];
		}
	}
	
	while(cur1 <= n) a[i++] = x[cur1++];
	while(cur2 <= n) a[i++] = y[cur2++];
}

int main()
{
	cin >> n >> r >> q;
	
	for(int i=1;i<=2*n;i++)
	{
		cin >> a[i].s;
		a[i].id = i;
	}
	
	for(int i=1;i<=2*n;i++) cin >> a[i].w;
	
	sort(a + 1, a + 1 + n + n, cmp);
	
	for(int i=1;i<=r;i++) //r轮比赛 
	{
		int pos = 1;
		for(int j=1;j<=2*n;j+=2) //遍历2n，两两比赛 
		{	
			if(a[j].w > a[j+1].w)
			{
				a[j].s++;
				x[pos] = a[j];
				y[pos] = a[j+1];
			}
			else
			{
				a[j+1].s++;
				x[pos] = a[j+1];
				y[pos] = a[j];
			}
			pos++;
		}
		
		//合并x、y这两个有序数组
		merge(); 
	}
	
	cout << a[q].id;
	return 0;
}
