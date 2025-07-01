#include<iostream>
#include<queue>

using namespace std;
const int N = 1e4 + 10;
typedef pair<int,int> PII; //{开始时间，结束时间}
priority_queue<PII,vector<PII>,greater<PII>> heap; 
int n,m;
int w[N];

int main()
{
	cin >> n >> m;
	int maxw = 0;
	for(int i=1;i<=n;i++)
	{
		int t; cin >> t; 
		w[i] = t;
		maxw = max(maxw,t);
	}
	
	if(n <= m) //水管多，人少，就直接返回最慢的那个maxw
	{
		cout << maxw << endl;
		return 0;
	}
	
	//水管少，人多，就先将水管全部用上
	for(int i=1;i<=m;i++)
	{
		heap.push({0,w[i]}); 
	} 
	
	//用ret记录 
	int ret = 0; 
	
	for(int i=m+1;i<=n;i++)
	{
		PII t = heap.top(); heap.pop();
		int a = t.first, b = t.second;
		ret = max(ret,b);
		heap.push({b,b+w[i]}); 
	}
	
	while(heap.size())
	{
		ret = max(ret,heap.top().second); 
		heap.pop();
	}
	
	cout << ret << endl;
	return 0;
}

#include<iostream>
#include<queue>

using namespace std;
const int N = 1e4 + 10;

priority_queue<int,vector<int>,greater<int>> heap; //小根堆，存结束时间 
int n,m;
int w[N];

int main()
{
	cin >> n >> m;
	int maxw = 0;
	for(int i=1;i<=n;i++)
	{
		int t; cin >> t; 
		w[i] = t;
		maxw = max(maxw,t);
	}
	
	if(n <= m) //水管多，人少，就直接返回最慢的那个maxw
	{
		cout << maxw << endl;
		return 0;
	}
	
	//水管少，人多，就先将水管全部用上
	for(int i=1;i<=m;i++)
	{
		heap.push(w[i]); 
	} 
	
	//用ret记录 
	int ret = 0; 
	
	for(int i=m+1;i<=n;i++)
	{
		int t = heap.top(); heap.pop();
		ret = max(ret,t);
		heap.push(t+w[i]); 
	}
	
	while(heap.size())
	{
		ret = max(ret,heap.top()); 
		heap.pop();
	}
	
	cout << ret << endl;
	return 0;
}

#include<iostream>
#include<queue>

using namespace std;
const int N = 1e4 + 10;

priority_queue<int,vector<int>,greater<int>> heap;
int n,m;

int main()
{
	cin >> n >> m;

	for(int i=1;i<=m;i++) //初始化，把每个水管的结束时间设置为0 
	{
		heap.push(0); 
	}

	int ret = 0; //ret记录最长接水时间 
	for(int i=1;i<=n;i++)
	{
		int w; cin >> w;
		int t = heap.top(); heap.pop();
		heap.push(t + w); 
		ret = max(ret,t + w); //虽然t+w的结束时间刚放进去，还没到，但是我们不一定非要按照线性的时间顺序模拟，既然已知一个更久的结束时间，我们就那它先与ret作比较 
	} 
	
	cout << ret << endl;
	return 0;
}
