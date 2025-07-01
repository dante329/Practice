#include<iostream>
#include<queue>

using namespace std;
const int N = 1e4 + 10;
typedef pair<int,int> PII; //{��ʼʱ�䣬����ʱ��}
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
	
	if(n <= m) //ˮ�ܶ࣬���٣���ֱ�ӷ����������Ǹ�maxw
	{
		cout << maxw << endl;
		return 0;
	}
	
	//ˮ���٣��˶࣬���Ƚ�ˮ��ȫ������
	for(int i=1;i<=m;i++)
	{
		heap.push({0,w[i]}); 
	} 
	
	//��ret��¼ 
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

priority_queue<int,vector<int>,greater<int>> heap; //С���ѣ������ʱ�� 
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
	
	if(n <= m) //ˮ�ܶ࣬���٣���ֱ�ӷ����������Ǹ�maxw
	{
		cout << maxw << endl;
		return 0;
	}
	
	//ˮ���٣��˶࣬���Ƚ�ˮ��ȫ������
	for(int i=1;i<=m;i++)
	{
		heap.push(w[i]); 
	} 
	
	//��ret��¼ 
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

	for(int i=1;i<=m;i++) //��ʼ������ÿ��ˮ�ܵĽ���ʱ������Ϊ0 
	{
		heap.push(0); 
	}

	int ret = 0; //ret��¼���ˮʱ�� 
	for(int i=1;i<=n;i++)
	{
		int w; cin >> w;
		int t = heap.top(); heap.pop();
		heap.push(t + w); 
		ret = max(ret,t + w); //��Ȼt+w�Ľ���ʱ��շŽ�ȥ����û�����������ǲ�һ����Ҫ�������Ե�ʱ��˳��ģ�⣬��Ȼ��֪һ�����õĽ���ʱ�䣬���Ǿ���������ret���Ƚ� 
	} 
	
	cout << ret << endl;
	return 0;
}
