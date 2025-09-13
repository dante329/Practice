#include<iostream>
#include<unordered_set>

using namespace std;

const int N = 1010;

int n,m,fa[N];

unordered_set<int> st;

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void un(int x,int y)
{
	fa[find(x)] = find(y);
} 

int main()
{
	while(cin >> n, n != 0)
	{
		cin >> m;
		for(int i=1;i<=n;i++) fa[i] = i;
		st.clear();
		while(m--)
		{
			int x,y; cin >> x >> y;
			un(x,y);
		}
		
		int ret = 0;
		for(int i=1;i<=n;i++)
		{
			if(!st.count(find(i))) 
			{
				ret++;
				st.insert(find(i));
			}
		}
		cout << ret - 1 << endl;
	} 
	return 0;
}

//р╡©иртеп╤о fa[i] == i
//#include<iostream>
//
//using namespace std;
//
//const int N = 1010;
//
//int n,m,fa[N];
//
//
//int find(int x)
//{
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//
//void un(int x,int y)
//{
//	fa[find(x)] = find(y);
//} 
//
//int main()
//{
//	while(cin >> n, n != 0)
//	{
//		cin >> m;
//		for(int i=1;i<=n;i++) fa[i] = i;
//		
//		while(m--)
//		{
//			int x,y; cin >> x >> y;
//			un(x,y);
//		}
//		
//		int ret = 0;
//		for(int i=1;i<=n;i++)
//		{
//			if(fa[i] == i) ret++;
//		}
//		cout << ret - 1 << endl;
//	} 
//	return 0;
//}

